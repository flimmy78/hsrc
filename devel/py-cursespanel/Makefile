# $NetBSD: Makefile,v 1.31 2017/09/03 08:53:08 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-cursespanel-${PY_DISTVERSION}
PKGREVISION=	4
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses panel module for Python

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_CURSES=	getsyx
FAKE_NCURSES=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_curses_panel.c
PYDISTUTILSPKG=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}

.include "../../lang/python/srcdist.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
