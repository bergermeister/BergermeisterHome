/**
 * @file HVAC Driver Precompiled Header File
 *
 * Precompiled header file.
 */
#pragma once

#include "TargetVersion.h"

// Define Windows 32-bit LEAN_AND_MEAN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define GQbExportHVACDriver

#include <windows.h>
#include <gpio.h>
#include <windows.devices.gpio.h>
#include <windows.devices.gpio.provider.h>

#include "..\Common\Source\Export.h"
#include "Export.h"
