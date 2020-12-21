/*
 * Exercise 1-2.
 *
 * Experiment to find out what happens when prints’s argument string contains \c, where c is some character not
 */

#include <stdio.h>

int main() {
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wunknown-escape-sequence"
	printf("\c");
	#pragma clang diagnostic pop
}
