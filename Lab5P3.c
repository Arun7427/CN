#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int numVertices, int startNode)
{
    int distance[MAX], visited[MAX];
    int i, j, count, minDistance, nextNode;

    for (i = 0; i < numVertices; i++)
    {
        distance[i] = graph[startNode][i];
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;

    for (count = 1; count < numVertices - 1; count++)
    {
        minDistance = INFINITY;
        nextNode = -1;

        for (i = 0; i < numVertices; i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        if (nextNode == -1)
            break;

        visited[nextNode] = 1;

        for (i = 0; i < numVertices; i++)
        {
            if (!visited[i] &&
                graph[nextNode][i] != INFINITY &&
                distance[nextNode] + graph[nextNode][i] < distance[i])
            {
                distance[i] = distance[nextNode] + graph[nextNode][i];
            }
        }
    }

    printf("\nShortest distances from node %d:\n", startNode);

    for (i = 0; i < numVertices; i++)
    {
        printf("To node %d = %d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int numVertices, i, j, startNode;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the starting node (0 to %d): ", numVertices - 1);
    scanf("%d", &startNode);

    dijkstra(graph, numVertices, startNode);

    return 0;
}
