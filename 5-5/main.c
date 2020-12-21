/*
 * Exercise 5-5.
 *
 * Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 */

#include <stdio.h>

#define MAXSIZE 10000
#define LENGTH1 20
#define LENGTH2 15

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"
char *strncpy(char *, char *, int);
char *strncat(char *, char *, int);
int strncmp(char *, char *, int);
#pragma clang diagnostic pop

int main() {
    char buf[MAXSIZE];
    char *s;
    int i;

    s = "hello, world";
    strncpy(buf, s, LENGTH1);
    for(i = 0; i < LENGTH1; i++) { /* hello, world\0\0\0\0\0\0\0\0 */
	if(buf[i] == '\0') {
	    printf("\\0");
	} else {
	    putchar(buf[i]);
	}
    }
    puts("");

    strncpy(buf, s, LENGTH2);
    for(i = 0; i < LENGTH2; i++) { /* hello, world\0\0\0 */
	if(buf[i] == '\0') {
	    printf("\\0");
	} else {
	    putchar(buf[i]);
	}
    }
    puts("");

    strncpy(buf, "lorem ", 6);
    strncat(buf, "ipsum", 100);
    printf("%s\n", buf); /* lorem ipsum */

    /* This one goes out of bound, segfault maybe */
    printf("%d\n", strncmp("123", "123", 10)); /* 0 */
    printf("%d\n", strncmp("00", "123", 10)); /* <0 */
    printf("%d\n", strncmp("123", "00", 10)); /* >0 */
    printf("%d\n", strncmp("124", "121", 2)); /* 0 */
}

char *strncpy(char *s, char *t, int n) {
    char *tp, *sp;
    int is_end_of_t_reached = 0;

    tp = t;
    sp = s;
    while(tp - t < n) {
	*sp = is_end_of_t_reached ? '\0' : *tp;
	sp++;
	tp++;
	if(*tp == '\0') is_end_of_t_reached = 1;
    }
    *sp = '\0';
    return s;
}

char *strncat(char *s, char *t, int n) {
    char *sp = s;
    char *tp = t;

    /* get the end of s */
    while(*++sp != '\0');

    /* append t to the end of s */
    while((*sp++ = *tp++)) {
	if(tp - t >= n) {
	    *sp = '\0';
	    break;
	}
    }

    return s;
}
    
int strncmp(char *s, char *tp, int n) {
    char *sp = s;
    int cmp = 0;
    while(sp - s < n && (cmp = *sp - *tp) == 0) {
	if(*s == '\0') return 0;

	sp++;
	tp++;
    };
    return cmp;
}
