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
    return 0;
}
