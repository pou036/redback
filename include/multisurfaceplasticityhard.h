#ifdef __cplusplus
extern "C"
{
#endif

extern "C" int usermat_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

extern "C" int usermat1_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

extern "C" int usermat2_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

#ifdef __cplusplus
}
#endif
