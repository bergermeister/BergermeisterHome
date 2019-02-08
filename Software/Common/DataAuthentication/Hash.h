/**
 * @file Hash.h
 * @brief Package interface for the Hash interface
 */
#ifndef Hash_h
#define Hash_h

#include <Types.h>

namespace GNCommon
{
   /** @brief Namespace containing Data Authentication and Validity utilities */
   namespace NDataAuthentication
   {
      class TcHash
      {
      public:        // Public Methods
         TcHash( void );
         TcHash( const TcHash& aorHash );
         virtual ~TcHash( void );
         
         TcHash& operator=( const TcHash& aorHash );

         virtual void MInitialize( void ) = 0;
         virtual void MProcess( const Tu8* aucpData, const Tu32 auiBytes ) = 0;
         virtual void MFinalize( void ) = 0;

         virtual const Tu8* MGet( void ) const = 0;

         inline Tu64 MSwap( const Tu64 aulVal )
         {
            return( ( ( aulVal & 0x00000000000000FF ) << 56 ) |
                    ( ( aulVal & 0x000000000000FF00 ) << 40 ) |
                    ( ( aulVal & 0x0000000000FF0000 ) << 24 ) |
                    ( ( aulVal & 0x00000000FF000000 ) <<  8 ) |
                    ( ( aulVal & 0x000000FF00000000 ) >>  8 ) |
                    ( ( aulVal & 0x0000FF0000000000 ) >> 24 ) |
                    ( ( aulVal & 0x00FF000000000000 ) >> 40 ) |
                    ( ( aulVal & 0xFF00000000000000 ) >> 56 ) );
         }
      };
   }
}

#endif
