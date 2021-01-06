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
CND_PLATFORM=MinGW_QT-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AcomodacaoMenu.o \
	${OBJECTDIR}/CatAcomod.o \
	${OBJECTDIR}/CatAcomodMenu.o \
	${OBJECTDIR}/FornecedorMenu.o \
	${OBJECTDIR}/HospedeControl.o \
	${OBJECTDIR}/HospedeMenu.o \
	${OBJECTDIR}/HotelMenu.o \
	${OBJECTDIR}/Login.o \
	${OBJECTDIR}/Principal.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menuAcomodacoes.o \
	${OBJECTDIR}/menuCategoria.o \
	${OBJECTDIR}/menuHospedes.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AcomodacaoMenu.o: AcomodacaoMenu.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AcomodacaoMenu.o AcomodacaoMenu.c

${OBJECTDIR}/CatAcomod.o: CatAcomod.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CatAcomod.o CatAcomod.c

${OBJECTDIR}/CatAcomodMenu.o: CatAcomodMenu.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CatAcomodMenu.o CatAcomodMenu.c

${OBJECTDIR}/FornecedorMenu.o: FornecedorMenu.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FornecedorMenu.o FornecedorMenu.c

${OBJECTDIR}/HospedeControl.o: HospedeControl.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeControl.o HospedeControl.c

${OBJECTDIR}/HospedeMenu.o: HospedeMenu.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeMenu.o HospedeMenu.c

${OBJECTDIR}/HotelMenu.o: HotelMenu.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HotelMenu.o HotelMenu.c

${OBJECTDIR}/Login.o: Login.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Login.o Login.c

${OBJECTDIR}/Principal.o: Principal.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Principal.o Principal.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menuAcomodacoes.o: menuAcomodacoes.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menuAcomodacoes.o menuAcomodacoes.c

${OBJECTDIR}/menuCategoria.o: menuCategoria.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menuCategoria.o menuCategoria.c

${OBJECTDIR}/menuHospedes.o: menuHospedes.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menuHospedes.o menuHospedes.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
