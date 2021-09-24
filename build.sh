#!/bin/bash

echo Create hex1 with bf and hex0.bf from stage0-posix/x86/hex1_x86.hex0
~/www/bf -eof0 hex0.bf <../stage0-posix/x86/hex1_x86.hex0 >hex1
chmod +x hex1

echo Create catm with bf and hex0.bf from stage0-posix/x86/hex1_x86.hex0
~/www/bf -eof0 hex0.bf <../stage0-posix/x86/catm_x86.hex0 >catm
chmod +x catm

echo Create hex2-0
./hex1 ../stage0-posix/x86/hex2_x86.hex1 hex2-0

echo Create M0
./catm hold ../stage0-posix/x86/ELF-i386.hex2 ../stage0-posix/x86/M0_x86.hex2
./hex2-0 hold M0

echo Create cc_x86
./M0 ../stage0-posix/x86/cc_x86.M1 temp1
./catm hold ../stage0-posix/x86/ELF-i386.hex2 temp1
./hex2-0 hold cc_x86

echo Create hold
./catm c_src \
	../live-bootstrap/sysa/stage0-posix/src/M2libc/x86/Linux/bootstrap.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc.h \
	../live-bootstrap/sysa/stage0-posix/src/M2libc/bootstrappable.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_globals.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_reader.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_strings.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_types.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_core.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc_macro.c \
	../live-bootstrap/sysa/stage0-posix/src/M2-Planet/cc.c
./cc_x86 c_src M2.M1
./catm hold.M1 ../live-bootstrap/sysa/stage0-posix/src/x86/x86_defs.M1 ../live-bootstrap/sysa/stage0-posix/src/x86/libc-core.M1 M2.M1
./M0 hold.M1 M2.hex2
./catm hold.hex2 ../stage0-posix/x86/ELF-i386.hex2 M2.hex2
./hex2-0 hold.hex2 M2



