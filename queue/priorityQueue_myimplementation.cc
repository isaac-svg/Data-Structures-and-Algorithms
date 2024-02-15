#include <stdexcept>
#include <iostream>

struct Node {
  int value;
  Node* next;
};

/**
 * @brief A Priority Queue class that stores elements in a max-heap structure
*/
class PriorityQueue {
private:
  Node* head;

  void swapNodes(Node* a, Node* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
  }

public:
  PriorityQueue() { head = nullptr; }
    /**
     * @brief inserts a value into a priority queue
    */
  void push(int value) {
    // Create a new node
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    // If the list is empty, make it the head
    if (head == nullptr) {
      head = newNode;
      return;
    }

    // Find the insertion position
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && curr->value > value) {
      prev = curr;
      curr = curr->next;
    }

    // Insert at the beginning
    if (prev == nullptr) {
      newNode->next = head;
      head = newNode;
      return;
    }

    // Insert in the middle
    prev->next = newNode;
    newNode->next = curr;
  }

  // Remove the highest priority element (max value)
  int pop() {
    if (head == nullptr) {
      throw std::runtime_error("Priority queue is empty");
    }

    int maxValue = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;

    // Maintain heap property by sifting down the new head
    Node* curr = head;
    while (curr != nullptr) {
      Node* left = curr->next;
      if (!left) return maxValue;
      Node* right = left->next;


      int maxIndex = curr->value;
      int maxIdx = -1; // Index of max value among curr, left, right

      if (left != nullptr && left->value > maxIndex) {
        maxIndex = left->value;
        maxIdx = 1;
      }
      if (right != nullptr && right->value > maxIndex) {
        maxIndex = right->value;
        maxIdx = 2;
      }

      if (maxIdx != -1) {
        swapNodes(curr, maxIdx == 1 ? left : right);
        curr = maxIdx == 1 ? left : right;
      } else {
        break;
      }
    curr = curr->next;
    }

    return maxValue;
  }

  // Check if the queue is empty
  bool empty() {
    return head == nullptr;
  }
};


int main() {
  PriorityQueue pq;

  pq.push(10);
  pq.push(20);
  pq.push(5);
  pq.push(-2);

  while (!pq.empty()) {
    int value = pq.pop();
    std::cout << value << " ";
  }

  std::cout << std::endl;

  return 0;
}
