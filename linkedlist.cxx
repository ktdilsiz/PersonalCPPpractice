#include <iostream>

struct node{
    int data;
    node *next;

    node::node(){}

    node::node(const int & val, node* link)
            : data(val), next(link)
    {}
};

class LinkedList
{

    public:
        LinkedList();
        void addToEnd(int val);
        void printList();

    private:
        int size;
        node *head, *tail;

};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

void LinkedList::addToEnd(int val){

    node *temp = new node(val, NULL);
    // temp->data = val;
    // temp->next = NULL;

    if(head==NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::printList(){

    node *temp = head;
    //temp = head;
    while(temp){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}

int main(){


    LinkedList list;

    for(int i=0;i<4;i++){
        list.addToEnd(i+1);
    }

    list.printList();

    return 0;
}
