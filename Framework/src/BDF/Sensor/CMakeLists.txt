target_sources( BDF
   PRIVATE
      DHT22.cpp
)

set( publicHeaders 
   DHT22.h
)

install( FILES publicHeaders DESTINATION Lib/BDF/Sensor )

