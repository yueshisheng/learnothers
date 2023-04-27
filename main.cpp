#include <iostream>
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

    return 0;
}
