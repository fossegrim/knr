/*
 * Exercise 1-24.
 *
 * Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
 */

#include <stdio.h>
#include <stdbool.h>

bool is_current_char_escaped();

int main() {
	bool in_single_line_comment = false; // //
	bool in_multi_line_comment = false; // /**/
	bool in_string = false; // ""
	bool in_char = false; // ''
	int levels_of_brace_nesting = 0; // {}
	int levels_of_parenthesis_nesting = 0; // ()
	int levels_of_bracket_nesting = 0; // []

	char prev_chars[] = { '\0', '\0' };
	char c = '\0';

	while((c = getchar()) != EOF) {
		if(in_string) {
			if(c == '\"' && !is_current_char_escaped(prev_chars)) {
				in_string = false;
			}
		} else if(in_char) {
			if(c == '\'' && !is_current_char_escaped(prev_chars)) {
				in_char = false;
			}
		} else if(in_single_line_comment) {
			if(c == '\n') {
				in_single_line_comment = false;
			}
		} else if(in_multi_line_comment) {
			if(prev_chars[0] == '*' && c == '/'){
				in_multi_line_comment = false;
			}
		} else if(c == ')') {
			levels_of_parenthesis_nesting--;
		} else if(c == '}') {
			levels_of_brace_nesting--;
		} else if(c == ']') {
			levels_of_bracket_nesting--;
		} else if(c == '\"') {
			in_string = true;
		} else if (c == '\'') {
			in_char = true;
		} else if ( prev_chars[0] == '/' && c == '/') {
			in_single_line_comment = true;
		} else if ( prev_chars[0] == '/' && c == '*') {
			in_multi_line_comment = true;
		} else if (c == '(') {
			levels_of_parenthesis_nesting++;
		} else if (c == '{') {
			levels_of_brace_nesting++;
		} else if (c == '[') {
			levels_of_bracket_nesting++;
		}

		prev_chars[1] = prev_chars[0];
		prev_chars[0] = c;
	}

	in_string && puts("String unclosed");
	in_char && puts("Char unclosed");
	in_single_line_comment && puts("Single line comment unclosed");
	in_multi_line_comment && puts("Multi line comment unclosed");

	if(levels_of_parenthesis_nesting > 0) {
		printf("%d unclosed parenthesis\n", levels_of_parenthesis_nesting);
	} else if (levels_of_parenthesis_nesting < 0) {
		printf("%d extra parenthesis\n", -levels_of_parenthesis_nesting);
	}

	if(levels_of_brace_nesting > 0) {
		printf("%d unclosed braces\n", levels_of_brace_nesting);
	} else if (levels_of_brace_nesting < 0) {
		printf("%d extra braces\n", -levels_of_brace_nesting);
	}

	if(levels_of_bracket_nesting > 0) {
		printf("%d unclosed brackets\n", levels_of_bracket_nesting);
	} else if (levels_of_bracket_nesting < 0) {
		printf("%d extra brackets\n", -levels_of_bracket_nesting);
	}
}

bool is_current_char_escaped(char prev_chars[]) {
	return prev_chars[0] == '\\' && prev_chars[1] != '\\';
}
