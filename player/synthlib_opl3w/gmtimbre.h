//
// Copyright (C) 1994-1995 Apogee Software, Ltd.
// Copyright (C) 2015-2016 Alexey Khokholov (Nuke.YKT)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#pragma once
#include "opl3type.h"

#pragma pack(1)

typedef struct
{
    byte mult[2];
    byte tl[2];
    byte ad[2];
    byte sr[2];
    byte wf[2];
    byte fb;
    int8_t note;
    byte octave;
} opl_timbre;

typedef struct
{
    byte base;
    byte note;
} opl_drum_map;

#pragma pack()

opl_timbre opl_timbres[ 256 ] =
   {
      { { 1, 1 }, { 143, 6 }, { 242, 242 }, { 244, 247 }, { 0, 0 }, 56, 0, 4 },
      { { 1, 1 }, { 75, 0 }, { 242, 242 }, { 244, 247 }, { 0, 0 }, 56, 0, 4 },
      { { 1, 1 }, { 73, 0 }, { 242, 242 }, { 244, 246 }, { 0, 0 }, 56, 0, 4 },
      { { 129, 65 }, { 18, 0 }, { 242, 242 }, { 247, 247 }, { 0, 0 }, 54, 0, 4 },
      { { 1, 1 }, { 87, 0 }, { 241, 242 }, { 247, 247 }, { 0, 0 }, 48, 0, 4 },
      { { 1, 1 }, { 147, 0 }, { 241, 242 }, { 247, 247 }, { 0, 0 }, 48, 0, 4 },
      { { 1, 22 }, { 128, 14 }, { 161, 242 }, { 242, 245 }, { 0, 0 }, 56, 0, 4 },
      { { 1, 1 }, { 146, 0 }, { 194, 194 }, { 248, 248 }, { 0, 0 }, 58, 0, 4 },
      { { 12, 129 }, { 92, 0 }, { 246, 243 }, { 244, 245 }, { 0, 0 }, 48, 0, 4 },
      { { 7, 17 }, { 151, 128 }, { 243, 242 }, { 242, 241 }, { 0, 0 }, 50, 0, 4 },
      { { 23, 1 }, { 33, 0 }, { 84, 244 }, { 244, 244 }, { 0, 0 }, 50, 0, 4 },
      { { 152, 129 }, { 98, 0 }, { 243, 242 }, { 246, 246 }, { 0, 0 }, 48, 0, 4 },
      { { 24, 1 }, { 35, 0 }, { 246, 231 }, { 246, 247 }, { 0, 0 }, 48, 0, 4 },
      { { 21, 1 }, { 145, 0 }, { 246, 246 }, { 246, 246 }, { 0, 0 }, 52, 0, 4 },
      { { 69, 129 }, { 89, 128 }, { 211, 163 }, { 243, 243 }, { 0, 0 }, 60, 0, 4 },
      { { 3, 129 }, { 73, 128 }, { 117, 181 }, { 245, 245 }, { 1, 0 }, 52, 0, 4 },
      { { 113, 49 }, { 146, 0 }, { 246, 241 }, { 20, 7 }, { 0, 0 }, 50, 0, 4 },
      { { 114, 48 }, { 20, 0 }, { 199, 199 }, { 88, 8 }, { 0, 0 }, 50, 0, 4 },
      { { 112, 177 }, { 68, 0 }, { 170, 138 }, { 24, 8 }, { 0, 0 }, 52, 0, 4 },
      { { 35, 177 }, { 147, 0 }, { 151, 85 }, { 35, 20 }, { 1, 0 }, 52, 0, 4 },
      { { 97, 177 }, { 19, 128 }, { 151, 85 }, { 4, 4 }, { 1, 0 }, 48, 0, 4 },
      { { 36, 177 }, { 72, 0 }, { 152, 70 }, { 42, 26 }, { 1, 0 }, 60, 0, 4 },
      { { 97, 33 }, { 19, 0 }, { 145, 97 }, { 6, 7 }, { 1, 0 }, 58, 0, 4 },
      { { 33, 161 }, { 19, 137 }, { 113, 97 }, { 6, 7 }, { 0, 0 }, 54, 0, 4 },
      { { 2, 65 }, { 156, 128 }, { 243, 243 }, { 148, 200 }, { 1, 0 }, 60, 0, 4 },
      { { 3, 17 }, { 84, 0 }, { 243, 241 }, { 154, 231 }, { 1, 0 }, 60, 0, 4 },
      { { 35, 33 }, { 95, 0 }, { 241, 242 }, { 58, 248 }, { 0, 0 }, 48, 0, 4 },
      { { 3, 33 }, { 135, 128 }, { 246, 243 }, { 34, 248 }, { 1, 0 }, 54, 0, 4 },
      { { 3, 33 }, { 71, 0 }, { 249, 246 }, { 84, 58 }, { 0, 0 }, 48, 0, 4 },
      { { 35, 33 }, { 74, 5 }, { 145, 132 }, { 65, 25 }, { 1, 0 }, 56, 0, 4 },
      { { 35, 33 }, { 74, 0 }, { 149, 148 }, { 25, 25 }, { 1, 0 }, 56, 0, 4 },
      { { 9, 132 }, { 161, 128 }, { 32, 209 }, { 79, 248 }, { 0, 0 }, 56, 0, 4 },
      { { 33, 162 }, { 30, 0 }, { 148, 195 }, { 6, 166 }, { 0, 0 }, 50, 0, 4 },
      { { 49, 49 }, { 18, 0 }, { 241, 241 }, { 40, 24 }, { 0, 0 }, 58, 0, 4 },
      { { 49, 49 }, { 141, 0 }, { 241, 241 }, { 232, 120 }, { 0, 0 }, 58, 0, 4 },
      { { 49, 50 }, { 91, 0 }, { 81, 113 }, { 40, 72 }, { 0, 0 }, 60, 0, 4 },
      { { 1, 33 }, { 139, 64 }, { 161, 242 }, { 154, 223 }, { 0, 0 }, 56, 0, 4 },
      { { 33, 33 }, { 139, 8 }, { 162, 161 }, { 22, 223 }, { 0, 0 }, 56, 0, 4 },
      { { 49, 49 }, { 139, 0 }, { 244, 241 }, { 232, 120 }, { 0, 0 }, 58, 0, 4 },
      { { 49, 49 }, { 18, 0 }, { 241, 241 }, { 40, 24 }, { 0, 0 }, 58, 0, 4 },
      { { 49, 33 }, { 21, 0 }, { 221, 86 }, { 19, 38 }, { 1, 0 }, 56, 0, 4 },
      { { 49, 33 }, { 22, 0 }, { 221, 102 }, { 19, 6 }, { 1, 0 }, 56, 0, 4 },
      { { 113, 49 }, { 73, 0 }, { 209, 97 }, { 28, 12 }, { 1, 0 }, 56, 0, 4 },
      { { 33, 35 }, { 77, 128 }, { 113, 114 }, { 18, 6 }, { 1, 0 }, 50, 0, 4 },
      { { 241, 225 }, { 64, 0 }, { 241, 111 }, { 33, 22 }, { 1, 0 }, 50, 0, 4 },
      { { 2, 1 }, { 26, 128 }, { 245, 133 }, { 117, 53 }, { 1, 0 }, 48, 0, 4 },
      { { 2, 1 }, { 29, 128 }, { 245, 243 }, { 117, 244 }, { 1, 0 }, 48, 0, 4 },
      { { 16, 17 }, { 65, 0 }, { 245, 242 }, { 5, 195 }, { 1, 0 }, 50, 0, 4 },
      { { 33, 162 }, { 155, 1 }, { 177, 114 }, { 37, 8 }, { 1, 0 }, 62, 0, 4 },
      { { 161, 33 }, { 152, 0 }, { 127, 63 }, { 3, 7 }, { 1, 1 }, 48, 0, 4 },
      { { 161, 97 }, { 147, 0 }, { 193, 79 }, { 18, 5 }, { 0, 0 }, 58, 0, 4 },
      { { 33, 97 }, { 24, 0 }, { 193, 79 }, { 34, 5 }, { 0, 0 }, 60, 0, 4 },
      { { 49, 114 }, { 91, 131 }, { 244, 138 }, { 21, 5 }, { 0, 0 }, 48, 0, 4 },
      { { 161, 97 }, { 144, 0 }, { 116, 113 }, { 57, 103 }, { 0, 0 }, 48, 0, 4 },
      { { 113, 114 }, { 87, 0 }, { 84, 122 }, { 5, 5 }, { 0, 0 }, 60, 0, 4 },
      { { 144, 65 }, { 0, 0 }, { 84, 165 }, { 99, 69 }, { 0, 0 }, 56, 0, 4 },
      { { 33, 33 }, { 146, 1 }, { 133, 143 }, { 23, 9 }, { 0, 0 }, 60, 0, 4 },
      { { 33, 33 }, { 148, 5 }, { 117, 143 }, { 23, 9 }, { 0, 0 }, 60, 0, 4 },
      { { 33, 97 }, { 148, 0 }, { 118, 130 }, { 21, 55 }, { 0, 0 }, 60, 0, 4 },
      { { 49, 33 }, { 67, 0 }, { 158, 98 }, { 23, 44 }, { 1, 1 }, 50, 0, 4 },
      { { 33, 33 }, { 155, 0 }, { 97, 127 }, { 106, 10 }, { 0, 0 }, 50, 0, 4 },
      { { 97, 34 }, { 138, 6 }, { 117, 116 }, { 31, 15 }, { 0, 0 }, 56, 0, 4 },
      { { 161, 33 }, { 134, 131 }, { 114, 113 }, { 85, 24 }, { 1, 0 }, 48, 0, 4 },
      { { 33, 33 }, { 77, 0 }, { 84, 166 }, { 60, 28 }, { 0, 0 }, 56, 0, 4 },
      { { 49, 97 }, { 143, 0 }, { 147, 114 }, { 2, 11 }, { 1, 0 }, 56, 0, 4 },
      { { 49, 97 }, { 142, 0 }, { 147, 114 }, { 3, 9 }, { 1, 0 }, 56, 0, 4 },
      { { 49, 97 }, { 145, 0 }, { 147, 130 }, { 3, 9 }, { 1, 0 }, 58, 0, 4 },
      { { 49, 97 }, { 142, 0 }, { 147, 114 }, { 15, 15 }, { 1, 0 }, 58, 0, 4 },
      { { 33, 33 }, { 75, 0 }, { 170, 143 }, { 22, 10 }, { 1, 0 }, 56, 0, 4 },
      { { 49, 33 }, { 144, 0 }, { 126, 139 }, { 23, 12 }, { 1, 1 }, 54, 0, 4 },
      { { 49, 50 }, { 129, 0 }, { 117, 97 }, { 25, 25 }, { 1, 0 }, 48, 0, 4 },
      { { 50, 33 }, { 144, 0 }, { 155, 114 }, { 33, 23 }, { 0, 0 }, 52, 0, 4 },
      { { 225, 225 }, { 31, 0 }, { 133, 101 }, { 95, 26 }, { 0, 0 }, 48, 0, 4 },
      { { 225, 225 }, { 70, 0 }, { 136, 101 }, { 95, 26 }, { 0, 0 }, 48, 0, 4 },
      { { 161, 33 }, { 156, 0 }, { 117, 117 }, { 31, 10 }, { 0, 0 }, 50, 0, 4 },
      { { 49, 33 }, { 139, 0 }, { 132, 101 }, { 88, 26 }, { 0, 0 }, 48, 0, 4 },
      { { 225, 161 }, { 76, 0 }, { 102, 101 }, { 86, 38 }, { 0, 0 }, 48, 0, 4 },
      { { 98, 161 }, { 203, 0 }, { 118, 85 }, { 70, 54 }, { 0, 0 }, 48, 0, 4 },
      { { 98, 161 }, { 153, 0 }, { 87, 86 }, { 7, 7 }, { 0, 0 }, 59, 0, 4 },
      { { 98, 161 }, { 147, 0 }, { 119, 118 }, { 7, 7 }, { 0, 0 }, 59, 0, 4 },
      { { 34, 33 }, { 89, 0 }, { 255, 255 }, { 3, 15 }, { 2, 0 }, 48, 0, 4 },
      { { 33, 33 }, { 14, 0 }, { 255, 255 }, { 15, 15 }, { 1, 1 }, 48, 0, 4 },
      { { 34, 33 }, { 70, 128 }, { 134, 100 }, { 85, 24 }, { 0, 0 }, 48, 0, 4 },
      { { 33, 161 }, { 69, 0 }, { 102, 150 }, { 18, 10 }, { 0, 0 }, 48, 0, 4 },
      { { 33, 34 }, { 139, 0 }, { 146, 145 }, { 42, 42 }, { 1, 0 }, 48, 0, 4 },
      { { 162, 97 }, { 158, 64 }, { 223, 111 }, { 5, 7 }, { 0, 0 }, 50, 0, 4 },
      { { 32, 96 }, { 26, 0 }, { 239, 143 }, { 1, 6 }, { 0, 2 }, 48, 0, 4 },
      { { 33, 33 }, { 143, 128 }, { 241, 244 }, { 41, 9 }, { 0, 0 }, 58, 0, 4 },
      { { 119, 161 }, { 165, 0 }, { 83, 160 }, { 148, 5 }, { 0, 0 }, 50, 0, 4 },
      { { 97, 177 }, { 31, 128 }, { 168, 37 }, { 17, 3 }, { 0, 0 }, 58, 0, 4 },
      { { 97, 97 }, { 23, 0 }, { 145, 85 }, { 52, 22 }, { 0, 0 }, 60, 0, 4 },
      { { 113, 114 }, { 93, 0 }, { 84, 106 }, { 1, 3 }, { 0, 0 }, 48, 0, 4 },
      { { 33, 162 }, { 151, 0 }, { 33, 66 }, { 67, 53 }, { 0, 0 }, 56, 0, 4 },
      { { 161, 33 }, { 28, 0 }, { 161, 49 }, { 119, 71 }, { 1, 1 }, 48, 0, 4 },
      { { 33, 97 }, { 137, 3 }, { 17, 66 }, { 51, 37 }, { 0, 0 }, 58, 0, 4 },
      { { 161, 33 }, { 21, 0 }, { 17, 207 }, { 71, 7 }, { 1, 0 }, 48, 0, 4 },
      { { 58, 81 }, { 206, 0 }, { 248, 134 }, { 246, 2 }, { 0, 0 }, 50, 0, 4 },
      { { 33, 33 }, { 21, 0 }, { 33, 65 }, { 35, 19 }, { 1, 0 }, 48, 0, 4 },
      { { 6, 1 }, { 91, 0 }, { 116, 165 }, { 149, 114 }, { 0, 0 }, 48, 0, 4 },
      { { 34, 97 }, { 146, 131 }, { 177, 242 }, { 129, 38 }, { 0, 0 }, 60, 0, 4 },
      { { 65, 66 }, { 77, 0 }, { 241, 242 }, { 81, 245 }, { 1, 0 }, 48, 0, 4 },
      { { 97, 163 }, { 148, 128 }, { 17, 17 }, { 81, 19 }, { 1, 0 }, 54, 0, 4 },
      { { 97, 161 }, { 140, 128 }, { 17, 29 }, { 49, 3 }, { 0, 0 }, 54, 0, 4 },
      { { 164, 97 }, { 76, 0 }, { 243, 129 }, { 115, 35 }, { 1, 0 }, 52, 0, 4 },
      { { 2, 7 }, { 133, 3 }, { 210, 242 }, { 83, 246 }, { 0, 1 }, 48, 0, 4 },
      { { 17, 19 }, { 12, 128 }, { 163, 162 }, { 17, 229 }, { 1, 0 }, 48, 0, 4 },
      { { 17, 17 }, { 6, 0 }, { 246, 242 }, { 65, 230 }, { 1, 2 }, 52, 0, 4 },
      { { 147, 145 }, { 145, 0 }, { 212, 235 }, { 50, 17 }, { 0, 1 }, 56, 0, 4 },
      { { 4, 1 }, { 79, 0 }, { 250, 194 }, { 86, 5 }, { 0, 0 }, 60, 0, 4 },
      { { 33, 34 }, { 73, 0 }, { 124, 111 }, { 32, 12 }, { 0, 1 }, 54, 0, 4 },
      { { 49, 33 }, { 133, 0 }, { 221, 86 }, { 51, 22 }, { 1, 0 }, 58, 0, 4 },
      { { 32, 33 }, { 4, 129 }, { 218, 143 }, { 5, 11 }, { 2, 0 }, 54, 0, 4 },
      { { 5, 3 }, { 106, 128 }, { 241, 195 }, { 229, 229 }, { 0, 0 }, 54, 0, 4 },
      { { 7, 2 }, { 21, 0 }, { 236, 248 }, { 38, 22 }, { 0, 0 }, 58, 0, 4 },
      { { 5, 1 }, { 157, 0 }, { 103, 223 }, { 53, 5 }, { 0, 0 }, 56, 0, 4 },
      { { 24, 18 }, { 150, 0 }, { 250, 248 }, { 40, 229 }, { 0, 0 }, 58, 0, 4 },
      { { 16, 0 }, { 134, 3 }, { 168, 250 }, { 7, 3 }, { 0, 0 }, 54, 0, 4 },
      { { 17, 16 }, { 65, 3 }, { 248, 243 }, { 71, 3 }, { 2, 0 }, 52, 0, 4 },
      { { 1, 16 }, { 142, 0 }, { 241, 243 }, { 6, 2 }, { 2, 0 }, 62, 0, 4 },
      { { 14, 192 }, { 0, 0 }, { 31, 31 }, { 0, 255 }, { 0, 3 }, 62, 0, 4 },
      { { 6, 3 }, { 128, 136 }, { 248, 86 }, { 36, 132 }, { 0, 2 }, 62, 0, 4 },
      { { 14, 208 }, { 0, 5 }, { 248, 52 }, { 0, 4 }, { 0, 3 }, 62, 0, 4 },
      { { 14, 192 }, { 0, 0 }, { 246, 31 }, { 0, 2 }, { 0, 3 }, 62, 0, 4 },
      { { 213, 218 }, { 149, 64 }, { 55, 86 }, { 163, 55 }, { 0, 0 }, 48, 0, 4 },
      { { 53, 20 }, { 92, 8 }, { 178, 244 }, { 97, 21 }, { 2, 0 }, 58, 0, 4 },
      { { 14, 208 }, { 0, 0 }, { 246, 79 }, { 0, 245 }, { 0, 3 }, 62, 0, 4 },
      { { 38, 228 }, { 0, 0 }, { 255, 18 }, { 1, 22 }, { 0, 1 }, 62, 0, 4 },
      { { 0, 0 }, { 0, 0 }, { 243, 246 }, { 240, 201 }, { 0, 2 }, 62, 0, 4 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 0, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 1, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 2, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 3, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 4, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 5, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 6, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 7, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 8, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 9, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 10, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 11, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 12, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 13, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 14, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 15, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 16, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 17, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 18, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 19, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 20, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 21, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 22, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 23, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 24, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 25, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 26, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 27, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 28, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 29, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 30, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 31, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 32, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 33, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 34, 0 },
      { { 16, 17 }, { 68, 0 }, { 248, 243 }, { 119, 6 }, { 2, 0 }, 56, 35, 4 },
      { { 16, 17 }, { 68, 0 }, { 248, 243 }, { 119, 6 }, { 2, 0 }, 56, 36, 4 },
      { { 2, 17 }, { 7, 0 }, { 249, 248 }, { 255, 255 }, { 0, 0 }, 56, 37, 4 },
      { { 0, 0 }, { 0, 0 }, { 252, 250 }, { 5, 23 }, { 2, 0 }, 62, 38, 4 },
      { { 0, 1 }, { 2, 0 }, { 255, 255 }, { 7, 8 }, { 0, 0 }, 48, 39, 4 },
      { { 0, 0 }, { 0, 0 }, { 252, 250 }, { 5, 23 }, { 2, 0 }, 62, 40, 4 },
      { { 0, 0 }, { 0, 0 }, { 246, 246 }, { 12, 6 }, { 0, 0 }, 52, 41, 4 },
      { { 12, 18 }, { 0, 0 }, { 246, 251 }, { 8, 71 }, { 0, 2 }, 58, 42, 4 },
      { { 0, 0 }, { 3, 0 }, { 248, 246 }, { 42, 69 }, { 0, 1 }, 52, 43, 4 },
      { { 12, 18 }, { 0, 5 }, { 246, 123 }, { 8, 71 }, { 0, 2 }, 58, 44, 4 },
      { { 0, 0 }, { 3, 0 }, { 248, 246 }, { 42, 69 }, { 0, 1 }, 52, 45, 4 },
      { { 12, 18 }, { 0, 0 }, { 246, 203 }, { 2, 67 }, { 0, 2 }, 58, 46, 4 },
      { { 0, 0 }, { 3, 0 }, { 248, 246 }, { 42, 69 }, { 0, 1 }, 52, 47, 4 },
      { { 0, 0 }, { 3, 0 }, { 248, 246 }, { 42, 69 }, { 0, 1 }, 52, 48, 4 },
      { { 14, 208 }, { 0, 0 }, { 246, 159 }, { 0, 2 }, { 0, 3 }, 62, 49, 4 },
      { { 0, 0 }, { 3, 0 }, { 248, 246 }, { 42, 69 }, { 0, 1 }, 52, 50, 4 },
      { { 14, 7 }, { 8, 74 }, { 248, 244 }, { 66, 228 }, { 0, 3 }, 62, 51, 4 },
      { { 14, 208 }, { 0, 10 }, { 245, 159 }, { 48, 2 }, { 0, 0 }, 62, 52, 4 },
      { { 14, 7 }, { 10, 93 }, { 228, 245 }, { 228, 229 }, { 3, 1 }, 54, 53, 4 },
      { { 2, 5 }, { 3, 10 }, { 180, 151 }, { 4, 247 }, { 0, 0 }, 62, 54, 4 },
      { { 78, 158 }, { 0, 0 }, { 246, 159 }, { 0, 2 }, { 0, 3 }, 62, 55, 4 },
      { { 17, 16 }, { 69, 8 }, { 248, 243 }, { 55, 5 }, { 2, 0 }, 56, 56, 4 },
      { { 14, 208 }, { 0, 0 }, { 246, 159 }, { 0, 2 }, { 0, 3 }, 62, 57, 4 },
      { { 128, 16 }, { 0, 13 }, { 255, 255 }, { 3, 20 }, { 3, 0 }, 60, 58, 4 },
      { { 14, 7 }, { 8, 81 }, { 248, 244 }, { 66, 228 }, { 0, 3 }, 62, 59, 4 },
      { { 6, 2 }, { 11, 0 }, { 245, 245 }, { 12, 8 }, { 0, 0 }, 54, 60, 4 },
      { { 1, 2 }, { 0, 0 }, { 250, 200 }, { 191, 151 }, { 0, 0 }, 55, 61, 4 },
      { { 1, 1 }, { 81, 0 }, { 250, 250 }, { 135, 183 }, { 0, 0 }, 54, 62, 4 },
      { { 1, 2 }, { 84, 0 }, { 250, 248 }, { 141, 184 }, { 0, 0 }, 54, 63, 4 },
      { { 1, 2 }, { 89, 0 }, { 250, 248 }, { 136, 182 }, { 0, 0 }, 54, 64, 4 },
      { { 1, 0 }, { 0, 0 }, { 249, 250 }, { 10, 6 }, { 3, 0 }, 62, 65, 4 },
      { { 0, 0 }, { 128, 0 }, { 249, 246 }, { 137, 108 }, { 3, 0 }, 62, 66, 4 },
      { { 3, 12 }, { 128, 8 }, { 248, 246 }, { 136, 182 }, { 3, 0 }, 63, 67, 4 },
      { { 3, 12 }, { 133, 0 }, { 248, 246 }, { 136, 182 }, { 3, 0 }, 63, 68, 4 },
      { { 14, 0 }, { 64, 8 }, { 118, 119 }, { 79, 24 }, { 0, 2 }, 62, 69, 4 },
      { { 14, 3 }, { 64, 0 }, { 200, 155 }, { 73, 105 }, { 0, 2 }, 62, 70, 4 },
      { { 215, 199 }, { 220, 0 }, { 173, 141 }, { 5, 5 }, { 3, 0 }, 62, 71, 4 },
      { { 215, 199 }, { 220, 0 }, { 168, 136 }, { 4, 4 }, { 3, 0 }, 62, 72, 4 },
      { { 128, 17 }, { 0, 0 }, { 246, 103 }, { 6, 23 }, { 3, 3 }, 62, 73, 4 },
      { { 128, 17 }, { 0, 9 }, { 245, 70 }, { 5, 22 }, { 2, 3 }, 62, 74, 4 },
      { { 6, 21 }, { 63, 0 }, { 0, 247 }, { 244, 245 }, { 0, 0 }, 49, 75, 4 },
      { { 6, 18 }, { 63, 0 }, { 0, 247 }, { 244, 245 }, { 3, 0 }, 48, 76, 4 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 77, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 78, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 79, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 80, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 81, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 82, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 83, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 84, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 85, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 86, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 87, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 88, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 89, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 90, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 91, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 92, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 93, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 94, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 95, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 96, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 97, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 98, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 99, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 100, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 101, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 102, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 103, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 104, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 105, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 106, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 107, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 108, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 109, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 110, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 111, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 112, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 113, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 114, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 115, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 116, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 117, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 118, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 119, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 120, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 121, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 122, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 123, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 124, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 125, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 126, 0 },
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 127, 0 }
   };


opl_drum_map opl_drum_maps[128]
{
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 35, 35 },
    { 35, 35 },
    { 37, 52 },
    { 38, 48 },
    { 39, 58 },
    { 40, 60 },
    { 41, 47 },
    { 42, 43 },
    { 41, 49 },
    { 44, 43 },
    { 41, 51 },
    { 46, 43 },
    { 41, 54 },
    { 41, 57 },
    { 49, 72 },
    { 41, 60 },
    { 51, 76 },
    { 52, 84 },
    { 53, 36 },
    { 54, 76 },
    { 55, 84 },
    { 56, 83 },
    { 57, 84 },
    { 58, 24 },
    { 51, 77 },
    { 60, 60 },
    { 61, 65 },
    { 62, 59 },
    { 63, 51 },
    { 64, 45 },
    { 65, 71 },
    { 66, 60 },
    { 67, 58 },
    { 68, 53 },
    { 69, 64 },
    { 70, 71 },
    { 71, 61 },
    { 72, 61 },
    { 73, 48 },
    { 74, 48 },
    { 75, 69 },
    { 76, 68 },
    { 77, 63 },
    { 78, 74 },
    { 79, 60 },
    { 80, 80 },
    { 81, 64 },
    { 82, 69 },
    { 83, 73 },
    { 84, 75 },
    { 85, 68 },
    { 86, 48 },
    { 87, 53 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 },
    { 255, 0 }
};
