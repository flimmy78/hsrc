# $NetBSD: Makefile,v 1.52 2018/07/03 05:03:18 adam Exp $

DISTNAME=	pytraffic-2.5.4
PKGREVISION=	33
CATEGORIES=	games
MASTER_SITES=	http://alpha.uhasselt.be/Research/Algebra/Members/pytraffic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alpha.uhasselt.be/Research/Algebra/Members/pytraffic/
COMMENT=	Computer version of a popular board game

# pytraffic-2.5.4 distfile was changed after release
DIST_SUBDIR=	pytraffic-2.5.4-070313

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 37 # py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
