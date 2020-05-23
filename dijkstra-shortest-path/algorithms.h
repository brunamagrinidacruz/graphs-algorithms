#ifndef ALGORITHMS_H
    #define ALGORITHMS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "adjacency_list.h"

    void dijkstras(GRAPH* graph, int initial_vertex, int *shortest_distance , int *previous_vertex, int max_distancy);

#endif