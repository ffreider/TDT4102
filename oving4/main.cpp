#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"


void printASCII(char c) {
   int i = c;
   cout<<"The ASCII value of "<<c<<" is "<<i<<endl;
}
int main()
{
	system("chcp 65001");
	srand (time(NULL));
	playMastermind();
	
	return 0;
}

