/*
 * queue.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: pbamotra
 */
#include <iostream>
using namespace std;

template<class T>
class Node {
public:
	T val;
	Node* next;

public:
	Node(T data) {
		val = data;
		next = NULL;
	}
};

template<class T>
class Queue {
public:
	Node<T>* front;
	Node<T>* rear;

public:
	Queue() {
		front = rear = NULL;
	}

	int getFrontVal() {
		if(front) return front->val;
		else {
			cout<<"Queue empty";
			return -99999999;
		}
	}

	int getRearValue() {
		if(rear) return rear->val;
		else {
					cout<<"Queue empty";
					return -99999999;
		}
	}

	void enqueue(T n) {
		Node<T>* newNode = new Node<T>(n);
		if(front == NULL) {
			front = newNode;
		} else {
			rear->next = newNode;
		}
		rear = newNode;
	}

	void dequeue() {
		Node<T>* temp = front;
		front = front->next;
		cout<<endl;
		cout<<"Deleted from front : "<<temp->val;
		cout<<endl;
		delete temp;
	}

	void printQueue() {
		Node<T>* temp = front;
		do {
			cout<<temp->val<<"\t";
			temp = temp->next;
		} while(temp!=NULL);
	}
};
/**
int main(int argc, char** argv) {
	Queue<int>* myQ = new Queue<int>();
	myQ->enqueue(12);
	myQ->enqueue(24);
	myQ->enqueue(36);
	myQ->enqueue(48);
	myQ->printQueue();
	myQ->dequeue();
	myQ->printQueue();
	cout<<endl;
	cout<<"Front: "<<myQ->getFrontVal()<<endl;
	cout<<"Rear: "<<myQ->getRearValue()<<endl;
	return 0;
}**/
