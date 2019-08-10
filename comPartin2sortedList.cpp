
/*打印两个有序链表的公共部分：
给定两个有序链表的头指针head1 head2打印它们的公共部分
思路：如果head1<head2 head1向下移动
	  如果head1>head2,head2向下移动
	  如果head1==head2,head1 head2均向下移动
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// TODO:此处用的是自己定义的链表节点，可以直接使用c++提供的list结构来实现
typedef struct ListNode{
	int value;
	ListNode * next;
	ListNode(int value){
		this->value = value;
		this->next = nullptr;
	}
}listNode;

void printcommonIn2List(ListNode* head1, listNode* head2){
	listNode* p1 = head1;
	listNode* p2 = head2;
	while (p1 != NULL && p2 != NULL){
		if (p1->value < p2->value){
			p1 = p1->next;
		}
		else if (p1->value > p2->value){
			p2 = p2->next;
		}
		else{
			cout << p1->value << "  ";
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	
}

int main(){
	// 创建链表
	listNode* head1 = new listNode(2);//创建节点并偏移
	listNode* head2 = new listNode(2);
	listNode* p = head1;// 记录头结点
	listNode* q = head2;// 记录头结点

	for (int i = 0; i < 14; i++){
		p->next = (new listNode(i));
		p = p->next;

		q->next = (new listNode(i*2));
		q = q->next;
	}

	cout << "head1:    ";
	p = head1;
	while (p != NULL){
		cout << p->value << "  ";
		p = p->next;
	}
	cout << endl;

	cout << "head2:    ";
	q = head2;
	while (q != NULL){
		cout << q->value << "  ";
		q = q->next;
	}
	cout << endl;
	


	cout << "common number:    ";
	printcommonIn2List(head1, head2);

	system("pause");
	return 0;
}