#include "Person.h"
using namespace std;

class Queue {
private:
	Person line[20];
	int number;
public:
	Queue();
	void push(Person p);
	Person pop();
	int printNumber();
};

Queue::Queue() {
	number = 0;
}
void Queue::push(Person p) {
	line[number] = p;
	number++;
	cout << number << endl;
	cout << p.printName() << " has joined the queue" << endl;

}
Person Queue::pop() {
	Person p = line[0]; // 앞에서 부터 빠진다.
	// 먼저 들어온 사람이 먼저 나간다.
	for (int i = 1; i < number; i++) {
		line[i - 1] = line[i];
	}
	number--;

	cout << p.printName() << "has left the queue" << endl;
	return p;
}
int Queue::printNumber() {
	return number;
}