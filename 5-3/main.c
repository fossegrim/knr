/*
 * Exercise 5-3.
 *
 * Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s;
 */

#include <stdio.h>

#define MAXSIZE 10000

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"
void strcat(char *, char *);
#pragma clang diagnostic pop

int main() {
    char s1[MAXSIZE] = "hello, ";
    char s2[] = "world!\n";

    strcat(s1, s2);
    printf("%s", s1); /* hello, world! */
}

void strcat(char *s1, char *s2) {
    /* iterate to end of s1 */
    while(*++s1 != '\0');
    /* write s2 to the end of s1 */
    while((*s1++ = *s2++) != '\0');
}
