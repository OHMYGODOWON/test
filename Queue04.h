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
	cout << p << "�� ���Խ��ϴ�." << endl;
	cout << "���� queue���� " << number << "�� �ֽ��ϴ�." << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "��/�� �������ϴ�." << endl;
	cout << "���� queue���� " << number << "�� �ֽ��ϴ�." << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
ostream& operator << (ostream& out, Queue &q) {
	if (q.number == 0) {
		out << "�ƹ��� �����ϴ�." << endl;
		return out;
	}
	out << "���� queue���� " << q.number << "�� �ְ� �̸��� ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "�Դϴ�. " << endl;
	return out;

}

