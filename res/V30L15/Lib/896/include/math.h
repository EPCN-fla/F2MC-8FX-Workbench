/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __MATH_H__
#define __MATH_H__

#include <errno.h>

extern	double const	_huge_val;

#define	HUGE_VAL	_huge_val

extern	double	acos( double);
extern	double	asin( double);
extern	double	atan( double);
extern	double	atan2( double, double);
extern	double	cos( double);
extern	double	sin( double);
extern	double	tan( double);
extern	double	cosh( double);
extern	double	sinh( double);
extern	double	tanh( double);
extern	double	exp( double);
extern	double	frexp( double, int *);
extern	double	ldexp( double, int);
extern	double	log( double);
extern	double	log10( double);
extern	double	modf( double, double *);
extern	double	pow( double, double);
extern	double	sqrt( double);
extern	double	ceil( double);
extern	double	fabs( double);
extern	double	floor( double);
extern	double	fmod( double, double);

#endif /* __MATH_H__ */
