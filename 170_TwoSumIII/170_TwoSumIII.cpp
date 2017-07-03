#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
	/** Initialize your data structure here. */
	TwoSum() {}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		hash[number]++;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for (auto val : hash){
			if (value != 2 * val.first && hash.count(value - val.first)){
				return true;
			}
			if (value == 2 * val.first && val.second > 1){
				return true;
			}
		}
		return false;
	}

private:
	unordered_map<int, int> hash;
};

int main(int argc, char *argv[]){
	TwoSum obj;
	obj.add(2);
	obj.add(3);
	cout << obj.find(5) << endl;
	system("pause");
	return 0;
}