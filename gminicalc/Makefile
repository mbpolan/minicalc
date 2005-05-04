# GMiniCalc Makefile

# variables and other info
###########################
# GCC/G++ Compilers (Linux)
###########################
CPP = g++
OFLAG = -o
CFLAG = -c
EXT = 
OSUFFIX = .o
CPPFLAGS = `pkg-config gtkmm-2.4 --cflags`
#CPPFLAGS = -D__LINUX__
LINKFLAGS = `pkg-config gtkmm-2.4 --libs`
DEL = rm -f

############################
# end compiler specific part
############################

.SUFFIXES : $(OSUFFIX) .cpp
.cpp$(OSUFFIX) :
	$(CPP) $(CPPFLAGS) $(OFLAG) $<

# compile this
all: \
	gminicalc

# object files
gminicalc: gminicalc$(OSUFFIX) buttons$(OSUFFIX) mainwindow$(OSUFFIX) 
	$(CPP) gminicalc$(OSUFFIX) buttons$(OSUFFIX) mainwindow$(OSUFFIX) $(LINKFLAGS) $(OFLAG) gminicalc$(EXT)

gminicalc$(OSUFFIX): gminicalc.cpp mainwindow.h
	$(CPP) $(CPPFLAGS) $(CFLAG) gminicalc.cpp $(OFLAG) gminicalc$(OSUFFIX)

buttons$(OSUFFIX): buttons.cpp buttons.h
	$(CPP) $(CPPFLAGS) $(CFLAG) buttons.cpp $(OFLAG) buttons$(OSUFFIX)

mainwindow$(OSUFFIX): mainwindow.cpp mainwindow.h buttons.h
	$(CPP) $(CPPFLAGS) $(CFLAG) mainwindow.cpp $(OFLAG) mainwindow$(OSUFFIX)


# clean the directory
clean: 
	$(DEL) *~
	$(DEL) *$(OSUFFIX)
	$(DEL) gminicalc$(EXT)
 
