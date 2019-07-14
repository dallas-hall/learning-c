#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef FSUPPORT

#define FSUPPORT
void print_usage(void);
FILE* gropen(char * infile);
FILE* gwopen(char * outfile);
/* the length of a line in the file */
#define MAXWIDTH 1
/* final two characters written by fgets to a char array */
#define EXTRASPACES 2
/* the number of command line arguments
 *
 * Changed from 0 to 1, as we are expecting a file as an input.
 * Don't forget the implicit passing of the program's name as the first argument.
 */
#define NUMARGS 1

typedef enum
{
    FALSE, TRUE
} BOOLEAN;

#endif
