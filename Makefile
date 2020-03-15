##############################################################################
##                            Carta™ GUI Library                            ##
##                                                                          ##
##                         Copyright © 2020 Aquefir                         ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

include base.mk

# name of project. used in output binary naming
PROJECT := carta

# put a ‘1’ for the desired target types to compile
EXEFILE :=
SOFILE  :=
AFILE   := 1

# space-separated path list for #includes
# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# space-separated library name list for linking
# libraries
LIBS      := SDL2
LIBDIRS   :=

# ‘3P’ are 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR := 3rdparty
3PLIBS   := uni qlibc

# frameworks (macOS only)
FWORKS := Cocoa

CFILES    := \
	src/carta.c \
	src/dispdrv.c
HFILES    := \
	include/carta/carta.h \
	include/carta/common.h \
	include/carta/dispdrv.h \
	src/carta.h \
	src/dispdrv.h
CPPFILES  :=
HPPFILES  :=
OFILES    := $(CFILES:.c=.c.o) $(CPPFILES:.cpp=.cpp.o)
# address-sanitisation metadata
GCNOFILES := $(CFILES:.c=.c.gcno) $(CPPFILES:.cpp=.cpp.gcno)
GCDAFILES := $(CFILES:.c=.c.gcda) $(CPPFILES:.cpp=.cpp.gcda)

TES_CFILES    := \
	src/dispdrv.tes.c
TES_HFILES    :=
TES_CPPFILES  :=
TES_HPPFILES  :=
TES_OFILES    := $(TES_CFILES:.tes.c=.c.tes.o) $(CPPFILES:.tes.cpp=.cpp.tes.o)
TES_GCNOFILES := $(TES_CFILES:.tes.c=.tes.c.gcno) \
	$(CPPFILES:.tes.cpp=.tes.cpp.gcno)
TES_GCDAFILES := $(TES_CFILES:.tes.c=.tes.c.gcda) \
	$(CPPFILES:.tes.cpp=.tes.cpp.gcda)

.PHONY: default

default: debug

# this defines all our usual targets
include targets.mk
