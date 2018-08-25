/**
 * @file Criticality.h
 * @brief Package interface for the Alert Criticality Enumeration
 */
#pragma once

namespace GNCommon
{
   namespace NNotification
   {
      /** Enumeration of Alert Criticality Identifiers */
      enum class TcCriticality : Tu8
      {
         XeNone    = 0, /**< Enumerated Alert Level: None    */
         XeNotice  = 1, /**< Enumerated Alert Level: Notice  */
         XeWarning = 2, /**< Enumerated Alert Level: Warning */
         XeAlarm   = 3  /**< Enumerated Alert Level: Alarm   */
      };
   }
}

