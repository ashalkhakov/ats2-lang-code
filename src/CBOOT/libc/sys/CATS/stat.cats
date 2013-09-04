/************************************************************************/
/*                                                                      */
/*                         Applied Type System                          */
/*                                                                      */
/*                              Hongwei Xi                              */
/*                                                                      */
/************************************************************************/

/*
** ATS - Unleashing the Power of Types!
**
** Copyright (C) 2002-2010 Hongwei Xi.
**
** ATS is  free software;  you can redistribute it and/or modify it under
** the  terms of the  GNU General Public License as published by the Free
** Software Foundation; either version 2.1, or (at your option) any later
** version.
** 
** ATS is distributed in the hope that it will be useful, but WITHOUT ANY
** WARRANTY; without  even  the  implied  warranty  of MERCHANTABILITY or
** FITNESS FOR A PARTICULAR PURPOSE.  See the  GNU General Public License
** for more details.
** 
** You  should  have  received  a  copy of the GNU General Public License
** along  with  ATS;  see the  file COPYING.  If not, please write to the
** Free Software Foundation,  51 Franklin Street, Fifth Floor, Boston, MA
** 02110-1301, USA.
*/

/* ****** ****** */

/* author: Hongwei Xi (hwxi AT cs DOT bu DOT edu) */

/* ****** ****** */

#ifndef ATS_LIBC_SYS_STAT_CATS
#define ATS_LIBC_SYS_STAT_CATS

/* ****** ****** */

#include <sys/stat.h>
#include "libc/sys/CATS/types.cats"
typedef struct stat ats_stat_type ;

/* ****** ****** */

#ifdef __MINGW32__
#define S_IFLNK    0120000 /* Symbolic link */
#define S_ISLNK(x) (((x) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(x) 0
#endif /* end of [__MINGW32__] */

/* ****** ****** */

extern
void perror (const char *msg) ; // declared in [stdio.h]

//
// HX: implemented in [prelude/DATS/basics.dats]
//
extern
ats_void_type
ats_exit_errmsg(ats_int_type n, ats_ptr_type msg) ;

/* ****** ****** */

ATSinline()
ats_bool_type
atslib_S_ISBLK (ats_mode_type m) { return S_ISBLK(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISCHR (ats_mode_type m) { return S_ISCHR(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISDIR (ats_mode_type m) { return S_ISDIR(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISFIFO (ats_mode_type m) { return S_ISFIFO(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISREG (ats_mode_type m) { return S_ISREG(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISLNK (ats_mode_type m) { return S_ISLNK(m) ; }

ATSinline()
ats_bool_type
atslib_S_ISSOCK (ats_mode_type m) { return S_ISSOCK(m) ; }

/* ****** ****** */

#define atslib_chmod_err chmod

/* ****** ****** */

#define atslib_mkdir_err mkdir

/* ****** ****** */

#ifdef __MINGW32__

#include <windows.h>

#undef off_t
#define off_t off64_t
#undef lseek
#define lseek _lseeki64

ATSinline()
int readlink(const char *path, char *buf, size_t bufsiz)
{ errno = ENOSYS; return -1; }

ATSinline() // from https://bitbucket.org/definitelylion/git/src/a117999ca8ef/compat/win32.h
int file_attr_to_st_mode (DWORD attr)
{
        int fMode = S_IREAD;
        if (attr & FILE_ATTRIBUTE_DIRECTORY)
                fMode |= S_IFDIR;
        else
                fMode |= S_IFREG;
        if (!(attr & FILE_ATTRIBUTE_READONLY))
                fMode |= S_IWRITE;
        return fMode;
}

ATSinline() // from https://bitbucket.org/definitelylion/git/src/a117999ca8ef/compat/win32.h
int get_file_attr(const char *fname, WIN32_FILE_ATTRIBUTE_DATA *fdata)
{
        if (GetFileAttributesExA(fname, GetFileExInfoStandard, fdata))
                return 0;

        switch (GetLastError()) {
        case ERROR_ACCESS_DENIED:
        case ERROR_SHARING_VIOLATION:
        case ERROR_LOCK_VIOLATION:
        case ERROR_SHARING_BUFFER_EXCEEDED:
                return EACCES;
        case ERROR_BUFFER_OVERFLOW:
                return ENAMETOOLONG;
        case ERROR_NOT_ENOUGH_MEMORY:
                return ENOMEM;
        default:
                return ENOENT;
        }
}

ATSinline() // from https://github.com/hsn10/tokyocabinet-win/blob/master/winstat.c
long long filetime_to_hnsec(const FILETIME *ft) {
  long long winTime = ((long long)ft->dwHighDateTime << 32) + ft->dwLowDateTime;
/* Windows to Unix Epoch conversion */
  return winTime - 116444736000000000LL;
}

ATSinline() // from https://bitbucket.org/definitelylion/git/src/a117999ca8ef6b8a03019e6830df86dbb16501e8/compat/mingw.c?at=mingw-w64
time_t filetime_to_time_t(const FILETIME *ft)
{
        return (time_t)(filetime_to_hnsec(ft) / 10000000);
}

/* We keep the do_lstat code in a separate function to avoid recursion.
 * When a path ends with a slash, the stat will fail with ENOENT. In
 * this case, we strip the trailing slashes and stat again.
 *
 * If follow is true then act like stat() and report on the link
 * target. Otherwise report on the link itself.
 */
ATSinline()
int do_lstat(int follow, const char *file_name, struct stat *buf)
{
	int err;
	WIN32_FILE_ATTRIBUTE_DATA fdata;

	if (!(err = get_file_attr(file_name, &fdata))) {
		buf->st_ino = 0;
		buf->st_gid = 0;
		buf->st_uid = 0;
		buf->st_nlink = 1;
		buf->st_mode = file_attr_to_st_mode(fdata.dwFileAttributes);
		buf->st_size = fdata.nFileSizeLow |
			(((off_t)fdata.nFileSizeHigh)<<32);
		buf->st_dev = buf->st_rdev = 0; /* not used by Git */
		buf->st_atime = filetime_to_time_t(&(fdata.ftLastAccessTime));
		buf->st_mtime = filetime_to_time_t(&(fdata.ftLastWriteTime));
		buf->st_ctime = filetime_to_time_t(&(fdata.ftCreationTime));
		if (fdata.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) {
			WIN32_FIND_DATAA findbuf;
			HANDLE handle = FindFirstFileA(file_name, &findbuf);
			if (handle != INVALID_HANDLE_VALUE) {
				if ((findbuf.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) &&
						(findbuf.dwReserved0 == IO_REPARSE_TAG_SYMLINK)) {
					if (follow) {
						char buffer[MAXIMUM_REPARSE_DATA_BUFFER_SIZE];
						buf->st_size = readlink(file_name, buffer, MAXIMUM_REPARSE_DATA_BUFFER_SIZE);
					} else {
						buf->st_mode = S_IFLNK;
					}
					buf->st_mode |= S_IREAD;
					if (!(findbuf.dwFileAttributes & FILE_ATTRIBUTE_READONLY))
						buf->st_mode |= S_IWRITE;
				}
				FindClose(handle);
			}
		}
		return 0;
	}
	errno = err;
	return -1;
}

/* We provide our own lstat/fstat functions, since the provided
 * lstat/fstat functions are so slow. These stat functions are
 * tailored for Git's usage (read: fast), and are not meant to be
 * complete. Note that Git stat()s are redirected to mingw_lstat()
 * too, since Windows doesn't really handle symlinks that well.
 */
ATSinline()
int do_stat_internal(int follow, const char *file_name, struct stat *buf)
{
	int namelen;
	static char alt_name[PATH_MAX];

	if (!do_lstat(follow, file_name, buf))
		return 0;

	/* if file_name ended in a '/', Windows returned ENOENT;
	 * try again without trailing slashes
	 */
	if (errno != ENOENT)
		return -1;

	namelen = strlen(file_name);
	if (namelen && file_name[namelen-1] != '/')
		return -1;
	while (namelen && file_name[namelen-1] == '/')
		--namelen;
	if (!namelen || namelen >= PATH_MAX)
		return -1;

	memcpy(alt_name, file_name, namelen);
	alt_name[namelen] = 0;
	return do_lstat(follow, alt_name, buf);
}

ATSinline()
int atslib_lstat_err(const char *file_name, struct stat *buf) {
  return do_stat_internal(0, file_name, buf);
}

ATSinline()
int atslib_stat_err(const char *file_name, struct stat *buf) {
  return do_stat_internal(1, file_name, buf);
}

ATSinline()
int atslib_fstat_err(int fd, struct stat *buf) {
  HANDLE fh = (HANDLE)_get_osfhandle(fd) ;
  BY_HANDLE_FILE_INFORMATION fdata ;

  if (fh == INVALID_HANDLE_VALUE) {
    errno = EBADF;
    return -1 ;
  }
  /* direct non-file handles to MS's fstat() */
  if (GetFileType(fh) != FILE_TYPE_DISK)
    return _fstati64(fd, buf) ;

  if (GetFileInformationByHandle(fh, &fdata)) {
    buf->st_ino = 0 ;
    buf->st_gid = 0 ;
    buf->st_uid = 0;
    buf->st_nlink = 1;
    buf->st_mode = file_attr_to_st_mode(fdata.dwFileAttributes) ;
    buf->st_size = fdata.nFileSizeLow | (((off_t)fdata.nFileSizeHigh)<<32) ;
    buf->st_dev = buf->st_rdev = 0 ; /* not used by Git */
    buf->st_atime = filetime_to_time_t(&(fdata.ftLastAccessTime)) ;
    buf->st_mtime = filetime_to_time_t(&(fdata.ftLastWriteTime)) ;
    buf->st_ctime = filetime_to_time_t(&(fdata.ftCreationTime)) ;
    return 0 ;
  }
  errno = EBADF ;
  return -1 ;
}

#else
#define atslib_stat_err stat
#define atslib_fstat_err fstat
#define atslib_lstat_err lstat
#endif /* end of [__MINGW32__] */

/* ****** ****** */

#define atslib_umask umask

/* ****** ****** */

#define atslib_mkfifo mkfifo

/* ****** ****** */

#endif /* end of [ATS_LIBC_SYS_STAT_CATS] */

/* end of [stat.cats] */
