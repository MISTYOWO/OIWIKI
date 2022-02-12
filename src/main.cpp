#include <iostream>
#include "kmp.h"
#include "segmentTree.h"
int main() {
	std::vector<uint32_t> arrays{10,11,12,13,14};
	SegmentTree<uint32_t> sg(arrays);

	sg.build();
	for (auto item : sg.nodes) {
		std::cout << item << std::endl;
	}
	while (true) {
		int l, r;
		int val;
		std::cin >> l >> r >> val;
		std::cout <<"l" << l << "r" << r << "val" << val << std::endl;
		sg.add(l,r,val);
		std::cout << sg.getSum(l,r) << std::endl;
	}
    return 0;
}
