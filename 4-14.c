/*
 * Exercise 4-14.
 *
 * Define a macro swap(t,x,y) that interchanges two arguments of type t. (block structure will help)
 */

#include <stdio.h>

#define printd(expr) printf(#expr " - %f\n", (double) expr)
#define swap(t,x,y) {\
    t temp = x;\
    x = y;\
    y = temp;\
}

int main() {
    int x, y;

    x = 10;
    y = -10;

    printd(x);
    printd(y);
    puts("SWAP");
    swap(int, x, y);
    printd(x);
    printd(y);
}
