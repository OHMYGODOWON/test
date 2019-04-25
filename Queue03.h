#include "Person03.h"
using namespace std;

/*
	Queue class
	1. ����迭
	2. �����
	3. ������
	4. push
	5. pop
	6. ����� ���
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
		out << "queue�� �ƹ��� �����ϴ�." << endl;
		return out;
	}
	out << "���� queue�� " << q.number << "�� �ֽ��ϴ�." << endl << "�̸��� ";
	for (int i = 0; i < q.number; i++) {
		out << q.line[i] << " ";
	}
	out << "�Դϴ�." << endl;
	return out;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << p << "�� ���Խ��ϴ�." << endl;
	cout << "���� queue�� " << number << "�� �ֽ��ϴ�." << endl << endl;
}
Person Queue::pop() {
	Person p = line[0];
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;
	cout << p << "�� �������ϴ�." << endl;
	cout << "���� queue�� " << number << "�� �ֽ��ϴ�." << endl << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}
int Queue::printMax() {
	return max;
}
