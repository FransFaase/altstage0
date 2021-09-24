#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>


#define OPEN_ARG_AS_INPUT input_fh = open(argv[0], O_RDONLY);
#define OPEN_ARG_AS_OUTPUT output_fh = open(argv[0], O_RDWR | O_TRUNC); if (output_fh == -1) output_fh = open(argv[0], O_RDWR | O_TRUNC | O_CREAT);
#define CHMOD_EXEC fchmod(output_fh, S_IXUSR | S_IWUSR | S_IRUSR);
#define READ_CH { char ch; if (read(input_fh, &ch, 1) == 1) input_ch = ch; else input_ch = 0; }
#define WRITE_CH write(output_fh, &output_ch, 1);

int reg;

#define NEXT_ARG argv++;
#define STORE(V) V = reg;
#define LOAD(V) reg = V;
#define ADD(V) reg += V;
#define ADD_CONST(C) reg += C;
#define SUB_CONST(C) reg -= C;
#define MUL_CONST(C) reg *= C;
#define JUMP_EQ(L) if (reg == 0) goto L;
#define JUMP_NE(L) if (reg != 0) goto L;
#define JUMP_GT(L) if (reg > 0) goto L;
#define JUMP_LT(L) if (reg < 0) goto L;
#define JUMP(L) goto L;
#define RETURN(V) return V;

