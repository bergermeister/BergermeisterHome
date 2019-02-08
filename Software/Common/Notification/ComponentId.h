/**
 * @file ComponentId.h
 */

#pragma once

namespace GNCommon
{
   namespace NNotification
   {
      /** @brief Enumeration of Alert Component Identifiers */
      enum class TcComponentId : Tu8
      {
         XeNone   = 0, /**< Enumerated Component: None */
         XeServer = 1, /**< Enumerated Component: Server */
         XeSensor = 2  /**< Enumerated Component: Sensor */
      };
   }
}

