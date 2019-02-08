/**
 * @file Types.h
 *
 * @brief Commnon Framework namespace, type definitions, and coding style guide
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
 *          | Prefix |                     
 *          |--------|                     
 *      Tb8 |    b   |                     
 *      Tc8 |    c   |                     
 *      Ti8 |    c   |                     
 *      Tu8 |   uc   |                     
 *     Ti16 |    s   |                     
 *     Tu16 |   us   |                     
 *     Ti32 |    i   |                     
 *     Tu32 |   ui   |                     
 *     Ti64 |    l   |                     
 *     Tu64 |   ul   |                     
 *     Tf32 |    f   |                     
 *     Tf64 |    d   |                     
 *   Object |    o   |
 *                                          
 *  (M)odifier:                             
 *               | Prefix |                 
 *               |--------|                 
 *     pointer   |    p   |                 
 *     reference |    r   |                 
 *                                          
 *  Naming Convention:                      
 *     STMHungarianNotationName                     
 *     GMFunctionGlobal
 * @endverbatim
 */

#pragma once

/** @brief Namespace containing Common components and infrastrucutre */
namespace GNCommon
{
   
   typedef               bool  Tb8; /**< Type definition for 8-bit boolean primitive */
   typedef               char  Tc8; /**< Type definition for 8-bit character primitive */
   typedef signed        char  Ti8; /**< Type definition for signed 8-bit integer primitive */
   typedef unsigned      char  Tu8; /**< Type definition for unsigned 8-bit integer primitive */
   typedef signed       short Ti16; /**< Type definition for signed 16-bit integer primitive */
   typedef unsigned     short Tu16; /**< Type definition for unsigned 16-bit integer primitive */
   typedef signed        long Ti32; /**< Type definition for signed 32-bit integer primitive */
   typedef unsigned      long Tu32; /**< Type definition for unsigned 32-bit primitive */
   typedef signed   long long Ti64; /**< Type definition for signed 64-bit integer primitive */
   typedef unsigned long long Tu64; /**< Type definition for unsigned 64-bit integer primitive */
   typedef              float Tf32; /**< Type definition for 32-bit single-precision floating point primitive */
   typedef             double Tf64; /**< Type definition for 64-bit double-precision floating point primitive */

   static const Tu32 XuiSizeOfTb8  = sizeof( Tb8 );  /**< Size of Tb8 */
   static const Tu32 XuiSizeOfTi8  = sizeof( Ti8 );  /**< Size of Ti8 */
   static const Tu32 XuiSizeOfTu8  = sizeof( Tu8 );  /**< Size of Tu8 */
   static const Tu32 XuiSizeOfTi16 = sizeof( Ti16 ); /**< Size of Ti16 */
   static const Tu32 XuiSizeOfTu16 = sizeof( Tu16 ); /**< Size of Tu16 */
   static const Tu32 XuiSizeOfTi32 = sizeof( Ti32 ); /**< Size of Ti32 */
   static const Tu32 XuiSizeOfTu32 = sizeof( Tu32 ); /**< Size of Tu32 */
   static const Tu32 XuiSizeOfTi64 = sizeof( Ti64 ); /**< Size of Ti64 */
   static const Tu32 XuiSizeOfTu64 = sizeof( Tu64 ); /**< Size of Tu64 */
   static const Tu32 XuiSizeOfTf32 = sizeof( Tu64 ); /**< Size of Tf32 */
   static const Tu32 XuiSizeOfTf64 = sizeof( Tu64 ); /**< Size of Tf64 */

   static const Tu64 XulMask32  = 0x00000000FFFFFFFF;
   static const Tu64 XulMask16  = 0x000000000000FFFF;
   static const Tu64 XulShift32 = 32;
}
