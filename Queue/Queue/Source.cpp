#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

struct Queue
{
	//Front Index, Rear Index, The Size of the queue
	int front, rear, size;
	unsigned capacity;
	int* array; // The Queue
};

struct Queue* createQueue(unsigned capacity) {
	//Create a stuct and allocate the memory
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	//Change the data types if you are not using an integer
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity); // return true if full
}

int isEmpty(struct Queue* queue) {
	return (queue->size == 0); //return true if the size of the queue is equal to zero
}

//Add an item to the queue this will change the rear and the front of the queue
void enqueue(struct Queue* queue, int item) {
	if (isFull(queue)) {
		return;
	}
	//increament the rear value of the queue
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item; //Assign the item to the array
	queue->size = queue->size + 1; //Change the size of the queue
	cout << item << " added to queue\n" << endl;
}


//Remove the from queue. Changes the front and size of the queue
int dequeue(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front]; // Removes the front item
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	cout << item << " had been deleted from queue\n" << endl;
	return item; // Deleted value
}

//Get front element of the queue
int front(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

//Get rear element of the queue
int rear(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int junk() {
	struct Queue* queue = createQueue(1000);
	while (true) {
		int ans;
		cout << "1 add item, 2 delete item\n";
		cin >> ans;
		switch (ans)
		{
			case 1:
				int item;
				cout << "Enter item to add:\n";
				cin >> item;
				enqueue(queue, item);
				break;
			case 2:
				dequeue(queue);
				break;
			default:
				cout << "Didn't get that\n";
				break;
		}
	}
}