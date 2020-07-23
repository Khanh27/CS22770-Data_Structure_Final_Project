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

void hashTable::deleteEntireLL(){

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
}

int hashTable::hash2(int key)
{
	int output = floor(key/tableSize);
  int output2 = output%tableSize;
	return output2;
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

		//cout<<"Error some shit happened";
		return;
	}

	delete current;

	//cout << "Element Deleted" << endl;
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

		cout<<"Error some shit happened";
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

		return lookupBST(inputRoot->left, inputKey, checker);
	}
	if(inputKey > inputRoot->key){

		return lookupBST(inputRoot->right, inputKey, checker);
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
	else{
    return rootInput;
  }
  return NULL;
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
			else{

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
		cout << "1" << endl;
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
	int idx = hash1(inputKey);
	node* temp = hashTableLP[idx];

	if(temp == NULL){

		return NULL;

	}
	if(temp->key == inputKey){
		// key found
		return temp;
	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp->key == inputKey){

				//key found
				return temp;

			}

		}
		cout << "key not found." << endl;
		return NULL;
	}
}

node* hashTable::lookupLinearhash2(int inputKey)
{
	int idx = hash2(inputKey);
	node* temp = hashTableLP[idx];

	if(temp == NULL){

		return NULL;

	}
	if(temp->key == inputKey){
		// key found
		return temp;
	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp->key == inputKey){

				//key found
				return temp;

			}

		}
		cout << "key not found." << endl;
		return NULL;
	}
}

void hashTable::deleteLinearhash1(int inputKey)
{
	int idx = hash1(inputKey);
	node* temp = hashTableLP[idx];

	if(temp == NULL){
		//nothing to delete
		return;

	}
	if(temp->key == inputKey){
		// key found
		hashTableLP[idx] = NULL;
		delete temp;
		return;
	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp->key == inputKey){

				hashTableLP[idx] = NULL;
				delete temp;
				return;
			}

		}
		cout << "key not found, couldn't delete." << endl;
		return;
	}
}

void hashTable::deleteLinearhash2(int inputKey)
{
	int idx = hash2(inputKey);
	node* temp = hashTableLP[idx];

	if(temp == NULL){
		//nothing to delete
		return;

	}
	if(temp->key == inputKey){
		// key found
		hashTableLP[idx] = NULL;
		delete temp;
		return;
	}
	else{

		for(int i = 0; i < tableSize; i++){

			idx++;

			temp = hashTableLP[idx];

			if(idx == tableSize){

				idx = 0;
			}

			if(temp->key == inputKey){

				hashTableLP[idx] = NULL;
				delete temp;
				return;
			}

		}
		cout << "key not found, couldn't delete." << endl;
		return;
	}

}

///////////////////////////////////////////////////////////////////////////
// Cuckoo Hashing
///////////////////////////////////////////////////////////////////////////
void hashTable::tableFill()
{
   tableSize = 10009;

	for(int i = 0; i < tableSize; i++)
  {
		hashTableCK1.push_back(NULL);
		hashTableCK2.push_back(NULL);
	}
  return;
}

node* hashTable::lookupcuckoohash(int inputKey)
{
  int idx1 = hash1(inputKey);
  int idx2 = hash2(inputKey);
  node* temp1 = hashTableCK1[idx1];
  node* temp2 = hashTableCK2[idx2];

  for(int i = 0; i < tableSize; i++) //loop first table
  {
    if(temp1->key == -1) //if cant found key
    {
      for(int j = 0; j < tableSize; j++) //loop 2nd table
      {
        if(temp2->key == inputKey)
        {
          return temp2;
        }

        else // if cant found
        {
          return NULL; //nothing found
        }
      }
    }

    if(temp1->key == inputKey)
    {
      return temp1;
    }
  }
  return NULL;
}

void hashTable::deletecuckoohash(int inputKey)
{
  int idx1 = hash1(inputKey);
  int idx2 = hash2(inputKey);
  node* temp1 = hashTableCK1[idx1];
  node* temp2 = hashTableCK2[idx2];

  for(int i = 0; i < tableSize; i++) //loop first table
  {
    if(temp1->key == -1) //if cant found key
    {
      for(int j = 0; j < tableSize; j++) //loop 2nd table
      {
        if(temp2->key == inputKey)
        {
          delete temp2;
        }

        else // if cant found
        {
          return; //nothing found
        }
      }
    }

    if(temp1->key == inputKey)
    {
      delete temp1;
    }
  }
  return;
}

/*void insertRecursive(int inputKey, int& idx){

}



void  hashTable::insertLLcuckoohash1(int inputKey){

	int idx = hash1(inputKey);

}

void hashTable::insertLLcuckoohash2(int inputKey){

	int idx = hash2(inputKey);

}
bool hashTable::lookupLLcuckoohash1(int inputKey){

	int idx = hash1(inputKey);

}

bool hashTable::lookupLLcuckoohash2(int inputKey){

	int idx = hash2(inputKey);
}

void hashTable::deleteLLcuckoohash1(int inputKey){

	int idx = hash1(inputKey);
}

void hashTable::deleteLLcuckoohash2(int inputKey){

	int idx = hash2(inputKey);
}*/

///////////////////////////////////////////////////////////////////////////

double getAverageTime(double inputTotalTime){

	double output = inputTotalTime / 100;
	return output;
}

int	LoadFactorInserts(double loadFactor){

	int elements =	loadFactor * 10009;
	return elements;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-- MAIN FUNCTION
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	cout << "general test runs good" << endl;

	hashTable LL1;
	hashTable LL2;
	hashTable BST1;
	hashTable BST2;
	hashTable LP1;
	hashTable LP2;
	hashTable CK1;
	hashTable CK2;

	hashTable LL1set2;
	hashTable LL2set2;
	hashTable BST1set2;
	hashTable BST2set2;
	hashTable LP1set2;
	hashTable LP2set2;
	hashTable CK1set2;
	hashTable CK2set2;

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
	cout << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "------------------------------  dataset 1  ----------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	cout << endl;


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
      CK1.lookupcuckoohash(inputK);
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
      ///////////
      startClock = clock();

			CK1.lookupcuckoohash(inputK);

			endClock = clock();
			execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

			CK1.lookupTotal += execTime;

			//__________________________________________________________
			////////////////////////////////////////////////////////////
		}
		/*cout << endl;
		cout << "------------------------- total 100 times  -  ( factor: " << Factor << ") ----------------------------------" << endl;
		cout << endl;



	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 inserts: " << LL1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 lookups: " << LL1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 deletes: " << LL1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 inserts: " << LL2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 lookups: " << LL2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 deletes: " << LL2.deleteTotal << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 inserts: " << BST1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 lookups: " << BST1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 deletes: " << BST1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 inserts: " << BST2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 lookups: " << BST2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 deletes: " << BST2.deleteTotal << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 inserts: " << LP1.insertTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 lookups: " << LP1.lookupTotal << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 deletes: " << LP1.deleteTotal << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 inserts: " << LP2.insertTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 lookups: " << LP2.lookupTotal << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 deletes: " << LP2.deleteTotal << endl;

	cout << endl;*/

	cout << endl;
	cout << "----------------------- total Average time  - ( factor: " << Factor << ") ---------------------------------" << endl;
	cout << endl;


	LL1.insertAvg = getAverageTime(LL1.insertTotal);
	LL2.insertAvg = getAverageTime(LL2.insertTotal);
	BST1.insertAvg = getAverageTime(BST1.insertTotal);
	BST2.insertAvg = getAverageTime(BST2.insertTotal);
	LP1.insertAvg = getAverageTime(LP1.insertTotal);
	LP2.insertAvg = getAverageTime(LP2.insertTotal);

	LL1.lookupAvg = getAverageTime(LL1.lookupTotal);
	LL2.lookupAvg = getAverageTime(LL2.lookupTotal);
	BST1.lookupAvg = getAverageTime(BST1.lookupTotal);
	BST2.lookupAvg = getAverageTime(BST2.lookupTotal);
	LP1.lookupAvg = getAverageTime(LP1.lookupTotal);
	LP2.lookupAvg = getAverageTime(LP2.lookupTotal);

	LL1.deleteAvg = getAverageTime(LL1.deleteTotal);
	LL2.deleteAvg = getAverageTime(LL2.deleteTotal);
	BST1.deleteAvg = getAverageTime(BST1.deleteTotal);
	BST2.deleteAvg = getAverageTime(BST2.deleteTotal);
	LP1.deleteAvg = getAverageTime(LP1.deleteTotal);
	LP2.deleteAvg = getAverageTime(LP2.deleteTotal);

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for inserts: " << LL1.insertAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for lookups: " << LL1.lookupAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for deletes: " << LL1.deleteAvg << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for inserts: " << LL2.insertAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for lookups: " << LL2.lookupAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for deletes: " << LL2.deleteAvg << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for inserts: " << BST1.insertAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for lookups: " << BST1.lookupAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for deletes: " << BST1.deleteAvg << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for inserts: " << BST2.insertAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for lookups: " << BST2.lookupAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for deletes: " << BST2.deleteAvg << endl;

	cout << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for inserts: " << LP1.insertAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for lookups: " << LP1.lookupAvg << endl;

	cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for deletes: " << LP1.deleteAvg << endl;

	cout << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for inserts: " << LP2.insertAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for lookups: " << LP2.lookupAvg << endl;

	cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for deletes: " << LP2.deleteAvg << endl;

	cout << endl;



	}
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;


	cout << endl << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "------------------------------  dataset 2  ----------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Factor = 0.0;
	numLoads = 0;
	loadIdx = 0;
	idx = 0;
	currentThings = 0;
	inputK = 0;

	startClock = 0;
	endClock = 0;
	execTime = 0.0;

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

				inputK = csvFile2[i]; // this

				LL1set2.insertLLhash1(inputK);

				LL2set2.insertLLhash2(inputK);

				BST1set2.insertBSThash1(inputK);

				BST2set2.insertBSThash2(inputK);

				LP1set2.insertLinearhash1(inputK);

				LP2set2.insertLinearhash2(inputK);

				currentThings++;

			}


			for(int i = idx; i < idx + 100; i++){

				inputK = csvFile2[i];

				//__________________________________________________________
				////////////////////////////////////////////////////////////
				/////////// linked-list/hash 1:
				startClock = clock();

				LL1set2.insertLLhash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL1set2.insertTotal += execTime;

				////////////////////////////////////////////////////////////
				startClock = clock();

				LL1set2.lookupLLhash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL1set2.lookupTotal += execTime;

				////////////////////////////////////////////////////////////
				startClock = clock();

				LL1set2.deleteLLhash1(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL1set2.deleteTotal += execTime;

				////////////////////////////////////////////////////////////
				/////////// linked-list/hash 2:

				startClock = clock();

				LL2set2.insertLLhash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL2set2.insertTotal += execTime;
				////////////////////////////////////////////////////////////
				startClock = clock();

				LL2set2.lookupLLhash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL2set2.lookupTotal += execTime;
				////////////////////////////////////////////////////////////
				startClock = clock();

				LL2set2.deleteLLhash2(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LL2set2.deleteTotal += execTime;

				//__________________________________________________________
				////////////////////////////////////////////////////////////
				/////////// BST/hash 1:
				startClock = clock();

				BST1set2.insertBSThash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST1set2.insertTotal += execTime;

				////////////////////////////////////////////////////////////
				startClock = clock();

				BST1set2.lookupBSThash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST1set2.lookupTotal += execTime;

				///////////////////////////////////////////////////////////

				startClock = clock();

				BST1set2.deleteBSThash1(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST1set2.deleteTotal += execTime;

				////////////////////////////////////////////////////////////
				/////////// BST/hash 2:

				startClock = clock();

				BST2set2.insertBSThash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST2set2.insertTotal += execTime;
				////////////////////////////////////////////////////////////
				startClock = clock();

				BST2set2.lookupBSThash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST2set2.lookupTotal += execTime;
				////////////////////////////////////////////////////////////

				startClock = clock();

				BST2set2.deleteBSThash2(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				BST2set2.deleteTotal += execTime;

				//__________________________________________________________
				////////////////////////////////////////////////////////////
				/////////// Linear/hash 1:
				startClock = clock();

				LP1set2.insertLinearhash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP1set2.insertTotal += execTime;

				////////////////////////////////////////////////////////////
				startClock = clock();

				LP1set2.lookupLinearhash1(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP1set2.lookupTotal += execTime;

				////////////////////////////////////////////////////////////
				startClock = clock();

				LP1set2.deleteLinearhash1(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP1set2.deleteTotal += execTime;

				////////////////////////////////////////////////////////////
				/////////// Linear/hash 2:

				startClock = clock();

				LP2set2.insertLinearhash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP2set2.insertTotal += execTime;
				////////////////////////////////////////////////////////////
				startClock = clock();

				LP2set2.lookupLinearhash2(inputK);

				endClock = clock();

				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP2set2.lookupTotal += execTime;
				////////////////////////////////////////////////////////////

				startClock = clock();

				LP2set2.deleteLinearhash2(inputK);

				endClock = clock();
				execTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;

				LP2set2.deleteTotal += execTime;

				//__________________________________________________________
				////////////////////////////////////////////////////////////
			}
      //// In case want to show total time
		/*cout << endl;
		cout << "------------------------- total 100 times  - ( factor: " << Factor << ") ----------------------------------" << endl;
		cout << endl;


		cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 inserts: " << LL1set2.insertTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 lookups: " << LL1set2.lookupTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linked List total time for 100 deletes: " << LL1set2.deleteTotal << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 inserts: " << LL2set2.insertTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 lookups: " << LL2set2.lookupTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List total time for 100 deletes: " << LL2set2.deleteTotal << endl;

		cout << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 inserts: " << BST1set2.insertTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 lookups: " << BST1set2.lookupTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST total time for 100 deletes: " << BST1set2.deleteTotal << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 inserts: " << BST2set2.insertTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 lookups: " << BST2set2.lookupTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST total time for 100 deletes: " << BST2set2.deleteTotal << endl;

		cout << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 inserts: " << LP1set2.insertTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 lookups: " << LP1set2.lookupTotal << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear total time for 100 deletes: " << LP1set2.deleteTotal << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 inserts: " << LP2set2.insertTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 lookups: " << LP2set2.lookupTotal << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear total time for 100 deletes: " << LP2set2.deleteTotal << endl;

		cout << endl;*/

		cout << endl;
		cout << "----------------------- total Average time  -  ( factor: " << Factor << ") --------------------------------" << endl;
		cout << endl;

		LL1set2.insertAvg = getAverageTime(LL1set2.insertTotal);
		LL2set2.insertAvg = getAverageTime(LL2set2.insertTotal);
		BST1set2.insertAvg = getAverageTime(BST1set2.insertTotal);
		BST2set2.insertAvg = getAverageTime(BST2set2.insertTotal);
		LP1set2.insertAvg = getAverageTime(LP1set2.insertTotal);
		LP2set2.insertAvg = getAverageTime(LP2set2.insertTotal);

		LL1set2.lookupAvg = getAverageTime(LL1set2.lookupTotal);
		LL2set2.lookupAvg = getAverageTime(LL2set2.lookupTotal);
		BST1set2.lookupAvg = getAverageTime(BST1set2.lookupTotal);
		BST2set2.lookupAvg = getAverageTime(BST2set2.lookupTotal);
		LP1set2.lookupAvg = getAverageTime(LP1set2.lookupTotal);
		LP2set2.lookupAvg = getAverageTime(LP2set2.lookupTotal);

		LL1set2.deleteAvg = getAverageTime(LL1set2.deleteTotal);
		LL2set2.deleteAvg = getAverageTime(LL2set2.deleteTotal);
		BST1set2.deleteAvg = getAverageTime(BST1set2.deleteTotal);
		BST2set2.deleteAvg = getAverageTime(BST2set2.deleteTotal);
		LP1set2.deleteAvg = getAverageTime(LP1set2.deleteTotal);
		LP2set2.deleteAvg = getAverageTime(LP2set2.deleteTotal);

		cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for inserts: " << LL1set2.insertAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for lookups: " << LL1set2.lookupAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linked List avg time for deletes: " << LL1set2.deleteAvg << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for inserts: " << LL2set2.insertAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for lookups: " << LL2set2.lookupAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linked List avg time for deletes: " << LL2set2.deleteAvg << endl;

		cout << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for inserts: " << BST1set2.insertAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for lookups: " << BST1set2.lookupAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /BST avg time for deletes: " << BST1set2.deleteAvg << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for inserts: " << BST2set2.insertAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for lookups: " << BST2set2.lookupAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /BST avg time for deletes: " << BST2set2.deleteAvg << endl;

		cout << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for inserts: " << LP1set2.insertAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for lookups: " << LP1set2.lookupAvg << endl;

		cout << "Hash 1 Factor ("<<Factor<<") /Linear avg time for deletes: " << LP1set2.deleteAvg << endl;

		cout << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for inserts: " << LP2set2.insertAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for lookups: " << LP2set2.lookupAvg << endl;

		cout << "Hash 2 Factor ("<<Factor<<") /Linear avg time for deletes: " << LP2set2.deleteAvg << endl;

		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	return 0;
}
