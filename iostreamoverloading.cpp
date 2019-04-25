#include <iostream>
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex() : real(0), imag(0) {}
	Complex(int r, int i) : real(r), imag(i) {}
	friend ostream& operator << (ostream& out, const Complex &c);
	friend istream& operator >> (istream& in, Complex &c);
};

ostream& operator << (ostream& out, const Complex &c) {
	out << c.real;
	out << " +i" << c.imag << endl;
	return out;
}
istream& operator >> (istream& in, Complex &c) {
	cout << "enter real : ";
	in >> c.real;
	cout << "enter image : ";
	in >> c.imag;
	return in;
}

int main() {
	Complex c1;
	cin >> c1;
	cout << "the complex number is ";
	cout << c1;
	system("pause");
}