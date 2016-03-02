#ADDITIONAL_LIBS := /Users/pou036/projects/dynamicLib/redback/.libs/myLib.dylib
#app_INCLUDES += -l /Users/pou036/projects/redback/.libs
#app_INCLUDES += -L/Users/pou036/projects/redback/.libs -myLib

#ADDITIONAL_LIBS := /usr/local/lib/myLib.dylib
#ADDITIONAL_LIBS := /usr/local/lib/myLibech.dylib
#
#include path for the header's folder
#app_INCLUDES += -I/Users/pou036/projects/dynamicLib/
#library name
#app_INCLUDES += -l/Users/pou036/projects/dynamicLib/myLib.dylib
#library-paths for libraries' folder
#app_INCLUDES += -L/usr/local/lib/myLib -lmyLib
myLibech_DIR := /Users/pou036/projects/echdyn/

​myLibech_srcfiles  :=
myLibech_srcfiles  += $(myLibech_DIR)/myLibech.C
#myLibech_srcfiles  += $(myLibech_DIR)/src/​file2.C

myLibech_objects   := $(patsubst %.C, %.$(obj-suffix), $(myLibech_srcfiles))
myLibech_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(myLibech_objects))
myLibech_LIB       := $(myLibech_DIR)/libmyLibech-$(METHOD).la

app_INCLUDES += -I$(myLibech_DIR)/src
app_LIBS += $(myLibech_LIB)

$(myLibech_LIB): $(myLibech_objects)
			@echo "Linking Library "$@"..."
			@$(libmesh_LIBTOOL) --tag=CC $(LIBTOOLFLAGS) --mode=link --quiet \
			$(libmesh_CC) $(libmesh_CFLAGS) -o $@ $(myLibech_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(myLibech_DIR)
			@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(myLibech_LIB) $(myLibech_DIR)

$(app_EXEC): $(myLibech_LIB)
-include $(myLibech_deps)

clean​myLibech:
			@rm -f $(myLibech_objects)
			@rm -f $(myLibech_deps)
			@rm -f $(myLibech_LIB)
			@rm -f $(myLibech_DIR)/libmyLibech-$(METHOD)*.dylib
			@rm -f $(myLibech_DIR)/libmyLibech-$(METHOD)*.so*
			@rm -f $(myLibech_DIR)/libmyLibech-$(METHOD)*.a
