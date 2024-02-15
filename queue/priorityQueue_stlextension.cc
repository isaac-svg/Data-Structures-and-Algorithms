#include  <queue>
#include <iostream>

struct Compare {
  bool operator()(int a, int b) const {
    return a % 2 < b % 2; // Even numbers have higher priority
  }
};
int main() {

  std::priority_queue<int> pq; // Max-heap 
//   std::priority_queue<int, std::vector<int>, Compare > pq2();

  pq.push(2);
  pq.push(5);
  pq.push(12);

 
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }

  return 0;
}
