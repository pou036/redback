#ifdef __cplusplus
extern "C"
{
#endif

extern "C" void usermat_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

extern "C" void usermat1_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

extern "C" void usermat2_(Real *STRESSF,Real *DEFORT,Real *DSDE,int *NSTR,Real *PROPS,int *NPROPS,Real *SVARSGP,int *NSVARSGP,int *NILL);

#ifdef __cplusplus
}
#endif
