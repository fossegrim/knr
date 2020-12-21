/*
 * Exercise 2-3.
 *
 * Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>

int htoi(char[]);
int htoi_digit(char);
int power(int, int);

int main() {
	// Demonstration
	printf("%c = %d\n", '0', htoi_digit('0'));
	printf("%c = %d\n", '3', htoi_digit('3'));
	printf("%c = %d\n", '9', htoi_digit('9'));
	printf("%c = %d\n", 'a', htoi_digit('a'));
	printf("%c = %d\n", 'c', htoi_digit('c'));
	printf("%c = %d\n", 'f', htoi_digit('f'));
	printf("%c = %d\n", 'A', htoi_digit('A'));
	printf("%c = %d\n", 'D', htoi_digit('D'));
	printf("%c = %d\n", 'F', htoi_digit('F'));
	printf("%c = %d\n", 'q', htoi_digit('q'));

	char hex_number1[] = "9";
	printf("%s = %d\n", hex_number1, htoi(hex_number1));
	
	char hex_number2[] = "0x12abe";
	printf("%s = %d\n", hex_number2, htoi(hex_number2));

	char hex_number3[] = "abc";
	printf("%s = %d\n", hex_number3, htoi(hex_number3));

	char hex_number4[] = "0xabc";
	printf("%s = %d\n", hex_number4, htoi(hex_number4));

	char hex_number5[] = "0xABC";
	printf("%s = %d\n", hex_number5, htoi(hex_number5));

	char hex_number6[] = "0XAbC";
	printf("%s = %d\n", hex_number6, htoi(hex_number6));
}

int htoi(char number[]) {
	int first_digit_index = 0;
	if(number[0] == '0' && (number[1] == 'x' || number[1] == 'X')) {
		first_digit_index = 2;
	}

	int last_digit_index = first_digit_index;
	for(; number[last_digit_index + 1] != '\0'; last_digit_index++);

	int decimal_number = 0;
	for(int i = last_digit_index; i >= first_digit_index; i--) {
		int exponent = last_digit_index - i;
		int digit = htoi_digit(number[i]);
		decimal_number += digit * power(16, exponent);
	}

	return decimal_number;
}

int htoi_digit(char digit) {
	if(digit >= '0' && digit <= '9') {
		return digit - '0';
	} else if(digit >= 'a' && digit <= 'f') {
		return digit - 'a' + 10;
	} else if(digit >= 'A' && digit <= 'F') {
		return digit - 'A' + 10;
	} else {
		return -1; // Not a valid digit
	}
}

int power(int base, int exponent) {
	// Only non-negative integers
	return exponent == 0 ? 1 : base * power(base, exponent - 1);
}
