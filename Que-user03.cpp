#include "Queue03.h"
using namespace std;

int Queue::number = 0;
int Queue::max = 10;

int main() {
	Queue q;

	q.push(Person("������"));
	q.push(Person("������"));
	q.push(Person("��������"));
	q.push(Person("������"));
	q.push(Person("�������̺�"));

	cout << q;

	q.pop();
	while (q.printNumber() < Queue::printMax()) {
		q.push(Person("clone"));
	}
	cout << "��� �����ּ���" << endl;
	while (q.printNumber() > 0) {
		q.pop();
	}
	cout << q;
	system("pause");
}