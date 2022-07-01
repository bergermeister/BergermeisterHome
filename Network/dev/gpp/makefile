OUT=../../lib/Network.a
CC=g++
ODIR=./obj
SDIR=../../src/Network

_OBJS = IPEndpoint.o UDPClient.o 
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
   $(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
   ar rvs $(OUT) $^

.PHONY: clean

clean:
    rm -f $(ODIR)/*.o $(OUT)