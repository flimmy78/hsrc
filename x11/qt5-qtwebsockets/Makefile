# $NetBSD: Makefile,v 1.20 2018/07/20 03:34:01 ryoon Exp $

DISTNAME=	qtwebsockets-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtwebsockets-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for websockets

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5WebSockets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
