## Copyright (C) 2011  Trevor Woerner

########################
## src/Makefile.am
########################
SUBDIRS =
AM_CFLAGS = -Wall -Werror -Wextra -Wconversion -Wreturn-type -Wstrict-prototypes
bin_PROGRAMS = bsort gcov-bsort
bsort_SOURCES = main.c bsort.h bsort.c
gcov_bsort_SOURCES = main.c bsort.h bsort.c
gcov_bsort_CFLAGS = $(AM_CFLAGS) -fprofile-arcs -ftest-coverage

clean-local:
	$(RM) *gcno *gcda *gcov *html
