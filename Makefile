CC = gcc #compiler
DFLAGS = -g -Wall -Werror #various debug flags enable -g=debug:-Wall=warnings:-Werror=warning turned into error
SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
TARGET = $(shell pwd)/app


$(TARGET): $(SRC) $(HDR)
	$(CC) $(DFLAGS) $^ -o $(TARGET)

run:
	$(TARGET)

clean: 
	rm -f $(TARGET)

.PHONY: clean
