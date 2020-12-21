#include <stdlib.h>

int numcmp(char *leftstr, char *rightstr) {
    double left, right;

    left = atof(leftstr);
    right = atof(rightstr);

    if(left < right) return -1;
    if(right < left) return 1;

    return 0;
}

static char up_case(char c) {
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

/* case insensitive comparision */
int fldcmp(char *leftstr, char *rightstr) {
    while(*leftstr != '\0' && *rightstr != '\0' && *leftstr != *rightstr) {
	leftstr++;
	rightstr++;
    }

    if(*leftstr == *rightstr) return 0; /* leftstr and rightstr are equal */
    else if(up_case(*leftstr) < up_case(*rightstr)) return 1;
    else return -1;
}

static is_digit_or_letter(char c) {
    int is_digit = c >= '0' && c <= '9';
    int is_letter = (c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z');
    return is_digit || is_letter;
}

static dircmp_char(char c1, char c2) {
    if(c1 == c2) {
	return 0;
    } else {
	if(c1 == '\0') return -1;
	if(c2 == '\0') return 1;

	if(!(is_digit_or_letter(c1) && is_digit_or_letter(c2))) return 0;
	else {
	    if(c1 < c2) return -1;
	    else return 1;
	}
    }
}

/* directory order, ie only compare letters, digits and blanks */
int dircmp(char *s1, char *s2) {
    while(1) {
	int cmp = dircmp_char(*s1, *s2);
	if(cmp != 0 || *s1 == '\0') return cmp;

	s1++; s2++;
    }
}
