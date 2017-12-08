#include "HashTable.h"

int main() {

	HashTable ht;
	string key;
	string data;
	int choice;
	bool active = true;

	while (active == true) {
		cout << "Input the choice that matches the operation you wish to test" << endl;
		cout << "1 - insert\n2 - remove\n3 - find\n4 - makeEmpty\n5 - printTable\n6 - exit\nChoice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "Input the key: ";
			cin >> key;

			cout << "Input the data: ";
			cin >> data;

			if (ht.insert(key, data) == true) {
				cout << "The data has been inserted" << endl;
			}

			else {
				cout << "The data has not been inserted due to the key already existing" << endl;
			}
			cout << endl; 
			break;
		}

		case 2: {
			cout << "Input the key: ";
			cin >> key;

			if (ht.remove(key) == true) {
				cout << "The key and it's data has been removed" << endl;
			}

			else {
				cout << "The data has not been removed due to the key not existing" << endl;
			}
			cout << endl;
			break;
		}

		case 3: {
			cout << "Input the key: ";
			cin >> key;

			if (ht.find(key) == true) {
				cout << "The key has been found" << endl;
			}

			else {
				cout << "The key does not exist within the table" << endl;
			}
			cout << endl;
			break;
		}

		case 4: {
			cout << "The table has been cleared" << endl;
			ht.makeEmpty();
			cout << endl;
			break;
		}

		case 5: {
			cout << "Current Table:" << endl;
			ht.printTable();
			cout << endl;
			break;
		}

		case 6: {
			active = false;
			cout << endl;
			break;
		}

		default: 
		{
			cout << "The number you have inputed is invalid" << endl;
		}
		}
	}

	return 0;
}