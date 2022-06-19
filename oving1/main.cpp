//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"


//------------------------------------------------------------------------------'
int maxOfTwo (int a, int b) {
	if (a > b) {
		cout << "A is greater than B\n";
		return a;
	} else {
		cout << "B is greater than or equal to A\n";
		return b;
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for (int i = 1; i < n + 1; i++) {
		cout << i << " " << b << "\n";
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}

int squareNumberSum (int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i * i;
		cout << i * i << "\n";
	}
	cout << totalSum << "\n";
	return totalSum;
}

void triangleNumbersBelow (int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below : " << n << "\n";
	while (acc < n) {
		cout << acc << "\n";
		acc += num;
		num += 1;
	}
	cout << "\n";
}

bool isPrime (int n) {
	for (int j = 2; j < n; j++) {
		if (n % j == 0) {
			return false;
		}
	}
	return true;
}

void naivePrimeNumberSearch (int n) {
	for (int number = 2; number < n; number++) {
		if (isPrime(number)) {
			cout << number << " is a prime\n";
		}
	}
}

int findGreatestDivisor (int n) {
	for (int divisor = n - 1; n > divisor; divisor--) {
		if (n % divisor == 0 ) {
			return divisor;
		}
	}
}

// C++ programs start by executing the function main
int main()
{
	// OPPGAVE 2

		// a)
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << '\n';

		// c)
	cout << fibonacci (5);

		// d)
	cout << squareNumberSum (4);

		// e)
	triangleNumbersBelow(9);

		// f)
	cout << isPrime(9);

		// g)
	naivePrimeNumberSearch(9);

		// h)
	cout << findGreatestDivisor(21);
}




//------------------------------------------------------------------------------
