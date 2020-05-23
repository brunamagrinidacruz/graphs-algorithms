#include "algorithms.h"

int get_unvisited_vertex_with_smallest_distance(int number_of_vertices, int max_distancy, int *visited_vertex, int *shortest_distance) {
    int i;
    int min_vertex;
    //Initializing as the min value the max value + 1
    int min_distancy = max_distancy+1;
    //Checking what vertex unvisited has the shortest distance
    for(i = 0; i < number_of_vertices; i++) {
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
        //To navigate in the neighbours of the current vertex
        int next_vertex, current_vertex;
        //Weight of the edge and distancy
        int weight, distancy;
        
        //Initializing the shortest_distance and previous_vertex
        // as the max distance between two vertex + 1
        for(i = 0; i < number_of_vertices; i++) {
            shortest_distance[i] = max_distancy+1;
            previous_vertex[i] = max_distancy+1;
        }
        //Initializing the initial vertex with shortest_distance = 0
        shortest_distance[initial_vertex] = 0;
        previous_vertex[initial_vertex] = -1;

        while(all_vertices_visited < number_of_vertices) {
            unvisited_vertex_with_smallest_distance = get_unvisited_vertex_with_smallest_distance(number_of_vertices, max_distancy, visited_vertex, shortest_distance);

            if(!graph_is_adjacency_list_empty(graph, unvisited_vertex_with_smallest_distance)) {
                int first_vertex_list_adjacency = graph_first_vertex_list_adjacency(graph, unvisited_vertex_with_smallest_distance);
                int is_end_vertex_list_adjacency = 0;
                //We are initializing the next_vertex as the first vertex of the list,
                //This because the function graph_next_vertex_list_adjacency will put the next_vertex
                //In current_vertex
                next_vertex = first_vertex_list_adjacency;
                //While the adjacency list of the vertex doesn't end, continue to visited their adjacencys
                while(!is_end_vertex_list_adjacency) {
                    //This function will put in current_vertex the id of the vertex we are analizing
                    //And in next_vertex, it will put the value of the next_vertex to be executed
                    is_end_vertex_list_adjacency = graph_next_vertex_list_adjacency(graph, unvisited_vertex_with_smallest_distance, &current_vertex, &next_vertex);

                    // If the vertex is visited, go to the next
                    if(visited_vertex[current_vertex] == 1) continue;
                    
                    //Calculating the distance between the current_vertex of adjacent list and the unvisited vertex
                    weight = graph_weight_edge(graph, unvisited_vertex_with_smallest_distance, current_vertex);
                    distancy = shortest_distance[unvisited_vertex_with_smallest_distance] + weight;

                    //If the distancy is less then the older, update
                    if(distancy <= shortest_distance[current_vertex]) {
                        shortest_distance[current_vertex] = distancy;
                        previous_vertex[current_vertex] = unvisited_vertex_with_smallest_distance;    
                    }
                }
            }
            //Updat the vertex to visited and increment the flag
            visited_vertex[unvisited_vertex_with_smallest_distance] = 1;
            all_vertices_visited++;
        }
        free(visited_vertex);
        return;
        
    }
}