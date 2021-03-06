# $NetBSD: Makefile,v 1.65 2018/07/17 06:38:02 adam Exp $

DISTNAME=	libgpg-error-1.32
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/
MASTER_SITES+=	${MASTER_SITE_RING_SERVER:=net/gnupg/libgpg-error/}
MASTER_SITES+=	ftp://mirror.switch.ch/mirror/gnupg/libgpg-error/
MASTER_SITES+=	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/libgpg-error/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_ENV+=		LC_ALL="C"
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
LIBS+=	-lrt
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
