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
        //~HashMap();

        void put(int key, int value);
        int get(int key);
        int deleteEntry(int key, int value);

        int generateHashCode(int number);
        void HashMap::putToListOfNodes(HashNode& first, HashNode& newNode);

        void printHashMap();
        void printNodes(HashNode* node);

        bool isEmpty();
        int getSize();

    private:
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
            if different, put in next node until nullptr

    When the user calls get(key)
        convert key to an index through hashcode
        check if key's match, if so return
        if key's don't match, continue traversing through
        Return the data from node when key's match

    When the user calls delete(key, value)
        convert key to an index through hashcode
        check if key's match, if so delete
        replace by next node if not null (you can always replace)
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
    table = new HashNode*[10];
}

HashMap::HashMap(int tableSizeInput){
    tableSize = tableSizeInput;
    empty = true;
    size = 0;
    table = new HashNode*[tableSize];
}

int HashMap::generateHashCode(int number){
    return number*31 % tableSize;
}

void HashMap::putToListOfNodes(HashNode& first, HashNode& newNode){
    HashNode temp = first;
    if(first.key == newNode.key){
        first.data = newNode.data;
        return;
    }else{
        while(temp.next){
            if(temp.next->key == newNode.key){
                temp.next->data = newNode.data;
                return;
            }
        }
        *temp.next = newNode;
    }
}

void HashMap::printNodes(HashNode* node){
    HashNode* temp = node;
    
    while(temp != NULL){
        std::cout << "| Key: " << temp->key << 
                " Value: " << temp->data <<
                " | \t";
        temp = temp->next;
    }
}

void HashMap::printHashMap(){
    for(int i = 0; i < tableSize; i++){
        printNodes(table[i]);
        std::cout << std::endl;
    }
}

void HashMap::put(int key, int value){
    std::cout << key << " " << value << std::endl;
    int index = generateHashCode(key);
    std::cout << index << std::endl;

    HashNode* newNode = new HashNode(NULL, value, key, index);

    std::cout << &table[index] << std::endl;

    if(&table[index] != NULL){
        std::cout << "test" << std::endl;
        putToListOfNodes(*table[index], *newNode);
    }else{
                std::cout << "test2" << index <<  std::endl;
        table[index] = newNode;
                std::cout << "test3" << std::endl;
    }

}

int HashMap::get(int key){


}
int HashMap::deleteEntry(int key, int value){


}


int main(int argc){
    
    HashMap map;

    for(int i=1; i < 15; i++){
        map.put(i, i*2);
        std::cout << i << " " << i*2 << std::endl;
    }

    map.printHashMap();

    return 0;
}