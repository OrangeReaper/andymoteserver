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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/clGetRemotesResponder.o \
	${OBJECTDIR}/clKeySeqResponder.o \
	${OBJECTDIR}/clListKeysResponder.o \
	${OBJECTDIR}/clReadMessage.o \
	${OBJECTDIR}/clServer.o \
	${OBJECTDIR}/clServerResponder.o \
	${OBJECTDIR}/clStartSending.o \
	${OBJECTDIR}/clStopSending.o \
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
LDLIBSOPTIONS=`pkg-config --libs lirc` -lboost_system -lboost_filesystem  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/andymote

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/andymote: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/andymote ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/clGetRemotesResponder.o: clGetRemotesResponder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clGetRemotesResponder.o clGetRemotesResponder.cpp

${OBJECTDIR}/clKeySeqResponder.o: clKeySeqResponder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clKeySeqResponder.o clKeySeqResponder.cpp

${OBJECTDIR}/clListKeysResponder.o: clListKeysResponder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clListKeysResponder.o clListKeysResponder.cpp

${OBJECTDIR}/clReadMessage.o: clReadMessage.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clReadMessage.o clReadMessage.cpp

${OBJECTDIR}/clServer.o: clServer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clServer.o clServer.cpp

${OBJECTDIR}/clServerResponder.o: clServerResponder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clServerResponder.o clServerResponder.cpp

${OBJECTDIR}/clStartSending.o: clStartSending.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clStartSending.o clStartSending.cpp

${OBJECTDIR}/clStopSending.o: clStopSending.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clStopSending.o clStopSending.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/lirc -I/usr/include/boost `pkg-config --cflags lirc` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
