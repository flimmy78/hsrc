# $NetBSD: Makefile,v 1.47 2018/06/03 07:49:27 leot Exp $

PKGNAME=	${PYPKGPREFIX}-curses-${PY_DISTVERSION}
PKGREVISION=	5
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes

# NetBSD-8 curses has enough support for py-curses
USE_CURSES=	getsyx
# But we build as ncurses still to get the full feature set easily
FAKE_NCURSES=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}

.include "../../lang/python/srcdist.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
