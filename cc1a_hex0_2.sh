#!/bin/bash

echo compile cc1.c
gcc cc1a.c -o cc1a
echo compile hex0_2.c to hex0_2_1a.M1
./cc1a <hex0_2.c >hex0_2_1a.M1
echo compile hex0_2_1a to hex0_2_1a.hex
./M0 hex0_2_1a.M1 hex0_2_1a.hex
echo compile hex0_2.hex2 to hex0_2
./catm hold.hex2_1a ../stage0-posix/x86/ELF-i386.hex2 hex0_2_1a.hex
./hex2-0 hold.hex2_1a hex0_2_1a
echo Done
