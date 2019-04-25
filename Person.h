#include <string>
#include <iostream>
using namespace std;

class Person {
	string name;
public:
	Person(string n) : name(n) {}
	Person(){}

	string printName() {
		return name;
	}
};
