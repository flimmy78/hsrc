# $NetBSD: Makefile,v 1.4 2018/07/03 05:03:01 adam Exp $

DISTNAME=	czipfile-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/czipfile/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/czipfile
COMMENT=	Replacement for builtin zipfile, with fast, C-based zipfile decryption
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37	# for 2.x only

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
