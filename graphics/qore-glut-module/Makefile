# $NetBSD: Makefile,v 1.8 2018/06/08 20:49:41 nros Exp $

DISTNAME=	qore-glut-module-0.0.3
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	GLUT Qore bindings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=--with-glut=${BUILDLINK_PREFIX.glut}

.include "options.mk"

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../graphics/qore-opengl-module/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
