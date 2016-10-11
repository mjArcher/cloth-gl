# "all" is name of the default target, running "make" without params would use it
all: run

# for C++, replace CC (c compiler) with CXX (c++ compiler) which is used as default linker
CC=./src/$(CXX)
OBJDIR=./objects

# tell which files should be used, .cpp -> .o make would do automatically
executable1: ${OBJDIR}/.o ${OBJDIR}/o
