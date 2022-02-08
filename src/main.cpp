#include <iostream>
#include "heap.h"
int main() {
	heap<int,std::greater<int>> pq;
	pq.push(10);
	pq.push(1000);
	pq.push(1000);
	pq.push(0);
	pq.push(1);
	pq.push(2);
	pq.push(99);
	pq.push(88);
	pq.push(77);

	while (pq.size()) {
		std::cout << pq.top() << std::endl;
		pq.pop();
	}

	return 0;
}
