#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

class Queue
{
public:
	int isFull();
	int isEmpty();
	void enqueue(int item);
	int dequeue();
	int getfront();
	int getrear();
	Queue(unsigned capacity);
	~Queue();
private:
	int front, rear, size;
	unsigned capacity;
	int* array; // The Queue
};

Queue::Queue(unsigned capacity1)
{
	capacity = capacity1;
	front = size = 0;
	rear = capacity - 1;
	//Change the data types if you are not using an integer
	array = (int*)malloc(capacity * sizeof(int));
}

Queue::~Queue()
{
}

int Queue::isFull() {
	return (size == capacity); // return true if full
}

int Queue::isEmpty() {
	return (size == 0); //return true if the size of the queue is equal to zero
}

//Add an item to the queue this will change the rear and the front of the queue
void Queue::enqueue(int item) {
	if (isFull()) {
		return;
	}
	//increament the rear value of the queue
	rear = (rear + 1) % capacity;
	array[rear] = item; //Assign the item to the array
	size = size + 1; //Change the size of the queue
	cout << item << " added to queue\n" << endl;
}


//Remove the from queue. Changes the front and size of the queue
int Queue::dequeue() {
	if (isEmpty())
		return INT_MIN;
	int item = array[front]; // Removes the front item
	front = (front + 1) % capacity;
	size = size - 1;
	cout << item << " had been deleted from queue\n" << endl;
	return item; // Deleted value
}

//Get front element of the queue
int Queue::getfront() {
	if (isEmpty())
		return INT_MIN;
	return array[front];
}

//Get rear element of the queue
int Queue::getrear() {
	if (isEmpty())
		return INT_MIN;
	return array[rear];
}
