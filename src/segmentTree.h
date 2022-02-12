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
	}
};

