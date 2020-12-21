/*
 * Exercise 2-9.
 *
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
 */

/*
 * STATEMENT
 * x &= (x-1) deletes (only) the rightmost 1-bit in x.
 *
 * EXPLANATION
 * x-1 removes the rightmost 1 in x such that the digits to the right of the 1 which we intended to delete becomes 1s (0b11011000 - 1 = 0b11010111). This is not the intended behaviour so we have to clear those new 1s. Since the digits right to the rightmost 1 by definition have to be 0s, and we haven't changed any digits to the left of the rightmost 1, bitwise &ing x and x-1 will clear the new 1s leaving us with x with only the rightmost 1 removed.
 */

#include <stdio.h>

int bitcount(unsigned);

int main() {
	printf("%d: %d\n", 0, bitcount(0));
	printf("%d: %d\n", 1, bitcount(1));
	printf("%d: %d\n", 2, bitcount(2));
	printf("%d: %d\n", 3, bitcount(3));
	printf("%d: %d\n", 4, bitcount(4));
	printf("%d: %d\n", 5, bitcount(5));
	printf("%d: %d\n", 6, bitcount(6));
	printf("%d: %d\n", 7, bitcount(7));
	printf("%d: %d\n", 8, bitcount(8));
}

int bitcount(unsigned int x) {
	int i = 0;
	while(x) {
		x &= (x-1);
		i++;
	}
	return i;
}
