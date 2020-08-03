##############################################################################
##                            Carta™ GUI Library                            ##
##                                                                          ##
##                         Copyright © 2020 Aquefir                         ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

include etc/base.mk

PROJECT := carta

# put a ‘1’ for the desired target types to compile
SOFILE := 1
AFILE  := 1

# space-separated path list for #includes
# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS      := SDL2
LIBDIRS   :=

# frameworks (macOS target only)
FWORKS :=

# ‘3P’ are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR := 3rdparty
3PLIBS   := uni qlibc

# sources
CFILES   := \
	src/carta.c \
	src/dispdrv.c
HFILES   := \
	include/carta/carta.h \
	include/carta/common.h \
	include/carta/dispdrv.h \
	src/carta.h \
	src/dispdrv.h
CPPFILES :=
HPPFILES :=

# test suite sources
TES_CFILES   := \
	src/dispdrv.tes.c
TES_HFILES   :=
TES_CPPFILES :=
TES_HPPFILES :=

# this defines all our usual targets
include etc/targets.mk
