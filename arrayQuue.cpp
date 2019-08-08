//用数组结构实现固定长度的循环队列

#include <vector>
#include <iostream>
using namespace std;

class ArrayQueue{
private: vector<int> arr;
		 int size;
		 int start;
		 int end;

public: ArrayQueue(int initsize) {
		if (initsize < 0) {
			cerr << "the init size is less than 0" << endl;
			//exit(1);
		}
		vector<int> tmp(initsize, 0);
		arr = tmp;
		size = 0; 
		start = 0;
		end = 0;
	}

	// 拿到最上面的数，但在队列中仍存在
	int peek() {
		if (size == 0){
			return NULL;
		}
		return arr[start];
	}

	// 向队列中添加一个数
	void push(int obj) {
		if (size == arr.size()) {
			cerr << "the queue is full" << endl;
			//exit(1);
		}
		size++;
		arr[end] = obj;
		end = nextIndex(arr.size(), end);
	}

	// 拿到最上面的数，并在队列中删除它
	int poll() {
		if (size == 0) {
			cerr << "the queue is empty" << endl;
		}
		size--;
		int tmp = start;
		start = nextIndex(arr.size(), start);
		return arr[tmp];
	}

	// 返回下一个start
	int nextIndex(int size, int index) {
		//cout << "size = " << size << endl;
		// ! == 而不是 =
		return index == size - 1 ? 0 : index + 1;
	}
};


int main()
{
	ArrayQueue arq(10);
	arq.push(2);
	cout << arq.peek() << endl;

	arq.push(3);
	cout << arq.peek() << endl;

	arq.push(4);
	cout << arq.peek() << endl;

	arq.push(5);
	cout << arq.peek() << endl;

	arq.push(6);
	cout << arq.peek() << endl;

	arq.poll();
	cout << arq.poll() << endl;
	cout << arq.poll() << endl;
	cout << arq.poll() << endl;;
	arq.push(7);
	arq.push(8);
	arq.push(9);
	arq.push(10);
	arq.push(1);
	cout << arq.peek() << endl;


	system("pause");
	return 0;
}