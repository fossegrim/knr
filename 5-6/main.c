/*
 * Exercise 5-6.
 *
 * Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

/*
 * Pointer only* implementatinos of getline, atoi, itoa, reverse and strindex.
 *
 * *no char arrays or char indexing used in the functions.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 80

/* unlike in K&R, getline is defined on my box which means i have to use a different name */
int _getline(char *, int);
int atoi(char *);
char *itoa(char *, int);
char *reverse(char *);
int strindex(char *, char*);

int main() {
    char buf[BUFSIZE];
    /* Since mutating string literals is UB, I must define char arrays for the reverse tests */
    char str1[] = "lorem, ipsum";
    char str2[] = "hello, world";

    /* _getline test */
    /* commented because they are interactive */
    /* char buf[BUFSIZE]; */
    /*  */
    /* puts("===---==="); */
    /* while(_getline(buf, BUFSIZE) > 0) { */
    /* 	printf("%s", buf); */
    /* 	puts("\n===---==="); */
    /* } */

    /* atoi tests */
    puts("===---===");
    printf("%d\n", atoi("12345")); /* 12345 */
    printf("%d\n", atoi("0")); /* 0 */
    printf("%d\n", atoi("-321")); /* -321 */
    printf("%d\n", atoi("abc")); /* 0 */

    /* itoa tests */
    puts("===---===");
    printf("%s\n", itoa(buf, 12345)); /* 12345 */
    printf("%s\n", itoa(buf, 0)); /* 0 */
    printf("%s\n", itoa(buf, -321)); /* -321 */

    /* reverse tests */
    puts("===---===");
    printf("%s\n", reverse(str1)); /* muspi ,merol */
    printf("%s\n", reverse(str2)); /* dlrow ,elloh */

    /* strindex tests */
    puts("===---===");
    printf("%d\n", strindex("olav", "olav")); /* 0 */
    printf("%d\n", strindex("ololavolavol", "olav")); /* 2 */
    printf("%d\n", strindex("01234olav", "olav")); /* 5 */

}

/* _getline:  write lim, or until EOF or newline, whichever comes first, chars to buf. buf must be at 1 in length */
int _getline(char *buf, int lim) {
    char c;
    char *bufp = buf;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
	*bufp++ = c;
    };
    if(c == '\n') *bufp++ = '\n';
    *bufp = '\0';
    return bufp - buf;
}

/* atoi:  parse int from str */
int atoi(char *str) {
    int n = 0;
    int sign = +1;

    if(*str == '+' || *str == '-') {
	*str == '-' && (sign = -1);
       str++;
    }

    for(n = 0; isdigit(*str); str++) {
	n *= 10;
	n += *str - '0';
    }

    return sign * n;
}

/* itoa:  write string representation of n to buf */
char *itoa(char *buf, int n) {
    char temp;
    char *bufp1 = buf;
    char *bufp2 = buf;

    /* add sign */
    if(n < 0) {
	*bufp1++ = '-';
	bufp2 = bufp1; /* point, bufp2 to the first digit to reverse */
	n = -n;
    }

    /* write n reversed to buf */
    do {
	*bufp1++ = n % 10 + '0';
	n /= 10;
    } while(n > 0); /* */

    *bufp1-- = '\0';

    /* reverse string */
    while(bufp1 - bufp2 >= 0) {
	temp = *bufp2;
	*bufp2 = *bufp1;
	*bufp1 = temp;

	bufp1--;
	bufp2++;
    }

    return buf;
}

/* reverse:  reverse s */
char *reverse(char *s) {
    int l = strlen(s);
    char *left = s;
    char *right = s + l - 1;
    char temp;

    while(left < right) {
	temp = *left;
	*left = *right;
	*right = temp;

	left++;
	right--;
    }

    return s;
}

/* strindex:  return index of t in s, -1 if none */
int strindex(char *s, char *t) {
    char *sp = s;
    char *tp = t; /* ??? why didn't clang catch this */


    while(*sp != '\0') {
	if(*sp == *tp) {
	    /* iterate to the first unmatching char or end of tp */
	    while(*++tp == *++sp && *tp != '\0');

	    /* if the words are equal to the end of t, they must match */
	    if(*tp == '\0') return (sp - s) - (tp - t);

	    tp = t;
	} else {
	    sp++;
	}
    }

    return -1;
}
