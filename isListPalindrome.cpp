/*给定一个单向链表的头结点，判断是否回文
要求时间复杂度O(N)
1:当空间复杂度为O(N)时 思路如下：
  将链表中的每个元素逐步压入一个栈，栈先进后出
  将链表第一个元素和栈顶元素进行比对(链表指向下一个元素,栈顶元素出栈 进行下一轮比对) 
  如果直到栈空 都一直是相等的说明是回文 否则false;
2:进阶1
  【常数项1/2,时间复杂度依然是O(N)】
  思路：设置一个快指针 一个慢指针（常见技巧），
  快指针每次走两步 慢指针每次走一步，快指针走完时 慢指针会来到中点位置
   将右半部分压栈：将链表前半段与栈中元素比对 若相等 则回文
3:进阶2
   【时间复杂度依然是O(1)】
   思路：设置一个快指针 一个慢指针（常见技巧），
   快指针每次走两步 慢指针每次走一步，快指针走完时 慢指针会来到中点位置
   将链表右半部分逆序，然后逐个判断是否回文 判断完成后再次将右半段逆序，回复链表本来的顺序
*/
#include <iostream>
#include <algorithm>
#include <list>   //用c++提供的链表结构
#include <stack>

using namespace std;

// 基础解法 ：额外开辟一个栈
bool isBack2Next_1(list<int> head){
	if (head.size() < 2)
		return true;
	stack<int> help;
	list<int>::iterator it = head.begin();
	for (; it != head.end(); it++){
		help.push(*it);
	}
	it = head.begin();
	for (; it != head.end(); ){
		if (*it != help.top()){
			return false;
		}
		help.pop();
		it++;
	}
	return true;
}


// 进阶解法1：空间复杂度O(N) 压一半栈_使用迭代器代替指针
bool isBack2Next_2(list<int> head){
	if (head.size() < 2)
		return true;
	list<int>::iterator slow = head.begin();
	list<int>::iterator fast = head.begin();
	while (fast != head.end()){
		fast++;
		if (fast != head.end())  // 假设上次++已经到了end,如果再++ 会溢出
		{
			fast++;
		}
		slow++;
	}
	//cout << *slow << endl;
	stack<int> help;
	while (slow != head.end()){
		help.push(*slow);
		slow++;
	}
	slow = head.begin();
	while (!help.empty()){
		if (*slow != help.top()){
			//cout <<" *slow  "<< *slow << endl;
			//cout << " help.top()  " << help.top() << endl;
			return false;
		}
		slow++;
		help.pop();
	}
	return true;
}

// 进阶解法2：链表后半段逆序
bool isBack2Next_3(list<int> head){
	// 得到中间指针后
	// !逆序：当前节点p 下一个节点k 让k->next=p之前先存储k->next;
	// TODO:由于使用c++自带的list,无法指定节点的下一个节点的指向 不便进行指针操作，所以改为用自己写的链表结构实现。
	// 具体见另一个cpp文件
	

}


int main(){
	list<int> head;
	for (int i = 0; i <= 8; i++){
		head.push_back(i);
	}
	for (int i = 7; i >= 0; i--){
		head.push_back(i);
	}
	cout << "list:   ";
	list<int>::iterator it = head.begin();
	for (; it != head.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;

	if (isBack2Next_1(head)){
		cout << "isBack2Next_1: head is a palindrome" << endl;
	}
	else{
		cout << "isBack2Next_1: head is not a palindrome" << endl;

	}

	if (isBack2Next_2(head)){
		cout << "isBack2Next_2: head is a palindrome" << endl;
	}
	else{
		cout << "isBack2Next_2: head is not a palindrome" << endl;

	}
	system("pause");
	return 0;
}