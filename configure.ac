dnl Copyright (C) 2011  Trevor Woerner

AC_INIT([gcov2html-check Example], 0.1.0, twoerner@gmail.com, gcov2html-check-example)
AC_CONFIG_SRCDIR(tests/check_money.c)
AC_CONFIG_AUX_DIR(cfg)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign no-dist-gzip dist-bzip2 1.9])
AM_CONFIG_HEADER(cfg/config.h)

SUBDIRS="src lib"

dnl **********************************
dnl checks for programs
dnl **********************************
AC_PROG_CC
AC_PROG_CPP

AC_PROG_MAKE_SET

AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL

PKG_CHECK_MODULES([CHECK], [check >= 0.8.2], [HAVE_CHECK=true], [HAVE_CHECK=false])
AM_CONDITIONAL(COND_HAVE_CHECK, test x$HAVE_CHECK = xtrue)
AC_SUBST(HAVE_CHECK)

PKG_CHECK_MODULES(gcov2html_check, gcov2html-check, [HAVE_GCOV=true], [HAVE_GCOV=false])
AM_CONDITIONAL(COND_HAVE_GCOV, test x$HAVE_GCOV = xtrue)
AC_SUBST(HAVE_GCOV)
gcov2html_check_PKGDATADIR=`pkg-config --variable=pkgdatadir gcov2html-check`
AC_SUBST(gcov2html_check_PKGDATADIR)
gcov2html_check_BINDIR=`pkg-config --variable=bindir gcov2html-check`
AC_SUBST(gcov2html_check_BINDIR)

AC_CHECK_PROGS(XSLTPROC, xsltproc, false)
AC_CHECK_PROGS(GCOV, gcov, false)
AC_CHECK_PROGS(GCOV2HTML, gcov2html-check, false)
HTML_CHECK_RESULT=false
if test x$HAVE_CHECK = xtrue; then
	if test x$XSLTPROC != xfalse; then
		if test x$GCOV != xfalse; then
			HTML_CHECK_RESULT=true
		fi
	fi
fi
AC_SUBST(HTML_CHECK_RESULT)

dnl **********************************
dnl checks for user features
dnl **********************************

dnl **********************************
dnl checks for libraries
dnl **********************************

dnl **********************************
dnl checks for header files
dnl **********************************

dnl **********************************
dnl checks for typedefs, structs, and
dnl compiler characteristics
dnl **********************************

dnl **********************************
dnl checks for library functions
dnl **********************************

dnl **********************************
dnl checks for system services
dnl **********************************

dnl **********************************
dnl checks for unix variants
dnl **********************************

dnl **********************************
dnl other stuff
dnl **********************************
if test x$HAVE_CHECK = xtrue; then
	SUBDIRS="$SUBDIRS tests"
fi
AC_SUBST(SUBDIRS)

dnl **********************************
dnl output
dnl **********************************
AC_OUTPUT(Makefile
cfg/Makefile
src/Makefile
lib/Makefile
tests/Makefile)
