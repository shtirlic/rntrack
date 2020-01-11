/*
 *  SMAPI; Modified Squish MSGAPI
 *
 *  Squish MSGAPI0 is copyright 1991 by Scott J. Dudley.  All rights reserved.
 *  Modifications released to the public domain.
 *
 *  Use of this file is subject to the restrictions contain in the Squish
 *  MSGAPI0 licence agreement.  Please refer to licence.txt for complete
 *  details of the licencing restrictions.  If you do not find the text
 *  of this agreement in licence.txt, or if you do not have this file,
 *  you should contact Scott Dudley at FidoNet node 1:249/106 or Internet
 *  e-mail Scott.Dudley@f106.n249.z1.fidonet.org.
 *
 *  In no event should you proceed to use any of the source files in this
 *  archive without having accepted the terms of the MSGAPI0 licensing
 *  agreement, or such other agreement as you are able to reach with the
 *  author.
 */

#ifndef __PROGPROT_H__
#define __PROGPROT_H__

#include <stdio.h>
#include <time.h>

#include "compiler.h"
#include "stamp.h"

/*#if !( (defined(__WATCOMC__) && !defined(__DOS__)) || defined(__MSVC__) )*/
#ifdef __DOS__
void pascal far flush_handle2(int fd);  /* flushasm.asm for DOS, redefined for known implementations in flush.c */
#endif

void _fast flush_handle(FILE * fp);
SMAPI_EXT int _fast fexist(const char *filename);
SMAPI_EXT long _fast fsize(const char *filename);
char *_fast firstchar(char *strng, char *delim, int findword);
char *_fast stristr(char *string, char *search);
void _fast qksort(int a[], size_t n);
SMAPI_EXT int _fast direxist(const char *directory);
SMAPI_EXT void _fast ASCII_Date_To_Binary(char *msgdate, union stamp_combo *d_written);
union stamp_combo *_fast Get_Dos_Date(union stamp_combo *st);
SMAPI_EXT struct tm *_fast DosDate_to_TmDate(union stamp_combo *dosdate, struct tm *tmdate);
SMAPI_EXT union stamp_combo *_fast TmDate_to_DosDate(struct tm *tmdate, union stamp_combo *dosdate);
SMAPI_EXT char *_fast Strip_Trailing(char *str, char strip);
SMAPI_EXT char *_fast Add_Trailing(char *str, char add);
void _fast Parse_NetNode(char *netnode, word * zone, word * net, word * node, word * point);
void _fast ParseNN(char *netnode, word * zone, word * net, word * node, word * point, word all);
SMAPI_EXT char *_fast sc_time(union stamp_combo *sc, char *string);
SMAPI_EXT char *_fast fts_time(char *string, struct tm *tmdate);
char *_fast strocpy(char *d, char *s);
void _fast tdelay(int);
SMAPI_EXT int _fast setfsize(int fd, long size);
#ifdef __LITTLE_ENDIAN__

#define put_dword(ptr, val)	(*(dword *)(ptr) = (val))
#define put_word(ptr, val)	(*(word *)(ptr) = (val))
#define get_dword(ptr)		(*(dword *)(ptr))
#define get_word(ptr)		(*(word *)(ptr))

#else

SMAPI_EXT void put_word(byte *ptr, word value);      /* structrw.c */
SMAPI_EXT void put_dword(byte *ptr, dword value);    /* structrw.c */
/*
 *  get_dword
 *
 *  Reads in a 4 byte word that is stored in little endian (Intel) notation
 *  and converts it to the local representation n an architecture-
 *  independent manner
 */

#define get_dword(ptr)            \
   ((dword)((unsigned char)(ptr)[0]) |           \
    (((dword)((unsigned char)(ptr)[1])) << 8)  | \
    (((dword)((unsigned char)(ptr)[2])) << 16) | \
    (((dword)((unsigned char)(ptr)[3])) << 24))  \

/*
 *  get_word
 *
 *  Reads in a 2 byte word that is stored in little endian (Intel) notation
 *  and converts it to the local representation in an architecture-
 *  independent manner
 */

#define get_word(ptr)         \
    ((word)((unsigned char)(ptr)[0]) |         \
     (((word)((unsigned char)(ptr)[1])) << 8 ))

#endif /* __LITTLE_ENDIAN__ */

SMAPI_EXT int  _createDirectoryTree(const char *pathName);
/*DOC
  Input:  a pointer to a \0 terminated string
  Output: 0 if successfull, 1 else
  FZ:     pathName is a correct directory name
          createDirectoryTree creates the directory and all parental directories
          if they do not exist.

  was taken from hpt\fcommon
*/

#endif
