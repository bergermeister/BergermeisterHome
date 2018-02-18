#pragma once

#ifdef GQbExportHVACDriver
#define GQHVACDriverDLL __declspec( dllexport )
#else
#define GQHVACDriverDLL __declspec( dllimport )
#endif

// Include all Exported Classes
#include "DHTSensor.h"