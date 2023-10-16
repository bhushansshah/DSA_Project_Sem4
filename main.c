#include <stdio.h>
#include "structures.h"

int main(){
	route r;
	worker w;
//	w.current_location.x = 0;
//	w.current_location.y = 4;
//	w.capacity = 6;
//	w.picked_up = 0;
	printf("Enter the worker X coordinate - ");
	scanf("%lf", &w.current_location.x);
	printf("Enter the worker Y coordinate - ");
	scanf("%lf", &w.current_location.y);
	printf("Enter the worker capacity - ");
	scanf("%d", &w.capacity);
	printf("Enter the worker no. of parcels picked up - ");
	scanf("%d", &w.picked_up);
	init_route(&r, w.current_location);
	request **rq;
	request rq_new;
	int no_of_requests;
	rq = malloc(sizeof(request *) * no_of_requests);
	printf("Enter the no. of existing request - ");
	scanf("%d", &no_of_requests);
	for(int i = 0; i < no_of_requests; i++){
		rq[i] = (request *) malloc(sizeof(request));
		printf("Enter the request %d origin X coordinate - ", i + 1);
		scanf("%lf", &rq[i]->origin.x);
		printf("Enter the request %d origin Y coordinate - ", i + 1);
		scanf("%lf", &rq[i]->origin.y);
		printf("Enter the request %d destination X coordinate - ", i + 1);
		scanf("%lf", &rq[i]->destination.x);
		printf("Enter the request %d destination Y coordinate - ", i + 1);
		scanf("%lf", &rq[i]->destination.y);
		printf("Enter the request %d release time - ", i + 1);
		scanf("%lf", &rq[i]->release_time);
		printf("Enter the request %d deadline time - ", i + 1);
		scanf("%lf", &rq[i]->deadline_time);
		printf("Enter the capacity of the request %d - ", i + 1);
		scanf("%d", &rq[i]->capacity);

	}
	printf("Enter the new request origin X coordinate - ");
	scanf("%lf", &rq_new.origin.x);
	printf("Enter the request origin Y coordinate - ");
	scanf("%lf", &rq_new.origin.y);
	printf("Enter the request destination X coordinate - ");
	scanf("%lf", &rq_new.destination.x);
	printf("Enter the request destination Y coordinate - ");
	scanf("%lf", &rq_new.destination.y);
	printf("Enter the request release time - ");
	scanf("%lf", &rq_new.release_time);
	printf("Enter the request deadline time - ");
	scanf("%lf", &rq_new.deadline_time);
	printf("Enter the capacity of the request  - ");
	scanf("%d", &rq_new.capacity);
/*
	rq1.origin.x = 4;
	rq1.origin.y = 4;
	rq1.destination.x = 10;
	rq1.destination.y = 4;
	rq1.release_time = 0;
	rq1.deadline_time = 25;
	rq1.capacity = 1;

	rq2.origin.x = 8;
	rq2.origin.y = 8;
	rq2.destination.x = 4;
	rq2.destination.y = 0;
	rq2.release_time = 0;
	rq2.deadline_time = 37;
	rq2.capacity = 1;

	rq3.origin.x = 10;
	rq3.origin.y = 2;
	rq3.destination.x = 10;
	rq3.destination.y = 0;
	rq3.release_time = 0;
	rq3.deadline_time = 33;
	rq3.capacity = 1;

	rq_new.origin.x = 4;
	rq_new.origin.y = 6;
	rq_new.destination.x = 6;
	rq_new.destination.y = 2;
	rq_new.release_time = 2;
	rq_new.deadline_time = 26;
	rq_new.capacity = 1;
*/
	int ind;
	int option;
	int flag;
	int *check_origin = calloc(no_of_requests, sizeof(int));
	int *check_destination = calloc(no_of_requests, sizeof(int));
	for(int i = 0; i < 2 * no_of_requests; i++){
		flag = 1;
		while(flag){
			while(1){
				printf("Enter the request no. of the for location %d in the route - ", i + 1);
				scanf("%d", &ind);
				if((ind > 0) && (ind <= no_of_requests)){
					break;
				}
				else{
					printf("!!You have entered incorrect input!!\nPlease try again.");

				}
			}
			if(i != 0){
				while(1){
					printf("Which location do you want to add? 1. Origin 2. Destination - ");
					scanf("%d", &option);
					if((option == 1) || (option == 2)){
						break;
					}
					else{
						printf("!!You have entered incorrect input!!\nPlease try again.");
					}
				}
			}
			else{
				option = 1;
			}
			if(option == 1){
				if(!check_origin[ind - 1]){
					add_location_in_route(&r, rq[ind - 1], 0);
					flag = 0;			
					check_origin[ind - 1] = 1;
				}
				else{
					printf("You have already added the origin of request %d in the route.\n", ind);
					printf("Please try again.\n");
				}
			}
			else{
				if(!check_destination[ind - 1]){
					if(!check_origin[ind - 1]){
						printf("You cannot add destination of request %d before origin in the route.\n", ind);
						printf("Please try again.\n");
					}
					else{
						add_location_in_route(&r, rq[ind - 1], 1);
						flag = 0;
						check_destination[ind - 1] = 1;
					}
				}
				else{
					printf("You have already added the destination of request %d in the route.\n", ind);
					printf("Please try again.\n");
				}
			}
		}	

	}
	/*
	add_location_in_route(&r, &rq1, 0);
	add_location_in_route(&r, &rq2, 0);
	add_location_in_route(&r, &rq1, 1);
	add_location_in_route(&r, &rq3, 0);
	add_location_in_route(&r, &rq3, 1);
	add_location_in_route(&r, &rq2, 1);
*/
	r = insertion_operator(r, w, &rq_new);
	printf("Route after insertion of the new request:\n");
	display_route(r);
	printf("max flow time - %lf\n", calculate_objective(r, rq_new.release_time));
	return 0;
}
