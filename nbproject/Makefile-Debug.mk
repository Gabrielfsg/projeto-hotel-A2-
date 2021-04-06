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
	${OBJECTDIR}/Acomodacao.o \
	${OBJECTDIR}/AcomodacaoMenu.o \
	${OBJECTDIR}/AcomodacaoSUB.o \
	${OBJECTDIR}/Caixa.o \
	${OBJECTDIR}/Categoria.o \
	${OBJECTDIR}/CategoriaMenu.o \
	${OBJECTDIR}/CategoriaSUB.o \
	${OBJECTDIR}/CategoriaXML.o \
	${OBJECTDIR}/CheckIn.o \
	${OBJECTDIR}/CheckOut.o \
	${OBJECTDIR}/ContaPagar.o \
	${OBJECTDIR}/ContaReceber.o \
	${OBJECTDIR}/ContasMenu.o \
	${OBJECTDIR}/Data.o \
	${OBJECTDIR}/Endereco.o \
	${OBJECTDIR}/EntradaProdutos.o \
	${OBJECTDIR}/Fornecedor.o \
	${OBJECTDIR}/FornecedorMenu.o \
	${OBJECTDIR}/FornecedorSUB.o \
	${OBJECTDIR}/Hora.o \
	${OBJECTDIR}/Hospede.o \
	${OBJECTDIR}/HospedeMenu.o \
	${OBJECTDIR}/Hotel.o \
	${OBJECTDIR}/HotelMenu.o \
	${OBJECTDIR}/HotelSub.o \
	${OBJECTDIR}/Login.o \
	${OBJECTDIR}/MenuCaixa.o \
	${OBJECTDIR}/MenuCheckIn.o \
	${OBJECTDIR}/MenuCheckOut.o \
	${OBJECTDIR}/MenuEntradaProdutos.o \
	${OBJECTDIR}/MenuRelatorio.o \
	${OBJECTDIR}/OperadorMenu.o \
	${OBJECTDIR}/OperadorSistema.o \
	${OBJECTDIR}/OperadorSub.o \
	${OBJECTDIR}/Principal.o \
	${OBJECTDIR}/Produto.o \
	${OBJECTDIR}/ProdutoConsumoMenu.o \
	${OBJECTDIR}/ProdutoReserva.o \
	${OBJECTDIR}/Reserva.o \
	${OBJECTDIR}/ReservaMenu.o \
	${OBJECTDIR}/ReservaSubC.o \
	${OBJECTDIR}/ReservaSubCancel.o \
	${OBJECTDIR}/Retirada.o \
	${OBJECTDIR}/SalvamentoBD.o \
	${OBJECTDIR}/Tag.o \
	${OBJECTDIR}/Venda.o \
	${OBJECTDIR}/VendaProduto.o \
	${OBJECTDIR}/VendaProdutosMenu.o \
	${OBJECTDIR}/csvHospede.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menuXML.o \
	${OBJECTDIR}/xml.o


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
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Acomodacao.o Acomodacao.c

${OBJECTDIR}/AcomodacaoMenu.o: AcomodacaoMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AcomodacaoMenu.o AcomodacaoMenu.c

${OBJECTDIR}/AcomodacaoSUB.o: AcomodacaoSUB.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AcomodacaoSUB.o AcomodacaoSUB.c

${OBJECTDIR}/Caixa.o: Caixa.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Caixa.o Caixa.c

${OBJECTDIR}/Categoria.o: Categoria.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Categoria.o Categoria.c

${OBJECTDIR}/CategoriaMenu.o: CategoriaMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CategoriaMenu.o CategoriaMenu.c

${OBJECTDIR}/CategoriaSUB.o: CategoriaSUB.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CategoriaSUB.o CategoriaSUB.c

${OBJECTDIR}/CategoriaXML.o: CategoriaXML.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CategoriaXML.o CategoriaXML.c

${OBJECTDIR}/CheckIn.o: CheckIn.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CheckIn.o CheckIn.c

${OBJECTDIR}/CheckOut.o: CheckOut.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CheckOut.o CheckOut.c

${OBJECTDIR}/ContaPagar.o: ContaPagar.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContaPagar.o ContaPagar.c

${OBJECTDIR}/ContaReceber.o: ContaReceber.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContaReceber.o ContaReceber.c

${OBJECTDIR}/ContasMenu.o: ContasMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContasMenu.o ContasMenu.c

${OBJECTDIR}/Data.o: Data.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Data.o Data.c

${OBJECTDIR}/Endereco.o: Endereco.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Endereco.o Endereco.c

${OBJECTDIR}/EntradaProdutos.o: EntradaProdutos.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EntradaProdutos.o EntradaProdutos.c

${OBJECTDIR}/Fornecedor.o: Fornecedor.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fornecedor.o Fornecedor.c

${OBJECTDIR}/FornecedorMenu.o: FornecedorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FornecedorMenu.o FornecedorMenu.c

${OBJECTDIR}/FornecedorSUB.o: FornecedorSUB.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FornecedorSUB.o FornecedorSUB.c

${OBJECTDIR}/Hora.o: Hora.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hora.o Hora.c

${OBJECTDIR}/Hospede.o: Hospede.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hospede.o Hospede.c

${OBJECTDIR}/HospedeMenu.o: HospedeMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HospedeMenu.o HospedeMenu.c

${OBJECTDIR}/Hotel.o: Hotel.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hotel.o Hotel.c

${OBJECTDIR}/HotelMenu.o: HotelMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HotelMenu.o HotelMenu.c

${OBJECTDIR}/HotelSub.o: HotelSub.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HotelSub.o HotelSub.c

${OBJECTDIR}/Login.o: Login.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Login.o Login.c

${OBJECTDIR}/MenuCaixa.o: MenuCaixa.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuCaixa.o MenuCaixa.c

${OBJECTDIR}/MenuCheckIn.o: MenuCheckIn.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuCheckIn.o MenuCheckIn.c

${OBJECTDIR}/MenuCheckOut.o: MenuCheckOut.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuCheckOut.o MenuCheckOut.c

${OBJECTDIR}/MenuEntradaProdutos.o: MenuEntradaProdutos.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuEntradaProdutos.o MenuEntradaProdutos.c

${OBJECTDIR}/MenuRelatorio.o: MenuRelatorio.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuRelatorio.o MenuRelatorio.c

${OBJECTDIR}/OperadorMenu.o: OperadorMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorMenu.o OperadorMenu.c

${OBJECTDIR}/OperadorSistema.o: OperadorSistema.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorSistema.o OperadorSistema.c

${OBJECTDIR}/OperadorSub.o: OperadorSub.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperadorSub.o OperadorSub.c

${OBJECTDIR}/Principal.o: Principal.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Principal.o Principal.c

${OBJECTDIR}/Produto.o: Produto.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Produto.o Produto.c

${OBJECTDIR}/ProdutoConsumoMenu.o: ProdutoConsumoMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProdutoConsumoMenu.o ProdutoConsumoMenu.c

${OBJECTDIR}/ProdutoReserva.o: ProdutoReserva.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProdutoReserva.o ProdutoReserva.c

${OBJECTDIR}/Reserva.o: Reserva.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reserva.o Reserva.c

${OBJECTDIR}/ReservaMenu.o: ReservaMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReservaMenu.o ReservaMenu.c

${OBJECTDIR}/ReservaSubC.o: ReservaSubC.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReservaSubC.o ReservaSubC.c

${OBJECTDIR}/ReservaSubCancel.o: ReservaSubCancel.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReservaSubCancel.o ReservaSubCancel.c

${OBJECTDIR}/Retirada.o: Retirada.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Retirada.o Retirada.c

${OBJECTDIR}/SalvamentoBD.o: SalvamentoBD.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SalvamentoBD.o SalvamentoBD.c

${OBJECTDIR}/Tag.o: Tag.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tag.o Tag.c

${OBJECTDIR}/Venda.o: Venda.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Venda.o Venda.c

${OBJECTDIR}/VendaProduto.o: VendaProduto.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VendaProduto.o VendaProduto.c

${OBJECTDIR}/VendaProdutosMenu.o: VendaProdutosMenu.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VendaProdutosMenu.o VendaProdutosMenu.c

${OBJECTDIR}/csvHospede.o: csvHospede.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/csvHospede.o csvHospede.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menuXML.o: menuXML.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menuXML.o menuXML.c

${OBJECTDIR}/xml.o: xml.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/xml.o xml.c

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
