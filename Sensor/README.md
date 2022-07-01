Compilation: 
   g++ -o bin/Sensor src/Sensor/Main.cpp src/Sensor/DHT22.cpp -Isrc -I../Network/src -l:Network.a -lgpiod -L../Network/lib