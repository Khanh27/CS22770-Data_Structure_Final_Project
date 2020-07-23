#include "FinalProjectDataV2h.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

hashTable::hashTable()
{
	tableSize = 10009;

	for(int i = 0; i < tableSize; i++){

		hashTableLP.push_back(NULL);

		hashTableLL.push_back(NULL);

		hashTableBST.push_back(NULL);
	}
}

int hashTable::hash1(int key)
{
	int output = key % tableSize;
	return output;
}

/*void hashTable::deleteEntireLL(){

	for(int i = 0; i < tableSize; i++){

		if(hashTableLL[i] -> next == NULL){

			hashTableLL[i] = NULL;
		}
		else{

			nodeLL* temp = hashTableLL[i];

			while(temp != NULL){

			}

		}
	}
}*/

int hashTable::hash2(int key)
{
	int output = floor(key/tableSize);
	return output;
}


///////////////////////////////////////////////////////////////////////////
// LINKED LIST:
///////////////////////////////////////////////////////////////////////////

void hashTable::insertLLhash1(int inputKey)
{

	int idx = hash1(inputKey);
	nodeLL* newNode = new nodeLL;
	newNode->key = inputKey;
	nodeLL* temp = hashTableLL[idx];

	if(temp == NULL){

		hashTableLL[idx] = newNode;
		newNode->next = NULL;
	}
	else{

		hashTableLL[idx] = newNode;
		newNode->next = temp;
	}

}

void hashTable::insertLLhash2(int inputKey)
{

	int idx = hash2(inputKey);
	nodeLL* newNode = new nodeLL;
	newNode->key = inputKey;

	nodeLL* temp = hashTableLL[idx];
	if(temp == NULL)
	{
		hashTableLL[idx] = newNode;
		newNode->next = NULL;
	}
	else
	{
		hashTableLL[idx] = newNode;
		newNode->next = temp;
	}

}

bool hashTable::lookupLLhash1(int inputKey)
{
	int idx = hash1(inputKey);
	nodeLL* temp = hashTableLL[idx];

	while(temp != NULL)
	{
		if(temp->key == inputKey)
		{
				return true;
		}
		temp = temp->next;
	}
	return false;
}

bool hashTable::lookupLLhash2(int inputKey)
{
		int idx = hash2(inputKey);
		nodeLL* temp = hashTableLL[idx];
		while(temp != NULL)
		{
			if(temp->key == inputKey)
			{

				return true;

			}
			temp = temp->next;
		}
		return false;
}

void hashTable::deleteLLhash1(int inputKey)
{

	int idx = hash1(inputKey);

	nodeLL* current = hashTableLL[idx];
	nodeLL* prev = NULL;
	bool Found = false;

	if(current == NULL)
	{
		//cout << "No element found" << endl;
		return;
	}
	if(current->key == inputKey){

		prev = current -> next;
		delete current;
		Found = true;
		hashTableLL[idx] = prev;

		//cout << "Element Deleted" << endl;
		return;
	}
	if(current -> key != inputKey){

		while(current -> next != NULL){

			prev = current;
			current = current -> next;

			if(current -> key == inputKey){

				Found = true;
				prev -> next = current -> next;
				delete current;
				break;
			}
		}
	}
	if(Found == false){
		return;
	}

	delete current;
	return;
}


void hashTable::deleteLLhash2(int inputKey)
{

	int idx = hash2(inputKey);

	nodeLL* current = hashTableLL[idx];
	nodeLL* prev = NULL;
	bool Found = false;

	if(current == NULL)
	{
	   cout << "No element found" << endl;
	   return;
  	}
	if(current->key == inputKey){

		prev = current -> next;
		delete current;
		Found = true;
		hashTableLL[idx] = prev;

		//cout << "Element Deleted" << endl;
		return;
	}
	if(current -> key != inputKey){

		while(current -> next != NULL){

			prev = current;
			current = current -> next;

			if(current -> key == inputKey){

				Found = true;
				prev -> next = current -> next;
				delete current;

				break;
			}
		}
	}
    if(Found == false){
		return;
	}

	delete current;

	//cout << "Element Deleted" << endl;
	return;
}

///////////////////////////////////////////////////////////////////////////
// BST;
///////////////////////////////////////////////////////////////////////////

nodeBST* addBST(nodeBST* inputRoot, nodeBST* inputParent, int inputKey)
{
	if(inputRoot == NULL){
	//leaf reached, add movie;
	 nodeBST* newNode = new nodeBST;
	 newNode->key = inputKey;
	 newNode->parent = inputParent;
	 newNode->left = NULL;
	 newNode->right = NULL;
	 return newNode;
	}
	if(inputKey < inputRoot->key)
	{
		inputRoot->left = addBST(inputRoot->left, inputRoot, inputKey);
	}
	if(inputKey > inputRoot->key)
	{
		inputRoot->right = addBST(inputRoot->right, inputRoot, inputKey);
	}
	return inputRoot;
}

void hashTable::insertBSThash1(int inputKey){

	int idx = hash1(inputKey);
	hashTableBST[idx] = addBST(hashTableBST[idx], NULL, inputKey);
}

void hashTable::insertBSThash2(int inputKey){

	int idx = hash2(inputKey);
	hashTableBST[idx] = addBST(hashTableBST[idx], NULL, inputKey);
}

nodeBST* lookupBST(nodeBST* inputRoot, int inputKey, int& checker)
{
	if(inputRoot->key == inputKey){

		//cout << "Key Found!" << endl;
		checker++;
		return inputRoot;
	}
	if(inputKey < inputRoot->key){

		inputRoot->left = lookupBST(inputRoot->left, inputKey, checker);
	}
	if(inputKey > inputRoot->key){

		inputRoot->right = lookupBST(inputRoot->right, inputKey, checker);
	}
	return NULL;
}

nodeBST* hashTable::lookupBSThash1(int inputKey){

	int idx = hash1(inputKey);
	nodeBST* output = NULL;
	int checker = 0;

	if(hashTableBST[idx] == NULL){

		// nothing at idx, no bst
		//cout << "Index empty, key not found!" << endl;
		return NULL;
	}
	if(hashTableBST[idx]->key == inputKey){

		//key found at idx (root)
		//cout << "Key Found!" << endl;
		return hashTableBST[idx];

	}
	else{

		output = lookupBST(hashTableBST[idx], inputKey, checker);

		if(checker == 0){

			//cout << "Key not found in BST at index" << endl;
									return NULL;
		}
	}
		 return output;
}

nodeBST* hashTable::lookupBSThash2(int inputKey){

	int idx = hash2(inputKey);
	int checker = 0;

	if(hashTableBST[idx] == NULL){

		// nothing at idx, no bst
		//cout << "Index empty, key not found!" << endl;
		return NULL;
	}

	if(hashTableBST[idx]->key == inputKey){ //bro you should return the index,
																					 //so the type cant be void for search, same for search1
		//key found at idx (root)
		//cout << "Key Found!" << endl;
		return hashTableBST[idx];

	}
	else{

		lookupBST(hashTableBST[idx], inputKey, checker);

		if(checker == 0){

			//cout << "Key not found in BST at index" << endl;
									return NULL;
		}
	}
			return NULL;
}


nodeBST* getMin(nodeBST* rootInput){


	if(rootInput == NULL){

		return rootInput->parent;
	}
	if(rootInput->left != NULL){

		getMin(rootInput->left);
	}
	//else
		return rootInput;
}

nodeBST* deleteBST(nodeBST* rootInput, int inputKey){

    if(rootInput == NULL){

        return rootInput;
	}
	if(rootInput->key == inputKey){

		nodeBST* rootRight = rootInput->right;
		nodeBST* rootParent = rootInput->parent;

		nodeBST* tempRoot = rootInput;

			if(rootInput->left == NULL && rootInput->right == NULL){

				if(rootParent->left == rootInput){

					rootParent->left = NULL;
					delete rootInput;
					rootInput = NULL;
					return NULL;
				}
				if(rootParent->right == rootInput){

					rootParent->right = NULL;
					delete rootInput;
					rootInput = NULL;
					return NULL;
				}

			}
			else if(rootInput->left == NULL){

				if(rootParent->left == rootInput){

					rootParent->left = tempRoot->right;
					delete rootInput;
					rootInput = NULL;

					return rootParent->left;
				}
				if(rootParent->right == rootInput){

					rootParent->right = tempRoot->right;
					delete rootInput;
					rootInput = NULL;

					return rootParent->right;
				}
			}
			else if(rootInput->right == NULL){

				if(rootParent->left == rootInput){

					rootParent->left = tempRoot->left;

					delete rootInput;
					rootInput = NULL;

					return rootParent->left;
				}
				if(rootParent->right == rootInput){

					rootParent->right = tempRoot->left;

					delete rootInput;
					rootInput = NULL;
					return rootParent->right;
				}
			}
			else
			{
        	nodeBST* replaceNode = getMin(rootRight);
          nodeBST* replaceLeft = replaceNode->left;
        	nodeBST* replaceRight = replaceNode->right;
        	nodeBST* replaceParent = replaceNode->parent;
        	rootInput->key = replaceNode->key;
			    replaceParent->left = replaceNode->right;
          delete replaceNode;
			}
			return rootInput;
	}
	if(rootInput->key < inputKey){

		rootInput->left = deleteBST(rootInput->left, inputKey);
	}

	if(rootInput->key > inputKey){

		rootInput->right = deleteBST(rootInput->right, inputKey);
	}
	return rootInput;
}


void hashTable::deleteBSThash1(int inputKey){

	int idx = hash1(inputKey);
	nodeBST* root = hashTableBST[idx];

	if(root == NULL){
		//cout << "1" << endl;
		return;
	}

	if(root->key == inputKey){

		if(root->left == NULL && root->right == NULL){

			hashTableBST[idx] = NULL;
			return;
		}
		else{

		deleteBST(root, inputKey);
		return;
		}
	}

	else{

		deleteBST(root, inputKey);
		return;
	}

}

void hashTable::deleteBSThash2(int inputKey){

	int idx = hash2(inputKey);
	nodeBST* root = hashTableBST[idx];

	if(root == NULL){
		//cout << "1" << endl;
		return;
	}

	if(root->key == inputKey){

		if(root->left == NULL && root->right == NULL){

			hashTableBST[idx] = NULL;
			return;
		}
		else{

		deleteBST(root, inputKey);
		return;
		}

	}
	else{

		deleteBST(root, inputKey);
		return;
	}

}



///////////////////////////////////////////////////////////////////////////
// LINEAR PROBING
///////////////////////////////////////////////////////////////////////////

void hashTable::insertLinearhash1(int inputKey){

	int idx = hash1(inputKey);

	node* newNode = new node;
	newNode->key = inputKey;

	node* temp = hashTableLP[idx];

	if(temp == NULL){

		temp = newNode;
		return;

	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp == NULL){

				temp = newNode;
				return;

			}

		}
		cout << "table is full, could not insert." << endl;
		return;
	}

}

void hashTable::insertLinearhash2(int inputKey){

	int idx = hash2(inputKey);

	node* newNode = new node;
	newNode->key = inputKey;

	node* temp = hashTableLP[idx];

	if(temp == NULL){

		temp = newNode;
		return;

	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp == NULL){

				temp = newNode;
				return;

			}

		}
		cout << "table is full, could not insert." << endl;
		return;
	}
}

node* hashTable::lookupLinearhash1(int inputKey)
{
	int index = hash1(inputKey);
	int originalIndex = index;
	//find the node with the given key
	while(hashTableLP[index] != NULL && index != originalIndex)
	{
		 if(hashTableLP[index]->key == inputKey) //if found corresponding node,
		 {
				return hashTableLP[index];
		 }
		 index++;
		 index%=tableSize;
	}
	return NULL; //if doesn't find anything
}

node* hashTable::lookupLinearhash2(int inputKey)
{
	int index = hash2(inputKey);
	int originalIndex = index;
	//find the node with the given key
	while(hashTableLP[index] != NULL && index != originalIndex)
	{
		 if(hashTableLP[index]->key == inputKey) //if found corresponding node,
		 {
				return hashTableLP[index];
		 }
		 index++; //otherwise, keep increasing the index, and find its remainder.
		 index%=tableSize;
	}
	return NULL; //if doesn't find anything
}

node* hashTable::deleteLinearhash1(int inputKey)
{
	int index = hash1(inputKey);
	while(hashTableLP[index] != NULL)
	{
		if(hashTableLP[index]->key == inputKey)
		{
			node* temp = hashTableLP[index]; //store the found key into temp
			tableSize--; // reduce the size
			return temp; // return temp key
		}
		index++;
		index%=tableSize;
	}
	return NULL; // if doesn't find anything
}

node* hashTable::deleteLinearhash2(int inputKey)
{
	int index = hash2(inputKey);
	while(hashTableLP[index] != NULL)
	{
		if(hashTableLP[index]->key == inputKey)
		{
			node* temp = hashTableLP[index]; //store the found key into temp
			tableSize--; // reduce the size
			return temp; // return temp key
		}
		index++;
		index%=tableSize;
	}
	return NULL; // if doesn't find anything
}
/////////////////

////////////////
double getAverageTime(double inputTotalTime){

	double output = inputTotalTime / 100;
	return output;
}

int	LoadFactorInserts(double loadFactor){

	int elements =	loadFactor * 10009;
	return elements;
}

int main(int argc, char *argv[])
{
	cout << "general test runs good" << endl;

	hashTable LL1;
	hashTable LL2;
	hashTable BST1;
	hashTable BST2;
	hashTable LP1;
	hashTable LP2;

	int csvFile1[100000];
	int csvFile2[100000];

	string line = "";
	string skey = "";
	int inputkey = 0;

	int numThings = 0;

	ifstream file;
	file.open(argv[1]);

	if(file.is_open()){

		getline(file, line);
		istringstream ssline(line);

		while(getline(ssline, skey, ',')){

			inputkey = stoi(skey);

			csvFile1[numThings] =  inputkey;

			numThings++;

		}
		file.close();

	}
	else{
		cout << "file did not open. " << endl;
	}



	line = "";
	skey = "";
	inputkey = 0;

	file.open(argv[2]);

	if(file.is_open()){

		getline(file, line);
		istringstream ssline(line);

		while(getline(ssline, skey, ',')){

			inputkey = stoi(skey);

			csvFile2[numThings] =  inputkey;

			numThings++;

		}

		file.close();
	}
	else{
		cout << "file did not open. " << endl;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// 	FUNCTION TEST:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float Factor;
int numLoads = 0;
int loadIdx = 0;
int idx = 0;
int currentThings = 0;
int inputK = 0;

int startClock = 0;
int endClock = 0;
double execTime = 0.0;

for(int x = 0; x < 6; x++){

	switch (x){

		case 0:
			Factor = 0.1;

			numLoads = 1000;
			loadIdx = 0;
			idx = 1000;
			break;

		case 1:
			Factor = 0.2;

			numLoads = 1000;
			loadIdx = 1000;
			idx = 2000;

			break;

		case 2:
			Factor = 0.5;

			numLoads = 3000;
			loadIdx = 2000;
			idx = 5000;
			break;

		case 3:
			Factor = 0.7;

			numLoads = 2000;
			loadIdx = 5000;
			idx = 7000;
			break;

		case 4:
			Factor = 0.9;

			numLoads = 2000;
			loadIdx = 7000;
			idx = 9000;
			break;

		case 5:
			Factor = 1.0; /// dont insert, table is supposed to be full

			numLoads = 9;
			loadIdx = 9000;
			idx = 10000;
			break;

	}

		for(int i = loadIdx; i < numLoads; i++){

			inputK = csvFile1[i]; // this

			LL1.insertLLhash1(inputK);

			LL2.insertLLhash2(inputK);

			BST1.insertBSThash1(inputK);

			BST2.insertBSThash2(inputK);

			LP1.insertLinearhash1(inputK);

			LP2.insertLinearhash2(inputK);

			currentThings++;

		}

		for(int i = loadIdx; i < numLoads; i++)
		{
			inputK = csvFile2[i];
			LL1.insertLLhash1(inputK);

			LL2.insertLLhash2(inputK);

			BST1.insertBSThash1(inputK);

			BST2.insertBSThash2(inputK);

			LP1.insertLinearhash1(inputK);

			LP2.insertLinearhash2(inputK);

			currentThings++;
		}


		for(int i = idx; i < idx + 100; i++){

			inputK = csvFile1[i];

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// linked-list/hash 1:
			startClock = clock();

			LL1.insertLLhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.insertTotal += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LL1.lookupLLhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.lookupTotal += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LL1.deleteLLhash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.deleteTotal += execTime;

			////////////////////////////////////////////////////////////
			/////////// linked-list/hash 2:

			startClock = clock();

			LL2.insertLLhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.insertTotal += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LL2.lookupLLhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.lookupTotal += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LL2.deleteLLhash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.deleteTotal += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// BST/hash 1:
			startClock = clock();

			BST1.insertBSThash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.insertTotal += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			BST1.lookupBSThash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.lookupTotal += execTime;

			///////////////////////////////////////////////////////////

			startClock = clock();

			BST1.deleteBSThash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.deleteTotal += execTime;

			////////////////////////////////////////////////////////////
			/////////// BST/hash 2:

			startClock = clock();

			BST2.insertBSThash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.insertTotal += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			BST2.lookupBSThash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.lookupTotal += execTime;
			////////////////////////////////////////////////////////////

			startClock = clock();

			BST2.deleteBSThash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.deleteTotal += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// Linear/hash 1:
			startClock = clock();

			LP1.insertLinearhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.insertTotal += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LP1.lookupLinearhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.lookupTotal += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LP1.deleteLinearhash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.deleteTotal += execTime;

			////////////////////////////////////////////////////////////
			/////////// Linear/hash 2:

			startClock = clock();

			LP2.insertLinearhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.insertTotal += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LP2.lookupLinearhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.lookupTotal += execTime;
			////////////////////////////////////////////////////////////

			startClock = clock();

			LP2.deleteLinearhash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.deleteTotal += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
		}

		LL1.insertAvg = getAverageTime(LL1.insertTotal);
		LL2.insertAvg = getAverageTime(LL2.insertTotal);
		LL1.lookupAvg = getAverageTime(LL1.lookupTotal);
		LL2.lookupAvg = getAverageTime(LL2.lookupTotal);
		LL1.deleteAvg = getAverageTime(LL1.deleteTotal);
		LL2.deleteAvg = getAverageTime(LL2.deleteTotal);

		BST1.insertAvg = getAverageTime(BST1.insertTotal);
		BST2.insertAvg = getAverageTime(BST2.insertTotal);
		BST1.lookupAvg = getAverageTime(BST1.lookupTotal);
		BST2.lookupAvg = getAverageTime(BST2.lookupTotal);
		BST1.deleteAvg = getAverageTime(BST1.deleteTotal);
		BST2.deleteAvg = getAverageTime(BST2.deleteTotal);

		LP1.insertAvg = getAverageTime(LP1.insertTotal);
		LP2.insertAvg = getAverageTime(LP2.insertTotal);
		LP1.lookupAvg = getAverageTime(LP1.lookupTotal);
		LP2.lookupAvg = getAverageTime(LP2.lookupTotal);
		LP1.deleteAvg = getAverageTime(LP1.deleteTotal);
		LP2.deleteAvg = getAverageTime(LP2.deleteTotal);

		for(int i = loadIdx; i < numLoads; i++)
		{
			inputK = csvFile2[i];
			LL1.insertLLhash1(inputK);

			LL2.insertLLhash2(inputK);

			BST1.insertBSThash1(inputK);

			BST2.insertBSThash2(inputK);

			LP1.insertLinearhash1(inputK);

			LP2.insertLinearhash2(inputK);

			currentThings++;
		}


		for(int i = idx; i < idx + 100; i++){

			inputK = csvFile1[i];

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// linked-list/hash 1:
			startClock = clock();

			LL1.insertLLhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.insertTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LL1.lookupLLhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.lookupTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LL1.deleteLLhash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL1.deleteTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			/////////// linked-list/hash 2:

			startClock = clock();

			LL2.insertLLhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.insertTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LL2.lookupLLhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.lookupTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LL2.deleteLLhash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LL2.deleteTotalcsv2 += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// BST/hash 1:
			startClock = clock();

			BST1.insertBSThash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.insertTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			BST1.lookupBSThash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.lookupTotalcsv2 += execTime;

			///////////////////////////////////////////////////////////

			startClock = clock();

			BST1.deleteBSThash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST1.deleteTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			/////////// BST/hash 2:

			startClock = clock();

			BST2.insertBSThash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.insertTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			BST2.lookupBSThash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.lookupTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////

			startClock = clock();

			BST2.deleteBSThash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			BST2.deleteTotalcsv2 += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
			/////////// Linear/hash 1:
			startClock = clock();

			LP1.insertLinearhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.insertTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LP1.lookupLinearhash1(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.lookupTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			startClock = clock();

			LP1.deleteLinearhash1(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP1.deleteTotalcsv2 += execTime;

			////////////////////////////////////////////////////////////
			/////////// Linear/hash 2:

			startClock = clock();

			LP2.insertLinearhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.insertTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////
			startClock = clock();

			LP2.lookupLinearhash2(inputK);

			endClock = clock();

			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.lookupTotalcsv2 += execTime;
			////////////////////////////////////////////////////////////

			startClock = clock();

			LP2.deleteLinearhash2(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			LP2.deleteTotalcsv2 += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
		}

		LL1.insertAvgcsv2 = getAverageTime(LL1.insertTotalcsv2);
		LL2.insertAvgcsv2 = getAverageTime(LL2.insertTotalcsv2);
		LL1.lookupAvgcsv2 = getAverageTime(LL1.lookupTotalcsv2);
		LL2.lookupAvgcsv2 = getAverageTime(LL2.lookupTotalcsv2);
		LL1.deleteAvgcsv2 = getAverageTime(LL1.deleteTotalcsv2);
		LL2.deleteAvgcsv2 = getAverageTime(LL2.deleteTotalcsv2);

		BST1.insertAvgcsv2 = getAverageTime(BST1.insertTotalcsv2);
		BST2.insertAvgcsv2 = getAverageTime(BST2.insertTotalcsv2);
		BST1.lookupAvgcsv2 = getAverageTime(BST1.lookupTotalcsv2);
		BST2.lookupAvgcsv2 = getAverageTime(BST2.lookupTotalcsv2);
		BST1.deleteAvgcsv2 = getAverageTime(BST1.deleteTotalcsv2);
		BST2.deleteAvgcsv2 = getAverageTime(BST2.deleteTotalcsv2);

		LP1.insertAvgcsv2 = getAverageTime(LP1.insertTotalcsv2);
		LP2.insertAvgcsv2 = getAverageTime(LP2.insertTotalcsv2);
		LP1.lookupAvgcsv2 = getAverageTime(LP1.lookupTotalcsv2);
		LP2.lookupAvgcsv2 = getAverageTime(LP2.lookupTotalcsv2);
		LP1.deleteAvgcsv2 = getAverageTime(LP1.deleteTotalcsv2);
		LP2.deleteAvgcsv2 = getAverageTime(LP2.deleteTotalcsv2);

	cout << "=================================AVG for dataA=========================" << endl;
	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total AVG for 100 inserts: " << LL1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total AVG for 100 lookups: " << LL1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total AVG for 100 deletes: " << LL1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total AVG for 100 inserts: " << LL2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total AVG for 100 lookups: " << LL2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total AVG for 100 deletes: " << LL2.deleteTotal << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total AVG for 100 inserts: " << BST1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total AVG for 100 lookups: " << BST1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total AVG for 100 deletes: " << BST1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total AVG for 100 inserts: " << BST2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total AVG for 100 lookups: " << BST2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total AVG for 100 deletes: " << BST2.deleteTotal << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total AVG for 100 inserts: " << LP1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total AVG for 100 lookups: " << LP1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total AVG for 100 deletes: " << LP1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total AVG for 100 inserts: " << LP2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total AVG for 100 lookups: " << LP2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total AVG for 100 deletes: " << LP2.deleteTotal << endl;

	cout << endl;


cout<<"=================================AVG for dataC================================" << endl;
cout << endl;
cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linked List AVG time for 100 inserts: " << LL1.insertTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linked List AVG time for 100 lookups: " << LL1.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linked List AVG time for 100 deletes: " << LL1.deleteTotalcsv2 << endl;

cout << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linked List AVG time for 100 inserts: " << LL2.insertTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linked List AVG time for 100 lookups: " << LL2.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linked List AVG time for 100 deletes: " << LL2.deleteTotalcsv2 << endl;

cout << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /BST AVG time for 100 inserts: " << BST1.insertTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /BST AVG time for 100 lookups: " << BST1.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /BST AVG time for 100 deletes: " << BST1.deleteTotalcsv2 << endl;

cout << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /BST AVG time for 100 inserts: " << BST2.insertTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /BST AVG time for 100 lookups: " << BST2.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /BST AVG time for 100 deletes: " << BST2.deleteTotalcsv2 << endl;

cout << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linear AVG time for 100 inserts: " << LP1.insertTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linear AVG time for 100 lookups: " << LP1.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 1 Factor ("<<Factor<<") /Linear AVG time for 100 deletes: " << LP1.deleteTotalcsv2 << endl;

cout << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linear AVG time for 100 inserts: " << LP2.insertTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linear AVG time for 100 lookups: " << LP2.lookupTotalcsv2 << endl;

cout << "For file 2 Hash 2 Factor ("<<Factor<<") /Linear AVG time for 100 deletes: " << LP2.deleteTotalcsv2 << endl;

cout << endl;

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}
