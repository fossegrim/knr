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

    if(*leftstr == *rightstr) return 0; /* lefstr and rightstr are equal */
    else if(up_case(*leftstr) < up_case(*rightstr)) return 1;
    else return -1;
}
