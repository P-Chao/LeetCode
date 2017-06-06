#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNumN(int num) {  //146ms
		maxsmall.push(num);
		minlarge.push(maxsmall.top());
		maxsmall.pop();
		if (maxsmall.size() < minlarge.size()){
			maxsmall.push(minlarge.top());
			minlarge.pop();
		}
	}

	double findMedian() {
		if (maxsmall.size() == minlarge.size()){
			return (maxsmall.top() + minlarge.top()) / 2.0;
		} else{
			return maxsmall.top();
		}
	}

private:
	priority_queue<int, vector<int>, less<int>> maxsmall;
	priority_queue<int, vector<int>, greater<int>> minlarge;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/

int main(int argc, char *argv[]){
	MedianFinder *obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(3);
	double param_2 = obj->findMedian();
	cout << param_2;
	return 0;
}
