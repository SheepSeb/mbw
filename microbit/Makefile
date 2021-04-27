# Makefile for user application

# Specify this directory relative to the current application.
TOCK_USERLAND_BASE_DIR = 

# Which files to compile.
C_SRCS := $(wildcard *.c)

# External libraries used
EXTERN_LIBS += simple-ble

# Include userland master makefile. Contains rules and flags for actually
# building the application.
include AppMakefile.mk

# Include simple-ble's Makefile so it's rebuilt automatically
include simple-ble/Makefile