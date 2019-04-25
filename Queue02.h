#include <iostream>
#include "Person02.h"
using namespace std;
/*
	�䱸����
	1. ����迭
	2. push
	3. pop
	4. �����
	5. ����� ����Լ�
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
		out << "�ƹ��� �����ϴ�.";
		return out;
	}
	out << "���� Queue �ȿ��� " << q.number << "���� �ְ�, �̸��� ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "�Դϴ�.";
	return out;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << p << "�� ���Խ��ϴ�. " << endl;
	cout << "���� " << number << "�� �ֽ��ϴ�." << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "�� �������ϴ�. " << endl;
	cout << "���� " << number << "�� �ֽ��ϴ�. " << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
