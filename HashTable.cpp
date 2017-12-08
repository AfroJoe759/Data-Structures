#include "HashTable.h"

HashTable::HashTable() {
	ht.resize(10); //sets the size of the hash table to 10
}

int HashTable::hash(string key) const {
	int keyValue = 0;
	int hashValue;

	for (int i = 0; i < key.length(); i++) {
		keyValue += key.at(i); //adds the ascii value of each character of the key
	}

	hashValue = keyValue % ht.size(); //formula determines the index we will be returning

	return hashValue;
}

bool HashTable::find(string key) {
	int index = hash(key); //calls the hash function to obtain the index of where the key should be located

	//searched the list held at the found index and if key is found returns true
	for (int i = 0; i < ht[index].size(); i++) {
		if (ht[index][i].getKey() == key) {
			return true;
		}
	}

	return false;
}

bool HashTable::insert(string key, string data) {
	int index = hash(key);  //calls the hash function to obtain the index of where the item is to be inserted
	bool found = find(key); //checks to see if the key already exists

	//if key does not exist simply go to the list held at index and push the information to the back of the list
	if (!found) { 
		ht[index].push_back({ key, data });
		return true;
	}

	return false;
}

bool HashTable::remove(string key) {
	int index = hash(key);  //calls the hash function to obtain the index of where the item is to be inserted
	bool found = find(key); //checks to see if the key already exists

	//if the ket exists one of the following operations will happen
	if (found == true) {
		//if only 1 element is in the list at index and that value contains the searched key, just pop it
		if (ht[index].size() == 1 && ht[index][0].getKey() == key) {
			ht[index].pop_back();
		}

		//if the element at the back of the list contains the searched key, pop it
		else if (ht[index].back().getKey() == key) {
			ht[index].pop_back();
		}

		//search the list for the list for the key one the key is found, from that position onward 
		//make the current value at that index equal to the one head of it
		//one that is done, pop the last element
		else {
			for (int i = 0; i < ht[index].size(); i++) {
				if (ht[index][i].getKey() == key) {
					for (int j = i; j < ht[index].size() - 1; j++) {
						ht[index][j] = ht[index][j + 1];
					}
					ht[index].pop_back();
					break;
				}
			}
		}
	}
	return found;
}

void HashTable::makeEmpty() {
	//clears the list heald at each index
	for (int i = 0; i < ht.size(); i++) {
		ht[i].clear();
	}
}

void HashTable::printTable() {
	for (int i = 0; i < ht.size(); i++) {
		cout << "Index " << i << ": ";

		if (ht[i].size() == 0) {
			cout << "Empty";
		}

		else {
			for (int j = 0; j < ht[i].size(); j++) {
				cout << "(" << ht[i][j].getKey() << ", " << ht[i][j].getData() << ") ";
			}
		}
		cout << endl;
	}
}