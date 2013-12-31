pg_hello, a very basic Postgres extension
=========================================

To get started I used [sywtwpge]
(https://github.com/johto/sywtwpge) which creates an
extension based on a template. The code in pg\_hello.c is
adapted from the first article in the ["Writing PostgreSQL
Functions in C"](http://linuxgazette.net/139/peterson.html)
series by Ron Peterson. Since the article was written the
VARATT_SIZEP macro has [been 
deprecated](http://bit.ly/1cEiiOg). I replaced this with
a call to SET\_VARSIZE instead.

Installation
============

Make sure you have development packages installed for postgres and
build tools in general. For me on CentOS I was missing pg\_config
in my path. I got that installed using alternatives:

    alternatives /usr/bin/pg_config pg_config /usr/pgsql-9.3/bin/pg_config 1

Once pg_config is in your path, do:

    make; sudo make install

Then in a psql session issue:

    CREATE extension pg_hello; SELECT hello('world');

There you go!
