/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include	<stddef.h>

#if !defined(EXIT_FAILURE)
#define	EXIT_FAILURE	-1
#define	EXIT_SUCCESS	0
#endif

typedef	struct {
	int	quot;
	int	rem;
} div_t;

typedef	struct {
	long int	quot;
	long int	rem;
} ldiv_t;

#define	RAND_MAX	0x7fff

#define	abort()	_abort()

extern double	atof(const char*);
extern int	atoi(const char*);
extern long int	atol(const char*);
extern double	strtod(const char*, char **);
extern long int	strtol(const char*, char **, int);
extern unsigned long int strtoul(const char *, char **, int);
extern int	rand(void);
extern void	srand(unsigned int);
extern void	*calloc(size_t, size_t);
extern void	free(void*);
extern void	*malloc(size_t);
extern void	*realloc(void*, size_t);
extern void	_abort(void);
extern int	atexit(void(*)(void));
extern void	exit(int);
extern void	*bsearch(const void*, const void *, size_t, size_t,
			 int(*)(const void *, const void *));
extern void	qsort(void *, size_t, size_t,
			 int (*)(const void *, const void *));
extern int	abs(int);
extern div_t	div(int, int);
extern long int	labs(long int);
extern ldiv_t	ldiv(long int, long int);

#endif /* __STDLIB_H__ */
