#include "Person04.h"
using namespace std;

class Queue {
private:
	Person line[20];
	static int number;
public:
	Queue();
	void push(Person p);
	Person pop();
	static int printNumber();
	friend ostream& operator << (ostream& out, Queue &q);
};
Queue::Queue() {
	number = 0;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << p << "가 들어왔습니다." << endl;
	cout << "현재 queue에는 " << number << "명 있습니다." << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "이/가 나갔습니다." << endl;
	cout << "현재 queue에는 " << number << "명 있습니다." << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
ostream& operator << (ostream& out, Queue &q) {
	if (q.number == 0) {
		out << "아무도 없습니다." << endl;
		return out;
	}
	out << "현재 queue에는 " << q.number << "명 있고 이름은 ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "입니다. " << endl;
	return out;

}

