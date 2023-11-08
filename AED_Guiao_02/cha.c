#include <stdio.h>

void DisplayPol(double* coef, size_t degree) {
    if (coef == NULL || degree < 0) {
        // Handle invalid input
        printf("Invalid input.\n");
        return;
    }

    printf("Pol(x) = ");

    for (size_t i = 0; i <= degree; i++) {
        // Print the coefficient with 6 decimal places and x^i term
        printf(" i = %d , %.6f * x^%zu", i, coef[i], degree - i);
        if (i < degree) {
            // Print a '+' sign for all terms except the last one
            printf(" + ");
        }
    }

    printf("\n");
}

int main() {
    double coef[] = {1.0, 4.0, 1.0}; // Example coefficients for a polynomial: x^2 + 4x + 1
    size_t degree = 2; // Degree of the polynomial

    DisplayPol(coef, degree);

    return 0;
}
