# $NetBSD: Makefile,v 1.11 2018/07/18 00:06:21 joerg Exp $

DISTNAME=	ppl-1.1
PKGREVISION=	4
CATEGORIES=	math
#MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/1.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.unipr.it/ppl/
COMMENT=	The Parma Polyhedra Library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake perl gsed gm4

USE_LANGUAGES=	c gnu++03
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
#CONFIGURE_ARGS+=	--enable-interfaces=c,cxx

do-build:
	set -e; cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE}

TEST_TARGET=	-k check

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
