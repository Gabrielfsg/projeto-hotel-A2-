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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Acomodacao.o \
	${OBJECTDIR}/AcomodacaoMenu.o \
	${OBJECTDIR}/Caixa.o \
	${OBJECTDIR}/CatAcomod.o \
	${OBJECTDIR}/CatAcomodMenu.o \
	${OBJECTDIR}/Categoria.o \
	${OBJECTDIR}/CheckIn.o \
	${OBJECTDIR}/CheckOut.o \
	${OBJECTDIR}/CheckOutProduto.o \
	${OBJECTDIR}/ContaPagar.o \
	${OBJECTDIR}/ContaReceber.o \
	${OBJECTDIR}/Data.o \
	${OBJECTDIR}/Endereco.o \
	${OBJECTDIR}/Fornecedor.o \
	${OBJECTDIR}/FornecedorMenu.o \
	${OBJECTDIR}/Hora.o \
	${OBJECTDIR}/Hospede.o \
	${OBJECTDIR}/HospedeControl.o \
	${OBJECTDIR}/HospedeMenu.o \
	${OBJECTDIR}/Hotel.o \
	${OBJECTDIR}/HotelMenu.o \
	${OBJECTDIR}/Login.o \
	${OBJECTDIR}/OperadorMenu.o \
	${OBJECTDIR}/OperadorSistema.o \
	${OBJECTDIR}/Principal.o \
	${OBJECTDIR}/Produto.o \
	${OBJECTDIR}/Reserva.o \
	${OBJECTDIR}/Retirada.o \
	${OBJECTDIR}/Venda.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2-.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2-.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto-hotel-a2- ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Acomodacao.o: Acomodacao.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Acomodacao.o Acomodacao.c

${OBJECTDIR}/AcomodacaoMenu.o: AcomodacaoMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AcomodacaoMenu.o AcomodacaoMenu.c

${OBJECTDIR}/Caixa.o: Caixa.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Caixa.o Caixa.c

${OBJECTDIR}/CatAcomod.o: CatAcomod.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CatAcomod.o CatAcomod.c

${OBJECTDIR}/CatAcomodMenu.o: CatAcomodMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CatAcomodMenu.o CatAcomodMenu.c

${OBJECTDIR}/Categoria.o: Categoria.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Categoria.o Categoria.c

${OBJECTDIR}/CheckIn.o: CheckIn.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CheckIn.o CheckIn.c

${OBJECTDIR}/CheckOut.o: CheckOut.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CheckOut.o CheckOut.c

${OBJECTDIR}/CheckOutProduto.o: CheckOutProduto.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CheckOutProduto.o CheckOutProduto.c

${OBJECTDIR}/ContaPagar.o: ContaPagar.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContaPagar.o ContaPagar.c

${OBJECTDIR}/ContaReceber.o: ContaReceber.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContaReceber.o ContaReceber.c

${OBJECTDIR}/Data.o: Data.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Data.o Data.c

${OBJECTDIR}/Endereco.o: Endereco.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Endereco.o Endereco.c

${OBJECTDIR}/Fornecedor.o: Fornecedor.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fornecedor.o Fornecedor.c

${OBJECTDIR}/FornecedorMenu.o: FornecedorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FornecedorMenu.o FornecedorMenu.c

${OBJECTDIR}/Hora.o: Hora.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hora.o Hora.c

${OBJECTDIR}/Hospede.o: Hospede.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hospede.o Hospede.c

${OBJECTDIR}/HospedeControl.o: HospedeControl.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeControl.o HospedeControl.c

${OBJECTDIR}/HospedeMenu.o: HospedeMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeMenu.o HospedeMenu.c

${OBJECTDIR}/Hotel.o: Hotel.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hotel.o Hotel.c

${OBJECTDIR}/HotelMenu.o: HotelMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HotelMenu.o HotelMenu.c

${OBJECTDIR}/Login.o: Login.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Login.o Login.c

${OBJECTDIR}/OperadorMenu.o: OperadorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorMenu.o OperadorMenu.c

${OBJECTDIR}/OperadorSistema.o: OperadorSistema.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorSistema.o OperadorSistema.c

${OBJECTDIR}/Principal.o: Principal.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Principal.o Principal.c

${OBJECTDIR}/Produto.o: Produto.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Produto.o Produto.c

${OBJECTDIR}/Reserva.o: Reserva.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reserva.o Reserva.c

${OBJECTDIR}/Retirada.o: Retirada.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Retirada.o Retirada.c

${OBJECTDIR}/Venda.o: Venda.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Venda.o Venda.c

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

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
