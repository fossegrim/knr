/*
 * Exercise 4-13.
 *
 * Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

#define MAXSIZE 10000

int main() {
    char s1[MAXSIZE] = "hello, world!";
    char s2[MAXSIZE] = "lorem ipsum";
    void reverse(char[]);

    reverse(s1);
    printf("%s\n", s1);

    reverse(s2);
    printf("%s\n", s2);
}

/* reverse:  reverse s */
void reverse(char s[]) {
    void reverse_recurse(char[], int, int);

    reverse_recurse(s, 0, strlen(s) - 1);
}

/* reverse_recurse:  reverse s in place from left to right */
void reverse_recurse(char s[], int left, int right) {
    void swap(char[], int, int);

    if(right - left <= 1) return;
    swap(s, left, right);
    reverse_recurse(s, left + 1, right - 1);
}

/* swap:  swap i and j */
void swap(char s[], int i, int j) {
    int temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
