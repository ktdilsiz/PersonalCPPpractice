#include <iostream>
#include <vector>
#include <cstddef>

struct HashNode{

    HashNode* next;
    int data;
    int key;
    int hashCode;

    HashNode::HashNode(){}

    HashNode::HashNode(
        HashNode* next, 
        const int& data, 
        const int& key, 
        const int& hashCode
        ) : next(next), data(data), key(key), hashCode(hashCode)
        {}

};

class HashMap{

    public:
        HashMap();
        HashMap(int tableSize);
        ~HashMap();

		HashMap(const HashMap& map);
		HashMap& operator=(const HashMap& map);

        void put(int& key, int& value);
        int get(int key);
        void deleteEntry(int key, int value);

        int generateHashCode(int number);

        void printHashMap();
        void printNodes(HashNode* node);

        bool isEmpty();
        int getSize();

    //private:
        int size;
        int tableSize;
        bool empty;
        HashNode** table;

};

/*
    Planning HashMap

    >array of size 10 intially
    >constructor to change size of array

    When the user calls put(key, value):
        convert key to an index through hashcode
        create a new HashNode
        place the HashNode in the index in array table
            if the index is occupied
            check if key's are the same
            if same, update value
            if different, put in next node until nullptrptr

    When the user calls get(key)
        convert key to an index through hashcode
        check if key's match, if so return
        if key's don't match, continue traversing through
        Return the data from node when key's match

    When the user calls delete(key, value)
        convert key to an index through hashcode
        check if key's match, if so delete
        replace by next node if not nullptr (you can always replace)
        if key's don't match, continue traversing through
        Delete the node when key's match

    Destructor
        traverse through the array and call deleteHashNode
        which should delete all the linking HashNodes

    Copy Constructor
        traverse through the array and copy 

    When the user calls isEmpty
        return isEmpty

*/ 

HashMap::HashMap(){
    tableSize = 10;
    empty = true;
    size = 0;
    table = new HashNode*[10]();
}

HashMap::HashMap(int tableSizeInput){
    tableSize = tableSizeInput;
    empty = true;
    size = 0;
    table = new HashNode*[tableSize]();
}

HashMap::~HashMap(){

	HashNode* temp;
	HashNode* prev;
	HashNode* toBeDeleted = nullptr;

	for (unsigned long i = 0; i < tableSize; i++) {
		HashNode* temp = table[i];
		HashNode* prev = nullptr;

		while (temp != nullptr) {
			prev = temp;
			toBeDeleted = temp;
			temp = prev->next;
			delete toBeDeleted;
		}

		table[i] = nullptr;
	}
}

HashMap::HashMap(const HashMap& map) {
	std::cout << "Copy Constructor called" << std::endl;
	HashNode* temp;
	HashNode* prev;

	tableSize = map.tableSize;
	empty = true;
	size = 0;
	table = new HashNode*[tableSize]();

	for (unsigned long i = 0; i < tableSize; i++) {
		HashNode* temp = map.table[i];
		HashNode* prev = nullptr;
		HashNode* current = table[i];

		if (temp != nullptr) {
			table[i] = new HashNode(nullptr, temp->data + 1000, temp->key, temp->hashCode);
			current = table[i];
			temp = temp->next;
		}

		while (temp != nullptr) {
			current->next = new HashNode(nullptr, temp->data + 1000, temp->key, temp->hashCode);
			current = current->next;
			temp = temp->next;
		}
	}
}

HashMap& HashMap::operator=(const HashMap& map) {
	std::cout << "Operator= called" << std::endl;
	
	HashNode* temp;
	HashNode* prev;

	tableSize = map.tableSize;
	empty = true;
	size = 0;
	table = new HashNode*[tableSize]();

	for (unsigned long i = 0; i < tableSize; i++) {
		HashNode* temp = map.table[i];
		HashNode* prev = nullptr;
		HashNode* current = table[i];

		if (temp != nullptr) {
			table[i] = new HashNode(nullptr, temp->data + 2000, temp->key, temp->hashCode);
			current = table[i];
			temp = temp->next;
		}

		while (temp != nullptr) {
			current->next = new HashNode(nullptr, temp->data + 2000, temp->key, temp->hashCode);
			current = current->next;
			temp = temp->next;
		}
	}
	return *this;
}


int HashMap::generateHashCode(int number){
    return number*31 % tableSize;
}

void HashMap::printNodes(HashNode* node){
    HashNode* temp = node;

	if (temp == nullptr) return;

    while(temp != nullptr){
        std::cout << "| Key: " << temp->key << 
                " Value: " << temp->data <<
                " | \t";
        temp = temp->next;
    }
	std::cout << std::endl;
}

void HashMap::printHashMap(){
	std::cout << "-------------- \n Printing HashMap \n --------------" << std::endl;
    for(unsigned long i = 0; i < tableSize; i++){
        printNodes(table[i]);
    }
	std::cout << "-------------- \n Finished Printing \n --------------" << std::endl;
}

void HashMap::put(int& key, int& value){
    unsigned long index = generateHashCode(key);

	HashNode *prev = nullptr;
    HashNode *entry = table[index];

    while(entry != nullptr && entry->key != key){
        prev = entry;
        entry = entry->next;
    }

    if(entry == nullptr){
        HashNode* newNode = new HashNode(nullptr, value, key, index);

        if(prev == nullptr){
            table[index] = newNode;
        }else{
            prev->next = newNode;
        }

    }else{
        entry->data = value;
    }

	std::cout << "Successfully added Key: " << key << " Value: " << value << std::endl;

}

int HashMap::get(int key){

	unsigned long index = generateHashCode(key);

	HashNode *prev = nullptr;
	HashNode *entry = table[index];

	while (entry != nullptr && entry->key != key) {
		prev = entry;
		entry = entry->next;
	}

	if (entry == nullptr) {
		std::cout << "Couldn't find " << key << std::endl;
		return NULL;
	}
	else {
		std::cout << "Successfully found " << key << std::endl;
		return entry->data;
	}

	//return 0;
}
void HashMap::deleteEntry(int key, int value){

	unsigned long index = generateHashCode(key);

	HashNode *prev = nullptr;
	HashNode *entry = table[index];

	while (entry != nullptr && entry->key != key) {
		prev = entry;
		entry = entry->next;
	}

	if (entry == nullptr) {
		std::cout << "Couldn't find/delete Key: " << key << " Value: " << value << std::endl;
		return;
	}
	else {
		if (prev == nullptr) {
			table[index] = entry->next;
			delete entry;
			std::cout << "Successfully deleted Key: " << key << " Value: " << value << std::endl;
		}
		else {
			prev->next = entry->next;
			delete entry;
			std::cout << "Successfully deleted Key: " << key << " Value: " << value << std::endl;
		}
	}

}


int main(int argc){
    
    HashMap map;
    int testValue;

    for(int i=0; i < 35; i++){
        testValue = i;
        map.put(testValue, testValue);
    }

    map.printHashMap();
	
	HashMap second(map);

	second.printHashMap();

	HashMap third;
	third = map;

	third.printHashMap();

	for (int i = 0; i < 40; i++) {
		testValue = i;
		std::cout << map.get(testValue) << "\t";
	}

	std::cout << std::endl;

	//map.deleteEntry(1, 1);
	//map.deleteEntry(33, 33);
	//map.deleteEntry(12, 12);
	//map.deleteEntry(35, 35);

	map.~HashMap();

	map.printHashMap();

    return 0;
}