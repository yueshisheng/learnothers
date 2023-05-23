#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory>

//模板可变参数
using namespace std;
template<typename   ...T>
auto sum(T ... t){
    return ( t +... );//必须加个括号

}
//虚基类在菱形继承中，只保留一个基类
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
    void show(){
        cout<<"class c"<<endl;
    }
    ~C(){

    }
};

class F
{
public:
    int a;
};

class S : public F
{
public:
    int b;
};





int main() {

    //指针数组，先与[]结合，再和*结合
    //二维数组是连续存放
    char* str[3]={"yue","shi","sheng"};
    //str作为指针数组的首地址，其实相当于该数组的一个指针，所以可以赋值给指针的指针
    char** str2=str;
    cout<<"二维数组访问 = "<<**(str2+2)<<endl;
    cout<<"二维数组："<<*(str2+1)<<endl;
    cout<<"二维数组："<<str[2]<<endl;
    int num1[2]={100,101};
    int num2[2]={200,202};
    int* numptr[2]={num1,num2};
    int** twoptr=numptr;
    cout<<"整数："<<*(twoptr+1)<<endl;
    cout<<"整数："<<*twoptr[1]<<endl;
    cout<<"整数："<<numptr[1]<<endl;
    cout<<"整数："<<*numptr[1]<<endl;





    cout<<"int的大小"<<sizeof(-1)<<endl;


    //lamada表达式
    int tep=12;
    auto f=[tep](int a,int b){return a-b+tep;};
    cout<<f(2,4)<<endl;









    F *father = new F;
    S *son = new S;

    // 父类转子类（不安全）
    //son = father;					// 隐式转换失败
    son = static_cast<S *>(father); // 转换成功，但是没有提供运行时检查，依然不安全

    // 子类转父类（安全）
    father = son;					// 成功
    father = static_cast<F *>(son); // 成功



//    //高风险的类型转换，无法通过编译
//    //1、不同指针类型进行转换
//    int* intptr;
//    char* charptr=static_cast<char *>(intptr);
//    //2、整型和指针无法转换
//    int i2=static_cast<int>(intptr);








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

    memmove(newdest,src,100);
    cout<<newdest<<endl;


    //malloc和free函数使用
    int* p;
    p= (int*)malloc(sizeof(int));
    int num=100;
    p=&num;
    cout<<*p<<endl;
    free(p);//释放的是内存空间，指针依然存在
    p= nullptr;


    //new
    //void *memset(void *str, int c, size_t n)
    //复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
    //memset一次只能赋值一个字节，1的是四个字节。只有0和-1是一个字节
    int* p2=new int[5]{1000};
    cout<<p2[1]<<endl;
    cout<<&p2[0]<<endl;
    cout<<&p2[1]<<endl;//刚好差4，连续分配内存
    delete[] p2;


    int p3[20];
    memset(p3, 1,20);
    //在int数组中，一个个体就是int，4个字节，每一个字节都为1，则一个int为16843009
    cout<<"p3:"<<p3[4]<<endl;



    //weakptr指针不控制生命周期，协助shardptr工作，没有重写 operator-> 和 operator* 方法，
    // 因此不能像 std::shared_ptr 或 std::unique_ptr 一样直接操作对象
    //通过expired()判断引用的对象是否被销毁

    shared_ptr<int> shared = make_shared<int>(1000);
    weak_ptr<int> weak(shared);

    cout << shared.use_count() << endl;
    shared.reset(new int(100000));






    if(weak.expired()==true){
        cout<<"过期了"<<endl;
    }else{
        cout<<"还未过期"<<endl;
    }



    //allocator
    //先分配内存，然后在其上装载对象
    std::allocator<C> alloc;
    auto cptr = alloc.allocate(1); // 分配一个C对象的内存
    alloc.construct(cptr);   // 调用C的构造函数，如果构造函数有参数，参数写在cptr之后
    // cptr 现在是一个指向C的指针，且其指向对象被初始化过
    // 对cptr进行一些操作
    cptr->show();
    // 销毁对象，但不释放内存，等同于调用销毁函数
    alloc.destroy(cptr);
    // 释放内存
    alloc.deallocate(cptr, 1);








    return 0;
}
