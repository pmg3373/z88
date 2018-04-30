#
# Created by gmakemake (Ubuntu Jul 25 2014) on Mon Apr 30 01:06:41 2018
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

BASE = /home/course/csci453
ARCHVER = arch2-5a
CXX = g++
CCFLAGS = -g -I$(BASE)/include/$(ARCHVER)
CXXFLAGS = $(CCFLAGS)
LIBFLAGS = -g -L$(BASE)/lib/$(SYS_TYPE) -l$(ARCHVER)
CCLIBFLAGS = $(LIBFLAGS)

########## End of flags from header.mak


CPP_FILES =	decode.cpp execute.cpp fetch.cpp forwarding.cpp globals.cpp instruction.cpp make_connections.cpp memory.cpp run_simulation.cpp writeback.cpp z88.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	globals.h includes.h instruction.h prototypes.h usefuldefines.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	decode.o execute.o fetch.o forwarding.o globals.o instruction.o make_connections.o memory.o run_simulation.o writeback.o 

#
# Main targets
#

all:	z88 

z88:	z88.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o z88 z88.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

decode.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
execute.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
fetch.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
forwarding.o:	
globals.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
instruction.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
make_connections.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
memory.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
run_simulation.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
writeback.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h
z88.o:	globals.h includes.h instruction.h prototypes.h usefuldefines.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) z88.o core

realclean:        clean
	-/bin/rm -f z88 
