Aim:To implement an Approximation Algorithm for the Vertex Cover p
roblem in C to find a near-optimal set of vertices that covers all
edges of a given graph.
  Program:
  #include <stdio.h>
#define V 5 // Number of vertices in our graph

/* A simple greedy approach to find a Vertex Cover.
 * It follows a 2-approximation strategy.
 */
void findVertexCover(int graph[V][V])
{
    int visited[V]; // Array to represent our Cover Set 'C'

    // Start with an empty set C by marking all vertices as "unmarked = 0"
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Repeat until no unmarked edges remain
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] == 1 --> Edge Exists
            // !visited[u] && !visited[v] --> Both endpoints are unmarked.
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Add BOTH its endpoints to cover set C
                visited[u] = 1;
                visited[v] = 1;

                /* By marking 'u' and 'v' as visited,
                   all other edges connected to them are skipped */
            }
        }
    }

    // Print the Cover Set C
    printf("Approximate Vertex Cover: ");
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency Matrix representation (1 = Edge exists, 0 = No edge)
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");
    findVertexCover(graph);

    return 0;
}
