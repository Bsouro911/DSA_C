#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the Term Structure
typedef struct Term
{
    int coeff;
    int exp;
    struct Term *next;
} Term;

// Function to create a new Term node
Term *createTerm(int coeff, int exp)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));
    if (newTerm == NULL)
    {
        perror("Memory allocation for Term failed");
        exit(EXIT_FAILURE);
    }
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a new term into the polynomial linked list
void insertTerm(Term **poly, int coeff, int exp)
{
    Term *newTerm = createTerm(coeff, exp);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial expression
void displayPolynomial(Term *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }
    while (poly != NULL)
    {
        if (poly->exp == 0)
        {
            printf("%d", poly->coeff);
        }
        else if (poly->exp == 1)
        {
            printf("%dx", poly->coeff);
        }
        else
        {
            printf("%dx^%d", poly->coeff, poly->exp);
        }
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials and store the result in a new linked list
Term *addPolynomials(Term *poly1, Term *poly2)
{
    Term *result = NULL;
    while (poly1 != NULL || poly2 != NULL)
    {
        int coeff1 = (poly1 != NULL) ? poly1->coeff : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coeff : 0;
        int exp1 = (poly1 != NULL) ? poly1->exp : 0;
        int exp2 = (poly2 != NULL) ? poly2->exp : 0;

        int newCoeff = coeff1 + coeff2;
        int newExp = (exp1 > exp2) ? exp1 : exp2;
        insertTerm(&result, newCoeff, newExp);

        if (poly1 != NULL)
        {
            poly1 = poly1->next;
        }
        if (poly2 != NULL)
        {
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to multiply two polynomials and store the result in a new linked list
Term *multiplyPolynomials(Term *poly1, Term *poly2)
{
    Term *result = NULL;
    while (poly1 != NULL)
    {
        Term *temp = poly2;
        while (temp != NULL)
        {
            int newCoeff = poly1->coeff * temp->coeff;
            int newExp = poly1->exp + temp->exp;
            insertTerm(&result, newCoeff, newExp);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

// Function to evaluate the polynomial for a given value of x
int evaluatePolynomial(Term *poly, int x)
{
    int result = 0;
    while (poly != NULL)
    {
        result += poly->coeff * pow(x, poly->exp);
        poly = poly->next;
    }
    return result;
}

// Function to multiply a polynomial by a scalar value
void multiplyPolynomialByScalar(Term *poly, int scalar)
{
    while (poly != NULL)
    {
        poly->coeff *= scalar;
        poly = poly->next;
    }
}

// Function to differentiate a polynomial and store the result in a new linked list
Term *differentiatePolynomial(Term *poly)
{
    Term *result = NULL;
    while (poly != NULL)
    {
        int newCoeff = poly->coeff * poly->exp;
        int newExp = poly->exp - 1;
        if (newExp >= 0)
        {
            insertTerm(&result, newCoeff, newExp);
        }
        poly = poly->next;
    }
    return result;
}

// Function to integrate a polynomial and store the result in a new linked list
Term *integratePolynomial(Term *poly)
{
    Term *result = NULL;
    while (poly != NULL)
    {
        int newCoeff = poly->coeff / (poly->exp + 1);
        int newExp = poly->exp + 1;
        insertTerm(&result, newCoeff, newExp);
        poly = poly->next;
    }
    return result;
}

// Function to free memory allocated for a polynomial
void freePolynomial(Term *poly)
{
    while (poly != NULL)
    {
        Term *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    Term *poly1 = NULL;
    Term *poly2 = NULL;

    printf("Enter the number of terms for polynomial 1: ");
    int n;
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial 1:\n");
    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial 2:\n");
    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Term *result;

    // Addition
    result = addPolynomials(poly1, poly2);
    printf("Addition Result: ");
    displayPolynomial(result);
    freePolynomial(result);

    // Multiplication
    result = multiplyPolynomials(poly1, poly2);
    printf("Multiplication Result: ");
    displayPolynomial(result);
    freePolynomial(result);

    // Evaluation
    int x;
    printf("Enter the value of x for polynomial evaluation: ");
    scanf("%d", &x);
    int evaluationResult = evaluatePolynomial(poly1, x);
    printf("Polynomial 1 evaluated at x = %d: %d\n", x, evaluationResult);

    // Optional Challenge: Multiplication by Scalar
    int scalar;
    printf("Enter a scalar value for polynomial multiplication: ");
    scanf("%d", &scalar);

    multiplyPolynomialByScalar(poly1, scalar);
    printf("Polynomial 1 multiplied by scalar %d: ", scalar);
    displayPolynomial(poly1);

    // Optional Challenge: Differentiation
    result = differentiatePolynomial(poly1);
    printf("Differentiation Result for Polynomial 1: ");
    displayPolynomial(result);
    freePolynomial(result);

    // Optional Challenge: Integration
    result = integratePolynomial(poly1);
    printf("Integration Result for Polynomial 1: ");
    displayPolynomial(result);
    freePolynomial(result);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);

    return 0;
}
