/*
 * Exercise 2-7.
 *
 * Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
 */

#include <stdio.h>

unsigned invert(unsigned, int, int);

int main() {
	/*
	 * EXAMPLE
	 * INPUT
	 * x = 44762 // 0b1010111011011010
	 * p = 5
	 * n = 4
	 *
	 * EXPECTED OUTPUT
	 * 44774 // 0b1010111011100110
	 *
	 * VERBOSE PROCESS
	 * x = 0b1010111011011010
	 * p = 5
	 * n = 4
	 * 
	 * int bits_to_keep = ~(~(1111111111111111 << n) << (p + 1 - n));
	 * int bits_to_keep = ~(~(1111111111110000) << (p + 1 - n));
	 * int bits_to_keep = ~(0000000000001111 << (p + 1 - n));
	 * int bits_to_keep = ~(0000000000001111 << 2);
	 * int bits_to_keep = ~(0000000000111100);
	 * int bits_to_keep =   1111111111000011
	 * 
	 * return (x & bits_to_keep) | (~x & ~bits_to_keep);
	 * return (1010111011011010 & 1111111111000011) | (~x & ~bits_to_keep);
	 * return (1010111011000010) | (~x & ~bits_to_keep);
	 * return (1010111011000010) | (~1010111011011010 & ~bits_to_keep);
	 * return (1010111011000010) | (0101000100100101 & ~1111111111000011);
	 * return (1010111011000010) | (0101000100100101 & 0000000000111100);
	 * return (1010111011000010) | (0000000000100100);
	 * return (1010111011100110)
	 */
	printf("invert(44762, 5, 4) => %d\n", invert(44762, 5, 4));
}

unsigned invert(unsigned x, int p, int n) {
	// bitmask where the bits we want to change are 0 and the ones we want to keep the same are 1
	int bits_to_keep = ~(~(~0 << n) << (p + 1 - n));

	return (x & bits_to_keep) | (~x & ~bits_to_keep);
}
