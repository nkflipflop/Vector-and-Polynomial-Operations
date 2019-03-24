using namespace std;

class Polynomial {
	int degree;
	int *contents;
public:
	Polynomial();						// Default Constructor
	Polynomial(int *);					// Constructor
	Polynomial(const Polynomial &);  	// Copy Constructor
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator*(const Polynomial &object_in) const;
	friend ostream & operator <<(ostream &, const Polynomial &);
};

Polynomial::Polynomial() {
}

// Constructor
Polynomial::Polynomial(int *in_data) {
	degree = in_data[0];
	contents = new int[degree+1];
	for (int i = 0; i <= degree; i++)
		contents[i] = in_data[i + 1];
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial &object_in) {
	degree = object_in.degree;
	contents = new int[degree+1];
	for (int i = 0; i < degree+1; i++)
		contents[i] = object_in.contents[i + 1];
}

//Polynomial Addition
Polynomial Polynomial::operator+(const Polynomial &object_in) const {
	int *contents_new;
	int degreeDifferance = degree - object_in.degree;		// calculates degree differance
	
	if (degreeDifferance > 0) {			// if the degree of the left is greater
		contents_new = new int[degree + 2];
		contents_new[0] = degree;
		for (int i = 0; i <= degree + 1; i++) {
			while (degreeDifferance > 0) {
				contents_new[i + 1] = contents[i];
				i++;
				degreeDifferance--;
			}
			contents_new[i + 1] = contents[i] + object_in.contents[i + object_in.degree - degree];
		}
	}
	else if (degreeDifferance < 0) {	// if the degree of the right is greater
		contents_new = new int[object_in.degree + 2];
		contents_new[0] = object_in.degree;
		for (int i = 0; i <= object_in.degree + 1; i++) {
			while (degreeDifferance < 0) {
				contents_new[i + 1] = object_in.contents[i];
				i++;
				degreeDifferance++;
			}
			contents_new[i + 1] = object_in.contents[i] + contents[i + degree - object_in.degree];
		}
	}
	else {								// if the degrees are equal
		contents_new = new int[object_in.degree + 2];
		contents_new[0] = object_in.degree;
		for (int i = 0; i <= object_in.degree + 1; i++)
			contents_new[i + 1] = contents[i] + object_in.contents[i];
	}
	return Polynomial(contents_new);
}

//Vector Dot Product
Polynomial Polynomial::operator*(const Polynomial &object_in) const {
	int *contents_new = new int[degree + object_in.degree + 2];

	contents_new[0] = degree + object_in.degree;
	for (int i = 1; i <= contents_new[0]+1; i++)
		contents_new[i] = 0;

	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= object_in.degree; j++)
			contents_new[i + j + 1] += contents[i] * object_in.contents[j];
	}
	return Polynomial(contents_new);
}

// Overloading << for Vector print operation
ostream & operator <<(ostream &output, const Polynomial &object_in) {
	for (int i = 0; i <= object_in.degree; i++) {
		if (i == object_in.degree)
			output << object_in.contents[i];
		else if( i == object_in.degree - 1 && object_in.contents[i] == 1)
			output << "x" ;
		else if (i == object_in.degree - 1 && object_in.contents[i] != 1)
			output << object_in.contents[i] << "x";
		else if (object_in.contents[i] == 1)
			output << "x^" << object_in.degree - i;
		else if (object_in.contents[i] != 0)
			output << object_in.contents[i] << "x^" << object_in.degree - i;

		if (i != object_in.degree && object_in.contents[i] != 0)
			output << " + ";
	}
	return output;
};