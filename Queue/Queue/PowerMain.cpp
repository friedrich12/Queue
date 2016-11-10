#include<iostream>
#include"queue.h"

using namespace std;

int main() {
	Queue d(1000);
	while (true) {
		int ans;
		cout << "1 add item, 2 delete item, 3 front, 4 rear\n";
		cin >> ans;
		switch (ans)
		{
		case 1:
			int item;
			cout << "Enter item to add:\n";
			cin >> item;
			d.enqueue(item);
			break;
		case 2:
			d.dequeue();
			break;
		case 3:
			cout << d.getfront() << endl;
			break;
		case 4:
			cout << d.getrear() << endl;
			break;
		default:
			cout << "Didn't get that\n";
			break;
		}
	}
}