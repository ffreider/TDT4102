#include "std_lib_facilities.h"
#include "Graph.h"
#include "AnimationWindow.h" 

using namespace Graph_lib;
using namespace TDT4102;

void inputAndPrintInteger() {
	int x = 0;
	cout << "Skriv inn et tall: ";
	cin >> x;
	cout << x;
}

int inputInteger() {
	int x = 0;
	cout << "Skriv inn et tall: ";
	cin >> x;
	return x;
}

void inputIntegersAndPrintSum() {
	int x = inputInteger() + inputInteger();
	cout << "Summen av tallene: " << x << endl;
}

bool isOdd(int n) {
	if (n % 2 == 0) {
		return false;
	}
	return true;
}

void printHumanReadableTime(int n) {
	if (n <= 60) {
		cout << n << " sekunder.";
	}
	else if (n <= 60*60) {
		cout << n / 60 << " minutter, " << n - (n/60)*60 << " sekunder.";
	}
	else if (n <= 60*60*24) {
		cout << n/3600 << " timer, " << n%(60*60)/60 << " minutter og " << n%60 << " sekunder.";
	}
}

int loopSummer() {
	cout << "Hvor mange tall vil du summere: ";
	int x = 0;
	cin >> x;

	int sum = 0;
	for (int i = 0; i < x; i++) {
		int y = 0;
		cout << "tall: ";
		cin >> y;
		sum += y;
	}
	return sum;
}

void writeZero() {
	int sum = 0;

	int x = 1;
	while (x != 0) {
		cout << "Skriv et tall: ";
		cin >> x;
		sum += x;
		cout << "Sum av tall skrevet: " << sum << endl;
	}
	cout << "Du skrev 0.";
}

double inputDouble() {
	double x = 0.0;
	cout << "Skriv inn et tall: ";
	cin >> x;
	return x;
}

double fromKrToEuro() {
	double nok = 0;
	cout << "Skriv inn antall som skal konverteres fra NOK til EUR: ";
	cin >> nok;

	return nok * 9.75;
} 

void table() {
	cout << "Angi hoyde: " << endl;
	int height = 0;
	cin >> height;

	cout << "Angi bredde: " << endl;
	int width = 0;
	cin >> width;

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cout << "|" << setw(4) << j*i; 
		}
		cout << "|\n";
	}
}

double discriminant(double a, double b, double c) {
	return b*b - 4*a*c;
}

void printRealRoots(double a, double b, double c) {
	if (discriminant(a, b, c) == 0) {
		cout << "En losning: x = " << -b/(2*a) << endl;
	} else if (discriminant(a, b, c) > 0) {
		cout << "To losninger: x_1 = " << (-b-(discriminant(a, b, c)))/(2*a) << " og x_2 = " << (-b+(discriminant(a, b, c)))/(2*a) << endl;
	} else if (discriminant(a, b, c) < 0) {
		cout << "Ingen reel losning" << endl;	
	}
}

void solveQuadraticEquation() {
	int a = 1;
	int b = 1;
	int c = 1;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	printRealRoots(a, b, c);
}


void pythagoras() {
	AnimationWindow win{100, 100, 1000, 1000, "Pythagoras"};
	Point point1{300, 300}; 
	Point point2{300, 500}; 
	Point point3{500, 500}; 
	win.draw_triangle(point1, point2, point3, Color::red);
	win.draw_quad(Point{300, 300}, Point{500, 500}, Point{700, 300}, Point{500, 100}, Color::blue);
	win.draw_quad(Point{300, 500}, Point{500, 500}, Point{500, 700}, Point{300, 700}, Color::yellow);
	win.draw_quad(Point{300, 300}, Point{300, 500}, Point{100, 500}, Point{100, 300}, Color::green);
	win.wait_for_close();
}

vector<int> calculateBalance(int total, int yield, int years) {
	vector<int> t(years);
	t[0] = total; 
	for (int i = 1; i < years; i++) {
		t[i] = (t[i-1])*(static_cast<double>(yield)/100 + 1);
	}
	return t;
}

void printBalance(vector<int> vec) {
	cout << setw(6) << "| " << "Year:";
	cout << setw(1) << "| " << "Amount:" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << setw(6) << "| " << i;
		cout << setw(6) << "| " << vec[i] << endl;
	}
}

int menu() { // Tror denne genererer en Warning fordi den ikke returner en int for alle valg? Eller er det fordi main en int og ikke void?
	int valg = 1;
	while (valg != 0) {	
		cout << "Velg funksjon:\n" << "0) Avslutt\n" << "1) Summer to tall\n" << "2) Summer flere tall\n" << "3) Konverter NOK til EURO\n" << "4) Andregradslikning\n" << "5) Rentekalkulator\n" << "Angi valg (0-5): ";
		cin >> valg;

		if (valg == 0) {
			return EXIT_SUCCESS;
		}
		else if (valg == 1) {
			inputIntegersAndPrintSum();
		}
		else if (valg == 2) {
			cout << loopSummer();
		}
		else if (valg == 3) {
			cout << fixed << setprecision(2) << fromKrToEuro();
		} 
		else if (valg == 4) {
			solveQuadraticEquation();
		} 
		else if (valg == 5) {
			int total = 0, yield = 0, years = 0;
			cout << "Første bankinnskudd: ";
			cin >> total;
			cout << "Rente: ";
			cin >> yield;
			cout << "Antall år med sparing: ";
			cin >> years;
			printBalance(calculateBalance(total, yield, years));
		}
		else {
			cout << "Invalid input.";
		}
	}
}

int main() {
	// OPPGAVE 1

		// a) 
	// inputAndPrintInteger();

		// b)
	// int number = inputInteger();
	// cout << "Du skrev: " << number;

		// c)
	// inputIntegersAndPrintSum();

		// d)
	// Fordi inputInteger returnerer verdien som gjør det mulig for meg å bruke den videre.

		// e)
	// cout << (isOdd(3) ? "true" : "false");

		// f)
	// printHumanReadableTime(20000);

	// OPPGAVE 2
		
		// a)
	// cout << loopSummer(); // Får en merkelig feil hvis jeg endrer funksjonen til å printe istedenfor å returnere.
	// Unhandled exception at 0x00007FF662FE86B9 in debug.exe: 0xC000001D: Illegal Instruction. 

		// b)
	// writeZero();

		// c)
	// For er god for kjøring i en gitt periode, mens while funker bedre for ubestemt tid.

	    // d)
	// cout << inputDouble();

		// e)
	// cout << fixed << setprecision(2) << fromKrToEuro();

	// OPPGAVE 3
		
		// a)
	// menu();

		// b)
	// table();

	// OPPGAVE 4

		// a)
	// cout << discriminant(1,2,3);

		// b)
	// printRealRoots(1,-2,-11);

		// c)
	// menu();

	// OPPGAVE 5
	// pythagoras();

	// OPPGAVE 6
		
		// a)
	// for (int i: calculateBalance(5000, 3, 5)) {
	// 	cout << i << ' ';
	// }

		// b)
	// menu();
		
		// c)
	// Som jeg forstår det er vektorer en klasse og cout støtter ikke klasser, men ikke helt sikker på hva dette egentlig betyr.

		// d) <= må erstattes med < siden v[9] ikke eksisterer.
	// vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// for (int i = 0; i < v.size(); i++) {
	// 	cout << v[i] << endl;
	// }
}