static void qsort_recurse(char *[], int, int, int (char *, char *), int);
static void swap(char *[], int, int);

/* underscore prepended to avoid name conflict with <stdlib.h> */
void _qsort(
    char *lineptr[],
    int lines,
    int cmp(char *, char *),
    int reverse) {
    qsort_recurse(lineptr, 0, lines - 1, cmp, reverse);
}

static void qsort_recurse(
    char *lineptr[],
    int left,
    int right,
    int cmp(char *, char *),
    int reverse) {
    int i, last;

    void swap(char *[], int, int);

    if (left >= right) /* do nothing if array contains fewer than two elements */
	return;

    swap(lineptr, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
	if ((reverse ? -1 : 1) * (*cmp)(lineptr[i], lineptr[left]) < 0)
	    swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    qsort_recurse(lineptr, left, last-1, cmp, reverse);
    qsort_recurse(lineptr, last+1, right, cmp, reverse);
}

static void swap(char *lineptr[], int i, int j) {
    char *temp;

    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}
