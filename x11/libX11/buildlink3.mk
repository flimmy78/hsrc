# $NetBSD: buildlink3.mk,v 1.13 2018/03/07 11:57:35 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !exists(${X11BASE}/lib/pkgconfig/x11.pc) && \
    !exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/x11.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libX11

.  if !defined(LIBX11_BUILDLINK3_MK)
LIBX11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.1
BUILDLINK_ABI_DEPENDS.libX11+=	libX11>=0.99
BUILDLINK_PKGSRCDIR.libX11?=	../../x11/libX11

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
X11_LDFLAGS+=	-L${BUILDLINK_PREFIX.libX11}/lib

.  if ${OPSYS} == "OSF1" || ${OPSYS} == "MirBSD" || ${OPSYS} == "OpenBSD"
.include "../../mk/pthread.buildlink3.mk"
.  endif

.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"

.  if ${X11_TYPE} == "modular" || \
    exists(${X11BASE}/lib/pkgconfig/xcb.pc) || \
    exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb.pc)
.include "../../x11/libxcb/buildlink3.mk"
.  endif

.include "../../x11/xorgproto/buildlink3.mk"

# http://cgit.freedesktop.org/xorg/lib/libX11/commit/?id=d0cbf388919364fe6b5b9127f36426eb744090a0
SUBST_CLASSES+=	fx-libX11-h-guards
SUBST_STAGE.fx-libX11-h-guards=	post-wrapper
SUBST_MESSAGE.fx-libX11-h-guards=\
	Add an "X11_" string to header guards to avoid possible collision
SUBST_FILES.fx-libX11-h-guards=	${BUILDLINK_X11_DIR}/include/X11/Xlocale.h
SUBST_SED.fx-libX11-h-guards=	-e 's/ _XLOCALE_H_/ _X11_XLOCALE_H_/g'

.  endif # LIBX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libX11

.endif
