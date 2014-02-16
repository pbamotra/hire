/*
 * lcs.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: pbamotra
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int min(int a, int b) {
	return (a<b)?a:b;
}

int lcs(string a, string b) {
	int acounts[256] = {0};
	int bcounts[256] = {0};
	int result = 0;

	int alen = strlen(a.c_str());
	int blen = strlen(b.c_str());

	for(int i=0; i<alen; i++) {
		acounts[(int)a[i]]++;
	}
	for(int i=0; i<blen; i++) {
			bcounts[(int)b[i]]++;
	}

	for(int i=0; i< 256; i++) {
		if(acounts[i]>0 && bcounts[i]>0)
		{
			result+= min(acounts[i], bcounts[i]);
		}
	}
	return result;
}
/**
int main(int argc, char** argv) {
	int n_test = 0;
	cin>> n_test;
	n_test *= 2;
	string arr;
	vector<string> vec;

	for(int i = 0 ; i < n_test; ++i)
	  if(cin >> arr)
		  vec.push_back(arr);

	for(unsigned int i=0; i<vec.size(); i+=2) {
		cout<<lcs(vec[i], vec[i+1])<<endl;
	}
	return 0;
}
**/



