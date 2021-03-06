# $NetBSD: Makefile,v 1.35 2018/05/17 14:10:11 fhajny Exp $

DISTNAME=	mongo-c-driver-1.9.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/mongodb/mongo-c-driver/
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

GITHUB_RELEASE=	${PKGVERSION_NOREV}

# Requires shm_open()
NOT_FOR_PLATFORM+=	OpenBSD-*-*

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "options.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-man-pages=yes
CONFIGURE_ARGS+=	--with-libbson=system
CONFIGURE_ARGS+=	--with-snappy=system
CONFIGURE_ARGS+=	--with-zlib=system
CONFIGURE_ENV+=		SPHINX_BUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}

PKGCONFIG_OVERRIDE+=	src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc-ssl-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

# Test behaves inconsistently
#TEST_MAKE_FLAGS+=	MONGOC_TEST_SKIP_LIVE=on
#TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../lang/python/application.mk"

# libbson and mongo-c-driver released are tied
BUILDLINK_API_DEPENDS.libbson+=	libbson>=${PKGVERSION_NOREV}
.include "../../devel/libbson/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
