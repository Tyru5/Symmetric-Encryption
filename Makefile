# Tyrus Malmstrom
# Makefile for P1 assignment
# CS356 -> Systems Paranoia

CXX		= g++
OBJS		= 

OBJ1		= 
OBJ2		= 

DEBUG		= -g
CPPFLAGS	= -Wall -std=c++11 -I. -c $(DEBUG)

LDFLAGS		= -Wall $(DEBUG)

EXE             = PA1

all: clean   # by default, make my makefile clean up the project directory, just to be safe.

clean:
	@echo "Cleaning up project directory ..."
	rm -f $(OBJS) *~

package:
	@echo "Packaging up project directory..."
	tar -cvf $(EXE).tar *.cpp *.h Makefile README.txt
