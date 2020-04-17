C = gcc
CFLAGS = -W -Wall
TARGET = market
DTARGET = market_debug
OBJECTS = market.c product.o manager.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean :
	rm *.o $(TARGET) $(DTARGET)

