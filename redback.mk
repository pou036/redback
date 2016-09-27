#to create a library by copying after compile in the user files
#ADDITIONAL_LIBS := /usr/local/lib/myLib.dylib



#ifeq ($(COSSERAT_DYNLIB_EXISTS), 1)
#to compile it and add the path automatically using libtool
multisurfaceplasticityhard_DIR := $(HOME)/projects/cosserat_dynlib/DruckerPrager_friction3D
#multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/src/​file1.C
multisurfaceplasticityhard_srcfiles  += $(multisurfaceplasticityhard_DIR)/DruckerPrager_friction3D.f

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
								@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link \
								$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard_DIR)
								@$(libmesh_LIBTOOL) --mode=install install -c $(multisurfaceplasticityhard_LIB) $(multisurfaceplasticityhard_DIR)


$(app_EXEC): $(multisurfaceplasticityhard_LIB)
-include $(multisurfaceplasticityhard_deps)


clean​multisurfaceplasticityhard:
			@rm -f $(multisurfaceplasticityhard_objects)
			@rm -f $(multisurfaceplasticityhard_deps)
			@rm -f $(multisurfaceplasticityhard_LIB)
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard_DIR)/libmultisurfaceplasticityhard-$(METHOD)*.a



#to compile it and add the path automatically using libtool for the second library
multisurfaceplasticityhard1_DIR := $(HOME)/projects/cosserat_dynlib/DruckerPrager_friction2D

multisurfaceplasticityhard1_srcfiles  += $(multisurfaceplasticityhard1_DIR)/DruckerPrager_friction2D.f

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


#to compile it and add the path automatically using libtool for the third library
multisurfaceplasticityhard2_DIR := $(HOME)/projects/cosserat_dynlib/DeBorst_2D
multisurfaceplasticityhard2_srcfiles  += $(multisurfaceplasticityhard2_DIR)/DeBorst_2D.f

multisurfaceplasticityhard2_objects   := $(patsubst %.f, %.$(obj-suffix), $(multisurfaceplasticityhard2_srcfiles))
multisurfaceplasticityhard2_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(multisurfaceplasticityhard2_objects))
multisurfaceplasticityhard2_LIB       := $(multisurfaceplasticityhard2_DIR)/libmultisurfaceplasticityhard2-$(METHOD).la

app_INCLUDES += -I$(multisurfaceplasticityhard2_DIR)
app_LIBS += $(multisurfaceplasticityhard2_LIB)

#command in the case of a Fortran file 77
$(multisurfaceplasticityhard2_LIB): $(multisurfaceplasticityhard2_objects)
							@echo "Linking Library "$@"..."
							@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
							$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard2_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard2_DIR)
							@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard2_LIB) $(multisurfaceplasticityhard2_DIR)


$(app_EXEC): $(multisurfaceplasticityhard2_LIB)
-include $(multisurfaceplasticityhard2_deps)

clean​multisurfaceplasticityhard2:
			@rm -f $(multisurfaceplasticityhard2_objects)
			@rm -f $(multisurfaceplasticityhard2_deps)
			@rm -f $(multisurfaceplasticityhard2_LIB)
			@rm -f $(multisurfaceplasticityhard2_DIR)/libmultisurfaceplasticityhard2-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard2_DIR)/libmultisurfaceplasticityhard2-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard2_DIR)/libmultisurfaceplasticityhard2-$(METHOD)*.a

#to compile it and add the path automatically using libtool for the fourth library
multisurfaceplasticityhard3_DIR := $(HOME)/projects/cosserat_dynlib/DruckerPrager_cohesion3D
multisurfaceplasticityhard3_srcfiles  += $(multisurfaceplasticityhard3_DIR)/DruckerPrager_cohesion3D.f

multisurfaceplasticityhard3_objects   := $(patsubst %.f, %.$(obj-suffix), $(multisurfaceplasticityhard3_srcfiles))
multisurfaceplasticityhard3_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(multisurfaceplasticityhard3_objects))
multisurfaceplasticityhard3_LIB       := $(multisurfaceplasticityhard3_DIR)/libmultisurfaceplasticityhard3-$(METHOD).la

app_INCLUDES += -I$(multisurfaceplasticityhard3_DIR)
app_LIBS += $(multisurfaceplasticityhard3_LIB)

#command in the case of a Fortran file 77
$(multisurfaceplasticityhard3_LIB): $(multisurfaceplasticityhard3_objects)
							@echo "Linking Library "$@"..."
							@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
							$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard3_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard3_DIR)
							@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard3_LIB) $(multisurfaceplasticityhard3_DIR)


$(app_EXEC): $(multisurfaceplasticityhard3_LIB)
-include $(multisurfaceplasticityhard3_deps)

clean​multisurfaceplasticityhard3:
			@rm -f $(multisurfaceplasticityhard3_objects)
			@rm -f $(multisurfaceplasticityhard3_deps)
			@rm -f $(multisurfaceplasticityhard3_LIB)
			@rm -f $(multisurfaceplasticityhard3_DIR)/libmultisurfaceplasticityhard3-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard3_DIR)/libmultisurfaceplasticityhard3-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard3_DIR)/libmultisurfaceplasticityhard3-$(METHOD)*.a


			#to compile it and add the path automatically using libtool for the fifth library
multisurfaceplasticityhard4_DIR := $(HOME)/projects/cosserat_dynlib/DruckerPrager_cohesion2D
multisurfaceplasticityhard4_srcfiles  += $(multisurfaceplasticityhard4_DIR)/DruckerPrager_cohesion2D.f

multisurfaceplasticityhard4_objects   := $(patsubst %.f, %.$(obj-suffix), $(multisurfaceplasticityhard4_srcfiles))
multisurfaceplasticityhard4_deps      := $(patsubst %.$(obj-suffix), %.$(obj-suffix).d, $(multisurfaceplasticityhard4_objects))
multisurfaceplasticityhard4_LIB       := $(multisurfaceplasticityhard4_DIR)/libmultisurfaceplasticityhard4-$(METHOD).la

app_INCLUDES += -I$(multisurfaceplasticityhard4_DIR)
app_LIBS += $(multisurfaceplasticityhard4_LIB)

#command in the case of a Fortran file 77
$(multisurfaceplasticityhard4_LIB): $(multisurfaceplasticityhard4_objects)
							@echo "Linking Library "$@"..."
							@$(libmesh_LIBTOOL) --tag=F77 $(LIBTOOLFLAGS) --mode=link --quiet \
							$(libmesh_F77) $(libmesh_FFLAGS) -o $@ $(multisurfaceplasticityhard4_objects) $(libmesh_LDFLAGS) $(EXTERNAL_FLAGS) -rpath $(multisurfaceplasticityhard4_DIR)
							@$(libmesh_LIBTOOL) --mode=install --quiet install -c $(multisurfaceplasticityhard4_LIB) $(multisurfaceplasticityhard4_DIR)


$(app_EXEC): $(multisurfaceplasticityhard4_LIB)
-include $(multisurfaceplasticityhard4_deps)

clean​multisurfaceplasticityhard4:
			@rm -f $(multisurfaceplasticityhard4_objects)
			@rm -f $(multisurfaceplasticityhard4_deps)
			@rm -f $(multisurfaceplasticityhard4_LIB)
			@rm -f $(multisurfaceplasticityhard4_DIR)/libmultisurfaceplasticityhard4-$(METHOD)*.dylib
			@rm -f $(multisurfaceplasticityhard4_DIR)/libmultisurfaceplasticityhard4-$(METHOD)*.so
			@rm -f $(multisurfaceplasticityhard4_DIR)/libmultisurfaceplasticityhard4-$(METHOD)*.a


#endif  #COSSERAT_DYNLIB_EXISTS
