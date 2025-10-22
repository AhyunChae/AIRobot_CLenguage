#include <stdio.h>

int main(void) {
    int int_a, int_b, int_c;
    float f_a, f_b, f_c;
    double d_a, d_b, d_c;

    int_a = 1;
    printf("int_a: %d\n", int_a);

    f_a = 1.2; f_b = 0.1;
    int_b = f_a + f_a;
    printf("int_b: %d\n", int_b);

    return 0;
}

