// VisualBoyAdvance - Nintendo Gameboy/GameboyAdvance (TM) emulator.
// Copyright (C) 1999-2003 Forgotten
// Copyright (C) 2004-2008 Forgotten and the VBA development team

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or(at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef VBA_SDL_FILTERS_H
#define VBA_SDL_FILTERS_H

#include "../System.h"

// List of available filters
enum Filter { kStretch1x, kStretch2x, k2xSaI, kSuper2xSaI, kSuperEagle, kPixelate,
				kMotionBlur, kAdMame2x, kBilinear, kBilinearPlus, kScanlines, kScanlinesTV,
				klq2x, khq2x, kStretch3x, khq3x, kStretch4x, khq4x, kInvalidFilter };

// Function pointer type for a filter function
typedef void(*FilterFunc)(u8*, u32, u8*, u8*, u32, int, int);

// Initialize a filter and get the corresponding filter function pointer
FilterFunc initFilter(const Filter f, const int colorDepth, const int srcWidth);

// Get the enlarge factor of a filter
int getFilterEnlargeFactor(const Filter f);

// Get the display name for a filter
char* getFilterName(const Filter f);

#endif // VBA_SDL_FILTERS_H