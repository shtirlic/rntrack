/* $Id$
 *  Turbo C and Borland C for Windows95/NT compiler-specific declarations
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; see file COPYING. If not, write to the
 * Free Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * See also http://www.gnu.org, license may be found here.
 */

/* Borland C/C++ for Win32 */

#ifndef SMAPI_BCW_H
#define SMAPI_BCW_H


#ifndef __TURBOC__
  #error This file may be used only with Turbo C and Borland C !
#endif

#ifndef __WIN32__
  #error This file may be used only with Windows-32bit version of Turbo C or Borland C !
#endif

#  define _stdc cdecl
#  define _intr
#  define _intcast
#  define _veccast
#  define _fast _fastcall
#  define _loadds
#  define near
#  undef  far
#  define far

#  define farread read
#  define farwrite write

#  define _XPENTRY

#  define strcasecmp stricmp
#  define strncasecmp strncmpi

#endif
