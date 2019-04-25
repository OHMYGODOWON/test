#include <iostream>
#include <string>
using namespace std;

/*
	Person class
	1. 이름
	2. 생성자
	3. 이름출력
	4. io 오버로딩
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
	cout << "이름 입력 : ";
	in >> p.name;
	return in;
}

