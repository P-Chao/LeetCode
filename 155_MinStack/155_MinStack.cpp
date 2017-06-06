#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || s2.top() >= x){
			s2.push(x);
		}
	}

	void pop() {
		if (s2.top() == s1.top()){
			s2.pop();
		}
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}

private:
	stack<int> s1, s2;
};

int main(int argc, char *argv[]){
	MinStack obj;
	obj.push(-3);
	obj.push(0);
	obj.push(-4);
	obj.push(-4);
	cout << obj.getMin() << endl; // -3
	obj.pop();
	obj.pop();
	obj.pop();
	cout << obj.top() << endl; // 0
	cout << obj.getMin() << endl; // -2
	system("pause");
	return 0;
}