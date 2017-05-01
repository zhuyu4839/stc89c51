
IHX = packihx
DOWNLOAD = stcflash

TOPDIR = .

exclude_dirs := include hex libs test

HEX = $(TOPDIR)/hex/main.hex

download:
	sudo stcflash $(HEX)

connect:
	sudo stcflash

include $(TOPDIR)/Makefile.env

#clean: 
#	-rm -f $(HEX)

.PHONY: download connect clean
