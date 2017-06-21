#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue { // push 复杂，而pop和peek简单，首选
	stack< int > s1;
	stack< int > s2;
public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.push(x);
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = s1.top();
		s1.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		return s1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty();
	}
};

class MyQueueMy {
public:
	/** Initialize your data structure here. */
	MyQueueMy() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (s1.empty()){
			return 0;
		}
		int n = s1.size(), r = 0;
		for (int i = 1; i < n; ++i){
			int t = s1.top();
			s1.pop();
			s2.push(t);
		}
		r = s1.top();
		s1.pop();
		for (int i = 1; i < n; ++i){
			int t = s2.top();
			s2.pop();
			s1.push(t);
		}
		return r;
	}

	/** Get the front element. */
	int peek() {
		if (s1.empty()){
			return 0;
		}
		s2.empty();
		int n = s1.size(), r = 0;
		for (int i = n-1; i > 0; --i){
			int t = s1.top();
			s1.pop();
			s2.push(t);
		}
		r = s1.top();
		//s1.pop();
		for (int i = n-1; i > 0; --i){
			int t = s2.top();
			s2.pop();
			s1.push(t);
		}
		return r;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty();
	}

private:
	stack<int> s1, s2;
};

int main(int argc, char *argv[]){
	MyQueue q;
	q.push(1);
	cout << q.peek() << endl;
	cout << q.pop() << endl;
	cout << q.empty() << endl;
	system("pause");
	return 0;
}