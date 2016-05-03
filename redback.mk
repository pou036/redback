#to create a library by copying after compile in the user files
#ADDITIONAL_LIBS := /usr/local/lib/myLib.dylib

#to compile it and add the path automatically using libtool
multisurfaceplasticityhard_DIR := $(HOME)/projects/cosserat_dynlib/druckerPrager3D_frictionHard
#multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/src/​file1.C
multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/druckerPrager3D_frictionHard.f

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

#$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
#								@echo "Linking Library "$@"..."
#								@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
#								$(libmesh_F90) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
#								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)

#command in the case of a Fortran file 90
#$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
#		@echo "Linking Library "$@"..."
#		@$(libmesh_LIBTOOL) --tag=FC $(LIBTOOLFLAGS) --mode=link --quiet \
#		$(libmesh_F90 $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
#		@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)

#command in the case of a Fortran file 77
$(multisurfaceplasticityhard_LIB): $(multisurfaceplasticityhard_objects)
								@echo "Linking Library "$@"..."
								@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
								$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
								@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)


$(app_EXEC): $(multisurfaceplasticityhard_LIB)
-include $(multisurfaceplasticityhard_deps)

clean​multisurfaceplasticityhard:
			@rm -f $(multisurfaceplasticityhard_objects)
			@rm -f $(multisurfaceplasticityhard_deps)
			@rm -f $(multisurfaceplasticityhard_LIB)
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.a



#to compile it and add the path automatically using libtool
multisurfaceplasticityhard1_DIR := $(HOME)/projects/cosserat_dynlib/druckerPrager3d_frictionHard_adim

multisurfaceplasticityhard1_srcfiles  += $(multisurfaceplasticityhard1_DIR)/druckerPrager3d_frictionHard_adim.f

multisurfaceplasticityhard1_objects   := $(patsubst %.f, %.$(obj-suffix), $(multisurfaceplasticityhard1_srcfiles))
multisurfaceplasticityhard1_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(multisurfaceplasticityhard1_objects))
multisurfaceplasticityhard1_LIB       := $(multisurfaceplasticityhard1_DIR)/libmultisurfaceplasticityhard1-$(METHOD).la

app_INCLUDES += -I$(multisurfaceplasticityhard1_DIR)
app_LIBS += $(multisurfaceplasticityhard1_LIB)

#command in the case of a Fortran file 77
$(multisurfaceplasticityhard1_LIB): $(multisurfaceplasticityhard1_objects)
							@echo "Linking Library "$@"..."
							@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
							$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard1_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard1_DIR)
							@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard1_LIB) $(multisurfaceplasticityhard1_DIR)


$(app_EXEC): $(multisurfaceplasticityhard1_LIB)
-include $(multisurfaceplasticityhard1_deps)

clean​multisurfaceplasticityhard1:
			@rm -f $(multisurfaceplasticityhard1_objects)
			@rm -f $(multisurfaceplasticityhard1_deps)
			@rm -f $(multisurfaceplasticityhard1_LIB)
			@rm -f $(multisurfaceplasticityhard1_DIR)/libmultisurfaceplasticityhard1-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard1_DIR)/libmultisurfaceplasticityhard1-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard1_DIR)/libmultisurfaceplasticityhard1-$(METHOD)*.a
