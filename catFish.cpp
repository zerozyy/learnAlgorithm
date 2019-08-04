/**
 * 小猫钓鱼
 * 游戏规则：将一份扑克牌均分为两份,玩家A和B各一份。
 * A先出，B后出。A和B交替出牌。假设牌面只有1-9。
 * 如果某人打出的牌与桌面上某张牌排面相同，可将两张相同的牌及其中间所加的牌全部取走，并依次放到自己手中牌的末尾。
 * 当任一玩家出完自己手中的牌时，游戏结束，另一玩家胜。
 */
/**
 * 算法思想：用两个队列和一个栈表示该游戏
 * 用两个队列分别表示玩家手中的牌。每位玩家有两种操作，分别是出牌和赢牌。出牌对应出队，赢牌对应入队。
 * 桌面上的牌用栈表示，当有人出牌时对应入栈，赢牌对应出栈。
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    stack tablePlate;
    queue APlate,Bplate;
    // 设初始每人有6张牌
    int num;
    cout<<"please input player A's plates:"<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>num;
        APlate.push_back(num);
    }
    cout<<"please input player B's plates:"<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>num;
        BPlate.push_back(num);
    }

    int t = 0;
    int book[10];
    fill(book.begin(),book.end(),0);// fill函数用于数组的赋值、初始化，也可以用memset(数组名，值，sizeof(数组名))
    while(!APlate.empty() && !BPlate.empty()) {// 两位玩家手中的牌都不为空时
        t = APlate.front();     // A出牌
        if(book[t] == 0){       //桌面没有t,A此轮不赢牌
            APlate.pop();
            tablePlate.push_back(t);
            book[t] = 1;        //桌面现在有一张牌面为t的牌了
        }
        else {                  //桌面有t,A此轮赢牌
            while(tablePlate.top()!=t){
                APlate.push_back(tablePlate.top()); // 收牌t与t之间的牌
                book(tablePlate.top())=0;
            }
            APlate.push_back(t); //收t牌
            book[t] = 0;
        }
        if(APlate.empty())      // A的牌完了，游戏结束
            break;

        t = BPlate.front();     // B出牌
        if(book[t] == 0){       //桌面没有t,A此轮不赢牌
            BPlate.pop();
            tablePlate.push_back(t);
            book[t] = 1;        //桌面现在有一张牌面为t的牌了
        }
        else {                  //桌面有t,A此轮赢牌
            while(tablePlate.top()!=t){
                BPlate.push_back(tablePlate.top()); // 收牌t与t之间的牌
                book(tablePlate.top())=0;
            }
            BPlate.push_back(t); //收t牌
            book[t] = 0;
        }
        if(BPlate.empty())      // B的牌完了，游戏结束
            break;
    }

    //判断输赢，输出结果
    if(BPlate.empty())
        cout<<"A win!"<<endl;
    else
    {
        cout<<"B win!"<<endl;
    }
    
}