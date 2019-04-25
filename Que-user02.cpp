#include <iostream>
#include "Queue02.h"
using namespace std;
int Queue::number = 0;
int main() {
	Queue q;
	q.push(Person("오도원"));
	q.push(Person("오도투"));
	q.push(Person("오도쓰리"));
	q.push(Person("오도포"));

	cout << q << endl;
	cout << "모두 나가주세요" << endl;
	while (q.printNumber() > 0) {
		q.pop();
	}
	
	cout << q << endl;
	system("pause");
}