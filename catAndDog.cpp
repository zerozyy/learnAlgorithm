/**猫狗队列：
 * 建立一个队列实现以下方法：
 *      add-->向队列中添加cat或dog
 *      isEmpty()   队列中是否还有cat or dog
 *      isDogEmpty() 队列中是否还有dog
 *      isCatEmpty() 队列中是否还有cat
 *      pollAll()    队首cat or dog（按照入队先后顺序）出队
 *      pollDog()    队列中第一个dog出队
 *      pollCat()    队列中第一个cat出队
 */


#include <iostream>
#include <queue>
#include <algorithm>
#include <string> // basic_string的输入输出操作在<string>里，而不是<iostream>
				  // 所以cout输出string类型变量需包含此头文件,直接cout<<"  xxs"这种不用

using namespace std;

class Pet{
public:
	Pet(){

	}
	Pet(string type){
		this->type = type;
	}
	string getType(){
		return this->type;
	}
private:
	string type;
};


class Cat:public Pet{
public:
	Cat():Pet("cat"){ // 初始化形参列表

	}
};


class Dog :public Pet{
public:
	Dog() :Pet("dog"){ // 初始化形参列表
		//cout << "create dog" << endl;
	}
};


// 不宜改变已定义的类的结构，所以重新定义一个类作为入队的结构
class PetEnterQueue{
private :
	Pet pet;
	
public:
	int index;
	PetEnterQueue(){

	}
	PetEnterQueue(Pet pet, int index){
		this->pet = pet;
		this->index = index;
	}
	Pet getPet(){
		return this->pet;
	}
	int getIndex(){
		return this->index;
	}
};


class CatAndDogQue{
private:
	queue<PetEnterQueue> catQue;
	queue<PetEnterQueue> dogQue;
	int index;

public:
	CatAndDogQue(){
		this->index = 0;
	}

	void add(Pet pet){
		if (pet.getType() == "cat"){
			PetEnterQueue peq = PetEnterQueue(pet, index);
			catQue.push(peq);
			this->index++;
		}
		else if (pet.getType() == "dog"){
			//cout << "get a dog" << endl;
			PetEnterQueue peq = PetEnterQueue(pet, index);
			dogQue.push(peq);
			this->index++;
		}
		else{
			cerr << "is not a dog or a cat.";
		}
	}

	Pet pollAll(){
		Pet res;
		if (this->isEmpty()){
			cerr << "your queue is empty";
			return NULL;
		}
		else if (this->isDogEmpty()){ // dog空  cat队列非空
			res = catQue.front().getPet();
			catQue.pop();
		}
		else if (this->isCatEmpty()){// cat空  dog队列非空
			res = dogQue.front().getPet();
			dogQue.pop();
		}
		else{						 //  cat    dog都非空
			if (catQue.front().getIndex() < dogQue.front().getIndex()){  //index小的先出队
				res = catQue.front().getPet();
				catQue.pop();
			}
			else{
				res = dogQue.front().getPet();
				dogQue.pop();
			}
		}
		return res;
	}

	Pet pollCat(){
		if (catQue.empty()){
			cerr << "no cat in queue" << endl;
			return NULL;
		}
		Pet res;
		while (!catQue.empty()){
			res = catQue.front().getPet();
			catQue.pop();
		}
		return res;
	}

	Pet pollDog(){
		if (dogQue.empty()){
			cerr << "no dog in queue" << endl;
			return NULL;
		}
		Pet res;
		while (!dogQue.empty()){
			res = dogQue.front().getPet();
			dogQue.pop();
		}
		return res;
	}

	bool isEmpty(){
		return catQue.empty() && dogQue.empty();
	}

	bool isDogEmpty(){
		return dogQue.empty();
	}

	bool isCatEmpty(){
		return catQue.empty();
	}

	~CatAndDogQue(){

	}
};
int main()
{
	Cat cat;
	Dog dog;
	CatAndDogQue cdq;
	for (int i = 0; i < 20; i++){
		if (i % 3 == 0){
			cdq.add(cat);
			cout << cat.getType() << "  added" << endl;
		}
		else{
			cdq.add(dog);
			cout << dog.getType() << "  added" << endl;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout << cdq.pollAll().getType()<<"  poll   "<<endl;

	}
	cdq.add(dog);
	cout << cdq.pollDog().getType() << "  poll   " << endl;
	system("pause");
	return 0;
}