#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class LRUCache {
	using ListIt = list<pair<int, int>>::iterator;
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end()){
			return -1;
		}
		cache.splice(cache.begin(), cache, it->second); // 将一个元素提前
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = hash.find(key);
		if (it != hash.end()){
			it->second->second = value;
			return cache.splice(cache.begin(), cache, it->second);
		}
		cache.insert(cache.begin(), {key, value});
		hash[key] = cache.begin();
		if (cache.size() > size){
			hash.erase(cache.back().first);
			cache.pop_back();
		}
	}
private:
	unordered_map<int, ListIt> hash;
	list<pair<int, int>> cache;
	int size;
};

int main(int argc, char *argv){
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);					// evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.put(4, 4);					// evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
	system("pause");
	return 0;
}