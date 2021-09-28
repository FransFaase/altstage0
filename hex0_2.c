#include "hex0_2.h"

VAR(input_fh)
VAR(output_fh)

VAR(input_ch)

VAR(hex_result)

VAR(output_ch)
VAR(toggle)

MAIN
{
	LOAD(0) STORE(toggle)

	NEXT_ARG	
	OPEN_ARG_AS_INPUT
	
	LOAD(input_fh) ADD(1) JUMP_NE(l_input_ok)
		RETURN(1)
	l_input_ok:

	NEXT_ARG
	OPEN_ARG_AS_OUTPUT
	LOAD(output_fh) ADD(1) JUMP_NE(l_output_ok)
		RETURN(1)
	l_output_ok:

	CHMOD_EXEC	

	// for (;;)	
	l_loop1:

		READ_CH
	
		LOAD(input_ch) JUMP_EQ(l_endloop1)
		
		LOAD(input_ch) SUB('0') JUMP_LT(l_endif1)
		LOAD(input_ch) SUB('9') JUMP_GT(l_endif1)
			LOAD(input_ch) SUB('0') STORE(hex_result)
			JUMP(l_found_hex)
		l_endif1:
		
		LOAD(input_ch) SUB('a') JUMP_LT(l_endif2)
		LOAD(input_ch) SUB('f') JUMP_GT(l_endif2)
			LOAD(input_ch) SUB('a') ADD(10) STORE(hex_result)
			JUMP(l_found_hex)
		l_endif2:
	
		LOAD(input_ch) SUB('A') JUMP_LT(l_endif3)
		LOAD(input_ch) SUB('F') JUMP_GT(l_endif3)
			LOAD(input_ch) SUB('A') ADD(10) STORE(hex_result)
			JUMP(l_found_hex)
		l_endif3:
	
		// if (input_ch == '#' || input_ch == ';')
		LOAD(input_ch) SUB('#') JUMP_EQ(l_comment)
		LOAD(input_ch) SUB(';') JUMP_EQ(l_comment)
		JUMP(l_loop1)
		
		l_comment:
			READ_CH
			
			LOAD(input_ch) SUB(10) JUMP_EQ(l_loop1)
			LOAD(input_ch) SUB(13) JUMP_EQ(l_loop1)
			JUMP(l_comment)
		
		l_found_hex:
		LOAD(toggle) JUMP_NE(l_else6)
			LOAD(hex_result) MUL(16) STORE(output_ch)
			LOAD(1) STORE(toggle)
			JUMP(l_loop1)
		l_else6:
			LOAD(output_ch) ADD(hex_result) STORE(output_ch)
			WRITE_CH
			LOAD(0) STORE(toggle)
		JUMP(l_loop1)
	l_endloop1:
	RETURN(0)
}