#to create a library by copying after compile in the user files
#ADDITIONAL_LIBS := /usr/local/lib/myLib.dylib

#to compile it and add the path automatically using libtool
multisurfaceplasticityhard_DIR := $(HOME)/projects/dynamic-cosserat-library/hardFric_nonAsso_Tsoft
#multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/src/​file1.C
multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/multisurfaceplasticityhard.f

#multisurfaceplasticityhard_objects   := $(patsubst %.f90, %.$(obj-suffix), $(multisurfaceplasticityhard_srcfiles))
multisurfaceplasticityhard_objects   := $(patsubst %.f, %.$(obj-suffix), $(multisurfaceplasticityhard_srcfiles))
multisurfaceplasticityhard_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(multisurfaceplasticityhard_objects))
multisurfaceplasticityhard_LIB       := $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD).la

app_INCLUDES += -I$(multisurfaceplasticityhard_DIR)
app_LIBS += $(multisurfaceplasticityhard_LIB)

#command in the case of a C++ file
#$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
#				@echo "Linking Library "$@"..."
#				@$(libmesh_LIBTOOL) --tag=CC $(LIBTOOLFLAGS) --mode=link --quiet \
#				$(libmesh_CC) $(libmesh_CFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
#				@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)

$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
								@echo "Linking Library "$@"..."
								@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
								$(libmesh_F90) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)

#command in the case of a Fortran file 90
#$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
#		@echo "Linking Library "$@"..."
#		@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
#		$(libmesh_F90 $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
#		@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)

#command in the case of a Fortran file 77
#$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
#								@echo "Linking Library "$@"..."
#								@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
#								$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
#								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)


$(app_EXEC): $(multisurfaceplasticityhard_LIB)
-include $(multisurfaceplasticityhard_deps)

clean​multisurfaceplasticityhard:
			@rm -f $(multisurfaceplasticityhard_objects)
			@rm -f $(multisurfaceplasticityhard_deps)
			@rm -f $(multisurfaceplasticityhard_LIB)
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.a
