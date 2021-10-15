#!/bin/bash

echo compile cc1.c
gcc cc1.c -o cc1
echo compile hex0_2.c to hex0_2
./cc1 <hex0_2.c >hex0_2.M1
echo compile hex0_2 to hex0_2.hex2
./catm hold.M1 ../live-bootstrap/sysa/stage0-posix/src/x86/x86_defs.M1 ../live-bootstrap/sysa/stage0-posix/src/x86/libc-core.M1 hex0_2.M1
./M0 hold.M1 hex0_2.hex2
echo compile hex0_2.hex2 to hex0_2
./catm hold.hex2 ../stage0-posix/x86/ELF-i386.hex2 hex0_2.hex2
./hex2-0 hold.hex2 hex0_2
echo Done