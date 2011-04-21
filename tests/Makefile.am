## Copyright (C) 2011  Trevor Woerner

########################
## tests/Makefile.am
########################
SUBDIRS = 
AM_MAKEFLAGS = -k
AM_CFLAGS = -Wall -Werror -Wextra -Wconversion -Wreturn-type -Wstrict-prototypes \
	-fprofile-arcs -ftest-coverage @CHECK_CFLAGS@ -I$(top_srcdir)/lib
LDADD = @CHECK_LIBS@ $(top_builddir)/lib/libmoney.la

if COND_HAVE_CHECK
TESTS = check_money check_bsort
noinst_PROGRAMS = check_money check_bsort
check_money_SOURCES =  check_money.c $(top_srcdir)/lib/money.c
check_bsort_SOURCES = check_bsort.c $(top_srcdir)/src/bsort.c
check_bsort_CFLAGS = -DUNDER_TEST $(AM_CFLAGS) -I$(top_srcdir)/src

check-local:
	$(RM) CheckLog.html
	-if test x$(HTML_CHECK_RESULT) = xtrue; then \
		$(gcov2html_check_BINDIR)/getgcov.sh money.o CheckLog.xml; \
		$(gcov2html_check_BINDIR)/getgcov.sh check_bsort-bsort.c CheckLog_bsort.xml; \
		$(XSLTPROC) $(gcov2html_check_PKGDATADIR)/CheckLog.xsl CheckLog*.xml > CheckLog.html; \
		if test x$(GCOV2HTML) != xfalse; then \
			$(GCOV2HTML) money.c.gcov; \
			$(GCOV2HTML) bsort.c.gcov; \
			$(INSTALL) $(gcov2html_check_PKGDATADIR)/gcov2html-check.png .; \
		fi \
	else \
		touch CheckLog.html; \
	fi

CheckLog.html: $(check_PROGRAMS)
	$(MAKE) $(AM_MAKEFLAGS) check

install-CheckLog: CheckLog.html
	$(mkdir_p) $(docbasedir)
	$(INSTALL) CheckLog.html money.c.html $(gcov2html_check_PKGDATADIR)/gcov2html.png *.gcov $(docbasedir)
endif

clean-local::
	$(RM) *png *html CheckLog*txt CheckLog*xml *.gc*
