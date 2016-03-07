#to create a library by copying after compile in the user files
#ADDITIONAL_LIBS := /usr/local/lib/myLib.dylib

#to compile it and add the path automatically using libtool
hadrienelasticity_DIR := /Users/pou036/projects/ioannis
#hadrienelasticity_srcfiles  += $(hadrienelasticity_DIR)/src/​file1.C
hadrienelasticity_srcfiles  += $(hadrienelasticity_DIR)/hadrienelasticity.f

#hadrienelasticity_objects   := $(patsubst %.f90, %.$(obj-suffix), $(hadrienelasticity_srcfiles))
hadrienelasticity_objects   := $(patsubst %.f, %.$(obj-suffix), $(hadrienelasticity_srcfiles))
hadrienelasticity_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(hadrienelasticity_objects))
hadrienelasticity_LIB       := $(hadrienelasticity_DIR)/libhadrienelasticity-$(METHOD).la

app_INCLUDES += -I$(hadrienelasticity_DIR)/src
app_LIBS += $(hadrienelasticity_LIB)

#command in the case of a C++ file
#$(hadrienelasticity_LIB): $(hadrienelasticity_objects)
#				@echo "Linking Library "$@"..."
#				@$(libmesh_LIBTOOL) --tag=CC $(LIBTOOLFLAGS) --mode=link --quiet \
#				$(libmesh_CC) $(libmesh_CFLAGS) -o $@ $(hadrienelasticity_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(hadrienelasticity_DIR)
#				@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(hadrienelasticity_LIB) $(hadrienelasticity_DIR)

$(hadrienelasticity_LIB): $(hadrienelasticity_objects)
								@echo "Linking Library "$@"..."
								@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
								$(libmesh_F90) $(libmesh_FFLAGS) -o $@ $(hadrienelasticity_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(hadrienelasticity_DIR)
								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(hadrienelasticity_LIB) $(hadrienelasticity_DIR)

#command in the case of a Fortran file 90
#$(hadrienelasticity_LIB): $(hadrienelasticity_objects)
#		@echo "Linking Library "$@"..."
#		@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
#		$(libmesh_F90 $(libmesh_FFLAGS) -o $@ $(hadrienelasticity_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(hadrienelasticity_DIR)
#		@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(hadrienelasticity_LIB) $(hadrienelasticity_DIR)

#command in the case of a Fortran file 77
#$(hadrienelasticity_LIB): $(hadrienelasticity_objects)
#								@echo "Linking Library "$@"..."
#								@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
#								$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(hadrienelasticity_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(hadrienelasticity_DIR)
#								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(hadrienelasticity_LIB) $(hadrienelasticity_DIR)


$(app_EXEC): $(hadrienelasticity_LIB)
-include $(hadrienelasticity_deps)

clean​hadrienelasticity:
			@rm -f $(hadrienelasticity_objects)
			@rm -f $(hadrienelasticity_deps)
			@rm -f $(hadrienelasticity_LIB)
			@rm -f $(hadrienelasticity_DIR)/libhadrienelasticity-$(METHOD)*.dylib
			@rm -f $(hadrienelasticity_DIR)/libhadrienelasticity-$(METHOD)*.so
			@rm -f $(hadrienelasticity_DIR)/libhadrienelasticity-$(METHOD)*.a
