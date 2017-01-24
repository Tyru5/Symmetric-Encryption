# Tyrus Malmstrom
# Makefile for P1 assignment
# CS356 -> Systems Paranoia

CXX		= g++
OBJS		= main.o BlockCipher.o StreamCipher.o

DEBUG		= -g
CPPFLAGS	= -Wall -std=c++11 -I. -c $(DEBUG)

LDFLAGS		= -Wall $(DEBUG)

EXE             = pa1

all: clean main   # by default, make my makefile clean up the project directory, just to be safe.

# Target is the executable
main: 	$(OBJS)
	@echo "Linking all object modules ..."
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXE)
	@echo ""

main.o: main.cpp
	@echo "-- Compiling main..."
	$(CXX) $(CPPFLAGS) main.cpp


BlockCipher.o: BlockCipher.cpp BlockCipher.h
	@echo "-- Compiling BlockCipher Class..."
	$(CXX) $(CPPFLAGS) BlockCipher.cpp

StreamCipher.o: StreamCipher.cpp StreamCipher.h
	@echo "-- Compiling StreamCipher class..."
	$(CXX) $(CPPFLAGS) StreamCipher.cpp

clean:
	@echo "Cleaning up project directory ..."
	rm -f $(OBJS) *~ pa1

package:
	@echo "Packaging up project directory..."
	tar -cvf $(EXE).tar *.cpp *.h Makefile README.txt
