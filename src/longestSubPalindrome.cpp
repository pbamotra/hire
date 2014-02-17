/*
 * longestSubPalindrome.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: pbamotra
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string lcp(string input) {
	int maxLen = 0;
	int length = strlen(input.c_str());

	string result;
	const char* input_char_arr = input.c_str();

	int** storage = new int*[length];
	for (int i = 0; i < length; i++) {
		storage[i] = new int[length];
	}

	//All single letters will be Palindrome by themselves; trivial case so ignore in result
	for (int i = 0; i < length; i++) {
		storage[i][i] = 1;
	}

	//For consecutive letters we need to check
	for (int i = 0; i <= length - 2; i++) {
		if (input_char_arr[i] == input_char_arr[i + 1]) {
			storage[i][i + 1] = 1;
			result = input.substr(i, 2);
		}
	}
	for (int l = 3; l <= length; l++) {
		//For less than condition refer previous block
		for (int i = 0; i <= length - l; i++) {
			//We consider next l characters from i position
			int j = i + l - 1;
			if (input_char_arr[i] == input_char_arr[j]) {
				storage[i][j] = storage[i + 1][j - 1];
				if (storage[i][j] == 1 && l > maxLen) {
					result = input.substr(i, i + l);
				}
			} else {
				storage[i][j] = 0;
			}
		}
	}

	return result;
}

int main(int argc, char** argv) {
	cout<<lcp("abccdeff");
	return 0;
}

