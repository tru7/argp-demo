argp-demo: argp-demo.c
	$(CC) $(CFLAGS) -o argp-demo argp-demo.c $(LDFLAGS)

install: argp-demo
	mkdir -p $(DESTDIR)/usr/bin
	cp argp-demo $(DESTDIR)/usr/bin
