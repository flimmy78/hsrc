# $NetBSD: Makefile,v 1.34 2018/02/11 03:37:22 schmonz Exp $

DISTNAME=	Crypt-SSLeay-0.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-SSLeay/
COMMENT=	Crypt::SSLeay - OpenSSL glue that provides LWP https support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Path-Class>=0.26:../../devel/p5-Path-Class
DEPENDS+=	p5-Try-Tiny>=0.19:../../devel/p5-Try-Tiny

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/SSLeay/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1
MAKE_PARAMS+=		--lib=${SSLBASE}
MAKE_PARAMS+=		--libpath=${SSLBASE}/lib

post-extract:
	chmod a-x ${WRKSRC}/lib/Net/SSL.pm

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
