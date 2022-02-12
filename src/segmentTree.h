#include <vector>
#include <list>
#include <functional>
#include <type_traits>
#include <set>
#include <iostream>
template<typename T,typename std::enable_if<std::is_integral<T>::value,bool>::type = true>
class SegmentTree {
public:
	std::vector<T> nodes;
	std::vector<T> origin;
	std::vector<T> modify;
	SegmentTree(std::vector<T> arrays) : origin(arrays){}
	void build(){
		int size = origin.size();
		std::function<int(int,int,int)> dfs = [&](int l,int r,int p)->int {
			if (p >= nodes.size()) {
				nodes.resize(p * 2 + 1);
			}
			if (l == r) {
				nodes[p] = origin[l];
				return origin[l];
			} else {
				int ret = 0;
				int mid = (l + r) / 2;
				ret += dfs(l,mid,p * 2 + 1);
				ret += dfs(mid + 1,r,p * 2 + 2);
				nodes[p] = ret;
				return ret;
			}
		};
		dfs(0,size - 1,0);
		modify.resize(nodes.size());
	}

	T getSum(int l, int r, int limitL, int limitR, int id) {
		if (limitL > r || limitR < l) {
			return 0;
		}

		if (limitL >= l && limitR <= r) {
			return nodes[id];
		}
		
		
		T ret = 0;
		int mid = (limitL + limitR) / 2;

		if(modify[id] && limitL != limitR) {
			nodes[id * 2 + 1] += modify[id] * (mid - limitL + 1);
			nodes[id * 2 + 2] += modify[id] * (limitR - mid);
			modify[id*2+1] += modify[id];
			modify[id*2+2] += modify[id];
			modify[id] = 0;
		}

		if (l <= mid) {
			ret += getSum(l,r,limitL,mid,id*2+1);
		}

		if (r > mid) {
			ret += getSum(l,r,mid + 1,limitR,id*2+2);	
		}

		return ret;
	}

	T getSum(int l, int r) {
		if (l > r) {
			return 0;
		}

		if (l < 0 || r >= origin.size()) {
			return 0;
		}

		return getSum(l,r,0,origin.size() - 1, 0);
	}

	void add(int l, int r, int val, int limitL, int limitR, int id) {
		if (l <= limitL && r >= limitR) {
			nodes[id] += val * (limitR - limitL + 1);
			modify[id] += val;
			return;
		}
		int mid = (limitL + limitR) / 2;
		if (modify[id] && limitL != limitR) {
			nodes[id*2+1] += modify[id] * (mid - limitL + 1);
			nodes[id*2+2] += modify[id] * (limitR - mid);
			modify[id*2+1] += modify[id*2];
			modify[id*2+2] += modify[id*2];
			modify[id] = 0;
		}
		if (l <= mid) {
			add(l,r,val,limitL,mid,id*2+1);
		}
		if (r > mid) {
			add(l,r,val,mid+1,limitR,id*2+2);
		}
		nodes[id] = nodes[id*2 + 1] + nodes[id*2 + 2];
	}

	void add(int l, int r, int val) {
		add(l,r,val,0,origin.size()-1,0);
	}
};

