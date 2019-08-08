// 实现一个特殊的栈，在实现栈的基本功能的基础上，再返回栈中最小元素的操作
// 要求 1 pop push getMin操作的时间复杂度都是O(1)
// 设计的栈类型可以使用现成的栈结构(栈的实现结构：双向链表结构 / 数组)
/**
* 思想:建立两个栈 1数据栈 2最小栈，每当数据栈有数据压入时将该数据与最小栈栈顶元素进行比较，将较小的值同步压入最小栈
*      弹出时两个栈也同步弹出
*/
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
class MyStack{

private:
	stack<int> dataStack;
	stack<int> minStack;
	
public: 
	MyStack(){
		
	}
	void push(int obj){
		dataStack.push(obj);
		if (minStack.empty()){
			minStack.push(obj);
		}
		else {
			minStack.push(min(this->getMin(), obj));
		}
	}

	void pop(){
		minStack.pop();
		dataStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin(){
		if (!minStack.empty()){
			return minStack.top();
		}
		else{
			cerr << "your stack is empty";
		}
	}
	int getSize(){
		return dataStack.size();
	}
};

int main(){
	MyStack s1;
	s1.push(1);
	s1.push(3);
	s1.push(6);

	cout <<"top is :"<< s1.top() << endl;

	for (int i = 0; i < s1.getSize(); i++){
		s1.pop();
	}

	for (int i = 0; i < 15; i++){
		s1.push(i % 5);
	}
	cout << "top is :" << s1.top() << endl;
	cout << "min is:"<<s1.getMin() << endl;
	system("pause");
	return 0;
}
