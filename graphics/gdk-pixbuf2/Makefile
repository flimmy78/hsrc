# $NetBSD: Makefile,v 1.35 2017/10/15 23:19:11 prlw1 Exp $

DISTNAME=	gdk-pixbuf-${PIXBUF2_VERSION}
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${MSITE_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gdk-pixbuf
COMMENT=	Image loaders for gtk2
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gtk2+<2.22

.include "../../graphics/gdk-pixbuf2/Makefile.version"

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in

_BUILDING_GTK2= yes
.include "loaders.mk"

# We remove the loader database during post-install since we create it
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GDK_PIXBUF_LOADERS_DB}

.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.37.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
