# altstage0

This is an attempt to implement an alternative for [oriansj/stage0](https://github.com/oriansj/stage0)
or at least for first steps. I am going to present it in the steps that I took, including all failed
attempts.

## hex0_1.c

The first step is that I wrote [`hex0_1.c`](hex0_1.c), a simple implementation of hex0 in C.

## Building some of stage0 programs

Next, I decided to build some of the first programs from stage0. For this I wrote a simple
bash script, called [`build.sh`](build.sh). It requires a BrainFuck compiler with the name
`bf`, which can be compiled, for example from [`Ha_bf.c`](https://www.iwriteiam.nl/Ha_bf_c.txt)
and a program generated with [BF Generator](https://www.iwriteiam.nl/BFgen.html), included
her as [`hex0.bf`](hex0.bf). The scipt assumes that in the parent directory the repositories 
[`live-bootstrap`](https://github.com/fosslinux/live-bootstrap) and
[`stage0-posix`](https://github.com/oriansj/stage0-posix) have been cloned.


