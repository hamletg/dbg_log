dnl ***************************************************************************
dnl
dnl The following code is derived, directly or indirectly, from the Mipi UniPro
dnl source code Copyright (c) 2004-2005 by all Contributors.
dnl All Rights reserved.
dnl
dnl  License stuff here ????????
dnl
dnl ***************************************************************************
dnl
dnl  configure.in --
dnl  Process this file with autoconf to produce a configure script.
dnl
dnl  Original Author: Michel Gillet, Nokia, 2005-09-05
dnl
dnl ***************************************************************************
dnl
dnl  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
dnl  changes you are making here.
dnl
dnl      Name, Affiliation, Date:
dnl  Description of Modification:
dnl
dnl ***************************************************************************

dnl
dnl Initialization.
dnl

AC_INIT(NEWS)
AC_CONFIG_HEADERS([include/logmod/unix/setup.h])
AC_CONFIG_HEADERS([include/dbg_log/config.h])
AC_CONFIG_AUX_DIR(config)

dnl
dnl Some simple checks.
dnl

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE(package,version,do-no-define)

AC_PROG_LIBTOOL

AM_PROG_AS
AC_PROG_CC
AC_PROG_CXX
dnl AC_PROG_RANLIB
AC_PROG_INSTALL


PKG_CHECK_MODULES([SQLITE3], [sqlite3 >= 3.7])

AM_OPTIONS_WXCONFIG
reqwx=2.9.4
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.
 
		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi
 
CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LIBS="$LIBS $WX_LIBS"

dnl AC_LANG(C++)
dnl AC_RUN_IFELSE([AC_LANG_SOURCE([[
dnl    #include <IceUtils/Config.h>
dnl    
dnl    int main() {
dnl	if ( ICE_INT_VERSION >=30402 )
dnl		return 0;
dnl	else
dnl		return -1;
dnl    }
dnl    ]])],[],[AC_MSG_FAILURE([Ice above 3.4.2 is required])],[])
    
dnl C_ARG_VAR([SYSTEMC],[library name of systemc (defaults is systemc)])

dnl
dnl Set the compiler flags and target architecture.
dnl

CXX_COMP=`basename $CXX`

case "$target" in
    sparc-sun-solaris*)
        case "$CXX_COMP" in
            CC)
                EXTRA_CXXFLAGS=""
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="sparcOS5"
		AR_TOOL="$CXX -xar -o"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="gccsparcOS5"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="sparc-os2"
        ;;
    *linux*)
        case "$CXX_COMP" in
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="linux"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="iX86"
        ;;
    *cygwin*)
        case "$CXX_COMP" in
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="cygwin"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="iX86"
        ;;
    *hpux11*)
        case "$CXX_COMP" in
            aCC)
                EXTRA_CXXFLAGS="-Aa -ext +DA2.0 +DS2.0"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="+O1"
                TARGET_ARCH="hpux11"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS -Wa,-w36"
                ;;
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="gcchpux11"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="hppa"
        ;;
    *)
        AC_MSG_ERROR("sorry...architecture not supported")
        ;;
esac

dnl
dnl extra "package" included ?
dnl

AC_ARG_ENABLE(dbg_class,        [  --enable-dbg_class      use dbg_class], [DBG_CLASS="$enableval"])


dnl
dnl --enable-debug
dnl
AC_ARG_ENABLE([debug],
                AC_HELP_STRING([--enable-debug],
                             [Enable debugging. default: disabled.]),
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -g"
                 DEBUG="yes"
                ],
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS}"
                 DEBUG="no"
                ])

dnl
dnl --disable-verbose
dnl Disable verbose compilation line (need special patch for automake/autoconf)
dnl
AC_ARG_ENABLE([verbose],
                AC_HELP_STRING([--disable-verbose],
                             [Display short compilation line. default: normal output.]),
                [
                 enable_niceoutput="yes"
                ],
                [
                 enable_niceoutput="no"
                ])

    AM_CONDITIONAL(NICEOUTPUT, test x$enable_niceoutput = xyes)

dnl
dnl --disable-systemc-warnings
dnl Disable systemc warnings
dnl
AC_ARG_ENABLE([systemc-warnings],
                AC_HELP_STRING([--disable-systemc-warnings],
                             [Disable compilation warnings for some systemc versions. default: enabled.]),
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -Wno-deprecated -Wno-char-subscripts"
                ])

 


dnl -------------------------------------------------------
dnl       Set the path of the XERCEC-C library  
dnl -------------------------------------------------------

dnl -------------------------------------------------------
dnl We now detect headers
dnl -------------------------------------------------------
dnl
dnl SystemC

dnl AC_CHECK_HEADER([systemc.h],
dnl	[
dnl Action if found 
dnl		echo 1 > /dev/null
dnl	],
dnl	[
dnl Action if not found
dnl	AC_MSG_ERROR([SystemC was not found in $SYSTEMC!])
dnl	])

dnl
dnl XERCES-C
dnl

old_c_include_path="$C_INCLUDE_PATH"
C_INCLUDE_PATH="$XERCESCROOT/include:$C_INCLUDE_PATH"
export C_INCLUDE_PATH

if test "$BUILD_XML_PARSER" = "yes" ; then
	AC_CHECK_HEADER([xercesc/util/PlatformUtils.hpp],
		[
dnl Action if found 
		echo 1 > /dev/null
		],
		[
dnl Action if not found
			AC_MSG_WARN([Xerces-C was not found in $XERCESCROOT!])
			AC_MSG_WARN([XML parser build disabled])
			BUILD_XML_PARSER="no"
		])
fi

C_INCLUDE_PATH="$old_c_include_path"
export C_INCLUDE_PATH


dnl -------------------------------------------------------
dnl We test the pragma
dnl -------------------------------------------------------
dnl
dnl __attribute__((unused))

AC_MSG_CHECKING([compiler support for __attribute__((unused))])
AC_TRY_CPP([static int __attribute__ ((unused)) test = 0;],
			[
				PRAGMA_UNSUSED_SUPP=yes
			],
			[
				PRAGMA_UNSUSED_SUPP=no
			]
		   )
AC_MSG_RESULT([$PRAGMA_UNSUSED_SUPP])

dnl -------------------------------------------------------
dnl create the config.h file
dnl -------------------------------------------------------
dnl

if test "$DBG_CLASS" = "yes" ; then	
    AC_DEFINE(DBG_LOG,[1],[Define to 1 if you have want to use dbg_class feature])
fi

if test "$PRAGMA_UNSUSED_SUPP" = "yes" ; then
    AC_DEFINE(UP_PRAGMA_UNSUSED_SUPP,[1],[Define to 1 if the __attribute__((unused)) is supported])
fi

LIBS="$LIBS $EXTRA_LIBS"

EXTRA_CXXFLAGS="$EXTRA_CXXFLAGS"
CXXFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"


dnl
dnl Substitution variables.
dnl

AC_SUBST(EXTRA_CXXFLAGS)
AC_SUBST(DEBUG_CXXFLAGS)
AC_SUBST(OPT_CXXFLAGS)
AC_SUBST(TARGET_ARCH)
AC_SUBST(QT_ARCH)
dnl AC_SUBST(LIBS)

dnl
dnl Create the Makefiles.
dnl

AC_OUTPUT(
Makefile 
src/Makefile 
src/logmod/logmod.pc
src/logmod/Makefile 
src/dbg_log/dbg_log.pc
src/dbg_log/Makefile
src/log_ice/log_ice.pc
src/log_ice/Makefile
src/log_ice/ice/Makefile
src/log_sqlite/log_sqlite.pc
src/log_sqlite/Makefile
samples/Makefile
samples/log_ice_dbg/Makefile
samples/log_ice_dbg/src/Makefile
samples/log_ice_dbg/src/log_ice_dbg/Makefile
samples/log_ice_dbg/src/log_ice_dbg/ice/Makefile
samples/test01/Makefile
samples/test01/src/Makefile
samples/test01/src/test01/Makefile
)

dnl -------------------------------------------------------
dnl       Do the reporting.  
dnl -------------------------------------------------------
echo "********************************************************"

echo "The value of DBG_CLASS is ${DBG_CLASS:-no}"
echo "The value of DEBUG is ${DEBUG}"

dnl done
