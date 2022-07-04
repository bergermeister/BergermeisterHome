cmake --configure -Blib -S. -DCMAKE_BUILD_TYPE=Debug
make -C lib
sudo make install -C lib