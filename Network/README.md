g++ -c src/Network/UDPSocket.cpp -Isrc -o dev/gpp/obj/UDPSocket.o
g++ -c src/Network/IPEndpoint.cpp -Isrc -o dev/gpp/obj/IPEndpoint.o
g++ -c src/Network/UDPClient.cpp -Isrc -o dev/gpp/obj/UDPClient.o
ar rvs lib/Network.a dev/gpp/obj/UDPSocket.o dev/gpp/obj/IPEndpoint.o dev/gpp/obj/UDPClient.o 