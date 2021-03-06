/*
** Copyright (c) 2006 Ingres Corporation
*/
/*
** CLCONFIG.H -- cl private definitions.
**
** This file lists defines symbols that configure the CL for
** system specific things that should not be visible to higher
** level clients.
**
** Historically, all symbols defined are of the form:
**
**	xCL_nnn_SOME_DESCRIPTIVE_NAME
**
** Where nnn is a unique identifying digit.  This is actually silly
** on UNIX, where all compilers understand long define names, and is
** no longer the standard. All new defines should be of the form:
**
**	xCL_SOME_DESCRIPTIVE_NAME
**
**
** Everything is really defined in <clsecret.h>, included below.
** It is machine generated by mksecret.sh, and is opaque.  The remainder
** of this file documents the things that may be defined there.
**
** ----------------------------------------------------------------------
** Nothing in the CL be ifdef-ed around a generic define like BSD, BSD42,
**	SYSV, SYS5, WECO, or WECOV.  You must use a specific attribute,
**	and arrange for a test in mksecret.
** ----------------------------------------------------------------------
**
** Nothing should be added to mksecret without updating the
** documentation here.
**
** History:
**	07-oct-88 (daveb)
**		Created.
**	23-Feb-1989 (fredv)
**		added xCL_033_SETPRIORITY_EXISTS and xCL_034_GETRLIMIT_EXISTS.
**	13-mar-89 (russ)
**		Added xCL_036_VTIMES_H_EXISTS, xCL_037_SYSV_DIRS and
**		xCL_038_BAD_SETJMP.
**	23-Mar-89 ((GordonW)
**		Added xCL_040_EXOS_EXISTS, xCL_041_DECNET_EXISTS,
**		xCL_042_TLI_EXISTS, xCL_043_SYSV_POLL_EXISTS
**	28-mar-89 (russ)
**		Added xCL_044_SETREUID_EXISTS.
**	13-apr-89 (russ)
**		Added xCL_045_LDFCN_H_EXISTS.
**	31-may-89 (daveb)
**		Added   xCL_046_IDIV_HARD
**			xCL_047_IDIV_SIGILL
**			xCL_048_IDIV_UNDETECTED
**			xCL_049_FDIV_HARD
**			xCL_050_FDIV_SIGILL
**			xCL_051_FDIV_UNDETECTED
**			xCL_052_IOVF_HARD
**			xCL_053_IOVF_SIGILL
**			xCL_054_IOVF_UNDETECTED
**			xCL_055_FOVF_HARD
**			xCL_056_FOVF_SIGILL
**			xCL_057_FOVF_UNDETECTED
**			xCL_058_FUNF_HARD
**			xCL_059_FUNF_SIGILL
**			xCL_060_FUNF_UNDETECTED
**		These will be generated by the mathsigs.c program.
**	15-jun-89 (markd)
**		Added   xCL_061_BAD_O_SYNC
**		For those machines in which O_SYNC is defined
**		but has no effect.  This will have to be 
**		added manually in mksecret as there is no easy
**		was to automatically test if the O_SYNC flag really works.
**	28-jun-89 (daveb)
**		Add: 
**			xCL_062_SETDTABLESIZE,
**			xCL_063_SQT_BMAP_CACHE,
**			xCL_064_SQT_DIRECT_IO,
**			xCL_065_SHADOW_PASSWD
**	27-jul-89 (russ)
**		Added xCL_066_UNIX_DOMAIN_SOCKETS.
**	14-nov-89 (blaise)
**		Added xCL_067_GETCWD_EXISTS
**	22-nov-89 (swm)
**		Added xCL_068_USE_SIGACTION (POSIX equivalent of sigvec)
**	24-nov-89 (swm)
**		Corrected all references to USE_SIGACTION define to use the
**		068 prefix.
**	24-nov-89 (swm)
**		Added xCL_069_UNISTD_H_EXISTS and xCL_070_LIMITS_H_EXISTS
**	29-nov-89 (swm)
**		Added xCL_071_UCONTEXT_H_EXISTS.
**	07-dec-89 (swm)
**		Added xCL_072_SIGINFO_H_EXISTS, xCL_073_CAN_POLL_FIFOS
**	15-Dec-89 (GordonW)
**		Added xCL_074_WRITEV_READV_EXISTS
**	28-dec-89 (mca)
**		Added xCL_075_SVS_V_IPC_EXISTS
**	08-jan-90 (kerry)
**		Added xCL_076_USE_UNAME when gethostname() does not exist.
**	12-feb-90 (twong)
**		Added xCL_077_BSD_MMAP and xCL_078_CVX_SEM.
**	13-feb-90 (swm)
**		Corrected xCL_075_SVS_V_IPC_EXISTS to  xCL_075_SYS_V_IPC_EXISTS
**				   ^				^
**		Added xCL_079_SYSCONF_EXISTS and xCL_080_GETPAGESIZE_EXISTS.
**	21-feb-90 (fredp)
**		Replaced this header file with the UNIX porting clconfig.h file
**		and added xCL_081_SUN_FAST_OSYNC_EXISTS.
**	12-apr-1990 (boba)
**		Corrected "comment" for xCL_077_BSD_MMAP.
**		Removed bogus _077_SYS_V_STREAMS_IPC (must be assigned a
**		new number before 6.2 STREAMS code is integrated into 6.3).
**	17-may-90 (blaise)
**              Added xCL_082_SYS_V_STREAMS_IPC, to define whether the
**              streams driver should be used for IPC. This symbol
**              integrated from 62, but with 082 instead of 077.
**	31-may-90 (blaise)
**		Removed obsolete xCL_037_SYSV_DIRS, which is never used.
**	15-jan-91 (mikem)
**		Added xCL_083_USE_SUN_DBE_INCREASED_FDS and 
**		xCL_084_SUN_AIO_EXISTS.
**	03-oct-91 (emerson)
**		Added xCL_085_PASS_DOUBLES_UNALIGNED.
**	24-jan-92 (sweeney)
**              renamed xCL_042_TLI_EXISTS to xCL_TLI_TCP_EXISTS
**              to reflect its actual use.
**		Added xCL_TLI_OSLAN_EXISTS and xCL_TLI_X25_EXISTS.
**	31-jan-92 (seiwald)
**	        Added xCL_BLAST_EXISTS.
**	29-feb-92 (jab)
**	        Added xCL_086_SETPGRP_0_ARGS and xCL_087_SETPGRP_2_ARGS.
**	20-Mar-92 (gautam)
**          Added xCL_088_FD_EXCEPT_LIST to select on exception conditions
**	06-Apr-92 (seiwald)
**		New xCL_SUN_LU62_EXISTS.
**	06-apr-1992 (jnash)
**		Added xCL_MLOCK_EXISTS and xCL_SETEUID_EXISTS.
**	07-Sep-92 (gautam)
**          Added xCL_091_BAD_STDIO_FD define for bad stdio systems
**	21-Sep-92 (seiwald)
**		New xCL_TLI_SPX_EXISTS.
**	07-Oct-92 (gautam)
**          Added xCL_TLI_UNIX_EXISTS for TLI loopback driver
**	19-nov-92 (peterk)
**		add xCL_NO_INADDR_ANY for machines whose TCP cannot do
**		INADDR_ANY addressing (currently sqs_us5 and su4_us5).
**	23-dec-92 ( puru )
**	    SIGEMT is generated on Amdahl for Fixed point/decimal exceptions
**	    and hence added a new define xCL_IDIV_SIGEMT
**	09-Feb-93 (bconnell)
**          Added xCL_092_CAREFUL_PUTC for putc macros that check various
**          flags before it writes.
**	10-mar-10 (mikem)
**	    Added xCL_OVERRIDE_IDIV_HARD to allow for systems which the
**	    the default tools say integer divide by zero is a "hard" error
**	    but can be coded to provide a soft recovery from the exception.
**	    This is the case on su4_us5.
**	16-mar-93 (swm)
**          On some platforms bad arithmetic operations can cause SIGTRAP
**          signals (as well as SIGFPE or SIGILL). Added automatic
**          detection of these (to mathsigs) and appropriate generation
**          of the following new configuration strings, added here:
**                xCL_IDIV_SIGTRAP, xCL_FDIV_SIGTRAP, xCL_IOVF_SIGTRAP,
**                xCL_FOVF_SIGTRAP, xCL_FUNF_SIGTRAP.
**	16-mar-92 (sweeney)
**	    Add xCL_SHMDT_ONE_ARG for case where shmdt() can't cope
**	    with spurious extra arguments.
**	25-Mar-93 (brucek)
**          Added xCL_TLI_NEEDS_TICOTSORD for TLI implementations that need
**	    a special device name for orderly release.
**	26-jul-93 (mikem)
**	    Added xCL_PROCFS_EXISTS for systems which support the "/proc"
**	    file system.
**	14-oct-1993 (tad/swm)
**	    Bug #58877
**	    Added xCL_ASYNC_IO for systems that can support Posix asynchronous
**	    disk IO with regular files.
**	    Before enabling xCL_ASYNC_IO the following should be checked
**	    carefully:
**	    o Is it supported for regular files as well as raw devices?
**	    o Would other file operations - open(), close(), rename(),
**	      mknod(), creat() ...  block? (It is ok for these to block
**	      in a slave process not in a DBMS server).
**	    o Are there sufficent file descriptors available in a DBMS to
**	      support the required number of GCA connections and async.
**	      disk i/o?
**	    o Does it actually perform better?
**	24-apr-1994 (mikem)
**	    Added new config defines for xCL_GETTIMEOFDAY_TIMEONLY and 
**	    xCL_GETTIMEOFDAY_TIME_AND_TZ.  These are used to determine
**	    when gettimeofday() can be used to get just the time vs. supporting
**	    timezone information as well.
**	26-feb-1997 (canor01)
**	    Added information on defines that had been added since
**	    last update.
**	21-jul-1997 (canor01)
**	    Added xCL_RESERVE_STREAM_FDS.
**	19-aug-1997 (canor01)
**	    Added xCL_NEED_SEM_CLEANUP.
**	28-aug-1997 (kosma01)
**	    Added xCL_TIME_CNVRT_TIME_AND_BUFFER
**	    for platforms where the asctime or asctime_r accepts
**	    only two arguments, the time and a buffer.
**	24-dec-1997 (canor01)
**	    Addec xCL_WAITPID_EXISTS.
**	06-Mar-1998 (kosma01)
**	    Remove xCL_TIME_CNVRT_TIME_AND_BUFFER. asctime_r is 
**	    now being used in gl/glf/tmgl/tmtzstr.c, under a
**	    wrapper macro defined in /cl/clf/hdr/tmcl.h.
**	    Fix for asctime_r has been moved to tmcl.h.
**	20-aug-1998 (canor01)
**	    Allow multiple includes of clconfig.h.
**      12-sep-2002 (devjo01)
**          Added xCL_095_USE_LOCAL_NUMA_HEADERS
**	01-nov-2002 (somsa01)
**	    Changed xCL_DIRECT_IO to xCL_NO_ATOMIC_READ_WRITE_IO.
**	27-Mar-2003 (jenjo02)
**	    Added xCL_DIRECTIO_EXISTS, unrelated to xCL_DIRECT_IO.
**	    SIR 109925.
**	18-Jun-2005 (hanje04)
**	    Added xCL_TERMIOS_EXISTS, for platforms where TERMIO no longer
**	    exists. (e.g. Mac OSX)
**	23-Sep-2005 (hanje04)
**	    Added xCL_USE_ETIMEDOUT for use instead of instead of ETIME.
**	07-Oct-2006 (lunbr01)  Sir 116548
**	    Added xCL_TCPSOCKETS_IPV6_EXIST for platforms supporting IPv6.
**	30-Apr-2007 (hanje04)
**	    SIR 117985
**	    Add xCL_NEED_RPCSVC_REX_HDR for conditional inclusion of
**	    rpcsvc/rex.h on Linux.
*/

# ifndef CLCONFIG_H_INCLUDED
# define CLCONFIG_H_INCLUDED

# include <clsecret.h>

# ifdef xCL_000_NEVER_DEFINED

#	error "Somebody defined xCL_000_NEVER_DEFINED!!!"

/* This is defined if sys/wait.h defines a wait union, like BSD */

# define xCL_001_WAIT_UNION


/*
** This is defined if the semun union is defined in the sys/sem.h,
** otherwise we use an int.  SVs differ wildly about this.
*/

# define xCL_002_SEMUN_EXISTS


/*
** This is defined if we have a BSD style getrusage call to use.
** Otherwise we use the SV times(2) interface, which isn't as useful.
*/

# define xCL_003_GETRUSAGE_EXISTS


/*
** This is defined is we need to use getdtablesize to find the max
** number of open files.  Otherwise, we assume _NFILE is OK.
*/
# define xCL_004_GETDTABLESIZE_EXISTS

/*
**  This is defined if we have a BSD style gettimeofday call to use.
**  Otherwise we use the SV time(2) call, which isn't as accurate.
*/

# define xCL_005_GETTIMEOFDAY_EXISTS


/* Defined if an fcntl.h exists in either /usr/include or /usr/include/sys */

# define xCL_006_FCNTL_H_EXISTS
# define xDI_009_FCNTL_H_EXISTS	1


/* Defined if sys/file.h exists */

# define xCL_007_FILE_H_EXISTS
# define xDI_008_FILE_H_EXISTS	1


/*
**  Defined if a mkdir system call exists.  There are thought to
**  be several flavors of this, mostly HP/UX permission wierdness,
**  but that has not yet been sorted out.
**
**  If this isn't defined, we need to use the /bin/mkdir program.
*/

# define xCL_008_MKDIR_EXISTS


/*
**  Defined if a rmdir system call exists.  If it does not, then we
**  need to use the /bin/rmdir program.
*/

# define xCL_009_RMDIR_EXISTS


/* Defined if an fsync system call exists */

# define xCL_010_FSYNC_EXISTS


/* Defined if we should use BSD style sigvec calls */

# define xCL_011_USE_SIGVEC


/*
** Defined if we have a dup2() system call.  Otherwise we fake it with
** fcntl.
*/
# define xCL_012_DUP2_EXISTS

/*
** Defined if we have BSD parent/child signal semantics when
** a child process is setuid to another user.
** BSD says you can't signal, SV says it is OK.
*/

# define xCL_013_CANT_KILL_SUID_CHILD


/*
** Defined if sys/types.h created an fd_set type.  If there isn't,
** we define one of our own in cl/cl/hdr/fdset.h.
*/

# define xCL_014_FD_SET_TYPE_EXISTS


/* Define if sys/time.h exists */

# define xCL_015_SYS_TIME_H_EXISTS


/*
** Defined if system has a valloc system call or library routine
** If so, we need to emulate it in cl/malloc/malloc.c.
*/

# define xCL_016_VALLOC_EXISTS


/* Defined if stdio's _ptr is to unsigned characters */

# define xCL_017_UNSIGNED_IOBUF_PTR


/* Defined if we should use termio interface to ttys */

# define xCL_018_TERMIO_EXISTS


/* Defined if BSD style tcp/ip sockets exist for IPC */

# define xCL_019_TCPSOCKETS_EXIST


/* Defined if select system call is available */

# define xCL_020_SELECT_EXISTS


/* Defined if select system call takes AIX style structures for args */

# define xCL_021_SELSTRUCT



/* Defined for AIX style LU6.2 support */

# define xCL_022_AIX_LU6_2


/*
** Defined if the system has a vfork() call.
*/
# define xCL_023_VFORK_EXISTS


/* Defined if system provide directory access routines and structures */

# define xCL_024_DIRFUNC_EXISTS


/* Defined if system directory access is with new style dirent structure */

# define xCL_025_DIRENT_EXISTS


/* Defined if system directory access files is /usr/include/ndir.h */

# define xCL_026_NDIR_H_EXISTS


/* Defined if system dir access file is /usr/include/sys/ndir.h */

# define xCL_027_SYS_NDIR_H_EXISTS


/* Defined if system dir access file is /usr/include/sys/aux/auxdir.h */

# define xCL_028_SYS_AUX_AUXDIR_H_EXISTS


/* Defined if system has an execvp call */

# define xCL_029_EXECVP_EXISTS


/* Defined if we have BSD style itimers */

# define xCL_030_SETITIMER_EXISTS


/* Defined if we have a sys/select.h to include */

# define xCL_031_SYS_SELECT_H_EXISTS

/*
** Defined if FNDELAY is defined in fcntl.h, otherwise we need
** to use O_FNDELAY.
*/
# define xCL_032_FNDELAY_FCNTL_ARG

/*
** Defined if there is the system call setpriority().
*/
# define xCL_033_SETPRIORITY_EXISTS

/*
** Defined if there is the system call getrlimit().
*/
# define xCL_034_GETRLIMIT_EXISTS

/*
** Defined if there is the system call rename().
*/
# define xCL_035_RENAME_EXISTS

/*
** Defined if sys/vtime.h exists */
*/

# define xCL_036_VTIMES_H_EXISTS

/*
** Defined if __setjmp does not exist.  This symbol is actually
** defined in bzarch.h, because it is used within the ex.h header
** file.
*/

# define xCL_038_BAD_SETJMP

/*
** Defined if ftok(3) does exist.
*/

# define xCL_039_FTOK_EXISTS

/*
** Excelan brain=-damaged TCP/IP
*/

# define xCL_040_EXOS_EXISTS

/*
** DECnet networking (Ultrix)
*/

# define xCL_041_DECNET_EXISTS

/*
** TLI (TCP) networking interface
*/

# define xCL_TLI_TCP_EXISTS

/*
** SYSTEM V poll system call
*/

# define xCL_043_SYSV_POLL_EXISTS

/*
** Defined if setreuid() exists.
*/

# define xCL_044_SETREUID_EXISTS

/*
** Defined if /usr/include/ldfcn.h exists.
*/

# define xCL_045_LDFCN_H_EXISTS

/*
** defined if integer div-by-0 causes a SIGFPE that may not be continued.
*/
# define xCL_046_IDIV_HARD

/*
** defined if the standard porting tool "mathsigs" thinks integer 
** div-by-0 causes a SIGFPE that may not be continued, but there actually is 
** a machine specific workaround.
*/
# define xCL_OVERRIDE_IDIV_HARD

/*
** defined if integer overflow causes a SIGILL
*/
# define xCL_047_IDIV_SIGILL

/*
** defined if integer div-by-0 is undetected
*/
# define xCL_048_IDIV_UNDETECTED

/*
** defined if floating div-by-0 causes a SIGFPE that may not be continued.
*/
# define xCL_049_FDIV_HARD

/*
** defined if integer overflow causes a SIGILL
*/
# define xCL_050_FDIV_SIGILL

/*
** defined if float div-by-0 goes undetected
*/
# define xCL_051_FDIV_UNDETECTED

/*
** defined if integer overflow causes a SIGFPE that can't be continued.
*/
# define xCL_052_IOVF_HARD

/*
** defined if integer overflow causes a SIGILL
*/
# define xCL_053_IOVF_SIGILL

/*
** defined if integer overflow goes undetected.
*/
# define xCL_054_IOVF_UNDETECTED

/*
** defined if float overflow causes a SIGFPE that can't be continued.
*/
# define xCL_055_FOVF_HARD

/*
** defined if float overflow causes a SIGILL
*/
# define xCL_056_FOVF_SIGILL

/*
** defined if float overflow goes undetected.
*/
# define xCL_057_FOVF_UNDETECTED

/*
** defined if float underflow causes a SIGFPE that can't be continued.
*/
# define xCL_058_FUNF_HARD

/*
** defined if float underflow causes a SIGILL
*/
# define xCL_059_FUNF_SIGILL

/*
** defined if float underflow goes undetected.
*/
# define xCL_060_FUNF_UNDETECTED

/*
** O_SYNC is defined but has no effect
*/
# define xCL_061_BAD_O_SYNC

/*
** Defined if setdtablesize call exists
*/

# define xCL_062_SETDTABLESIZE,

/*
** defined if sequent style BmapCache call exists
*/
# define xCL_063_SQT_BMAP_CACHE,

/*
** defined if sequent style DirectRead and DirectWrite calls exist
*/
# define xCL_064_SQT_DIRECT_IO,

/*
** defined is system has a shadow password file, requireing us to have 
** a setuid program to validate user logins for INGRES/NET
*/
# define xCL_065_SHADOW_PASSWD

/*
**  defined if unix domain sockets exist
*/

# define xCL_066_UNIX_DOMAIN_SOCKETS

/* 
**  defined if getcwd system call exists; on many sysV machines this is
**  the equivalent of getwd system call.
**
** 23-June-2008: xCL_067_GETCWD_EXISTS has been deprecated and is no
** longer used.
*/

# define xCL_067_GETCWD_EXISTS

/* Defined if we should use POSIX sigaction (like sigvec) calls */

# define xCL_068_USE_SIGACTION

/*
** defined if <unistd.h> file exists
*/
# define xCL_069_UNISTD_H_EXISTS

/*
** defined if <limits.h> file exists
*/
# define xCL_070_LIMITS_H_EXISTS

/*
** defined if <ucontext.h> file exists
*/
# define xCL_071_UCONTEXT_H_EXISTS

/*
** defined if <siginfo.h> file exists
*/
# define xCL_072_SIGINFO_H_EXISTS

/*
** defined if it is possible to poll a FIFO
*/
# define xCL_073_CAN_POLL_FIFOS

/*
** defined if it is possible to do a "readv(2)", or "writev(2)" system calls
*/
# define xCL_074_WRITEV_READV_EXISTS

/*
** Defined if the system include files sys/ipc.h and sys/sem.h exist
** so we can include them.
*/
#define xCL_075_SYS_V_IPC_EXISTS

/*
** defined if gethostname does not exist or is broken.
** (pure Sys V.3 boxes)  Uses uname(2) call.
*/
#define	xCL_076_USE_UNAME

/*
** defined if your system uses mmap for its
** shared memory implementation.
*/
#define	xCL_077_BSD_MMAP

/*
** defined if your system uses mset, and mclear
** for its semaphore operations.
*/
#define	xCL_078_CVX_SEM

/*
** defined if the sysconf() call exists.
**
*/
# define xCL_079_SYSCONF_EXISTS

/*
** defined if the getpagesize() call exists.
**
*/
# define xCL_080_GETPAGESIZE_EXISTS

/*
** defined if Sun's "fast O_SYNC" feature exists.
**
*/
# define xCL_081_SUN_FAST_OSYNC_EXISTS

/*
** defined if streams driver should be used for IPC.
*/
#define xCL_082_SYS_V_STREAMS_IPC

/*
** defined if SunOS4.1/SunDBE increased # of file descriptors feature
** may exist on user's system.  Temporary--SystemVr4 supports unlimited
** # of file descriptors.
*/
# define xCL_083_USE_SUN_DBE_INCREASED_FDS

/*
** defined if SunOS asynchronous I/O (AIO) facility exists.
*/
# define xCL_084_SUN_AIO_EXISTS

/*
** Defined if doubles normally require more alignment than integers
** *but* doubles passed by value are pushed onto the stack
** (or placed into registers) as a pair of integers (with integer alignment).
** This is known to be true on SPARC platforms.  Used by OLpcall.
*/
# define xCL_085_PASS_DOUBLES_UNALIGNED

/*
** for those machines that have 4097 bytes multiple only read/write/lseek
** on the raw device (such as Amdahl and AIX/370)
*/
# define xCL_086_BAD_RAWIO

/*
** The following is a matched set: either setpgrp(2) takes two args
** or none. Some ANSI compilers actually compare what you pass to the
** routine against its prototype and generate an error, so this allows
** us to do "the right thing."
*/
# define xCL_086_SETPGRP_0_ARGS
# define xCL_087_SETPGRP_2_ARGS

/*
** defined for fixed point/decimal exception on amd_us5
** see alxo xCL_IDIV_SIGEMT
*/
# define xCL_087_IDIV_SIGEMT

/*
** Define this if you want to select() on an exception fd list also.
** The only place this will be used is clpoll.c in iiCLpoll()
*/
# define xCL_088_FD_EXCEPT_LIST 

/*
** Define this if you have bad stdio on lower numbered fd's
** problem where stdio fails on an fd even though the open_file limit
** is not exceeded. This is a bug in stdio implementations on many
** System V platforms, include SunOS.
*/
# define xCL_091_BAD_STDIO_FD 

/*
** Define this if you have a putc which checks if you opened the file for
**      writing to it.  Most putc macros do not check this.  ODT 2.0 does.
*/
# define xCL_092_CAREFUL_PUTC

/*
** AIX 4.1 fsync() will return EINVAL when the file is RAW character
** special file.
*/
# define xCL_092_NO_RAW_FSYNC

/*
** xCL_093_MALLOC_OK -- Ingres on many Unix platforms cannot
** allow the standard "malloc()" function to be linked with the
** server due to incompatibilities with shared-memory allocation.
** If xCL_093_MALLOC_OK is not defined, libmalloc.a will be
** built with replacements for the system malloc/calloc/etc calls
** that use MEreqmem (using sbrk() or another method that does not
** conflict with shared memory.
*/
# define xCL_093_MALLOC_OK

/*
** xCL_094_TLS_EXISTS -- For servers built with operating-system threads,
** private storage for each thread is allocated using thread-local
** storage (TLS).  For System V threads, these are the thr_getspecific(),
** etc. functions.  For POSIX threads, they are pthread_getspecific(),
** etc.  If a server cannot be built using the system TLS functions
** (usually because they depend on the system malloc()), replacement
** functions from the CL will be used unless xCL_094_TLS_EXISTS is defined.
*/
# define xCL_094_TLS_EXISTS

/*
** xCL_095_USE_LOCAL_NUMA_HEADERS -- defined if "local" copies of
** the various NUMA header files should be referenced.   This is
** only a problem when building on Tru64 5.0, since NUMA support
** (which is dynamically linked in) did not exist until 5.1.
*/
# define xCL_095_USE_LOCAL_NUMA_HEADERS

/* 
** Defined if the operating system mlock() function exists.
** If it does exist, ME code to lock the DMF cache is enabled.
*/
# define xCL_MLOCK_EXISTS

/*
** Defined if this platform will support BLAST, an serial line (async)
** protocol driver.
*/
# define xCL_BLAST_EXISTS

/*
** Defined if the operating system seteuid() function exists.
** If it does exist, ME code to lock the DMF cache is enabled.
*/
# define xCL_SETEUID_EXISTS

/*
** Defined for SunOS 4.1, which supports the wretched Sun SNALU6.2.
*/
# define xCL_SUN_LU62_EXISTS

/*
** Defined if we have a TLI interface to an ISO OSI local area network.
*/
# define xCL_TLI_OSLAN_EXISTS

/*
** Defined if we have a TLI interface to an ISO OSI x25 network.
*/
# define xCL_TLI_X25_EXISTS

/*
** Defined for platforms which support Novel Portable Transports SPX/IPX.
*/
# define xCL_TLI_SPX_EXISTS

/*
** Defined for those systems which have a TLI loopback driver
*/
# define xCL_TLI_UNIX_EXISTS 

/*
** Defined for those systems which require a special TLI device for 
** orderly release.
*/
# define xCL_TLI_NEEDS_TICOTSORD

/*
** Defined for those systems which generate a SIGEMT for fixed-point/decimal
** exceptions
** See also xCL_087_IDIV_SIGEMT
*/
# define xCL_IDIV_SIGEMT

/*
** Defined if TCP cannot use IN_ADDR_ANY adressing
*/
# define xCL_NO_INADDR_ANY

/*
** defined if integer overflow causes a SIGTRAP
*/
# define xCL_IDIV_SIGTRAP

/*
** defined if floating overflow causes a SIGTRAP
*/
# define xCL_FDIV_SIGTRAP

/*
** defined if integer overflow causes a SIGTRAP
*/
# define xCL_IOVF_SIGTRAP

/*
** defined if float overflow causes a SIGTRAP
*/
# define xCL_FOVF_SIGTRAP

/*
** defined if float underflow causes a SIGTRAP
*/
# define xCL_FUNF_SIGTRAP

/*
** defined if semaphore cleanup needs to be done at server shutdown
*/
# define xCL_NEED_SEM_CLEANUP

/*
** Defined for those systems which insist on one argument to shmdt()
*/
# define xCL_SHMDT_ONE_ARG

/*
** Defined to be the right return type for the signal system call,
** which is either void or int
*/
# define TYPESIG int

/*
** Defined to be a string representing the printer program to use,
** usually "/usr/ucb/lpr" or "/usr/bin/lpr"
*/
# define PRINTER_CMD	"/usr/ucb/lpr"

/*
** Defined for those systems which have a "/proc" filesystem.  The "/proc"
** filesystem allows programs to find out about and control a process by 
** opening the file "/proc/pid" and then performing various ioctl() calls
** on the open file descriptor.
*/
# define xCL_PROCFS_EXISTS 

/*
** Defined for systems that can support Posix asynchronous disk IO.
**
**    Before enabling xCL_ASYNC_IO the following should be checked
**    carefully:
**    o Is it supported for regular files as well as raw devices?
**    o Would other file operations - open(), close(), rename(),
**      mknod(), creat() ...  block? (It is ok for these to block
**      in a slave process not in a DBMS server).
**    o Are there sufficent file descriptors available in a DBMS to
**      support the required number of GCA connections and async.
**      disk i/o?
**    o Does it actually perform better?
*/
# define xCL_ASYNC_IO

/* 
** On systems with a gettimeofday() function (xCL_005_GETTIMEOFDAY_EXISTS),
** the function may take one or two parameters.  Only one of the following
** xCL_GETTIMEOFDAY_... macros should be defined.
*/
/*
** Defined on systems with a gettimeofday() function which accepts a single
** argument (a pointer to a time to be filled in).  A call to this routine
** returns the current time in subsecond precision.
** int gettimeofday( struct timeval * );
*/
# define xCL_GETTIMEOFDAY_TIMEONLY
/*
** Same as xCL_GETTIMEOFDAY_TIMEONLY, but accepts other, undefined
** and unused paramters.
** int gettimeofday( struct timeval *, ... );
*/
# define xCL_GETTIMEOFDAY_TIMEONLY_V
/*
** Same as xCL_GETTIMEOFDAY_TIMEONLY_V, but would get warnings on
** the variable parameters.  The system (such as AIX) requres a void*
** as the second argument.
** int gettimeofday( struct timeval *, void * );
*/
# define xCL_GETTIMEOFDAY_TIME_AND_VOIDPTR
/*
** Defined on systems with a gettimeofday() function which accepts two
** arguments (a pointer to a time to be filled in and pointer to a timezone
** information to be filled in), and which correctly fills in the timezone
** information.  A call to this routine returns both the current time in
** subsecond precision and the current time zone information.
** int gettimeofday( struct timeval *, struct timezone * );
*/
# define xCL_GETTIMEOFDAY_TIME_AND_TZ

/* 
** Defined on systems that do direct io such that the  
** lseek and the read/write are not atomic. This necessitates
** holding onto a semaphore on the file descriptor while doing  
** the lseek, read/write. This #define and xCL_ASYNCH_IO are
** not mutually exclusive. Ingres may be built with the possibility
** of using asynch io, but may not use it at run-time.
*/
# define xCL_NO_ATOMIC_READ_WRITE_IO
 
/* 
** Defined on systems that dynamically adjust the priority of
** threads in areas of the code where priority inversion can occur.
*/
# define xCL_PRIORITY_ADJUST

/*
** Defined on systems that need to reserve all low-numbered (0-255)
** file descriptors for stream i/o (stdio and SI).
*/
# define xCL_RESERVE_STREAM_FDS

/*
** Defined on systems that have the waitpid() function.
*/
# define xCL_WAITPID_EXISTS

/*
** Defined on system that use the OS to manage the allocation and freeing of
** memory instead of Ingres managing the free page maps.
*/

# define xCL_SYS_PAGE_MAP

/*
** Defined on systems that have the directio() function
*/
# define xCL_DIRECTIO_EXISTS

/* Defined if we should use termios interface to ttys */

# define xCL_TERMIOS_EXISTS

/* Defined if we need to use ETIMEDOUT instead of ETIME */

# define xCL_USE_ETIMEDOUT

/*
** Defined if BSD style tcp/ip sockets exist for IPv6 
** New getaddrinfo(), getnameinfo(), and freeaddrinfo() functions required
*/

# define xCL_TCPSOCKETS_IPV6_EXIST

/*
** Should we include rpcsvc/rex.h on Linux
*/

# define xCL_NEED_RPCSVC_REX_HDR

# endif /* xCL_000_NEVER_DEFINED */

# endif /* CLCONFIG_H_INCLUDED */
