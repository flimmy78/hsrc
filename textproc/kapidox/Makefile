# $NetBSD: Makefile,v 1.3 2018/04/11 11:50:38 markd Exp $

DISTNAME=	kapidox-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Frameworks API Documentation Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
