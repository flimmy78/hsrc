# $NetBSD: Makefile,v 1.7 2015/03/15 17:25:56 hiramatsu Exp $

DISTNAME=	kcc
PKGNAME=	kcc-2.3
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/os/linux/JE/sources/base/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Kanji code converter with auto encoding detection
LICENSE=	gnu-gpl-v2

INSTALL_MAKE_FLAGS+=	BINPATH=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MANPATH=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	JMANDIR=ja_JP.eucJP

INSTALL_TARGET=	install install.man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.eucJP/man1

.include "../../mk/bsd.pkg.mk"
