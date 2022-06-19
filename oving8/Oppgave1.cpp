#include <iostream>
#include "Oppgave1.h"


void fillInFibonacciNumbers(long long* result, int length) {
	result[0] = 0;
	result[1] = 1;
	for (int i = 2; i < length; i++) {
		result[i] = result[i-1] + result[i-2];
	}
}

void printArray(long long* arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << std::endl;
	}
}

void createFibonacci() {
	int amount = 3;
	std::cout << "Hvor mange tall vil du ha med?" << std::endl;
	std::cin >> amount;
	long long *ptr = new long long[amount];
	fillInFibonacciNumbers(ptr, amount);
	printArray(ptr, amount);
	delete[] ptr;
	ptr = nullptr;
}