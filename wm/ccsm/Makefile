# $NetBSD: Makefile,v 1.22 2018/07/03 05:03:38 adam Exp $

PKGVER=			0.8.4
DISTNAME=		ccsm-${PKGVER}
PKGREVISION=		4
CATEGORIES=		wm gnome
MASTER_SITES=		http://releases.compiz.org/${PKGVER}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compiz.org/
COMMENT=		CompizConfig Settings Manager
LICENSE=		gnu-gpl-v2

DEPENDS+=		compizconfig-backend-gconf>=0.6.0:../../devel/compizconfig-backend-gconf
DEPENDS+=		${PYPKGPREFIX}-compizconfig-[0-9]*:../../devel/py-compizconfig
DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_TOOLS+=		msgfmt intltool

REPLACE_PYTHON=		${WRKSRC}/setup.py ${WRKSRC}/ccm/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
