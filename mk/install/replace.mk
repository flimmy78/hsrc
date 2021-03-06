# $NetBSD: replace.mk,v 1.18 2016/04/10 15:58:02 joerg Exp $
#
# Public targets:
#
# replace:
#	Updates a package in-place on the system.
#	It will acquire elevated privileges just-in-time.
#
# undo-replace:
#	Undoes the effects of a previous "make replace".
#	It will acquire elevated privileges just-in-time.
#
#
# Private targets that must be defined by the package system format:
#
# _pkgformat-destdir-replace:
#	Updates a package in-place on the system.
#
# _pkgformat-undo-replace:
#	Undoes a previous "make _pkgformat-replace".

# _pkgformat-destdir-undo-replace:
#	Undoes a previous "make _pkgformat-destdir-replace".

_PRE_REPLACE_TARGETS+=	stage-package-create
_PRE_REPLACE_TARGETS+=	replace-message
_PRE_REPLACE_TARGETS+=	unprivileged-install-hook
.if ${_CREATE_BIN_PKGS} == "yes"
_POST_REPLACE_TARGETS+=	package
.endif

#
# replace
#

.PHONY: replace
.if defined(_PKGSRC_BARRIER)
replace: ${_PRE_REPLACE_TARGETS} su-target ${_POST_REPLACE_TARGETS}
.else
replace: barrier
.endif

replace-message: .PHONY
	@${PHASE_MSG} "Replacing for ${PKGNAME}"

su-replace: .PHONY _pkgformat-destdir-replace
MAKEFLAGS.su-replace=	_UPDATE_RUNNING=yes
MAKEFLAGS.su-replace+=	PKGNAME_REQD=${PKGNAME_REQD:Q}

#
# undo-replace
#

undo-replace: .PHONY undo-replace-message su-target

undo-replace-message: .PHONY
	@${PHASE_MSG} "Undoing replacement for ${PKGNAME}"
	@${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-undo-replace: .PHONY _pkgformat-destdir-undo-replace
MAKEFLAGS.su-undo-replace=	_UPDATE_RUNNING=yes
