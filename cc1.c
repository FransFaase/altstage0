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
	
	while (   (buffer[pos] >= 'a' && buffer[pos] <= 'z')
	       || (buffer[pos] >= 'A' && buffer[pos] <= 'Z')
	       || buffer[pos] == '_')
	{
		token[i] = buffer[pos];
		i++;
		pos++;
	}
	if (i > 0) goto accepted;

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

	while (fgets(buffer, 99, stdin))
	{
		printf("; %s", buffer);
		pos = 0;
		
		parse_token();
		if (token[0] == '#')
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
				printf("; STORE(%s)\nLOAD_IMMEDIATE_ebx &%s\nSTORE_INTEGER\n", token, token);
				parse_token();
			}
			else if (strcmp(token, "LOAD") == 0)
			{
				parse_token();
				parse_token();
				if (token[0] == '0')
				{
					printf("; LOAD(%d)\nLOAD_IMMEDIATE_aex %%%d\n", token_val, token_val);
				}
				else
				{
					printf("; LOAD(%s)\nLOAD_IMMEDIATE_aex &%s\nLOAD_INTEGER\n", token, token);
				}
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