#include<vector>
using namespace std;
        vector<int> a ;                                //声明一个int型向量a
        vector<int> a(10) ;                            //声明一个初始大小为10的向量
        vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
        vector<int> b(a) ;                             //声明并用向量a初始化向量b
        vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
        //全部输出
        vector<int>::iterator t;
        for(t=a.begin();t!=a.end();t++)
            printf("%d",*t);
        //基本操作
        a.size();
        a.empty();
        a.clear();
        a=b;
        a==b;
        a.erase(b.begin(),b.begin()+3);
        //二维向量
        vector< vector<int> > b(10, vector<int>(5));        //创建一个10*5的int型二维向量
        c.pop_back()       // 删除最后一个数据
        c.push_back(elem)  // 在尾部加入一个数据
        c.rbegin()         // 传回一个逆向队列的第一个数据。
        c.rend()           // 传回一个逆向队列的最后一个数据的下一个位置。
        c.at()//获得指定位置的元素