# $NetBSD: Makefile,v 1.27 2018/04/17 01:57:18 christos Exp $

PKGNAME=	${DISTPKGNAME:S/cyrus-sasl/cy2-gssapi/}
COMMENT=	Cyrus SASL GSSAPI authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

BUILD_DIRS=	common plugins

MAKE_FLAGS+=	sasl_LTLIBRARIES=libgssapiv2.la

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
