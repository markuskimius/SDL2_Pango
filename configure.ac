# Process this file with autoconf to produce a configure script.

AC_INIT([SDL2_Pango],[2.1.5])
AM_MAINTAINER_MODE

# Set various version strings - taken gratefully from the GTk sources

# Making releases:
#   MICRO_VERSION += 1;
#   INTERFACE_AGE += 1;
#   BINARY_AGE += 1;
# if any functions have been added, set INTERFACE_AGE to 0.
# if backwards compatibility has been broken,
# set BINARY_AGE and INTERFACE_AGE to 0.

MAJOR_VERSION=2
MINOR_VERSION=1
MICRO_VERSION=5
INTERFACE_AGE=0
BINARY_AGE=1
VERSION=$MAJOR_VERSION.$MINOR_VERSION.$MICRO_VERSION

AC_SUBST(MAJOR_VERSION)
AC_SUBST(MINOR_VERSION)
AC_SUBST(MICRO_VERSION)
AC_SUBST(INTERFACE_AGE)
AC_SUBST(BINARY_AGE)
AC_SUBST(VERSION)

# libtool versioning

LT_RELEASE=$MAJOR_VERSION.$MINOR_VERSION
LT_CURRENT=`expr $MICRO_VERSION - $INTERFACE_AGE`
LT_REVISION=$INTERFACE_AGE
LT_AGE=`expr $BINARY_AGE - $INTERFACE_AGE`

AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

# Detect the canonical host and target build environment

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

# Setup for automake

AM_INIT_AUTOMAKE

# Check for tools

LT_INIT([win32-dll])
AC_PROG_CC
AC_PROG_INSTALL

# The alpha architecture needs special flags for binary portability
case "$target" in
    alpha*-*-linux*)
        CFLAGS="$CFLAGS -mcpu=ev4 -Wa,-mall"
        ;;
    *-*-beos*)
        ac_default_prefix=/boot/develop/tools/gnupro
        ;;
    *-*-cygwin* | *-*-mingw32*)
        if test "$build" != "$target"; then # cross-compiling
            ac_default_prefix=/usr/local/cross-tools/i386-mingw32msvc
        fi
        ;;
esac

# Check for Pango

PKG_CHECK_MODULES(PANGO, pango >= 1.2.0, , AC_MSG_ERROR([*** pango >= 1.2.0 not found!]))
CFLAGS="$CFLAGS $PANGO_CFLAGS"
LIBS="$LIBS $PANGO_LIBS"

PKG_CHECK_MODULES(PANGOFT2, pangoft2 >= 1.2.0, , AC_MSG_ERROR([*** pangoft2 >= 1.2.0 not found!]))
CFLAGS="$CFLAGS $PANGOFT2_CFLAGS"
LIBS="$LIBS $PANGOFT2_LIBS"

# Check for SDL

SDL_VERSION=2.0.2
AM_PATH_SDL2($SDL_VERSION,
            :,
	    AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)
CFLAGS="$CFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"

AC_CONFIG_FILES([Makefile src/Makefile SDL2_Pango.pc docs/Makefile docs/Doxyfile VisualC2003/Makefile Wix/Makefile Wix/merge_module.xml Wix/dev.xml Wix/testbench.xml])
AC_CONFIG_MACRO_DIRS([m4])

# Finally create all the generated files
AC_OUTPUT
