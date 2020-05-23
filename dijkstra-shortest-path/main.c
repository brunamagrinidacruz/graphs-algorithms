#include <stdio.h>
#include <stdlib.h>
#include "adjacency_list.h"
#include "algorithms.h"

#define INSERT_EDGE 1
#define REMOVE_EDGE 2
#define SHOW_LIST 3

int main(void) {
    GRAPH* graph;
    int i;
    int number_of_vertices, number_of_edges;
    int convergent, divergent, weight;
    int *shortest_distance, *previous_vertex;
    int initial_vertex, max_distancy = 0;

    printf("Number of vertices: ");
    scanf("%d", &number_of_vertices);
    graph = graph_create(number_of_vertices);

    printf("Number of edges: ");
    scanf("%d",&number_of_edges);
    printf("Edges: \n");
    for(i = 0; i < number_of_edges; i++) {
        printf("Convergent: ");
        scanf("%d", &convergent);
        printf("Divergent: ");
        scanf("%d", &divergent);
        printf("Weight: ");
        scanf("%d", &weight);
        //Set the max distancy as the sum of all weight because is going to be the max value of distance
        max_distancy += weight;
        graph_insert(graph, convergent, divergent, weight);
    }

    printf("Initial vertex: ");
    scanf("%d", &initial_vertex);

    shortest_distance = (int *) malloc (sizeof(int) * number_of_vertices);
    previous_vertex = (int *) malloc (sizeof(int) * number_of_vertices);
    
    dijkstras(graph, initial_vertex, shortest_distance, previous_vertex, max_distancy);

    printf("\nVertex | Distance | Previous Vertex\n");
    for(i = 0; i < number_of_vertices; i++) {
        printf("   %d   |     %d    |        %d \n", i, shortest_distance[i], previous_vertex[i]);
    }

    free(shortest_distance);
    free(previous_vertex);
    graph_delete(&graph);

    return 0;
}

