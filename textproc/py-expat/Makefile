# $NetBSD: Makefile,v 1.25 2017/09/03 08:53:16 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-expat-${PY_DISTVERSION}
CATEGORIES=	textproc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/
COMMENT=	Python interface to expat

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/pyexpat.c

USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
