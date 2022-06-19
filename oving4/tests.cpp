#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

// gir da v0 + (increment*iterations) = 5 + (2*10) = 25
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}
void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}
void testString() {
    string x = randomizeString(8, 'A', 'F');
    cout << x << endl;
    string compareTo = "ABCDEF";
    vector<int> gradeCount (0, x.length());
    double average = 0.0;
    int worth = 5;
    for (int i = 0; i < int(compareTo.length()); i++) {
        int temp = countChar(x, char(compareTo[i]));
        gradeCount.push_back(temp);
        average += temp*worth;
        worth -= 1;
    }
    cout << average/double(compareTo.length());
}




