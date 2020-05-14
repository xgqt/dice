BIN	= dice
MAN	= $(BIN).1

DESTDIR =
PREFIX	= /usr
INSTDIR	= $(DESTDIR)$(PREFIX)
INSTBIN	= $(INSTDIR)/bin
INSTMAN	= $(INSTDIR)/share/man/man1

CC	= gcc
SRCDIR	= src
SRC	= $(BIN).c
CFLAGS	= -std=c99 -Wall -Wextra -pipe -O2


.PHONY: all debug clean install uninstall


all:
	$(CC) $(CFLAGS) $(SRCDIR)/$(SRC) -o $(BIN)


$(BIN): all


clean:
	$(RM) $(BIN)


debug: CFLAGS += -g
debug: all


install:
	test -d $(INSTDIR) || mkdir -p $(INSTDIR)
	test -d $(INSTBIN) || mkdir -p $(INSTBIN)
	test -d $(INSTMAN) || mkdir -p $(INSTMAN)

	install -m 0755 $(BIN) $(INSTBIN)
	install -m 0644 $(MAN) $(INSTMAN)


uninstall:
	$(RM) $(INSTBIN)/$(BIN)
	$(RM) $(INSTMAN)/$(MAN)
