## Copyright (C) 2011  Trevor Woerner

########################
## src/Makefile.am
########################
SUBDIRS =
bin_PROGRAMS = bsort gcov-bsort
gcov_bsort_SOURCES = bsort.c
gcov_bsort_CFLAGS = -fprofile-arcs -ftest-coverage

clean-local:
	$(RM) *gcno *gcda
