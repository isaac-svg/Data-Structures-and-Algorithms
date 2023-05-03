

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
    virtual void freeList();
    virtual void reverse();
    virtual void removeDuplicate();
    virtual LinkedList *CopyListReversed();
    virtual LinkedList *CopyList();
    virtual int findLength();
    virtual int nthNodeFromBegining(int index);
    virtual int nthNodeFromEnd(int index);
    virtual bool loopDetect();
    virtual bool reverseListLoopDetect();
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

    if (curr == nullptr || curr->value > v)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    while (curr->next != nullptr && curr->next->value < v)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
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

/**

*@brief Delete all the elements of a linked list.
*/
void LinkedList::freeList()
{
    Node *currNode = head;
    Node *nextNode;
    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = nullptr;
    list_size = 0;
}
/**
 * @brief reverse the linked list
 *
 */
void LinkedList::reverse()
{
    Node *currNode = head;
    Node *nextNode = nullptr;
    Node *prevNode = nullptr;

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}
/**
 * @brief Remove duplicates from the linked list
Remove duplicate values from the linked list. The linked list is sorted and it
contains some duplicate values, you need to remove those duplicate values. (You
can create the required linked list using SortedInsert() function)
 *
 * @return void
 */
void LinkedList::removeDuplicate()
{

    Node *currNode = head;

    while (currNode != nullptr)
    {
        if (currNode->next != nullptr && currNode->value == currNode->next->value)
        {
            Node *delMe;
            delMe = currNode->next;
            currNode->next = currNode->next->next;
            delete delMe;
        }
        else
        {
            currNode = currNode->next;
        }
    }
}
/**
 * @brief Copy List Reversed.
* Copy the content of linked list in another linked list in reverse order. If the original linked list contains elements in order 1,2,3,4, the new list should contain
the elements in order 4,3,2,1.
 *
 * @return LinkedList*
 */
LinkedList *LinkedList::CopyListReversed()
{
    Node *currNode = head;
    Node *tempNode1 = nullptr;
    Node *tempNode2 = nullptr;
    // traverse through the linked list
    while (currNode != nullptr)

    {
        tempNode2 = new Node(currNode->value, tempNode1);
        currNode = currNode->next;
        tempNode1 = tempNode2;
    }
    LinkedList *LL2 = new LinkedList();
    LL2->head = tempNode1;
    // the head of LL2(LinkedList2) is return because you only need the head of the linked to perform all other operations
    return LL2;
}
/**
 * @brief Copy the content of given linked list into another linked list.
 Copy the content of given linked list into another linked list. If the original
linked list contains elements in order 1,2,3,4, the new list should contain the
elements in order 1,2,3,4.
 *
 * @return LinkedList*
 */
LinkedList *LinkedList::CopyList()
{
    Node *headNode = nullptr;
    Node *tailNode = nullptr;
    Node *tempNode = nullptr;
    Node *currNode = head;

    if (currNode == nullptr)
    {
        LinkedList *LL2 = new LinkedList();
        LL2->head = nullptr;
        return LL2;
    }
    headNode = new Node(currNode->value, nullptr);
    tailNode = headNode;
    currNode = currNode->next;

    // iteration starts from the second node;
    while (currNode != nullptr)
    {
        tempNode = new Node(currNode->value, nullptr);
        tailNode->next = tempNode;
        tailNode = tempNode;
        currNode = currNode->next;
    }
    LinkedList *LL2 = new LinkedList();
    LL2->head = tempNode;
    return LL2;
}
/**
 * @brief Find Length
 Find the length of given linked list
 *
 * @return int
 */
int LinkedList::findLength()
{
    Node *currNode = head;
    int count = 0;
    while (currNode->next != nullptr)
    {
        count += 1;
        currNode = currNode->next;
    }
    return count;
}
int LinkedList::nthNodeFromBegining(int index)
{

    if (index > size() || index < 1)
    {
        throw std::string("TooFewNodes");
    }
    Node *currNode = head;
    int count = 0;

    while (currNode != nullptr && count < index - 1)
    {

        count += 1;
        currNode = currNode->next;
    }
    return currNode->value;
}
/**
 * @brief return the value of a linked list from the end
 *
 * @param index index from end
 * @return int
 */
int LinkedList::nthNodeFromEnd(int index)
{
    if (index > size())
    {
        std::string("TooFewNodes");
    }
    // in this approach we take two pointers one leads the other by the index the forward pointers moves to the indexth position while the other pointer waits. We then iterate both the forward pointer and the ther pointer. The forward pointer will reacch the end of the list before the other pointer .Therefore the position at which the other  pointer reached when the forward pointer had reached the end of the list is the right position.

    Node *forward = head;  // leading ptr
    Node *currNode = head; // lagging ptr
    int count = 0;
    while (forward != nullptr && count < index)
    {
        count++;
        forward = forward->next;
    }
    // now forwarding is leading currNode
    if (forward == nullptr)
    {
        throw std::string("TooFewNodes");
    }
    // makes forward and currNode move together
    while (forward != nullptr)
    {
        forward = forward->next;
        currNode = currNode->next;
    }
    return currNode->value;
}
/**
 * @brief Find if there is a loop in a linked list. If there is a loop, then
return true if not, then return false.
 *
 Analysis:
· The list is traversed with two pointers, one is slow pointer and another is
fast pointer. Slow pointer always moves one-step. Fast pointer always
moves two steps. If there is no loop, then control will come out of whileloop. So return false.
· If there is a loop, then there came a point in a loop where the fast pointer
will come and try to pass slow pointer and they will meet at a point. When
this point arrives, we come to know that there is a loop in the list. So return
true.
 * @return bool
 */
bool LinkedList::loopDetect()
{
    Node *fastPtr;
    Node *slowPtr;
    slowPtr = fastPtr = head; // all start from the head
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (fastPtr == slowPtr)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Find if there is a loop in a linked list. Use reverse list approach.
 *Analysis:
· Store pointer of the head of list in a temp variable.
· Reverse the list
· Compare the reversed list head pointer to the current list head pointer.
· If the head of reversed list and the original list are same then reverse the
list back and return true.
· If the head of the reversed list and the original list are not same, then
reverse the list back and return false. Which means there is no loop.
 * @return bool
 */
bool LinkedList::reverseListLoopDetect()
{
    Node *tempHead = head;
    reverse();
    if (head == tempHead)
    {
        reverse();
        return true;
    }
    return false;
}

/*
********************************DOUBLY LINKED LIST***************************
*/

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
    virtual LinkedList *CopyListReversed();
    virtual LinkedList *CopyList();
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
    // if (head == nullptr)
}
int main()
{

    LinkedList II = LinkedList();
    II.addHead(1);
    II.addHead(2);
    II.addHead(4);
    II.addHead(5);
    II.addHead(6);
    II.freeList();
    II.addHead(6);
    II.freeList();
    II.sortedInsert(7);
    II.print();
    int size = II.size();
    std::cout << size;
    std::cout << std::endl;
}