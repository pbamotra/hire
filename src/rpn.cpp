/*
 * rpn.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: pbamotra
 */

#include "myStack.h"
#include <string>
#include <iostream>

using namespace std;

int rpn_eval(const char rpn[], unsigned int n) {
	Stack<int>* mystack = new Stack<int>();
	int a, b;
	for (unsigned int i = 0; i < n; i++) {
		if (rpn[i] != '+' && rpn[i] != '-' && rpn[i] != '*' && rpn[i] != '/')
			mystack->push(int(rpn[i] - '0'));
		else {
			switch (rpn[i]) {
			case '+':
				a = mystack->pop();
				b = mystack->pop();

				mystack->push(a + b);
				break;
			case '-':
				a = mystack->pop();
				b = mystack->pop();

				mystack->push(b - a);
				break;
			case '*':
				a = mystack->pop();
				b = mystack->pop();

				mystack->push(a * b);
				break;
			case '/':
				a = mystack->pop();
				b = mystack->pop();

				mystack->push(b / a);
				break;
			}
		}
	}
	return mystack->pop();
}
/**
int main(int argc, char** argv) {
	const char rpn[] = { '3', '3', '+', '6', '*' };
	cout<<rpn_eval(rpn, sizeof(rpn) / sizeof(char));

	return 0;
}**/
