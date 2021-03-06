# $NetBSD: Makefile,v 1.35 2017/05/15 14:14:04 wiz Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
PKGREVISION=	1
COMMENT=	Tools for providing messages in different languages

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

USE_LANGUAGES=		c c++
USE_TOOLS+=		xz:run
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--with-included-libcroco
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--with-xz
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--without-emacs
CONFIGURE_ARGS+=	--disable-openmp
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
LDFLAGS.AIX+=		-Wl,-brtl

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

BUILDLINK_TRANSFORM.Cygwin+=	rm:-Wl,--disable-auto-import

#bug 20453 in bug-gzip list, passed onto gnulib
CONFIGURE_ENV.AIX+=	ac_cv_header_wctype_h=no

PLIST_SUBST+=	ARCHIVE_VERSION=${PKGVERSION_NOREV:S/./ /g:[1..3]:ts.}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
