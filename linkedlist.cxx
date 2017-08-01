#include <iostream>

struct node{
    int data;
    node *next;

    node::node(){}

    node::node(const int & val, node* link)
            : data(val), next(link)
    {}
};

class SingleLinkedList
{

    public:
        SingleLinkedList();

        SingleLinkedList(const SingleLinkedList& list);

        SingleLinkedList& operator=(const SingleLinkedList& list);

        void addToEnd(int val);
        void printList();
        void deleteList(node *head);
        void deleteNode(node *toBeDeleted);
        node* get(int index);
        ~SingleLinkedList();

    protected:
        int size;
        node *head, *tail;

};

SingleLinkedList::SingleLinkedList(){
    std::cout << "Simple Constructor called" << std::endl;
    head = NULL;
    tail = NULL;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& list)
{
    std::cout << "Copy Constructor called" << std::endl;

    if(!list.head) head = NULL;
    else{
        head = new node(list.head->data + 1000, NULL);

        node* current = head;
        node* temp = list.head;

        while(temp->next){
            std::cout << "copy constructor new element " 
                        << temp->next->data << endl;
            current->next = new node(temp->next->data + 1000, NULL);
            temp = temp->next;
            current = current->next;
        }

        tail = current;
    }
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& list)
{
    std::cout << "Operator= called" << std::endl;

    if(!list.head) head = NULL;
    else{
        head = new node(list.head->data + 2000, NULL);

        node* current = head;
        node* temp = list.head;

        while(temp->next){
            std::cout << "operator= new element" << endl;
            current->next = new node(temp->next->data + 2000, NULL);
            temp = temp->next;
            current = current->next;
        }

        tail = current;
    }
    return *this;
}

SingleLinkedList::~SingleLinkedList(){
    std::cout << "Destructor called" << std::endl;

    deleteList(head);
}

node* SingleLinkedList::get(int index){
    node* temp = head;
    int pointer = 0;

    while(pointer != index){
        if(!temp) return NULL;
        temp = temp->next;
        pointer++;
    }

    return temp;

}

void SingleLinkedList::addToEnd(int val){
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

void SingleLinkedList::printList(){
    node *temp = head;
    //temp = head;
    while(temp){
        std::cout<<temp->data<<"\t";
        temp = temp->next;
    }

    std::cout << std::endl;
}

void SingleLinkedList::deleteList(node *start){
    if(start){
        deleteList(start->next);
        delete start;
    }
}

void SingleLinkedList::deleteNode(node* toBeDeleted){
    if(head == toBeDeleted){
        head = toBeDeleted->next;
        delete toBeDeleted;
        if (!head) tail = NULL;
        return;
    }

    node* temp = head;

    while(temp->next != toBeDeleted){
        temp = temp->next;
    }

    temp->next = toBeDeleted->next;
    delete toBeDeleted;
    
    if(!temp->next) tail = temp;

}

int main(){
    SingleLinkedList list;

    for(int i=0;i<4;i++){
        list.addToEnd(i+1);
    }

    SingleLinkedList test1(list);

    SingleLinkedList test2;
    test2 = list;

    //list.deleteList(list.get(2));
    //list.deleteNode(list.get(2));

    list.printList();
    test1.printList();
    test2.printList();

    return 0;
}
