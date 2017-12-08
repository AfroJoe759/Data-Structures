#include <iostream>
#include <string>
#include <vector>

using namespace std;

//vector implementation of hash table using seprate chaining
//
class HashTable {

public: 

	HashTable();

	int hash(string key) const; //hashes given key

	bool insert(string key, string data); //inserts into the hash table if key doesn't exist
	bool remove(string key); //removes the data associated to the key
	bool find(string key); //searches to see if the entered key exists

	void makeEmpty(); //clears the table
	void printTable(); //prints all contents within a hash table (key, data)

private: 

	struct HTNode {  //this struct allows us to store and access our table's key and data
		string data;
		string key;

		HTNode(string key, string data) {
			this->data = data;
			this->key = key;
		}

		string getData() {
			return data;
		}

		string getKey() {
			return key;
		}
	};

	vector<vector<HTNode>> ht; //the hash table itself implemented using a multidimentional vector 
							// a vector that at each index contains another vector vector
};