#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "insertion_operator.h"




RideSharing_State ridesharing_state;
double dis_from_origin[20];

int main(){

    Request r1, r2, r3, newRequest;
    
    init_Ridesharing_State(&ridesharing_state);
    printf("Ridesharing init done\n");
    init_request(&r1, 4, 4, 10, 4, 0, 25, 1);
    init_request(&r2, 8, 8, 4, 0, 0, 37, 1);
    init_request(&r3, 10, 2, 10, 0, 0, 33, 1);
    printf("Init request called successfullly\n");
    insert_node(&r1, r1.origin, 1);
    insert_node(&r2, r2.origin, 2);
    insert_node(&r1, r1.destination, 3);
    insert_node(&r3, r3.origin, 4);
    insert_node(&r3, r3.destination, 5);
    insert_node(&r2, r2.destination, 6);
    printf("Insert Node called successfully\n");
    display_route(ridesharing_state.route);
    init_request(&newRequest, 4, 6, 6, 2, 2, 26, 1);
    update_worker_route(&newRequest);
    printf("Update worker called successfully\n");
    display_route(ridesharing_state.route);
    printf("Outside display function\n");
    insertion_operator(&newRequest); 
    printf("Route after insertion\n");
    display_route(ridesharing_state.route);
    return 0;
}
