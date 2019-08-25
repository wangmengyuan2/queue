#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

static const struct product
{
	char name[10];
	double price;
	int	amount;
}list[] = {
	{"apple", 10.0, 2}, 
	{"tomato", 8.0, 2},
	{"potato", 4.0, 3},
	{"banana", 10.0, 1},
	{"melon", 4.0, 5},
	{""}, 
};

void destroy(void* data)
{
	
}

void function(void* data, void* user_data)
{
		struct product* product = data;
//		struct product* user_product = user_data;

		printf("matched!! name: %s, price: %lf, amout: %d\n", product->name, product->price, product->amount);
}

int main()
{
	struct queue* queue = queue_new();
	int i;
	
	struct product user_data = {"banana"};

	if(!queue){
		printf("queue_new error\n");
		return -1;
	}

	for(i = 0; strlen(list[i].name); i++){
		printf("pushing: %s\n", list[i].name);
		queue_push_tail(queue, &list[i]);
	}
	
	queue_foreach(queue, function, &user_data);

	queue_destroy(queue, destroy);	
	return 0;
	
}
