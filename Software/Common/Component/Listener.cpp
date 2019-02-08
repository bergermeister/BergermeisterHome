#include <Types.h>
#include <Constants.h>
#include <Component\Listener.h>

using namespace GNCommon;
using namespace GNCommon::NComponent;

/**
 *
 */
GTcListener::GTcListener ( void )
{
   this->vopInstance = NULL;
   this->vopHandle   = NULL;
}

/**
*
*/
GTcListener::GTcListener ( void* aopInstance, const TsHandle aopHandle )
{
   this->vopInstance = aopInstance;
   this->vopHandle   = aopHandle;
}

/**
*
*/
GTcListener::~GTcListener ( void )
{
   // Nothing to destruct
}

/**
*
*/
void* GTcListener::MGetInstance ( void ) const
{
   return this->vopInstance;
}

/**
*
*/
GTcListener::TsHandle GTcListener::MGetHandle ( void ) const
{
   return this->vopHandle;
}

/**
*
*/
Tb8 GTcListener::operator== ( const GTcListener& aorListener )
{
   return this->vopHandle == aorListener.vopHandle;
}

