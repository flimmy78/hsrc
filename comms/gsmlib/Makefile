# $NetBSD: Makefile,v 1.27 2018/07/18 00:06:12 joerg Exp $
#

DISTNAME=	gsmlib-1.10
PKGREVISION=	3
CATEGORIES=	comms devel
#MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
