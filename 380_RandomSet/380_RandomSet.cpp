#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <algorithm>

using namespace std;

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(time(NULL));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash.find(val) != hash.end()){
			return false;
		}
		nums.push_back(val);
		hash[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hash.find(val) == hash.end()){
			return false;
		}
		hash[nums.back()] = hash[val];
		nums[hash[val]] = nums.back();
		hash.erase(val);
		nums.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int t = rand() % hash.size();
		return nums[t];
	}
private:
	unordered_map<int, int> hash;
	vector<int> nums;
};

int main(int argc, char *argv[]){
	RandomizedSet obj;
	cout << obj.insert(3) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.remove(1) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.getRandom() << endl;
	system("pause");
	return 0;
}