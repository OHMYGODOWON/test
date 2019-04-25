#include <iostream>
#include <string>
using namespace std;

class String {
public:
	String();
	String(const String &s);
	String& operator = (const String &s);
	String(char *s);
	~String();
	char * string;
};


String::String() {
	string = new char[10];
}
String::String(char* _string) {
	string = new char[strlen(_string) + 1];
	strcpy_s(string, strlen(_string) + 1, _string);
}
String::String(const String& str) {
	string = new char[strlen(str.string) + 1];
	strcpy_s(string, strlen(str.string) + 1, str.string);
}
String& String::operator = (const String &str) {
	string = new char[strlen(str.string) + 1];
	strcpy_s(string, strlen(str.string) + 1, str.string);
	return *this;
}
String::~String() {
	delete[] string;
}
