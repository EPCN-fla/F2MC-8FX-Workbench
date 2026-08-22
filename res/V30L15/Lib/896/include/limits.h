/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __LIMITS_H__
#define __LIMITS_H__

#define	MB_LEN_MAX	  1
#define	CHAR_BIT	  8
#define	SCHAR_MIN	(-SCHAR_MAX-1)
#define	SCHAR_MAX	127
#define	UCHAR_MAX	255
#ifndef __SCHAR__
#define	CHAR_MIN	0
#define	CHAR_MAX	UCHAR_MAX
#else
#define	CHAR_MIN	SCHAR_MIN
#define	CHAR_MAX	SCHAR_MAX
#endif
#define	INT_MIN		(-INT_MAX-1)
#define	INT_MAX		32767
#define	UINT_MAX	65535U
#define	SHRT_MIN	(-SHRT_MAX-1)
#define	SHRT_MAX	32767
#define	USHRT_MAX	65535U
#define	LONG_MIN	(-LONG_MAX-1)
#define	LONG_MAX	2147483647L
#define	ULONG_MAX	4294967295UL

#endif /* __LIMITS_H__ */
