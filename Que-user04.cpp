#include "Queue04.h"
using namespace std;

int Queue::number = 0;

int main() {
	Queue q;
	q.push(Person("오도원"));
	q.push(Person("오도투"));
	q.push(Person("오도쓰리"));
	q.push(Person("오도포"));
	q.push(Person("오도파이브"));
	q.push(Person("오도식스"));

	cout << q;
	q.pop();
	while (Queue::printNumber() < 20) {
		q.push(Person("클론"));
	}
	cout << "모두 나가주세요" << endl;
	while (q.printNumber() > 0) {
		q.pop();
	}
	cout << q;
	system("pause");
}