#pragma once

#ifdef GQbExportCommon
#define GQCommonDLL __declspec( dllexport )
#else
#define GQCommonDLL __declspec( dllimport )
#endif

// Include all Exported Classes
#include "Types.h"
#include "Constants.h"              // Depends on Types.h
#include "Containers\List.h"        // Depends on Types.h
#include "Containers\Queue.h"       // Depends on Types.h and List.h
#include "Containers\ListNode.h"    // Depends on Types.h
#include "Containers\LinkedList.h"
#include "Component\Listener.h"     // Depends on Types.h
#include "Component\Event.h"        // Depends on ListNode.h, LinkedList.h, and Listener.h
#include "Component\Model.h"
#include "StopWatch.h"              // Depends on Types.h

// Include Notification Framework
#include "Notification\EventId.h"
#include "Notification\ComponentId.h"
#include "Notification\Criticality.h"
#include "Notification\GroupId.h"
#include "Notification\Identifier.h"
#include "Notification\Status.h"
#include "Notification\Alert.h"     // Depends on Types.h