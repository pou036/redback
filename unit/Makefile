###############################################################################
################### MOOSE Application Standard Makefile #######################
###############################################################################
#
# Required Environment variables (one of the following)
# PACKAGE_DIR   - Location of the MOOSE redistributable package 
# CPPUNIT_DIR   - Location of CPPUNIT
#
# Optional Environment variables
# MOOSE_DIR     - Root directory of the MOOSE project 
# FRAMEWORK_DIR - Location of the MOOSE framework
#
###############################################################################
MOOSE_DIR          ?= $(shell dirname `pwd`)/moose
HERD_TRUNK_DIR     ?= $(shell dirname `pwd`)
FRAMEWORK_DIR      ?= $(MOOSE_DIR)/framework
PACKAGES_DIR       ?= /opt/moose
CPPUNIT_DIR        ?= $(PACKAGES_DIR)/cppunit-1.12.1
###############################################################################

# Extra stuff for CPPUNIT
ADDITIONAL_INCLUDES 	:= -I$(CPPUNIT_DIR)/include
ADDITIONAL_LIBS 	:= -L$(CPPUNIT_DIR)/lib -lcppunit 

# framework
include $(FRAMEWORK_DIR)/build.mk
include $(FRAMEWORK_DIR)/moose.mk

################################## MODULES ####################################
SOLID_MECHANICS   := yes
TENSOR_MECHANICS  := yes
include           $(MOOSE_DIR)/modules/modules.mk
###############################################################################

APPLICATION_DIR := $(MOOSE_DIR)/unit
APPLICATION_NAME := moose_unit
BUILD_EXEC       := yes
DEP_APPS    ?= $(shell $(FRAMEWORK_DIR)/scripts/find_dep_apps.py $(APPLICATION_NAME))
include $(FRAMEWORK_DIR)/app.mk

# Find all the MOOSE unit test source files and include their dependencies.
moose_unit_srcfiles := $(shell find $(MOOSE_DIR)/unit -name "*.C")
moose_unit_deps := $(patsubst %.C, %.$(obj-suffix).d, $(moose_unit_srcfiles))
-include $(moose_unit_deps)

###############################################################################
# Additional special case targets should be added here
