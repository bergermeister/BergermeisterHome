#pragma once

#ifdef GXbExportHVACDriver
#define GXHVACDriverDLL __declspec( dllexport )
#else
#define GXHVACDriverDLL __declspec( dllimport )
#endif

// Include all Exported Classes
#include "DHTSensor.h"