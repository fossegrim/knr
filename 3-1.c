/*
 * Exercise 3-1.
 *
 * Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time
 */

#include <stdio.h>
#define LENGTH 100

int binsearch(int, int[], int);

int main() {
	int v[LENGTH];
	for(int i = 1; i < LENGTH; i++) v[i] = i;

	// Benchmark reports made with time(1)
	for(int i = 0; i < 100000; i++) {
		for(int j = 1; j < LENGTH; j++) {
			binsearch(j, v, LENGTH);
		}
	}

	/*
	 * BENCHMARK
	 * I could not benchmark the one in the book because it did not work for me. when x=3, v=[0..99], v = 100 it enters an infinite loop.
	 *
	 * Either way the benchmarks for mine are listed below.
	 * $ time ./a.out
	 *     0m01.40s real     0m01.40s user     0m00.01s system
	 */
}

int binsearch(int x, int v[], int n) {
	// Boundaries are inclusive
	int lower_boundary = 0;
	int upper_boundary = n - 1;

	int mid;
	while(lower_boundary < upper_boundary) {
		mid = (lower_boundary + upper_boundary) / 2;
		if(v[mid] < x) {
			lower_boundary = mid + 1;
		} else {
			upper_boundary = mid;
		}
	}
	return v[mid] == x ? mid : -1;
}
