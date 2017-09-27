#Compiler to use
COMPILER=g++
#Possible Arguments
CFLAGS=-g -Wall
#Here insert the library you could need
LFLAGS=-lm

SRC=$(wildcard *.cc)

#Compile
all: server client

server:
	$(COMPILER) -o $@ $@.cc $(CFLAGS) $(LFLAGS)

client :
	$(COMPILER) -o $@ $@.cc $(CFLAGS) $(LFLAGS)

#Cleaning
clean:
	rm server client 
