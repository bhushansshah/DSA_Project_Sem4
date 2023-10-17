#include <stdio.h>
#include "structures.h"

int main(int argc, char *argv[]){
	route r;
	worker w;
	int no_of_requests = argc - 3;
	char *worker_filename = argv[1];
	FILE *wfile = fopen(worker_filename, "r");
//	printf("Enter the worker X coordinate - ");
	fscanf(wfile, "%lf", &w.current_location.x);
//	printf("Enter the worker Y coordinate - ");
	fscanf(wfile, "%lf", &w.current_location.y);
//	printf("Enter the worker capacity - ");
	fscanf(wfile, "%d", &w.capacity);
//	printf("Enter the worker no. of parcels picked up - ");
	fscanf(wfile, "%d", &w.picked_up);
	fclose(wfile);
	init_route(&r, w.current_location);
	request **rq;
	request rq_new;
	rq = malloc(sizeof(request *) * no_of_requests);
	printf("Enter the no. of existing request - ");
	FILE *fptr;
	for(int i = 0; i < no_of_requests; i++){
		fptr = fopen(argv[i + 2], "r");
		rq[i] = (request *) malloc(sizeof(request));
//		printf("Enter the request %d origin X coordinate - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->origin.x);
//		printf("Enter the request %d origin Y coordinate - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->origin.y);
//		printf("Enter the request %d destination X coordinate - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->destination.x);
//		printf("Enter the request %d destination Y coordinate - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->destination.y);
//		printf("Enter the request %d release time - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->release_time);
//		printf("Enter the request %d deadline time - ", i + 1);
		fscanf(fptr, "%lf", &rq[i]->deadline_time);
//		printf("Enter the capacity of the request %d - ", i + 1);
		fscanf(fptr, "%d", &rq[i]->capacity);
		fclose(fptr);
		printf("done\n");

	}
	fptr = fopen(argv[argc - 1], "r");
//	printf("Enter the new request origin X coordinate - ");
	fscanf(fptr, "%lf", &rq_new.origin.x);
//	printf("Enter the request origin Y coordinate - ");
	fscanf(fptr, "%lf", &rq_new.origin.y);
//	printf("Enter the request destination X coordinate - ");
	fscanf(fptr, "%lf", &rq_new.destination.x);
//	printf("Enter the request destination Y coordinate - ");
	fscanf(fptr, "%lf", &rq_new.destination.y);
//	printf("Enter the request release time - ");
	fscanf(fptr, "%lf", &rq_new.release_time);
//	printf("Enter the request deadline time - ");
	fscanf(fptr, "%lf", &rq_new.deadline_time);
//	printf("Enter the capacity of the request  - ");
	fscanf(fptr, "%d", &rq_new.capacity);
	fclose(fptr);

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
				if((ind > 0) && (ind <= 2 * no_of_requests)){
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







	r = insertion_operator(r, w, &rq_new);
	printf("Route after insertion of the new request:\n");
	display_route(r);
	printf("max flow time - %lf\n", calculate_objective(r, rq_new.release_time));
	return 0;
}
