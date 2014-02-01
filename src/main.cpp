/*
 * File:   main.cpp
 * Author: pbamotra
 * Company: PayPal India
 *
 * Created on February 1, 2014, 7:19 PM
 *
 * Given an array of integer elements and an integer d please consider all the
 * sequences of d consecutive elements in the array. For each sequence we
 * compute the difference between the maximum and the minimum value of the
 * elements in that sequence and name it the deviation.
 *
 *	•	write a function that computes the maximum value among the deviations of all the sequences considered above
 *	•	print the value the standard output (stdout)
 *
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

template<class TYPE>
TYPE* spliceArray(TYPE array[], int start, int end) {
    static TYPE* boo = new TYPE[end - start + 1];
    for (int i = 0; i < (end - start + 1); i++) {
        boo[i] = array[i + start];
    }
    return boo;
}

template<class TYPE>
TYPE getMinMax(TYPE array[], int size, bool isMin = true) {
    TYPE init = array[0];
    if (!isMin) {
        for (int i = 1; i < size; i++) {
            if (array[i] > init) {
                init = array[i];
            }
        }
    } else {
        for (int i = 1; i < size; i++) {
            if (array[i] < init) {
                init = array[i];
            }
        }
    }
    return init;
}

template<class TYPE>
int findMaxDeviation(TYPE array[], int size, int d) {

    static int result = -999999;
    for (int i = 0; i < size - d + 1; i++) {
        TYPE* splice = spliceArray<TYPE>(array, i, i + d);
        TYPE dev = getMinMax(splice, d, false) - getMinMax(splice, d);
        if (dev > result) {
            result = dev;
        }
    }
    return result;
}

template<class TYPE>
TYPE* randomGen(TYPE limit, int count) {
    static TYPE* randArr = new TYPE[count];
    srand((unsigned) time(0));
    for (int index = 0; index < count; index++) {
        randArr[index] = (rand() % limit) + 1;
    }
    return randArr;
}

template<class TYPE>
void printArray(TYPE array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " - ";
    }
}

int main(int argc, char** argv) {
    int length = 100000;
    int* array = randomGen<int>((int) pow(2, 20), length);
    cout << endl << "Answer is : " << findMaxDeviation(array, length, 3);
    return 0;
}

