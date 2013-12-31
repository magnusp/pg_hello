MODULE_big = pg_hello
OBJS = pg_hello.o

EXTENSION = pg_hello
DATA = pg_hello--1.0.sql

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
