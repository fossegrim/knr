/*
 * Exercise 5-15.
 *
 * Add the option -f to fold upper and lower case together, so that case
 * distinctions are not made during sorting; for example, a and A compare equal.
 */

#include "alloc.c"
#include "lines.c"
#include "qsort.c"
#include "cmp.c"

#define MAXLINES 10000 /* Maximum number of lines */
#define USAGE "usage:  sort [-f|-n] [-r]\n"

void exit_with_usage();

int main(int argc, char *argv[]) {
    int fold_case, numeric, reverse;

    /* Parse flags */
    fold_case = 0; /* -f */
    numeric = 0;   /* -n */
    reverse = 0;   /* -r */
    {
	int argi;
	for(argi = 1; argi < argc; argi++) {
	    if(argv[argi][0] == '-' && argv[argi][1] != '\0') {
		int flagi;
		for(flagi = 1; argv[argi][flagi] != '\0'; flagi++) {
		    if(argv[argi][flagi] == 'f') fold_case = 1;
		    else if(argv[argi][flagi] == 'n') numeric = 1;
		    else if(argv[argi][flagi] == 'r') reverse = 1;
		    else exit_with_usage();
		}
	    } else exit_with_usage();
	}
    }

    /* -f and -n are mutually exclusive */
    if(fold_case && numeric) exit_with_usage();

    /* Sort stdin */
    {
	int lines;
	char *lineptr[MAXLINES];
	int (*cmp)(char *, char*);

	lines = read_lines(lineptr, MAXLINES);
	if(lines == -1) {
	    fprintf(stderr, "error: maximum %d lines\n", MAXLINES);
	    return 1;
	}

	if(fold_case) cmp = fldcmp;
	else if(numeric) cmp = numcmp;
	else cmp = (int (*)(char *, char *)) strcmp;
	_qsort(lineptr, lines, cmp, reverse);

	/* _qsort( */
	/*     lineptr, */
	/*     lines, */
	/*     numeric ? numcmp : ( */
	/* 	fold_case ? fldcmp : ( */
	/* 	     */
	/*         ) */
	/*     ), */
	/*     reverse); */

	write_lines(lineptr, lines);
    }
}

void exit_with_usage() {
    fputs(USAGE, stderr);
    exit(1);
}
