# $NetBSD: Makefile,v 1.2 2018/05/31 01:47:03 wen Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/IRdisplay/
COMMENT=	Jupyter display machinery
LICENSE=	mit

DEPENDS+=	R-repr-[0-9]*:../../devel/R-repr

R_PKGNAME=	IRdisplay
R_PKGVER=	0.5.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
