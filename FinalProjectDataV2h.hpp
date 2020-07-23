#ifndef HASH
#define HASH
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;


struct node{

	int key;
};

struct nodeLL{

	int key;
	nodeLL* next;
};

struct nodeBST{

	int key;
	nodeBST* parent;
	nodeBST* left;
	nodeBST* right;
};

class hashTable{

	int tableSize;

	vector<node*> hashTableCK1;
	vector<node*> hashTableCK2;
	vector<node*> hashTableLP;
	vector<nodeLL*> hashTableLL;
	vector<nodeBST*> hashTableBST;

	public:

	double insertTotal;      //we need this to keep track of the 100 individual timings for each operation (of each hashtable object in the main)
	double lookupTotal;
	double deleteTotal;

	double insertAvg;      //we need this to keep the average time of the total time for each operation (of each hashtable object in the main)
	double lookupAvg;
	double deleteAvg;

	double loadFact;


	hashTable();

	int hash1(int inputKey);
	int hash2(int inputKey);

	void deleteEntireLL();

	void insertLLhash1(int inputKey);
	void insertLLhash2(int inputKey);
	bool lookupLLhash1(int inputKey);
	bool lookupLLhash2(int inputKey);
	void deleteLLhash1(int inputKey);
	void deleteLLhash2(int inputKey);

	void insertBSThash1(int inputKey);
	void insertBSThash2(int inputKey);
	nodeBST* lookupBSThash1(int inputKey);
	nodeBST* lookupBSThash2(int inputKey);
	void deleteBSThash1(int inputKey);
	void deleteBSThash2(int inputKey);

	void insertLinearhash1(int inputKey);
	void insertLinearhash2(int inputKey);
	node*lookupLinearhash1(int inputKey); //change type into Node
	node* lookupLinearhash2(int inputKey);
	void deleteLinearhash1(int inputKey);
	void deleteLinearhash2(int inputKey);

	void tableFill();
	void insertcuckoohash(int inputKey);
	node* lookupcuckoohash(int inputKey);
	void deletecuckoohash(int inputKey);

};


#endif
