# Tyrus Malmstrom
# Makefile for P1 assignment
# CS356 -> Systems Paranoia

CXX		= g++
OBJS		= main.o

DEBUG		= -g
CPPFLAGS	= -Wall -std=c++11 -I. -c $(DEBUG)

LDFLAGS		= -Wall $(DEBUG)

EXE             = PA1

all: clean main   # by default, make my makefile clean up the project directory, just to be safe.

# Target is the executable
main: 	$(OBJS)
	@echo "Linking all object modules ..."
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXE)
	@echo ""

# Compile .c files to .o files
.o.c:
	$(CXX) $(CPPFLAGS) $<

clean:
	@echo "Cleaning up project directory ..."
	rm -f $(OBJS) *~ PA1

package:
	@echo "Packaging up project directory..."
	tar -cvf $(EXE).tar *.cpp *.h Makefile README.txt
