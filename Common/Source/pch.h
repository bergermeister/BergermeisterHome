/**
 * @file Common Precompiled Header File
 *
 * Precompiled header file.
 * This defines the class hierarchy for the Common Framework.
 */

#pragma once

#include "TargetVersion.h"

// Define Windows 32-bit LEAN_AND_MEAN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define GXbExportCommon

#include <windows.h>

#include "Export.h"
