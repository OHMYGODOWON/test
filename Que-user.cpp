#include <iostream>
#include "Queue.h"
using namespace std;

void main() {
	Queue q;
	cout << "queue�� �ִ� ����� " << q.printNumber()
		<< "���Դϴ�. " << endl << endl;

	q.push(Person ("������"));
	q.push(Person ("������"));
	q.push(Person("��������"));
	q.push(Person("������"));
	cout << "queue�� �ִ� ����� " << q.printNumber()
		<< "���Դϴ�. " << endl << endl;

	q.pop();
	cout << "queue�� �ִ� ����� " << q.printNumber()
		<< "���Դϴ�. " << endl << endl;
	q.push(Person("�������̺�"));
	cout << "queue�� �ִ� ����� " << q.printNumber()
		<< "���Դϴ�. " << endl << endl;

	cout << "��� ����� queue���� �����ϴ�." << endl << endl;
	while (q.printNumber() > 0) {
		q.pop();
		cout << "queue�� �ִ� ����� " << q.printNumber()
			<< "���Դϴ�. " << endl << endl;
	}
	system("pause");
}