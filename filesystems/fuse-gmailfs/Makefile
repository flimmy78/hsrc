# $NetBSD: Makefile,v 1.16 2018/07/04 13:40:18 jperkin Exp $

DISTNAME=	gmailfs-0.7.2
PKGREVISION=	3
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://richard.jones.name/google-hacks/gmail-filesystem/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://richard.jones.name/google-hacks/gmail-filesystem/gmail-filesystem.html
COMMENT=	FUSE filesystem which uses Google mail for free space

DEPENDS+=	${PYPKGPREFIX}-fuse-bindings-[0-9]*:../../filesystems/py-fuse-bindings

NO_BUILD=			yes
REPLACE_PYTHON=		gmailfs.py mount.gmailfs
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-fuse-bindings

CONF_FILES=		${PREFIX}/share/examples/gmailfs/gmailfs.conf \
			${PKG_SYSCONFDIR}/gmailfs.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	gmailfs.py mount.gmailfs
SUBST_SED.config=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_SED.config+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.config+=	-e "s|@PYSITELIB@|${PREFIX}/${PYSITELIB}|g"
SUBST_MESSAGE.config=   Fixing paths.

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

INSTALLATION_DIRS=	sbin ${PYSITELIB}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gmailfs.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/
	${INSTALL_SCRIPT} ${WRKSRC}/mount.gmailfs \
		${DESTDIR}${PREFIX}/sbin/mount_gmailfs
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gmailfs
	${INSTALL_DATA} ${WRKSRC}/gmailfs.conf \
		${DESTDIR}${PREFIX}/share/examples/gmailfs/

.include "../../lang/python/application.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
