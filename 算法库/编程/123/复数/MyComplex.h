#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MyMath.h"


void InputComplex(REAL *rp,REAL *ip);
void OutputComplex(REAL rp,REAL ip);
void AddComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip); 
void SubComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip);
void MulComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip);
void DivComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip);
