# $NetBSD: Makefile,v 1.139 2018/06/24 11:16:12 wiz Exp $

.include "../../print/evince/Makefile.common"
PKGREVISION=	70

COMMENT=		Document viewer

.include "options.mk"

CONFIGURE_ARGS+=	--enable-comics
CONFIGURE_ARGS+=	--disable-nautilus

USE_TOOLS+=	gsed

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
