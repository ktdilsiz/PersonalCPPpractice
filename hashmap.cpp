#include <iostream>
#include <vector>


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


struct HashNode{

    HashNode* next;
    int data;
    int key;
    int hashCode;

    HashNode::HashNode(
        HashNode* next, 
        const int& data, 
        const int& key, 
        const int& hashCode
        ) : next(next), data(data), key(key), hashCode(hashCode)
        {}

}

class HashMap{

    public:
        HashMap();
        ~HashMap();

        void put(int key, int value);
        int get(int key);

        bool isEmpty();
        int size();

    private:
        int size();
        bool isEmpty;
        HashNode* table;

}