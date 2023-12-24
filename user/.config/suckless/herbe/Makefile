TARGETC  = herbe
TARGETV  = tiramisu
CFLAGS  += -Wall -Wno-unused-value -Wextra -pedantic -lX11 -lXft -I/usr/include/freetype2 -pthread
IFLAGS   = --pkg gio-2.0
SRCC    := herbe.c config.h
SRCV    := src/notification.vala src/dbus.vala src/tiramisu.vala

PREFIX ?= /usr/local
CC ?= cc
VALAC ?= valac
PKG_CONFIG ?= pkg-config

all: $(TARGETC)

$(TARGETC): $(SRCC)
	$(CC) herbe.c $(CFLAGS) -o $(TARGETC)

all: $(TARGETV)

$(TARGETV): $(SRCV)
	$(VALAC) $(IFLAGS) $(SRCV) -o $(TARGETV)

install: $(TARGETC) $(TARGETV)
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f $(TARGETC) ${DESTDIR}${PREFIX}/bin
	cp -f $(TARGETV) ${DESTDIR}${PREFIX}/bin
	cp -f herbed ${DESTDIR}${PREFIX}/bin

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/$(TARGETC)
	rm -f ${DESTDIR}${PREFIX}/bin/$(TARGETV)
	rm -f ${DESTDIR}${PREFIX}/bin/herbed

clean:
	rm -f $(TARGETC)
	rm -f $(TARGETV)

.PHONY: all install uninstall clean
