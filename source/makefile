# Mini-Calc source makefile
# This file should be able to
# compile on most systems 
# 4/19/04 - KanadaKid

CPP = g++
OFLAG = -o
.SUFFIXES : .o .cpp
.cpp.o :
	$(CPP) $(CPPGLAGS) -c $<

all: \
	calculator \
	
test: all
	calculator

calculator: calculator.o
	$(CPP) $(OFLAG)calculator calculator.o

calculator.o : calculator.cpp

clean: 
	rm -rf *.o
