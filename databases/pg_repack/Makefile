# $NetBSD: Makefile,v 1.3 2018/05/21 13:20:20 fhajny Exp $

DISTNAME=	pg_repack-1.4.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=reorg/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://reorg.github.io/pg_repack/
COMMENT=	Reorganize tables in PostgreSQL databases with minimal locks
LICENSE=	modified-bsd

GITHUB_PROJECT=	pg_repack
GITHUB_TAG=	ver_${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
