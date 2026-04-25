#include <stdio.h>

/**
 * Function: fib
 * Description: Computes the nth Fibonacci term using a recursive approach.
 * Complexity: O(2^n) - Tree Recursion with overlapping subproblems.
 * @param n: The index of the Fibonacci term to be computed.
 * @return: The Fibonacci value at the given index.
 */
int fib(int n)
{
    /* Base Condition: If n is 0 or 1, the term is the value itself */
    if (n <= 1)
    {
        return n;
    }

    /* Recursive Step: F(n) = F(n-1) + F(n-2) */
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, result = 0;

    /* Step 1: Read the input n and validate that it is non-negative */
    printf("Enter the value of n: ");
    scanf("%d", &n);

    /* Checking if input is a valid integer and non-negative */
    if (n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("\nNth Fibonacci term = %d\n", fib(n));

    return 0;
}
