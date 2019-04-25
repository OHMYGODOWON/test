#include <iostream>
#include <string>
using namespace std;

/*
	Person class
	1. �̸�
	2. ������
	3. �̸����
	4. io �����ε�
*/
class Person {
private:
	string name;
public:
	Person() : name(string()){}
	Person(string name) : name(name) {}
	string printName() {
		return name;
	}
	friend ostream& operator << (ostream& out, Person &p);
	friend istream& operator >> (istream& in, Person &p);
};
ostream& operator << (ostream& out, Person &p) {
	out << p.name;
	return out;
}
istream& operator >> (istream& in, Person &p) {
	cout << "�̸� �Է� : ";
	in >> p.name;
	return in;
}

