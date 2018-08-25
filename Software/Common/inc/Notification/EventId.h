/**
 * @file EventId.h
 * @brief Package interface for the Event Identifier Enumeration
 */
#pragma once

namespace GNCommon
{
   namespace NNotification
   {
      /** Enumeration of Alert Event Identifiers */
      enum class TcEventId : Tu32
      {
         XeIdentifier,
         XeStatus,
         XeTimestamp,
         XeData
      };
   }
}

