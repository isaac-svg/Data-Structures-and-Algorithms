

/**
 * @file LinkedList.c++
 * @author isaac-svg (https://github.com/isaac-svg)
 * @brief  LinkedList Data Structure
 * @version 0.1
 * @date 2023-04-09
 */

#include <iostream>

/**
 * The linked list is a list of items, called nodes. Nodes have two parts, value part
and link part. Value part is used to stores the data. The value part of the node can
be either a basic data-type like an integer or it can be some other data-type like
an object of some class.
The link part is a pointer, which is used to store addresses of the next element in
the list.
 *
 */

/**
 * @brief Types of Linked list
There are different types of linked lists. The main difference among them is how
their nodes refer to each other.
Singly Linked List
Each node (Except the last node) has a pointer to the next node in the linked list.
The link portion of node contains the address of the next node. The link portion
of the last node contains the value null.
Doubly Linked list
The node in this type of linked list has pointer to both previous and the next node
in the list.
Circular Linked List
This type is similar to the singly linked list except that the last element have
pointer to the first node of the list. The link portion of the last node contains the
address of the first node.
 *
 */

/**
 * @brief The various parts of linked list
1. Head: Head is a pointer that holds the address of the first node in the linked
list.
2. Nodes: Items in the linked list are called nodes.
3. Value: The data that is stored in each node of the linked list.
4. Link: Link part of the node is used to store the pointer of other node.
 */

class LinkedList
{

private:
    struct Node
    {
        int value;
        Node *next;
        Node(int v, Node *n);
        Node(int v);
    };
    Node *head;
    int list_size = 0;

public:
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
    // Other Linked List Methods
};

LinkedList::Node::Node(int v, Node *n)
{
    value = v;
    next = n;
}
LinkedList::Node::Node(int v)
{
    value = v;
    next = nullptr;
}

int LinkedList::size()
{
    return list_size;
}
bool LinkedList::isEmpty()
{
    return list_size == 0;
}
/**
 * @brief Various methods by which an element may be inserted in alinked list
1. Insertion of an element at the start of linked list
2. Insertion of an element at the end of linked list
3. Insertion of an element at the Nth position in linked list
4. Insert element in sorted order in linked list
 */

// Insert element at the Head
void LinkedList::addHead(int v)
{
    head = new Node(v, head);
    list_size++;
}
// peek value at the head
int LinkedList::peek()
{
    if (head == nullptr)
    {
        throw std::string("EmptyListException");
    }
    return head->value;
}
// Insert element at the Tail

void LinkedList::addTail(int v)
{
    Node *NewNode = new Node(v, nullptr);
    Node *curr = head;
    if (head == nullptr)
    {
        head = NewNode;
    }
    while (head != nullptr)
    {
        curr = curr->next;
    }
    curr->next = NewNode;
}
// Traversing Linked List

void LinkedList::print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value;
        temp = temp->next;
    }
    std::cout << std::endl;
}
// Sorted Insert Insert an element in sorted order in linked list given Head pointer
void LinkedList::sortedInsert(int v)
{
    Node *newNode = new Node(v, nullptr);
    Node *curr = head;

    if (curr->next != nullptr || curr->value > v)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    while (curr->next != nullptr && curr->next->value < v)
    {
        curr = curr->next;
    }
    newNode = curr->next;
    curr->next = newNode;
}

/**
 * @brief Search Element in a Linked-List
 *
Search element in linked list. Given a head pointer and value. Returns true if
value found in list else returns false.
 * @return bool
 */
bool LinkedList::isPresent(int data)
{
    Node *curr = head;

    while (curr->next != nullptr)
    {
        if (curr->value == data)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
// Complete code for list creation and printing the list.
/**
 * @brief remove the head node;
 *
 * @return head->value
 */
int LinkedList::removeHead()
{
    if (isEmpty())
    {
        throw std::string("EmptyListException");
    }
    Node *deleteMe = head;
    int value = head->value;
    head = head->next;
    list_size--;
    delete deleteMe;
    return value;
}
// Delete node from the linked list given its value.

bool LinkedList::deleteNode(int data)
{
    if (isEmpty())
    {
        throw std::string("EmptyListException");
    }
    // traverse through the linked list to find the node the node that has value data.
    Node *curr = head;
    Node *delMe = nullptr;

    if (head->value == data)
    {
        Node *delMe = head;
        head = head->next;
        list_size--;
        delete delMe;
        return true;
    }
    while (curr->next != nullptr)
    {
        if (curr->next->value == data)
        {
            delMe = curr->next;
            curr->next = curr->next->next;
            list_size--;
            delete delMe;
            return true;
        }
        curr = curr->next;
    }
    return false;
}
// Delete all the occurrence of particular value in linked list.
void LinkedList::deleteNodes(int delValue)
{
    Node *currNode = head;
    Node *delMe = nullptr;
    Node *nextNode = nullptr;
    // check for first occurence.
    while (currNode != nullptr && currNode->value == delValue)
    {
        delMe = head;
        head = currNode->next;
        currNode = head;
        delete delMe;
    }
    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        if (nextNode != nullptr && nextNode->value == delValue)
        {
            delMe = currNode->next;
            currNode->next = nextNode->next;
            delete delMe;
        }
        else
        {
            currNode = nextNode;
        }
    }
}
int main()
{

    LinkedList II = LinkedList();
    II.addHead(1);
    II.addHead(2);
    II.addHead(4);
    II.addHead(5);
    II.addHead(6);
    II.addHead(6);
    II.sortedInsert(7);
    II.print();
    int size = II.size();
    std::cout << size;
    std::cout << std::endl;
}