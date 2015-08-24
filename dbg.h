/*************************************************
 * author: Adrien Bodineau
 * github: codeOverFlow
 * License: GPL V2
 ************************************************/
#ifndef DBG_H
#define DBG_H
#include <errno.h>
#include <stdio.h>
#include <string.h>
#ifdef NDEBUG
#define debug(M,...)
#define var_val(V,F)
#define printbits(V,S)
#else
#define debug(M,...)fprintf(stderr,"DEBUG (%s:%d, %s): "M"\n",__FILE__,__LINE__,__func__,##__VA_ARGS__)
#define var_val(V,F)fprintf(stderr,"VALUE (%s:%d, %s): %s = "F"\n",__FILE__,__LINE__,__func__,#V,V)
#define printbits(V,S)for(int i=(S*8)-1;i>=0;i--){putchar('0'+((V>>i)&1));}printf("\t");
#endif
#define clean_errno()(errno==0?"NONE":strerror(errno))
#define check(P,L,M,...)if(!(P)){fprintf(stderr,"[ERROR] (%s:%d,%s --> errno: %s): "M"\n",__FILE__,__LINE__,__func__,clean_errno(),##__VA_ARGS__);errno=0;goto L;}
#endif
