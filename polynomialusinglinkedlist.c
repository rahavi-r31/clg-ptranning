#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 100

typedef struct {
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} *Polynomial;

void ZeroPolynomial(Polynomial Poly);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);

void ZeroPolynomial(Polynomial Poly) {
    int i;
    for (i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
    int i;
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Poly1->HighPower > Poly2->HighPower ? Poly1->HighPower : Poly2->HighPower;
    for (i = PolySum->HighPower; i >= 0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

int main() {
    Polynomial poly1, poly2, polySum;

    poly1 = malloc(sizeof(*poly1));
    poly2 = malloc(sizeof(*poly2));
    polySum = malloc(sizeof(*polySum));

    // Initialize the polynomials
    ZeroPolynomial(poly1);
    ZeroPolynomial(poly2);
    ZeroPolynomial(polySum);

    // Set the coefficients and high powers of the polynomials
    poly1->CoeffArray[0] = 1;
    poly1->CoeffArray[1] = 2;
    poly1->HighPower = 1;

    poly2->CoeffArray[0] = 3;
    poly2->CoeffArray[1] = 2;
    poly2->CoeffArray[2] = 2;
    poly2->HighPower = 2;

    // Add the polynomials
    AddPolynomial(poly1, poly2, polySum);

    // Print the resulting polynomial
    int i;
    for (i = polySum->HighPower; i >= 0; i--)
        printf("%d ", polySum->CoeffArray[i]);
    printf("\n");

    // Free the allocated memory
    free(poly1);
    free(poly2);
    free(polySum);

    return 0;
}
