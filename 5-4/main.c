/*
 * Exercise 5-4.
 *
 * Write the function strend(s, t), which returns 1 if the string t occurs at the end of the string s and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

#define MAXSIZE 10000

int strend(char s1[], char s2[]);

int main() {
    char *s1, *s2;

    s1 = "lorem ipsum";
    s2 = "ipsum";
    printf("%s\n", strend(s1, s2) ? "true" : "false"); /* true */

    s1 = "hello, world";
    s2 = "wowed";
    printf("%s\n", strend(s1, s2) ? "true" : "false"); /* false */
}

/* strend:  return 1 if s1 ends with s2, otherwise return 0 */
int strend(char s1[], char s2[]) {
    char *s1p, *s2p;

    s1p = s1;
    s2p = s2;

    /* point to the ends of the strings */
    while(*s1p != '\0') s1p++;
    while(*s2p != '\0') s2p++;

    /* handle edge case where w2 is longer than s1 */
    if((s1p - s1) < (s2p - s2)) return 0;

    /* ensure all of s2 is equal to the end of s1 */
    while(s2p >= s2) {
	if(*s1p != *s2p) return 0;

	s1p--;
	s2p--;
    }

    return 1;
}
