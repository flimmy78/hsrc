# $NetBSD: Makefile,v 1.22 2018/04/29 21:32:02 adam Exp $
#

PKGNAME=	dirb-1.9
DISTNAME=	dirb19
PKGREVISION=	15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

WRKSRC=${WRKDIR}/dirb

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
