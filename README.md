# altstage0

This is an attempt to implement an alternative for [oriansj/stage0](https://github.com/oriansj/stage0)
or at least for first steps. I am going to present it in the steps that I took, including all failed
attempts.

## hex0_1.c

The first step is that I wrote [`hex0_1.c`](hex0_1.c), a simple implementation of hex0 in C.

## Building some of the stage0 programs

Next, I decided to build some of the first programs from stage0. For this I wrote a simple
bash script, called [`build.sh`](build.sh). It requires a BrainFuck compiler with the name
`bf`, which can be compiled, for example from [`Ha_bf.c`](https://www.iwriteiam.nl/Ha_bf_c.txt)
and a program generated with [BF Generator](https://www.iwriteiam.nl/BFgen.html), included
her as [`hex0.bf`](hex0.bf). The scipt assumes that in the parent directory the repositories 
[`live-bootstrap`](https://github.com/fosslinux/live-bootstrap) and
[`stage0-posix`](https://github.com/oriansj/stage0-posix) have been cloned.

## hex0_2.h/c

I decided to rewrite `hex0_1.c` into a version using very basic operations represented by
macros for which it would be relatively easy to write a compiler. This resulted in a header
file [`hex0_2.h`](hex0_2.h) with all the macro definitions and a program file [`hex0_2.c`](hex0_2.c),
which is probably easy to parse and compile to assembly. The program can be compiled with gcc.

## cc1.c

I decided to write a compiler, [`cc1.c`](cc1.c), that can compile `hex0_2.c` to M1. The
idea is to make this compiler as simple as possible, assuming that the input is correct.
The compiler is an almost a one-on-one translation. I wrote a bash script, called
[`cc1_hex0_2.sh`](cc1_hex0_2.sh), that compiles `cc1.c` with gcc, uses it to compile
`hex0_2.c` to `hex0_2.M1` and uses `catm`, `M0`, `hex2-0` and some files from `live-bootstrap`
and `stage0-posix` to create the `hex0_2` executable.

I made extensive use of the [edb](https://github.com/eteran/edb-debugger) debugger to get
the cc1.c to work correctly. I also made use of:
* [Online x86 / x64 Assembler and Disassembler](https://defuse.ca/online-x86-assembler.htm)
* The book _De INTEL 8036_ by Lance A. Leventhal.
* [x86 and amd64 instruction reference](https://www.felixcloutier.com/x86/)

## cc1a.c

The program [`cc1a.c`](cc1a.c) is a slightly adapted version of `cc1.c` where the files from
`live-bootstrap` are partially incorporated (and slightly modified) into the source of `cc1a.c`.
The generated code is slight more compact.
The necessary compile steps are found in [`cc1a_hex0_2.sh`](cc1a_hex0_2.sh).