# $NetBSD: Makefile,v 1.22 2018/07/20 03:31:16 wen Exp $

DISTNAME=	Audio-Scan-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Audio-Scan/
COMMENT=	XS parser for MP3, MP4, Ogg Vorbis, etc
LICENSE=	gnu-gpl-v2

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Audio/Scan/.packlist
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
