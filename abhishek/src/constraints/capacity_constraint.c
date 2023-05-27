#include <stdio.h>
#include "constraints.h"

void pre_calculate_pck(Route r, double *pck_values, Worker worker){
	pck_values[0] = worker.picked_up;

	location_node *p = r.path->next_location_node;
	int i = 1;
	double pck_k = pck_values[0];

	Request *req;
	
	while(p){
		req = p->corresponding_request;

		if(p == req->origin){
			pck_k += req->capacity;
		}
		else if(p == req->destination){
			pck_k -= req->capacity;
		}

		pck_values[i] = pck_k;
		p = p->next_location_node;
		i++;
	}

	return;
}

int check_capacity_constraint(Worker worker, Request new_request, double *pck_values, int i, int j){
	int c = (worker.capacity - new_request.capacity);

	if((pck_values[i] <= c) && (pck_values[j] <= c)){
		return 1;
	}
	else{
		return 0;
	}
}