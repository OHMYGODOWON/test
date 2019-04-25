#include <iostream>
#include "Queue.h"
using namespace std;

void main() {
	Queue q;
	cout << "queue에 있는 사람은 " << q.printNumber()
		<< "명입니다. " << endl << endl;

	q.push(Person ("오도원"));
	q.push(Person ("오도투"));
	q.push(Person("오도쓰리"));
	q.push(Person("오도포"));
	cout << "queue에 있는 사람은 " << q.printNumber()
		<< "명입니다. " << endl << endl;

	q.pop();
	cout << "queue에 있는 사람은 " << q.printNumber()
		<< "명입니다. " << endl << endl;
	q.push(Person("오도파이브"));
	cout << "queue에 있는 사람은 " << q.printNumber()
		<< "명입니다. " << endl << endl;

	cout << "모든 사람이 queue에서 나갑니다." << endl << endl;
	while (q.printNumber() > 0) {
		q.pop();
		cout << "queue에 있는 사람은 " << q.printNumber()
			<< "명입니다. " << endl << endl;
	}
	system("pause");
}