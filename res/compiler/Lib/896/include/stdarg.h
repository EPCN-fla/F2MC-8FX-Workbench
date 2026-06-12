/*	F2MC-8L/8FX Family C Library V30L14				*/
/*			COPYRIGHT(C) FUJITSU SEMICONDUCTOR LIMITED 1986	*/

#ifndef __STDARG_H__
#define __STDARG_H__

#if !defined(va_arg)
typedef	char	*va_list;

#define	va_start(ap,parmN) (ap=(va_list)&parmN+(((int)sizeof(parmN)+1)&~1))
#define	va_arg(ap, type)   (*(type *)((ap += (((int)sizeof(type)+1)&~1))\
-(((int)sizeof(type)+1)&~1)))
#define	va_end(ap)	((void)0)
#endif

#endif /* __STDARG_H__ */
