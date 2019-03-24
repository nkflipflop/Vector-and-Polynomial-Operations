using namespace std;

class Vector {
	int size;
	int *contents;
public:
	Vector();					// Default Constructor
	Vector(int *);				// Constructor
	Vector(const Vector &);  	// Copy Constructor
	Vector operator+(const Vector&) const;
	Vector operator*(const int) const;
	int operator*(const Vector &object_in) const;
	friend ostream & operator <<(ostream &, const Vector &);
};

Vector::Vector() {
}

// Constructor
Vector::Vector(int *in_data) {
	size = in_data[0];
	contents = new int[size];
	for (int i = 0; i < size; i++)
		contents[i] = in_data[i + 1];
}

// Copy Constructor
Vector::Vector(const Vector &object_in) {
	size = object_in.size;
	contents = new int[size];
	for (int i = 0; i < size; i++)
		contents[i] = object_in.contents[i + 1];
}

//Vector Addition
Vector Vector::operator+(const Vector &object_in) const {
	if (size == object_in.size) {
		int *contents_new;
		contents_new = new int[object_in.size + 1];
		contents_new[0] = object_in.size;
		for (int i = 0; i < object_in.size; i++)
			contents_new[i + 1] = contents[i] + object_in.contents[i];
		return Vector(contents_new);
	}
	else {			// if sizes are not equal
		cout << "Are you sure that you select the correct vectors?" << endl;
		return Vector();
	}
}

//Vector Scalar Multiplication
Vector Vector::operator*(const int num_in) const {
	int *contents_new = new int[size + 1];
	contents_new[0] = size;
	for (int i = 0; i < size; i++)
		contents_new[i + 1] = contents[i] * num_in;

	return Vector(contents_new);
}

//Vector Dot Product
int Vector::operator*(const Vector &object_in) const {
	if (size == object_in.size) {
		int *contents_new = new int[size + 1];
		int sum = 0;
		contents_new[0] = size;
		for (int i = 0; i < size; i++)
			sum += contents[i] * object_in.contents[i];
		return sum;
	}
	else {
		cout << "Are you sure that you select the correct vectors?" << endl;
		return 0;
	}
}

// Overloading << for Vector print operation
ostream & operator <<(ostream &output, const Vector &object_in) {
	output << "(";
	for (int i = 0; i < object_in.size; i++) {
		output << object_in.contents[i];
		if (i != object_in.size - 1)
			output << ", ";
	}
	output << ")";
	return output;
};