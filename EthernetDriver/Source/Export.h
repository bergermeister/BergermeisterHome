#pragma once

#ifdef GXbExportEthernetDriver
#define GXEthernetDLL __declspec( dllexport )
#else
#define GXEthernetDLL __declspec( dllimport )
#endif

// Include all Exported Classes
#include "EventId.h"
#include "EndPoint.h"
#include "UDPClient.h"
