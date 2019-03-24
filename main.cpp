/* @Author
* Student Name: Nurdogan Karaman
* Student ID : 150150141
* Date: 25.03.2019 */

#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Polynomial.h"
//#pragma warning(disable : 4996)

using namespace std;
ifstream input;
Vector *Vectors;
Polynomial *Polynomials;
int vectorsAmount;
int polynomialsAmount;


void inputTake(char *in) {				// takes inputs that polynomials or vector which will be operated
	cin >> in[0] >> in[1] >> in[2];
}

void Operations(char *in, int option) { // does the operations
	int sum;

	if (option == 2) {					// polynomial operations
		Polynomial *nwV = new Polynomial;
		if (in[1] == '+') {				// Sum
			*nwV = Polynomials[in[0] - 49] + Polynomials[in[2] - 49];
			cout << "(" << Polynomials[in[0] - 49] << ") + (" << Polynomials[in[2] - 49] << ") = " << *nwV << endl;
		}
		else if (in[1] == '*') {		// Multiplication
			*nwV = Polynomials[in[0] - 49] * Polynomials[in[2] - 49];
			cout << "(" << Polynomials[in[0] - 49] << ") * (" << Polynomials[in[2] - 49] << ") = " << *nwV << endl;
		}
	}
	else {								// vector operations
		Vector *nwV = new Vector;
		if (in[1] == '+') {				// Sum
			*nwV = Vectors[in[0] - 49] + Vectors[in[2] - 49];
			cout << Vectors[in[0] - 49] << " + " << Vectors[in[2] - 49] << " = " << *nwV << endl;

		}
		else if (in[1] == '*') {		// Scalar multiplication
			*nwV = Vectors[in[0] - 49] * (in[2] - 48);
			cout << Vectors[in[0] - 49] << " * " << in[2] << " = " << *nwV << endl;
		}
		else if (in[1] == '.') {		// Dot product
			sum = Vectors[in[0] - 49] * Vectors[in[2] - 49];
			cout << Vectors[in[0] - 49] << " . " << Vectors[in[2] - 49] << " = " << sum << endl;
		}
	}

}

void Print() {		// Prints the list of elements
	cout << "Vectors:" << endl;
	for (int i = 0; i < vectorsAmount; i++)
		cout << i + 1 << ". " << Vectors[i] << endl;

	cout << endl << "Polynomials:" << endl;
	for (int i = 0; i < polynomialsAmount; i++)
		cout << i + 1 << ". " << Polynomials[i] << endl;
}

void readFiles() {
	int unitsSize, *unitsVector, *unitsPolynomial;

	input.open("Vector.txt");			// Reads Vector.txt and assign values to the array
	if (!input)
		cout << "File can not be opened" << endl;

	input >> vectorsAmount;	
	Vectors = new Vector[vectorsAmount];

	for (int i = 0; i < vectorsAmount; i++) {
		input >> unitsSize;
		unitsVector = new int[unitsSize + 1];
		unitsVector[0] = unitsSize;
		for (int j = 1; j <= unitsSize; j++)
			input >> unitsVector[j];

		Vector newVector(unitsVector);
		Vectors[i] = newVector;

		delete[] unitsVector;
	}
	input.close();

	input.open("Polynomial.txt");		// Reads Polynomial.txt and assign values to the array
	if (!input)
		cout << "File can not be opened" << endl;

	input >> polynomialsAmount;
	Polynomials = new Polynomial[polynomialsAmount];

	for (int i = 0; i < polynomialsAmount; i++) {
		input >> unitsSize;
		unitsPolynomial = new int[unitsSize + 2];
		unitsPolynomial[0] = unitsSize;

		for (int j = 1; j <= unitsSize+1; j++) {
			input >> unitsPolynomial[j];
		}
		Polynomial newPolynomial(unitsPolynomial);
		Polynomials[i] = newPolynomial;

		delete[] unitsPolynomial;
		
	}
	input.close();
}

void menuActions() {		// Menu operations
	cout << "Polynomial and Vector List Program!" << endl;
	cout << "Polynomials and Vectors are read from text files!\n" << endl;

	//The Great Menu
	cout << "Possible Actions:" << endl;
	cout << "1 Print Polynomial and Vector lists" << endl;
	cout << "2 Do a polynomial operation" << endl;
	cout << "3 Do a vector operation" << endl;
	cout << "0 Exit the program" << endl;

	int option = -1;
	char *in = new char[3];
	while (option != 0) {
		cout << "\nEnter an option: ";
		cin >> option;
		switch (option) {
		case 1:
			Print();
			break;
		case 2:
			cout << "Which polynomial operation would you like to do?((+:addition, *:multiplication):" << endl;
			cin >> in[0] >> in[1] >> in[2];
			Operations(in, option);
			break;
		case 3:
			cout << "Which vector operation would you like to do?((+:addition, *:scalar multiplication, .:dot product):" << endl;
			cin >> in[0] >> in[1] >> in[2];
			Operations(in, option);
			break;
		default:
			break;
		}
	}
}

//------- Main Function -------
int main() {
	readFiles();	// Reads files
	menuActions();	// Does operations

	getchar();
	return 0;
}

