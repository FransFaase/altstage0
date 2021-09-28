#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

char *input_fn;
int input_fh;
char *output_fn;
int output_fh;

int input_ch;

int hex_result;

int output_ch;
int toggle;

#define READ_CH { char ch; if (read(input_fh, &ch, 1) == 1) input_ch = ch; else input_ch = -1; }
#define WRITE_CH write(output_fh, &output_ch, 1);
#define OPEN_INPUT input_fh = open(input_fn, O_RDONLY);
#define OPEN_OUTPUT output_fh = open(output_fn, O_RDWR | O_TRUNC); if (output_fh == -1) output_fh = open(output_fn, O_RDWR | O_TRUNC | O_CREAT);


int main(int argc, char *argv[])
{
	toggle = 0;
	
	argv++;
	input_fn = argv[0];
	OPEN_INPUT
	if (input_fh == -1) return -1;

	argv++;
	output_fn = argv[0];
	OPEN_OUTPUT
	if (output_fh == -1) return -1;

	fchmod(output_fh, S_IXUSR | S_IWUSR | S_IRUSR);	

l_loop1:

	READ_CH

	if (input_ch == -1) goto l_endloop1;
	
	if (input_ch < '0') goto l_endif1;
	if (input_ch > '9') goto l_endif1;
		input_ch -= '0';
		hex_result = input_ch;
		goto l_found_hex;
	l_endif1:
	
	if (input_ch < 'a') goto l_endif2;
	if (input_ch > 'f') goto l_endif2;
		input_ch -= 'a';
		input_ch += 10;
		hex_result = input_ch;
		goto l_found_hex;
	l_endif2:

	if (input_ch < 'A') goto l_endif3;
	if (input_ch > 'F') goto l_endif3;
		input_ch -= 'A';
		input_ch += 10;
		hex_result = input_ch;
		goto l_found_hex;
	l_endif3:
	
	hex_result = -1;
	
	if (input_ch == '#') goto l_ifthen4;
	if (input_ch == ';') goto l_ifthen4;
		goto l_endif4;
	l_ifthen4:
	
		l_loop2:
			READ_CH
			
			if (input_ch == '\n') goto l_endloop2;
			if (input_ch == '\r') goto l_endloop2;
			
			goto l_loop2;
		l_endloop2:
	l_endif4:
	
	l_found_hex:
	if (hex_result == -1) goto l_endif5;

		if (toggle == 1) goto l_ifelse6;
			hex_result *= 16;
			output_ch = hex_result;
			toggle = 1;
			goto l_endif6;
		l_ifelse6:
			output_ch += hex_result;
			WRITE_CH
			toggle = 0;	
		l_endif6:
		
	l_endif5:
	
	goto l_loop1;
l_endloop1:
	return 0;
}