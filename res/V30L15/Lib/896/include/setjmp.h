/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __SETJMP_H__
#define __SETJMP_H__

typedef int	jmp_buf[6];

#define	setjmp(env)	_setjmp(env)

extern	void	longjmp(jmp_buf, int);
extern	int	_setjmp(jmp_buf);

#endif /* __SETJMP_H__ */
