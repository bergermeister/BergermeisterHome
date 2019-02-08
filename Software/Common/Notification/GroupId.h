/**
 * @file GroupId.h
 * @brief Package interface for the Group Identifier Enumeration
 */
#pragma once

namespace GNCommon
{
   namespace NNotification
   {
      /** Enumeration of Group Identifiers */
      enum class TcGroupId : Tu8
      {
         XeNone    = 0, /**< Enumerated Group: None */
         XeNetwork = 1  /**< Enumerated Group: Network */
      };
   }
}