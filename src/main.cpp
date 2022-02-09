#include <iostream>
#include "kmp.h"
int main() {
    std::string s = "abbbadc";
    std::string t = "badce";
    int ret = find(s,t);
    std::cout << ret << std::endl; 
    return 0;
}
//#include "heap.h"
//int main() {
//	heap<int,std::greater<int>> pq;
//	pq.push(10);
//	pq.push(1000);
//	pq.push(1000);
//	pq.push(0);
//	pq.push(1);
//	pq.push(2);
//	pq.push(99);
//	pq.push(88);
//	pq.push(77);
//
//	while (pq.size()) {
//		std::cout << pq.top() << std::endl;
//		pq.pop();
//	}
//
//	return 0;
//}
