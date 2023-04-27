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


    //malloc和free函数使用
    int* p;
    p= (int*)malloc(sizeof(int));
    int num=100;
    p=&num;
    cout<<*p<<endl;
    free(p);//释放的是内存空间，指针依然存在


    //new
    //void *memset(void *str, int c, size_t n)
    //复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
    //memset一次只能赋值一个字节，1的是四个字节。只有0和-1是一个字节
    int* p2=new int[5]{1000};
    cout<<p2[1]<<endl;
    delete[] p2;


    int p3[20];
    memset(p3, -1,20);
    cout<<p3[0]<<endl;








    return 0;
}
