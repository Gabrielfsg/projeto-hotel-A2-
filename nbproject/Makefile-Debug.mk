#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AcomodacaoMenu.o \
	${OBJECTDIR}/CatAcomodMenu.o \
	${OBJECTDIR}/FornecedorMenu.o \
	${OBJECTDIR}/HospedeControl.o \
	${OBJECTDIR}/HospedeMenu.o \
	${OBJECTDIR}/HotelMenu.o \
	${OBJECTDIR}/Login.o \
	${OBJECTDIR}/OperadorMenu.o \
	${OBJECTDIR}/Principal.o \
	${OBJECTDIR}/ProdutoConsumoMenu.o \
	${OBJECTDIR}/ReservaControl.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2-.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2-.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2- ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AcomodacaoMenu.o: AcomodacaoMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AcomodacaoMenu.o AcomodacaoMenu.c

${OBJECTDIR}/CatAcomodMenu.o: CatAcomodMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CatAcomodMenu.o CatAcomodMenu.c

${OBJECTDIR}/FornecedorMenu.o: FornecedorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FornecedorMenu.o FornecedorMenu.c

${OBJECTDIR}/HospedeControl.o: HospedeControl.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeControl.o HospedeControl.c

${OBJECTDIR}/HospedeMenu.o: HospedeMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeMenu.o HospedeMenu.c

${OBJECTDIR}/HotelMenu.o: HotelMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HotelMenu.o HotelMenu.c

${OBJECTDIR}/Login.o: Login.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Login.o Login.c

${OBJECTDIR}/OperadorMenu.o: OperadorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorMenu.o OperadorMenu.c

${OBJECTDIR}/Principal.o: Principal.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Principal.o Principal.c

${OBJECTDIR}/ProdutoConsumoMenu.o: ProdutoConsumoMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProdutoConsumoMenu.o ProdutoConsumoMenu.c

${OBJECTDIR}/ReservaControl.o: ReservaControl.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReservaControl.o ReservaControl.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
