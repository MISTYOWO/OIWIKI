#include "../src/heapsort.h"
#include "iostream"

int main() {
	std::vector<int> nums{2,3,5,1,4,2,55,21,321,41,55,1341232,4124,11};
	heapSort<int,std::greater<int>>(nums);
	for (auto num : nums) {
		std::cout << num << std::endl;
	}
	return 0;
}
