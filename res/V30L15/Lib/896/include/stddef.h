/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __STDDEF_H__
#define __STDDEF_H__

#if !defined(_STDDEF_)
#define	_STDDEF_

typedef long	ptrdiff_t;

#define	NULL	((void*)0)
typedef	unsigned int	size_t;

#define	offsetof(type,member) ((size_t)(&((type*)0)->member))
#endif

#endif /* __STDDEF_H__ */
