# $NetBSD: Makefile,v 1.10 2018/07/19 15:15:21 jaapb Exp $

VERSION=	2.2.0
GITHUB_PROJECT=	ocaml-base64
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-base64/
COMMENT=	Base64 encoding and decoding in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-jbuilder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
