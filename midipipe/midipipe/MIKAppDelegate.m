//
//  MIKAppDelegate.m
//  MIDI Testbed
//
//  Created by Andrew Madsen on 3/7/13.
//  Copyright (c) 2013 Mixed In Key. All rights reserved.
//

#import "MIKAppDelegate.h"
#import <MIKMIDI/MIKMIDI.h>
#import <mach/mach.h>
#import <mach/mach_time.h>

#import "audio_output/audio_output.h"
#import "player/MIDIPlay.h"

@interface MIKAppDelegate () <MIKMIDIConnectionManagerDelegate>

@property (nonatomic, strong) MIKMIDIConnectionManager *connectionManager;
@property (nonatomic, strong) MIKMIDIDeviceManager *midiDeviceManager;

@end

void audio_callback(void * context, float * out, uint32_t count)
{
    MIKAppDelegate * mad = ((__bridge MIKAppDelegate *)context);
    
    [mad.lock lock];
    
    if (mad.mp)
        mp_render(mad.mp, out, count);
    else
        memset(out, 0, count * sizeof(float) * 2);
    
    [mad.lock unlock];
}

@implementation MIKAppDelegate

- (id)init
{
    self = [super init];
    if (self) {
		_connectionManager = [[MIKMIDIConnectionManager alloc] initWithName:@"net.kode54.midipipe.ConnectionManager" delegate:self eventHandler:^(MIKMIDISourceEndpoint *source, NSArray<MIKMIDICommand *> *commands) {
			for (MIKMIDIChannelVoiceCommand *command in commands) { [self handleMIDICommand:command]; }
		}];
		_connectionManager.automaticallySavesConfiguration = NO;
		_midiDeviceManager = [MIKMIDIDeviceManager sharedDeviceManager];
        
        _lock = [[NSLock alloc] init];
        
        _cas = cas_create( audio_callback, (__bridge void *)self, 44100 );

        _mp = mp_create(3);
        mp_set_rate(_mp, 44100);
        
        cas_start(_cas);
    }
    return self;
}

- (void)dealloc
{
    if (_cas) {
        cas_close(_cas);
        cas_delete(_cas);
        _cas = 0;
    }
    [_lock lock];
    if (_mp) {
        mp_delete(_mp);
        _mp = 0;
    }
    [_lock unlock];
}

- (void)handleMIDICommand:(MIKMIDICommand *)command
{
    [_lock lock];
    if (_mp)
    {
        if (command.statusByte == 0xF0 || command.statusByte == 0xF7)
            mp_send_long(_mp, command.data.bytes, command.data.length);
        else
        {
            uint32_t command_short = command.statusByte | (command.dataByte1 * 0x100) | (command.dataByte2 * 0x10000);
            mp_send_short(_mp, command_short);
        }
    }
    [_lock unlock];
}

#pragma mark - Devices

+ (NSSet *)keyPathsForValuesAffectingAvailableDevices { return [NSSet setWithObject:@"connectionManager.availableDevices"]; }
- (NSArray *)availableDevices { return self.connectionManager.availableDevices; }

- (void)setDevice:(MIKMIDIDevice *)device
{
	if (device != _device) {
		if (_device) [self.connectionManager disconnectFromDevice:_device];
		_device = device;
		if (_device) {
			NSError *error = nil;
			if (![self.connectionManager connectToDevice:_device error:&error]) {
				[NSApp presentError:error];
			}
		}
	}
}

#pragma mark - Command Execution

- (IBAction)clearOutput:(id)sender 
{
    [self.textView setString:@""];
}

- (IBAction)sendSysex:(id)sender
{
    NSComboBox *comboBox = self.commandComboBox;
    NSString *commandString = [[comboBox stringValue] stringByReplacingOccurrencesOfString:@" " withString:@""];
    if (!commandString || commandString.length == 0) {
        return;
    }
    
    struct MIDIPacket packet;
    packet.timeStamp = mach_absolute_time();
    packet.length = commandString.length / 2;
    
    char byte_chars[3] = {'\0','\0','\0'};
    for (int i = 0; i < packet.length; i++) {
        byte_chars[0] = [commandString characterAtIndex:i*2];
        byte_chars[1] = [commandString characterAtIndex:i*2+1];
        packet.data[i] = strtol(byte_chars, NULL, 16);;
    }

    MIKMIDICommand *command = [MIKMIDICommand commandWithMIDIPacket:&packet];
	NSLog(@"Sending idenity request command: %@", command);
	
	NSArray *destinations = [self.device.entities valueForKeyPath:@"@unionOfArrays.destinations"];
	if (![destinations count]) return;
	for (MIKMIDIDestinationEndpoint *destination in destinations) {
        NSError *error = nil;
        if (![self.midiDeviceManager sendCommands:@[command] toEndpoint:destination error:&error]) {
            NSLog(@"Unable to send command %@ to endpoint %@: %@", command, destination, error);
        }
    }
}

@synthesize availableCommands = _availableCommands;
- (NSArray *)availableCommands 
{
    if (_availableCommands == nil) {
        MIKMIDISystemExclusiveCommand *identityRequest = [MIKMIDISystemExclusiveCommand identityRequestCommand];
        NSString *identityRequestString = [NSString stringWithFormat:@"%@", identityRequest.data];
        identityRequestString = [identityRequestString substringWithRange:NSMakeRange(1, identityRequestString.length-2)];
        _availableCommands = @[@{@"name": @"Identity Request",
                                 @"value": identityRequestString}];
    }
    return _availableCommands;
}

- (IBAction)commandTextFieldDidSelect:(id)sender 
{
    NSComboBox *comboBox = (NSComboBox *)sender;
    NSString *selectedValue = [comboBox objectValueOfSelectedItem];
    NSArray *availableCommands = [self availableCommands];
    NSPredicate *predicate = [NSPredicate predicateWithFormat:[NSString stringWithFormat:@"name=\"%@\"", selectedValue]];
    NSDictionary *selectedObject = [[availableCommands filteredArrayUsingPredicate:predicate] firstObject];
    if (selectedObject) {
        [comboBox setStringValue:selectedObject[@"value"]];
    }
    [self sendSysex:sender];
}

#pragma mark - MIKMIDIConnectionManagerDelegate

// We only want to connect to the device that the user selects
- (MIKMIDIAutoConnectBehavior)connectionManager:(MIKMIDIConnectionManager *)manager shouldConnectToNewlyAddedDevice:(MIKMIDIDevice *)device
{
	return MIKMIDIAutoConnectBehaviorDoNotConnect;
}

@end
