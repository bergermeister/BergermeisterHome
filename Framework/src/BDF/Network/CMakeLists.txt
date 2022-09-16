target_sources( BDF
   PRIVATE
      IPEndpoint.cpp
      UDPClient.cpp
      UDPSocket.cpp
)

set( publicHeaders 
   IPEndpoint.h
   UDPClient.h
   UDPSocket.h
)

install( FILES publicHeaders DESTINATION Lib/BDF/Network )

