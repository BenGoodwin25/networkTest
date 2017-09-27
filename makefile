#Compiler to use
COMPILER=g++
#Possible Arguments
CFLAGS=-g -Wall
#Here insert the library you could need
LFLAGS=-lm

#Directory
BUILDDIR=./build

SRC=$(wildcard *.cc)
OBJ=$(SRC:.cc=.o)
#Exec will have the folder's name
EXEC=$(BUILDDIR)/exec_$(shell basename $(CURDIR))

#Compile
all: $(EXEC) $(BUILDDIR)

$(EXEC): $(OBJ)
	$(COMPILER) -o $@ $(OBJ) $(CFLAGS) $(LFLAGS)

%.o: %.cc %.h
	$(COMPILER) -o $@ $(CFLAGS) -c $<

#Fonctionaly to come lather
#install:

#Creation of folder
$(BUILDDIR):
	mkdir $(BUILDDIR)


#Cleaning
clean:
	rm *.o

mrproper: clean
	rm -r $(BUILDDIR)
