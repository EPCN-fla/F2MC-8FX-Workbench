/*	F2MC-8L/8FX Family C Library V30L15				*/
/*	(c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014	*/

#ifndef __CTYPE_H__
#define __CTYPE_H__

extern const unsigned char _ctable[];

#define	_CUPPER		0x80
#define	_CLOWER		0x40
#define	_CDIGIT		0x20
#define	_CHEX		0x10
#define	_CCTRL		0x08
#define	_CSPACE		0x04
#define	_CPUNCT		0x02
#define	_CSP		0x01
#define	_CALNUM		0xe0
#define	_CALPHA		0xc0
#define	_CGRAPH		0xe2
#define	_CPRINT		0xe3
#define	_CXDIGIT	0x30

extern int	isalnum( int);
extern int	isalpha( int);
extern int	iscntrl( int);
extern int	isdigit( int);
extern int	isgraph( int);
extern int	islower( int);
extern int	isprint( int);
extern int	ispunct( int);
extern int	isspace( int);
extern int	isupper( int);
extern int	isxdigit( int);
extern int	tolower( int);
extern int	toupper( int);

#define	isalnum(c)	(_ctable[(c)+1] & _CALNUM)
#define	isalpha(c)	(_ctable[(c)+1] & _CALPHA)
#define	iscntrl(c)	(_ctable[(c)+1] & _CCTRL)
#define	isdigit(c)	(_ctable[(c)+1] & _CDIGIT)
#define	isgraph(c)	(_ctable[(c)+1] & _CGRAPH)
#define	islower(c)	(_ctable[(c)+1] & _CLOWER)
#define	isprint(c)	(_ctable[(c)+1] & _CPRINT)
#define	ispunct(c)	(_ctable[(c)+1] & _CPUNCT)
#define	isspace(c)	(_ctable[(c)+1] & _CSPACE)
#define	isupper(c)	(_ctable[(c)+1] & _CUPPER)
#define	isxdigit(c)	(_ctable[(c)+1] & _CXDIGIT)
#define	tolower(c)	(isupper(c)?(c)-'A'+'a':(c))
#define	toupper(c)	(islower(c)?(c)-'a'+'A':(c))

#endif /* __CTYPE_H__ */
