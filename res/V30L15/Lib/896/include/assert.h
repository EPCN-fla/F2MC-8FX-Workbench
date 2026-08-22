/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifdef  __ASSERT_H__
#undef  __ASSERT_H__
#undef  assert
#endif

#ifndef __ASSERT_H__
#define __ASSERT_H__

extern void	_assert(int, char *, char *,int );
#if defined(NDEBUG)
#define	assert( ignore )	((void)0)
#else
#define	assert( exp )		_assert( exp, # exp,__FILE__,__LINE__)
#endif

#endif /* __ASSERT_H__ */
