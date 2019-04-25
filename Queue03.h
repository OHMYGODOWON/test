#include "Person03.h"
using namespace std;

/*
	Queue class
	1. 사람배열
	2. 사람수
	3. 생성자
	4. push
	5. pop
	6. 사람수 출력
	7. io overloading
*/
class Queue {
private:
	Person line[10];
	static int number;
	static int max;
public:
	Queue();
	void push(Person p);
	Person pop();
	static int printNumber();
	static int printMax();
	friend ostream& operator << (ostream& out, Queue &q);
};
Queue::Queue() {
	number = 0;
}
ostream& operator << (ostream& out, Queue &q) {
	if (q.number == 0) {
		out << "queue에 아무도 없습니다." << endl;
		return out;
	}
	out << "현재 queue에 " << q.number << "명 있습니다." << endl << "이름은 ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "입니다." << endl;
	return out;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << p << "가 들어왔습니다." << endl;
	cout << "현재 queue에 " << number << "명 있습니다." << endl << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "가 나갔습니다." << endl;
	cout << "현재 queue에 " << number << "명 있습니다." << endl << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
int Queue::printMax() {
	return max;
}
