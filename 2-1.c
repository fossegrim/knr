/*
 * Exercise 2-1.
 *
 * Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main(){
	printf("char: %d..%d\n", CHAR_MIN, CHAR_MAX);
	printf("int: %d..%d\n", INT_MIN, INT_MAX);
	printf("long: %ld..%ld\n", LONG_MIN, LONG_MAX);
	printf("schar: %d..%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("shrt: %d..%d\n", SHRT_MIN, SHRT_MAX);
	printf("uchar: 0..%d\n", UCHAR_MAX);
	printf("uint: 0..%u\n", UINT_MAX); // This print one
	printf("ulong: 0..%lu\n", ULONG_MAX);
	printf("ushrt: 0..%d\n", USHRT_MAX);
}
