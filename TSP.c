Aim:To implement the Travelling Salesman Problem (TSP) using an appropriate algorithm
(such as brute force or dynamic programming) to find the shortest possible route
that visits each city exactly once and returns to the starting city

Program:
#include <stdio.h>
#define MAXN 15

// Used to initialize minCost to a very large value.
// Since all travel costs are non-negative, any valid cost
// will be less than INF and replace it.
#define INF 999999

int n;
int d[MAXN][MAXN];
// Bitwise AND checks whether that city's bit is set in S.
// S will have 2^n possible combinations of cities, so the size of it should be 1 << MAXN
int dp[MAXN][1 << MAXN];

// g(i,S)
// Returns the minimum cost of visiting all cities in set S starting from city i
int g(int i, int S)
{
    // Base case: If S is empty, return the cost to return to the starting city (A)
    if (S == 0)
        return d[i][0]; // g(i,{}) = d[i][0]

    // If already computed, return stored value
    if (dp[i][S] != -1)
        return dp[i][S];

    int minCost = INF;

    // Try all possible next cities
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set S
        if (S & (1 << k))
        {
            // g(i, S) = d(i,k) + g(k, S without k)
            int cost = d[i][k] + g(k, S & ~(1 << k));

            // Update minimum cost
            if (cost < minCost)
            {
                minCost = cost;
            }
        }
    }

    // Store and return result
    return dp[i][S] = minCost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize dp table with -1 (uncomputed)
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }

    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    int result = g(0, S);

    printf("Given Cost Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
