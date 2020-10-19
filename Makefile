PREFIX=/usr
CC=cc
RM=rm -f

tof: tof.c
	$(CC) -o $@ $<

install: tof
	cp tof wof $(PREFIX)/bin

clean:
	$(RM) tof
