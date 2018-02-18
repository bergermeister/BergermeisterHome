/**
 * @file Types.h
 *
 * Defines the common namespace (GNCommon), common primitive types, and provides the style guide to be used.
 *
 * @verbatim
 * Style Guide
 *
 *  (S)cope:                                
 *                | Priv  |  Pub  | Global |
 *                |-------|-------|--------|
 * Class Variable |   v   |   V   |  ----  |
 * Stack Variable |   k   |  ---  |  ----  | 
 *       Argument |   a   |  ---  |  ----  |
 *        Typedef |   t   |   T   |   GT   |
 *   Constant ROM |   x   |   X   |   GX   |
 *         Method |   m   |   M   |   GM   |
 *                                          
 *  (T)ype:                                 
 *           | Prefix |                     
 *           |--------|                     
 *      GTb8 |    b   |                     
 *      GTc8 |    c   |                     
 *      GTi8 |    c   |                     
 *      GTu8 |   uc   |                     
 *     GTi16 |    s   |                     
 *     GTu16 |   us   |                     
 *     GTi32 |    i   |                     
 *     GTu32 |   ui   |                     
 *     GTi64 |    l   |                     
 *     GTu64 |   ul   |                     
 *     GTf32 |    f   |                     
 *     GTf64 |    d   |                     
 *                                          
 *  (O)perator:                             
 *               | Prefix |                 
 *               |--------|                 
 *     pointer   |    p   |                 
 *     reference |    r   |                 
 *                                          
 *  Naming Convention:                      
 *     STOCamelCaseName                     
 *     GMFunctionGlobal
 * @endverbatim
 */

#pragma once

/**
 * @namespace GNCommon
 *
 * Common Framework Namespace.
 */
namespace GNCommon
{
   
   typedef               bool  GTb8; /**< Type definition for 8-bit boolean primitive */
   typedef               char  GTc8; /**< Type definition for 8-bit character primitive */
   typedef signed        char  GTi8; /**< Type definition for signed 8-bit integer primitive */
   typedef unsigned      char  GTu8; /**< Type definition for unsigned 8-bit integer primitive */
   typedef signed       short GTi16; /**< Type definition for signed 16-bit integer primitive */
   typedef unsigned     short GTu16; /**< Type definition for unsigned 16-bit integer primitive */
   typedef signed        long GTi32; /**< Type definition for signed 32-bit integer primitive */
   typedef unsigned      long GTu32; /**< Type definition for unsigned 32-bit primitive */
   typedef signed   long long GTi64; /**< Type definition for signed 64-bit integer primitive */
   typedef unsigned long long GTu64; /**< Type definition for unsigned 64-bit integer primitive */
   typedef              float GTf32; /**< Type definition for 32-bit single-precision floating point primitive */
   typedef             double GTf64; /**< Type definition for 64-bit double-precision floating point primitive */

   static const GTu32 XuiSizeOfGTb8  = sizeof( GTb8 );  /**< Size of GTb8 */
   static const GTu32 XuiSizeOfGTi8  = sizeof( GTi8 );  /**< Size of GTi8 */
   static const GTu32 XuiSizeOfGTu8  = sizeof( GTu8 );  /**< Size of GTu8 */
   static const GTu32 XuiSizeOfGTi16 = sizeof( GTi16 ); /**< Size of GTi16 */
   static const GTu32 XuiSizeOfGTu16 = sizeof( GTu16 ); /**< Size of GTu16 */
   static const GTu32 XuiSizeOfGTi32 = sizeof( GTi32 ); /**< Size of GTi32 */
   static const GTu32 XuiSizeOfGTu32 = sizeof( GTu32 ); /**< Size of GTu32 */
   static const GTu32 XuiSizeOfGTi64 = sizeof( GTi64 ); /**< Size of GTi64 */
   static const GTu32 XuiSizeOfGTu64 = sizeof( GTu64 ); /**< Size of GTu64 */
   static const GTu32 XuiSizeOfGTf32 = sizeof( GTu64 ); /**< Size of GTf32 */
   static const GTu32 XuiSizeOfGTf64 = sizeof( GTu64 ); /**< Size of GTf64 */
}
