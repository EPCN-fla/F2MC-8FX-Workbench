/*	F2MC-8L/8FX Family C Library V30L14				*/
/*			COPYRIGHT(C) FUJITSU SEMICONDUCTOR LIMITED 1986	*/

#ifndef __STDIO_H__
#define __STDIO_H__

#include	<stddef.h>
#include	<stdarg.h>

typedef struct {
    int	info1;
} _PTRFILE;


#define	BUFSIZ		512

extern int	sprintf(char*, const char*, ...);
extern int	sscanf(const char*, const char*, ...);
extern int	vsprintf(char*, const char*, va_list);

extern _PTRFILE *_ptr_file;

#endif /* __STDIO_H__ */
