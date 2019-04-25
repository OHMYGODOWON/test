#include <iostream>
#include "Person02.h"
using namespace std;
/*
	요구사항
	1. 사람배열
	2. push
	3. pop
	4. 사람수
	5. 사람수 출력함수
*/
class Queue {
private:
	Person line[10];
	static int number;
public:
	Queue();
	void push(Person p);
	Person pop();
	static int printNumber();

	friend ostream& operator << (ostream& out, const Queue &q);
	//friend istream& operator >> (istream& out, Queue &q);
};
Queue::Queue() {
	number = 0;
}
ostream& operator << (ostream& out, const Queue &q) {
	if (q.number == 0) {
		out << "아무도 없습니다.";
		return out;
	}
	out << "현재 Queue 안에는 " << q.number << "명이 있고, 이름은 ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "입니다.";
	return out;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << p << "가 들어왔습니다. " << endl;
	cout << "현재 " << number << "명 있습니다." << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "가 나갔습니다. " << endl;
	cout << "현재 " << number << "명 있습니다. " << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
