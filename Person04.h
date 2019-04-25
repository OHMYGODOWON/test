#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
public:
	Person() : name(string()) {}
	Person(string name) :name(name) {}
	string printName();
	friend ostream& operator << (ostream& out, const Person& p);
	friend istream& operator >> (istream& in, Person& p);
};

string Person::printName() {
	return name;
}
ostream& operator << (ostream& out, const Person& p) {
	out << p.name;
	return out;
}
istream& operator >> (istream& in, Person &p) {
	in >> p.name;
	return in;
}
