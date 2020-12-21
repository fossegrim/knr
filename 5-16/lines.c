#include <stdio.h>
#include <string.h>

#define MAXLEN 80

/* underscore prepended to avoid name conflict with <stdio.h> */
static int _getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') s[i++] = c;
    if (c == '\n') s[i++] = c;

    s[i] = '\0';
    return i;
}

int read_lines(char *lineptr[], int maxlines) {
    int len, lines;
    char *p, line[MAXLEN];

    lines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) {
	if (lines >= maxlines || (p = alloc(len)) == NULL) return -1;
	else {
	    line[len-1] = '\0'; /* delete newline */
	    strcpy(p, line);
	    lineptr[lines++] = p;
	}
    }
    return lines;
}

void write_lines(char *lineptr[], int lines) {
    int i;
    for (i = 0; i < lines; i++) printf("%s\n", lineptr[i]);
}
