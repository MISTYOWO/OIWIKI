#pragma once
#include <functional>
#include <vector>
#include <iostream>

template<class T,class Cmp = std::less<>>
void shiftdown(std::vector<T>& nums,int id,int len) {
	Cmp cmp;
	while (id < len) {
		int l = id * 2 + 1;
		int r = id * 2 + 2;
		int swapid = id;
		if (l < len || r < len) {
			if (l < len && r < len) {
				if (cmp(nums[l],nums[r])) {
					swapid = l;
				} else {
					swapid = r;
				}
			} else {
				swapid = l;
			}
			if (cmp(nums[swapid],nums[id])) {
				std::swap(nums[swapid],nums[id]);
				id = swapid;
			} else {
				return;
			}
		} else {
			return;
		}
	}	
}

template<class T,class Cmp = std::less<>>
void heapSort(std::vector<T>& nums) {
	int id = nums.size() / 2 - 1;
	while (id >= 0) {
		shiftdown(nums,id,nums.size());
		id--;
	}
	for (int i = 0; i < nums.size();i++) {
		std::swap(nums[0],nums[nums.size() - i - 1]);
		std::cout << "..." << nums[nums.size() - i -1];
		shiftdown(nums,0,nums.size() - i - 1);
	}
}
