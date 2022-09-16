target_sources( BDF
   PRIVATE
      StopWatch.cpp
)

set( publicHeaders 
   StopWatch.h
)

install( FILES publicHeaders DESTINATION Lib/BDF/Time )

