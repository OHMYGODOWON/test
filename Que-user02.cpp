#include <iostream>
#include "Queue02.h"
using namespace std;
int Queue::number = 0;
int main() {
	Queue q;
	q.push(Person("������"));
	q.push(Person("������"));
	q.push(Person("��������"));
	q.push(Person("������"));

	cout << q << endl;
	cout << "��� �����ּ���" << endl;
	while (q.printNumber() > 0) {
		q.pop();
	}
	
	cout << q << endl;
	system("pause");
}