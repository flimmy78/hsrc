# $NetBSD: Makefile,v 1.51 2018/06/18 06:47:03 adam Exp $

DISTNAME=	numpy-1.14.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.19:../../devel/py-cython

USE_LANGUAGES=		c fortran
MAKE_ENV+=		ATLAS=None

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95)
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mgfortran)
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+=	--fcompiler=gnu
.endif

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

.include "../../mk/bsd.prefs.mk"

# numpy fails using the gold linker with:
# fatal error: --sysroot=: must take a non-empty argument
# Work around it on DragonFly by specifying the classic gnu linker
MAKE_ENV.DragonFly+=	LDVER=ld.bfd

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

do-test:
	${RUN}cd ${WRKSRC};${PYTHONBIN} runtests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.if ${OPSYS} != "Darwin"
# blas and lapack are not needed; numpy will use Accelerate.framework
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
