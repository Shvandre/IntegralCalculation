#pragma once

#ifdef TEST
#include "TestFunctions.h"
#endif

__attribute__ ((cdecl))
double f1(double x);

__attribute__ ((cdecl))
double f1_deriv(double x);

__attribute__ ((cdecl))
double f2(double x);

__attribute__ ((cdecl))
double f2_deriv(double x);

__attribute__ ((cdecl))
double f3(double x);

__attribute__ ((cdecl))
double f3_deriv(double x);