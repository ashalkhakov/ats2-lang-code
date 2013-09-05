This fork contains some hacks necessary
to make ATS2 run on (and compile programs for) Windows.

Currently, MinGW is the primary target.
MSVC support is planned, however, to make it
happen, the build procedure must be settled on.

Status: the compiler in $ATSHOME/src/CBOOT
finishes compilation successfully.

To reproduce the build, please follow these
instructions.

First, please ensure you have a working
Cygwin installation, and that you have
installed the MinGW compiler (straight
through the Cygwin package manager).
Next, you'll need GMP for MinGW, which is
available through CygwinPorts (http://cygwinports.org/),
under the name mingw64-x86_64-gmp.

Assuming that you changed your current directory
to the repository root and that you have all the
necessary packages installed via the Cygwin package manager:

$ aclocal
$ autoheader
$ automake --add-missing --foreign || true

automake will probably complain, please ignore.

$ autoconf
$ ./configure --host=mingw64 --build=x86_64-w64-mingw32 --target=x86_64-w64-mingw32
$ cd src/CBOOT
$ make CCOMP=x86_64-w64-mingw32-gcc LD=x86_64-w64-mingw32-ld

This should build the bootstrap compiler.
To run it, please do:

$ export PATH=/usr/x86_64-w64-mingw32/sys-root/mingw/bin:$PATH
$ export PATSHOME=/home/admin/ats2-lang
$ ./patsopt.exe

The first step is necessary to make it possible for patsopt.exe to find
some shared libraries.
