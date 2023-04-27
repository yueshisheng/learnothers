#include <iostream>
#include <stdio.h>
#include <string.h>

//模板可变参数
using namespace std;
template<typename   ...T>
auto sum(T ... t){
    return (t+ ... );//必须加个括号

}
class N{
    public:
        int data=100;
};

class A:virtual public N{

};
class B:virtual public N{

};
class C: public A,public B{
public:
    int c_data=10000;
};




int main() {
    std::cout << sum(1,2,3,4,5,6)<< std::endl;
    C c;
    cout<<c.c_data<<endl;
    cout<<c.data<<endl;//返回虚基类数据

    //strcpy()函数,会遇到\n结束
    char* src="yueshi\0sheng";
    char dest[20];
    strcpy(dest,src);
    cout<<dest<<endl;

    //memcpy()函数按指定大小copy,遇到\0也会结束
    char newdest[20];
    memcpy(newdest,src,100);
    cout<<newdest<<endl;

    





    return 0;
}
