/*
 * myStack.h
 *
 *  Created on: Feb 16, 2014
 *      Author: pbamotra
 */
#include <iostream>
using namespace std;

#ifndef MYSTACK_H_
#define MYSTACK_H_
/*
 * stack.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: pbamotra
 *
 *
 */

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
class Stack {
public:
	Node<T>* top;
public:
	Stack() {
		top = NULL;
	}

	void push(int n) {
		Node<T>* newNode = new Node<T>(n);
		if(top) {
			newNode->next = top;
		}
		top = newNode;
	}

	int pop() {
		Node<T>* temp = top;
		int ret = temp->val;
		top = top->next;
		delete temp;
		return ret;
	}

	void display() {
		cout<<"TOP =>";
		Node<T>* temp = top;
		do {
			cout<<temp->val<<"\t";
			temp=temp->next;
		}while(temp!=NULL);
	}
};

#endif /* MYSTACK_H_ */
