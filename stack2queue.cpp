#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
 * 用两个栈：push栈和pop栈
 * push栈往pop栈中倒数据时遵循两个原则：
 * 1 pop栈必须是空的才可以倒
 * 2 push栈每次倒数据必须把push栈中的数据全部倒到pop栈中不能有剩余
 * 遵循以上两个原则后，则倒数据的动作可以发生在任何时候。
 */
class MyQueue{
private:
	stack<int> stackpush, stackpop;
public:
	MyQueue(){

	}
	void push(int obj){
		stackpush.push(obj);
		//swap_push_and_pop();
	}

	void pop(){
		swap_push_and_pop();
		stackpop.pop();
	}

	// 返回队列头部元素
	int front(){
		if (stackpush.empty() && stackpop.empty()){
			cerr << "your queue is empty" << endl;
			return NULL;
		}
		// 队列头部元素即push栈栈底元素,即pop栈栈顶元素
		swap_push_and_pop();
		return stackpop.top();
	}

	// 返回队列底部元素
	int back(){
		// 队列底部元素即push栈栈顶元素
		if (stackpush.empty() && stackpop.empty()){
			cerr << "your queue is empty" << endl;
			return NULL;
		}
		//swap_push_and_pop();
		return stackpush.top();
	}

	int size(){
		return stackpush.size();
	}
	void swap_push_and_pop(){
		if (stackpop.empty()){
			while (!stackpush.empty()){
				int tmp = stackpush.top();
				stackpop.push(tmp);
				stackpush.pop();
			}
		}
	}
};

// 另一个想法：用两个栈：数据栈和辅助栈，pop和front的时候将数据栈的数据除了栈底外均导入辅助栈
// 删掉栈底(因为数据栈只剩这一个元素，也即栈顶),然后再将辅助栈的元素逐个弹出并压回数据栈
class MyQueue2{
private:
	stack<int> data,help;
public:
	MyQueue2(){

	}
	void push(int obj){
		data.push(obj);
	}

	void pop(){
		if (data.empty()){
			cerr << "your queue is empty";
		}
		else if (data.size() == 1){
			data.pop();
		}
		else{
			int datasize = data.size();
			for (int i = 0; i < datasize - 1; i++){
				int tmp = data.top();
				data.pop();
				help.push(tmp);
			}
			data.pop();
			int helpsize = help.size();
			for (int i = 0; i < helpsize; i++){
				int tmp = help.top();
				help.pop();
				data.push(tmp);
			}
		}
	}

	int front(){
		if (data.empty()){
			cerr << "your queue is empty";
			return NULL;
		}
		else if (data.size() == 1){
			return data.top();
		}
		else{
			int datasize = data.size();
			for (int i = 0; i < datasize - 1; i++){
				int tmp = data.top();
				data.pop();
				help.push(tmp);
			}
			int result = data.top();
			//data.pop();
			int helpsize = help.size();
			for (int i = 0; i < helpsize; i++){
				int tmp = help.top();
				help.pop();
				data.push(tmp);
			}
			data.push(result);
			return result;
		}
	}
	int back(){
		return data.top();
	}
	int size(){
		return data.size();
	}

};
int main(){
	MyQueue q1;
	cout << "befroe pop:   ";
	for (int i = 0; i < 20; i++){
		q1.push(i);
		cout << q1.back() << "   ";
	}
	cout << endl;
	cout << "q1.front:  "<<q1.front() << endl;
	cout << "after pop,q1.front: ";
	for (int i = 0; i < 20; i++){
		cout << q1.front() << "   ";
		q1.pop();
	}
	cout << endl;


	MyQueue2 q2;
	cout << "befroe pop:   ";
	for (int i = 0; i < 20; i++){
		q2.push(i);
		cout << q2.back() << "   ";
	}
	cout << endl;
	cout << "q2.front:  " << q2.front() << endl;
	cout << "after pop,q1.front: ";
	for (int i = 0; i < 20; i++){
		cout << q2.front() << "   ";
		q2.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}