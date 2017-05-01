
TOPDIR = ../


HEXPATH = $(TOPDIR)/hex

HEXFILE = main.hex
TARGET = main.ihx
REL = main.rel


INCPATH = $(TOPDIR)/include
LIBPATH = $(TOPDIR)/libs

CFLAGS = -I$(INCPATH)
# sdcc与gcc不一样，sdcc依赖模块使用全路径rel或者lib
# LDFLAGS = -lbstv51
LDFLAGS = $(TOPDIR)/src/display/lcd1602.rel $(TOPDIR)/src/chips/ds1302.rel $(TOPDIR)/src/c51/delay.rel

include $(TOPDIR)/Makefile.env
