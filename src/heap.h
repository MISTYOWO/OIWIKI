#pragma once
#include <vector>
#include <functional>

template<typename T, class Cmp = std::less<>>
class heap {
	std::vector<T> datas;
	Cmp cmp;
public:
	void push(T value);
	void pop();
	T top();
	int size();
private:
	void shiftup();
	void shiftdown();
};

template<typename T, class Cmp>
void heap<T,Cmp>::shiftup() {
	int id = this->datas.size()-1;
	while (id) {
		int prel = id / 2;
		if (cmp(this->datas[id],this->datas[prel])) {
			std::swap(this->datas[prel],this->datas[id]);
			id = id / 2;
		} else {
			return;
		}
	}
}

template<typename T, class Cmp>
void heap<T,Cmp>::shiftdown() {
	if (this->datas.empty()) {
		return;
	}

	int id = 0;
	while (id < this->datas.size()) {
		int l = id * 2 + 1;
		int r = id * 2 + 2;
		int swapid = 0;
		if (l < this->datas.size() || r < this->datas.size()) {
			if (l < this->datas.size() && r < this->datas.size()) {
				if (cmp(this->datas[l],this->datas[r])) {
					swapid = l;
				} else {
					swapid = r;
				}
			} else {
				swapid = l;
			}
		}
		if (swapid == 0) {
			return;	
		}
		if (cmp(this->datas[swapid],this->datas[id])) {
			std::swap(this->datas[swapid],this->datas[id]);
			id = swapid;
		} else {
			return;
		}

	}
}

template<typename T, class Cmp>
void heap<T,Cmp>::push(T value) {
	this->datas.push_back(value);
	shiftup();
 }

template<typename T, class Cmp>
T heap<T,Cmp>::top() {
	if (this->datas.empty()) {
		return T{};
	}
	return this->datas.front();
}

template<typename T,class Cmp>
void heap<T,Cmp>::pop() {
	if (this->datas.empty()) {
		return;
	}

	auto size = this->datas.size();
	std::swap(this->datas[size - 1],this->datas[0]);
	this->datas.pop_back();	
	shiftdown();
}

template<typename T,class Cmp>
int heap<T,Cmp>::size() {
	return this->datas.size();
}
