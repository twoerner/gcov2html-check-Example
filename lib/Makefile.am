## Copyright (C) 2011  Trevor Woerner

########################
## lib/Makefile.am
########################
SUBDIRS =
AM_CFLAGS = -Wall -Werror -Wextra -Wconversion -Wreturn-type -Wstrict-prototypes
pkginclude_HEADERS = money.h

########################
## shared lib
########################
lib_LTLIBRARIES = libmoney.la
libmoney_la_SOURCES = money.h money.c
libmoney_la_LDFLAGS =  -release @VERSION@
libmoney_la_LDFLAGS += -version-info 0:0:0
## C:R:A
## any code change       -> inc(R)
## interface add/del/chg -> R=0, inc(C)
## interface added       -> inc(A)
## interfece removed     -> A=0
