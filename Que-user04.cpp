#include "Queue04.h"
using namespace std;

int Queue::number = 0;

int main() {
	Queue q;
	q.push(Person("������"));
	q.push(Person("������"));
	q.push(Person("��������"));
	q.push(Person("������"));
	q.push(Person("�������̺�"));
	q.push(Person("�����Ľ�"));

	cout << q;
	q.pop();
	while (Queue::printNumber() < 20) {
		q.push(Person("Ŭ��"));
	}
	cout << "��� �����ּ���" << endl;
	while (q.printNumber() > 0) {
		q.pop();
	}
	cout << q;
	system("pause");
}