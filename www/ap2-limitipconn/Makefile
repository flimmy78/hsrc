# $NetBSD: Makefile,v 1.1 2014/08/27 11:15:14 is Exp $
#
#        * APACHE_PKG_PREFIX = ap24
#        * PKG_APACHE = apache24

LICVER=			limitipconn-0.24

DISTNAME=		mod_${LICVER}
EXTRACT_SUFX=		.tar.bz2
PKGNAME=		${APACHE_PKG_PREFIX}-${LICVER}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://dominia.org/djao/limit/
LICENSE=		apache-2.0


PATCH_SITES=		http://dominia.org/djao/limit/contrib/dg/
PATCHFILES=		mod_limitipconn_local_IP_patch_2.diff

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://dominia.org/djao/limitipconn2.html
COMMENT=		Limits per-IP connections to an Apache 2 server

APACHE_MODULE=		yes
MAKE_FLAGS+=		APXS=${APXS:Q}
USE_LIBTOOL=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${BUILDLINK_PREFIX.apache}/share/httpd/build/instdso.sh \
		SH_LIBTOOL=${BUILDLINK_PREFIX.apache}/share/httpd/build/libtool \
		${WRKSRC}/mod_limitipconn.la \
		${DESTDIR}${PREFIX}/lib/httpd
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mod_limitipconn
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_limitipconn/

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
