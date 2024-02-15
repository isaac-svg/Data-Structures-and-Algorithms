#include <iostream>
#include <string>


class DoublyLinkedList
{
private:
    struct Node
    {
        int value;
        Node *prev;
        Node *next;
        Node(int value, Node *prev, Node *next);
        Node(int v);
    };
    Node *head;
    Node *tail;
    int list_size;

public:
    DoublyLinkedList();
    virtual int size();
    virtual int peek();
    virtual bool isEmpty();
    virtual void addHead(int v);
    virtual int removeHead();
    virtual void addTail(int v);
    virtual void print();
    virtual void sortedInsert(int v);
    virtual bool isPresent(int v);
    virtual bool deleteNode(int v);
    virtual void deleteNodes(int v);
    virtual void freeList();
    virtual void reverse();
    virtual void removeDuplicate();
    virtual DoublyLinkedList *CopyListReversed();
    virtual DoublyLinkedList *CopyList();
    virtual int findLength();
    virtual int nthNodeFromBegining(int index);
    virtual int nthNodeFromEnd(int index);
    virtual bool loopDetect();
    virtual bool reverseListLoopDetect();
};

DoublyLinkedList::DoublyLinkedList(/* args */)
{
    list_size = 0;
}
DoublyLinkedList::Node::Node(int val)
{
    value = val;
    next = nullptr;
    prev = nullptr;
}
DoublyLinkedList::Node::Node(int val, Node *next, Node *prev)
{
    value = val;
    this->next = next;
    this->prev = prev;
}
int DoublyLinkedList::size()
{
    return list_size;
}

bool DoublyLinkedList::isEmpty()
{
    return list_size == 0;
}
int DoublyLinkedList::peek()
{
    if (isEmpty())
    {
        throw std::string("EmptyListException");
    }
    return head->value;
}
void DoublyLinkedList::addHead(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
    }

   head->prev = newNode;
   newNode->next = head;
   head = newNode;


}

int DoublyLinkedList::removeHead(){

    if (head == nullptr) return -1;
    Node *delMe = head;
    int val = delMe->value;
    head = head->next;

    if (head){

    head->prev = nullptr;
    }

    delete delMe;

    return val;

}
void DoublyLinkedList::addTail(int val){

// if head is null then just add to head
    if (head == nullptr){
        addHead(val);
        return;
    }
    Node *currNode =  head;
// loop to the end of the list
    while (currNode)
    {
        currNode = currNode->next;
    }

    Node *newNode = new Node(val);

    currNode->next = newNode;
    newNode->prev = currNode;

}

void DoublyLinkedList::reverse(){
    if (head == nullptr || head->next == nullptr) return;

    Node *currNode = head;
    Node *nextNode =nullptr;


    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = currNode->prev;
        currNode->prev = nextNode;
        currNode = nextNode;
    }
    
}



bool DoublyLinkedList::deleteNode(int v){
    if (head == nullptr) return false;

    Node *currentNode = head;
    if (head->value == v){
        Node *delMe = head;

        head = head->next;
        head->next->prev = nullptr;
        return;
    }
    while (currentNode->next != nullptr)
    {
        if (currentNode->value == v){

            Node * delMe = currentNode;
            currentNode->prev->next = delMe->next;
            currentNode->prev = delMe->prev;

             return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}
 DoublyLinkedList* DoublyLinkedList::CopyList(){

    if (head == nullptr) return nullptr;

    DoublyLinkedList * newList = new DoublyLinkedList();

    Node *currNode = head;

    while (currNode !=  nullptr)
    {
        Node *newNode = new Node(currNode->value);
        // if inserting for the first time into the list
        if (newList->head == nullptr){
            newList->head = newNode;
            newList->tail =newNode;
        }
        else{

            newList->tail->next = newNode;
            newNode->prev = newList->tail;
            newList->tail = newNode;
        }
        currNode = currNode->next;
    }
    return newList;
 }
