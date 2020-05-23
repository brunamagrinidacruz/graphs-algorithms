#include "algorithms.h"

int get_unvisited_vertex_with_smallest_distance(int number_of_vertices, int *visited_vertex, int *shortest_distance) {
    int i;
    //Initializing as the min value the first vertex
    int min_vertex = 0, min_distancy = shortest_distance[0];
    //Checking what vertex unvisited has the shortest distance
    for(i = 1; i < number_of_vertices; i++) {
        if(visited_vertex[i] == 0) {
            if(shortest_distance[i] < min_distancy) {
                min_distancy = shortest_distance[i];
                min_vertex = i;
            }
        }
    }
    return min_vertex;
}

void dijkstras(GRAPH* graph, int initial_vertex, int *shortest_distance , int *previous_vertex, int max_distancy) {
    if(graph != NULL) {
        int i;
        int number_of_vertices = graph_number_of_vertices(graph);

        //Initializing the visited vertex as 0 to all vertex
        int *visited_vertex = (int *) calloc(sizeof(int), number_of_vertices);
        //Flag to define if all vertices were visited
        int all_vertices_visited = 0;
        //Number of the vertex with the smallest distance from start vertex
        int unvisited_vertex_with_smallest_distance;

        //Initializing the shortest_distance and previous_vertex
        // as the max distance between two vertex + 1
        for(i = 0; i < number_of_vertices; i++) {
            shortest_distance[i] = max_distancy+1;
            previous_vertex[i] = max_distancy+1;
        }
        //Initializing the initial vertex with shortest_distance = 0
        shortest_distance[initial_vertex] = 0;

        while(!all_vertices_visited) {
            unvisited_vertex_with_smallest_distance = get_unvisited_vertex_with_smallest_distance(number_of_vertices, visited_vertex, shortest_distance);
            all_vertices_visited = 1;
            printf("unvisited: %d", unvisited_vertex_with_smallest_distance);
        }
        return;
    }
}