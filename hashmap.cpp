#include <iostream>
#include <vector>

struct HashNode{

    HashNode* next;
    int data;
    int key;
    int hashCode;

    HashNode::HashNode(
        HashNode* link, 
        const int& val, 
        const int& key, 
        const int& hashCode
        ) : next(link), data(val), key(key), hashCode(hashCode)
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


}