# $NetBSD: Makefile,v 1.13 2016/08/28 15:48:35 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-cElementTree-${PY_DISTVERSION}
CATEGORIES=	textproc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.effbot.org/zone/celementtree.htm
COMMENT=	C implementation of Python ElementTree API

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_elementtree.c

USE_GCC_RUNTIME=yes

PYDISTUTILSPKG=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
