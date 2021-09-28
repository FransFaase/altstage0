#include <stdio.h>
#include <string.h>

char buffer[100];
int pos;
char token[20];
int token_val;

char var_decls[40][20];
int nr_var_decls;

int i;

void parse_token()
{
	token[0] = '\0';
	
	while (buffer[pos] == ' ' || buffer[pos] == '\t')
		pos++;
	
	if (buffer[pos] < ' ')
		return;
	
	i = 0;
	
	if (   (buffer[pos] >= 'a' && buffer[pos] <= 'z')
	    || (buffer[pos] >= 'A' && buffer[pos] <= 'Z'))
	{
		while (   (buffer[pos] >= 'a' && buffer[pos] <= 'z')
		       || (buffer[pos] >= 'A' && buffer[pos] <= 'Z')
		       || (buffer[pos] >= '0' && buffer[pos] <= '9')
		       || buffer[pos] == '_')
		{
			token[i] = buffer[pos];
			i++;
			pos++;
		}
		goto accepted;
	}

	token_val = 0;
	while (buffer[pos] >= '0' && buffer[pos] <= '9')
	{
		token_val = 10 * token_val + buffer[pos] - '0';
		pos++;
		token[0] = '0';
		i = 1;
	}
	if (i > 0) goto accepted;

	if (buffer[pos] == '\'')
	{
		token[0] = '0';
		i = 1;
		
		pos++;
		token_val = buffer[pos];
		pos += 2;
	}
	if (i > 0) goto accepted;

	token[0] = buffer[pos];
	pos++;
	i = 1;
	
accepted:
	token[i] = '\0';
}


	
int main(int argc, char *argv[])
{
	nr_var_decls = 0;
	
	printf(
		":f_next_arg\n"
		"LOAD_BASE_ADDRESS_eax %%-8\n"
		"PUSH_eax\n"
		"LOAD_BASE_ADDRESS_eax %%-8\n"
		"LOAD_INTEGER\n"
		"LOAD_IMMEDIATE_ebx %%1\n"
		"ADD_ebx_to_eax\n"
		"POP_ebx\n"
		"STORE_INTEGER\n"
		"RETURN\n"
	);
	printf(
		":f_open_arg_as_input\n"
		"LOAD_BASE_ADDRESS_eax %%-8\n"
		"PUSH_eax\n"
		"POP_ebx\n"
		"LOAD_IMMEDIATE_ecx %%0\n"
		"LOAD_IMMEDIATE_edx %%0\n"
		"LOAD_IMMEDIATE_eax %%5\n"
		"INT_80\n"
		"LOAD_IMMEDIATE_ebx &input_fh\n"
		"STORE_INTEGER\n"
		"RETURN\n"
	);
	printf(
		":f_open_arg_as_output\n"
		"LOAD_BASE_ADDRESS_eax %%-8\n"
		"PUSH_eax\n"
		"POP_ebx\n"
		"LOAD_IMMEDIATE_ecx %%577\n"
		"LOAD_IMMEDIATE_edx %%384\n"
		"LOAD_IMMEDIATE_eax %%5\n"
		"INT_80\n"
		"LOAD_IMMEDIATE_ebx &output_fh\n"
		"STORE_INTEGER\n"
		"RETURN\n"
	);
	printf(
		":f_read_ch\n"
		"LOAD_IMMEDIATE_ebx &input_fh\n"
		"LOAD_IMMEDIATE_ecx &input_ch\n"
		"LOAD_IMMEDIATE_edx %%1\n"
		"LOAD_IMMEDIATE_eax %%3\n"
		"INT_80\n"
		"TEST"
		"JUMP_NE8 !f_read_ch_done\n"
		"LOAD_IMMEDIATE_eax %%0\n"
		"LOAD_IMMEDIATE_ebx &input_ch\n"
		"STORE_INTEGER\n"
		":f_read_ch_done\n"
		"RETURN\n"
	);
	printf(
		":f_write_ch\n"
		"LOAD_IMMEDIATE_ebx &output_fh\n"
		"LOAD_IMMEDIATE_ecx &output_ch\n"
		"LOAD_INTEGER_ecx\n"
		"LOAD_IMMEDIATE_edx %%1\n"
		"LOAD_IMMEDIATE_eax %%4\n"
		"RETURN\n"
	);

	while (fgets(buffer, 99, stdin))
	{
		i = strlen(buffer);
		if (buffer[i-1] < ' ') buffer[i-1] = '\0';
		if (buffer[i-2] < ' ') buffer[i-2] = '\0';

		printf("# %s\n", buffer);
		pos = 0;
		
		parse_token();
		if (token[0] == '#' || token[0] == '/')
			continue;
		
		while (token[0] != '\0')
		{
			if (strcmp(token, "VAR") == 0)
			{
				parse_token();
				parse_token();
				strcpy(var_decls[nr_var_decls], token);
				parse_token();
				nr_var_decls++;
			}
			else if (strcmp(token, "MAIN") == 0)
			{
				printf(":FUNCTION_main\n");
			}
			else if (strcmp(token, "STORE") == 0)
			{
				parse_token();
				parse_token();
				printf("LOAD_IMMEDIATE_ebx &%s  ; STORE(%s)\nSTORE_INTEGER\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "LOAD") == 0)
			{
				parse_token();
				parse_token();
				if (token[0] == '0')
					printf("LOAD_IMMEDIATE_eax %%%d  ; LOAD(%d)\n", token_val, token_val);
				else
					printf("LOAD_IMMEDIATE_eax &%s  ; LOAD(%s)\nLOAD_INTEGER\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "ADD") == 0)
			{
				parse_token();
				parse_token();
				if (token[0] == '0')
					printf("LOAD_IMMEDIATE_ebx %%%d  ; ADD(%d)\n", token_val, token_val);
				else
					printf("PUSH_eax  ; ADD(%s)\nLOAD_IMMEDIATE_eax &%s\nLOAD_INTEGER\nPOP_ebx\n", token, token);
				printf("ADD_ebx_to_eax\n");
				parse_token();
			}
			else if (strcmp(token, "SUB") == 0)
			{
				parse_token();
				parse_token();
				if (token[0] == '0')
					printf("PUSH_eax  ; SUB(%d)\nLOAD_IMMEDIATE_eax %%%d\n", token_val, token_val);
				else
					printf("PUSH_eax  ; SUB(%s)\nLOAD_IMMEDIATE_eax &%s\nLOAD_INTEGER\n", token, token);
				printf("POP_ebx\nSUBTRACT_eax_from_ebx_into_ebx\nMOVE_ebx_to_eax\n");
				parse_token();
			}
			else if (strcmp(token, "MUL") == 0)
			{
				parse_token();
				parse_token();
				if (token[0] == '0')
					printf("PUSH_eax  ; SUB(%d)\nLOAD_IMMEDIATE_eax %%%d\n", token_val, token_val);
				else
					printf("PUSH_eax  ; SUB(%s)\nLOAD_IMMEDIATE_eax &%s\nLOAD_INTEGER\n", token, token);
				printf("POP_ebx\nMULTIPLY_eax_by_ebx_into_eax\n");
				parse_token();
			}
			else if (strcmp(token, "JUMP") == 0)
			{
				parse_token();
				parse_token();
				printf("JUMP %%%s\n", token);
				parse_token();
			}
			else if (strcmp(token, "JUMP_EQ") == 0)
			{
				parse_token();
				parse_token();
				printf("TEST  ; JUMP_EQ(%s)\nJUMP_EQ %%%s\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "JUMP_NE") == 0)
			{
				parse_token();
				parse_token();
				printf("TEST  ; JUMP_NE(%s)\nJUMP_NE %%%s\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "JUMP_GT") == 0)
			{
				parse_token();
				parse_token();
				printf("CMP  ; JUMP_GT(%s)\nSETG\nMOVEZBL\nTEST\nJUMP_EQ %%%s\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "JUMP_LT") == 0)
			{
				parse_token();
				parse_token();
				printf("CMP  ; JUMP_LT(%s)\nSETL\nMOVEZBL\nTEST\nJUMP_EQ %%%s\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "RETURN") == 0)
			{
				parse_token();
				parse_token();
				parse_token();
				printf("RETURN\n");
			}
			else if (strcmp(token, "NEXT_ARG") == 0)
			{
				printf("CALL_IMMEDIATE %%f_next_arg\n");
			}
			else if (strcmp(token, "OPEN_ARG_AS_INPUT") == 0)
			{
				printf("CALL_IMMEDIATE %%f_open_arg_as_input\n");
			}
			else if (strcmp(token, "OPEN_ARG_AS_OUTPUT") == 0)
			{
				printf("CALL_IMMEDIATE %%f_open_arg_as_output\n");
			}
			else if (strcmp(token, "CHMOD_EXEC") == 0)
			{
			}
			else if (strcmp(token, "READ_CH") == 0)
			{
				printf("CALL_IMMEDIATE %%f_read_ch\n");
			}
			else if (strcmp(token, "WRITE_CH") == 0)
			{
				printf("CALL_IMMEDIATE %%f_write_ch\n");
			}
			else if (strcmp(token, "{") == 0)
			{
			}
			else if (strcmp(token, "}") == 0)
			{
				printf("RETURN\n");
			}
			else if (   (token[0] >= 'a' && token[0] <= 'z')
		             || (token[0] >= 'A' && token[0] <= 'Z'))
		    {
		    	printf(":%s\n", token);
		    	parse_token();
		    }
		    else        
			{
				if (token[0] == '0')
					printf("; token value %d\n", token_val);
				else
					printf("; token '%s'\n", token);
			}
			
			parse_token();
		}
		
	}
	printf("\n\n");
	
	
	for (i = 0; i < nr_var_decls; i++)
		printf(":%s\n00000000\n", var_decls[i]);
	printf(":ELF_end\n");
}