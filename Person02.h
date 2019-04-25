#include <string>
#include <iostream>
using namespace std;
/*
	Person class
	요구사항
	1. 이름저장
	2. 이름출력
*/
class Person {
private:
	string name;
public:
	Person() {}
	Person(string name) : name(name) {}
	string getName() {
		return name;
	}
	friend ostream& operator << (ostream& out, const Person &p);
	friend istream& operator >> (istream& in, Person &p);
};
ostream& operator << (ostream& out, const Person &p) {
	out << p.name;
	return out;
}
istream& operator >> (istream& in, Person &p) {
	cout << "enter name : ";
	in >> p.name;
	return in;
}

