# $NetBSD: Makefile,v 1.13 2018/07/03 05:03:05 adam Exp $

DISTNAME=	zbase32-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zbase32/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://pypi.python.org/pypi/zbase32/
COMMENT=	Alternate base32 encoder (not RFC 3548 compliant)
LICENSE=	modified-bsd

REPLACE_PYTHON=	zbase32/zbase32.py zbase32/test/test_zbase32.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.1.5

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
