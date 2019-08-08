// 用队列实现栈
// 思路 用两个队列
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack{
private:
	queue<int> q1;
	queue<int> q2;
public:
	MyStack(){

	}

	void push(int obj){
		q1.push(obj);
	}

	void pop(){
		if (q1.empty()){
			cerr << "pop-->your stack is empty" << endl;
		}
		else if (q1.size() == 1){
			q1.pop();
		}
		else{
			int size = q1.size();
			//!这里将for循环条件换成for (int i = 0; i < q1.size() - 1; i++)
			//!则当长度为20时，循环只会进行9次,原因是循环体内有pop()操作，这会改变q1.size()的值
			for (int i = 0; i < size - 1; i++){
				int tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			q1.pop();
            // 这里也可以直接将q1和q2的引用交换一下
			//!此处与上文同，需记录q2的长度
			int size2 = q2.size();
			for (int i = 0; i < size2; i++){
				int tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
		}
	}
	int top(){
		if (q1.empty()){
			cerr << "top-->your stack is empty" << endl;
			return NULL;
		}
		else{
			return q1.back();
		}
	}
	int size(){
		return q1.size();
	}
};

int main(){
	MyStack s1;
	cout << "the content:" << endl;
	for (int i = 0; i < 20; i++){
		s1.push(i);
		cout << s1.top() << "  ";
	}
	cout << endl;

	cout << "pop:" << endl;
	for (int i = 0; i < 20; i++){
		cout << s1.top() << "  ";
		s1.pop();
	}
	system("pause");
	return 0;
}