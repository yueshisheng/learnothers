#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory>

//ģ��ɱ����
using namespace std;
template<typename   ...T>
auto sum(T ... t){
    return ( t +... );//����Ӹ�����

}
//����������μ̳��У�ֻ����һ������
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

    //ָ�����飬����[]��ϣ��ٺ�*���
    //��ά�������������
    char* str[3]={"yue","shi","sheng"};
    //str��Ϊָ��������׵�ַ����ʵ�൱�ڸ������һ��ָ�룬���Կ��Ը�ֵ��ָ���ָ��
    char** str2=str;
    cout<<"��ά������� = "<<**(str2+2)<<endl;
    cout<<"��ά���飺"<<*(str2+1)<<endl;
    cout<<"��ά���飺"<<str[2]<<endl;
    int num1[2]={100,101};
    int num2[2]={200,202};
    int* numptr[2]={num1,num2};
    int** twoptr=numptr;
    cout<<"������"<<*(twoptr+1)<<endl;
    cout<<"������"<<*twoptr[1]<<endl;
    cout<<"������"<<numptr[1]<<endl;
    cout<<"������"<<*numptr[1]<<endl;





    cout<<"int�Ĵ�С"<<sizeof(-1)<<endl;


    //lamada���ʽ
    int tep=12;
    auto f=[tep](int a,int b){return a-b+tep;};
    cout<<f(2,4)<<endl;









    F *father = new F;
    S *son = new S;

    // ����ת���ࣨ����ȫ��
    //son = father;					// ��ʽת��ʧ��
    son = static_cast<S *>(father); // ת���ɹ�������û���ṩ����ʱ��飬��Ȼ����ȫ

    // ����ת���ࣨ��ȫ��
    father = son;					// �ɹ�
    father = static_cast<F *>(son); // �ɹ�



//    //�߷��յ�����ת�����޷�ͨ������
//    //1����ָͬ�����ͽ���ת��
//    int* intptr;
//    char* charptr=static_cast<char *>(intptr);
//    //2�����ͺ�ָ���޷�ת��
//    int i2=static_cast<int>(intptr);








    std::cout << sum(1,2,3,4,5,6)<< std::endl;
    C c;
    cout<<c.c_data<<endl;
    cout<<c.data<<endl;//�������������

    //strcpy()����,������\n����
    char* src="yueshi\0sheng";
    char dest[20];
    strcpy(dest,src);
    cout<<dest<<endl;

    //memcpy()������ָ����Сcopy,����\0Ҳ�����
    char newdest[20];
    memcpy(newdest,src,100);
    cout<<newdest<<endl;

    memmove(newdest,src,100);
    cout<<newdest<<endl;


    //malloc��free����ʹ��
    int* p;
    p= (int*)malloc(sizeof(int));
    int num=100;
    p=&num;
    cout<<*p<<endl;
    free(p);//�ͷŵ����ڴ�ռ䣬ָ����Ȼ����
    p= nullptr;


    //new
    //void *memset(void *str, int c, size_t n)
    //�����ַ� c��һ���޷����ַ��������� str ��ָ����ַ�����ǰ n ���ַ�
    //memsetһ��ֻ�ܸ�ֵһ���ֽڣ�1�����ĸ��ֽڡ�ֻ��0��-1��һ���ֽ�
    int* p2=new int[5]{1000};
    cout<<p2[1]<<endl;
    cout<<&p2[0]<<endl;
    cout<<&p2[1]<<endl;//�պò�4�����������ڴ�
    delete[] p2;


    int p3[20];
    memset(p3, 1,20);
    //��int�����У�һ���������int��4���ֽڣ�ÿһ���ֽڶ�Ϊ1����һ��intΪ16843009
    cout<<"p3:"<<p3[4]<<endl;



    //weakptrָ�벻�����������ڣ�Э��shardptr������û����д operator-> �� operator* ������
    // ��˲����� std::shared_ptr �� std::unique_ptr һ��ֱ�Ӳ�������
    //ͨ��expired()�ж����õĶ����Ƿ�����

    shared_ptr<int> shared = make_shared<int>(1000);
    weak_ptr<int> weak(shared);

    cout << shared.use_count() << endl;
    shared.reset(new int(100000));






    if(weak.expired()==true){
        cout<<"������"<<endl;
    }else{
        cout<<"��δ����"<<endl;
    }



    //allocator
    //�ȷ����ڴ棬Ȼ��������װ�ض���
    std::allocator<C> alloc;
    auto cptr = alloc.allocate(1); // ����һ��C������ڴ�
    alloc.construct(cptr);   // ����C�Ĺ��캯����������캯���в���������д��cptr֮��
    // cptr ������һ��ָ��C��ָ�룬����ָ����󱻳�ʼ����
    // ��cptr����һЩ����
    cptr->show();
    // ���ٶ��󣬵����ͷ��ڴ棬��ͬ�ڵ������ٺ���
    alloc.destroy(cptr);
    // �ͷ��ڴ�
    alloc.deallocate(cptr, 1);








    return 0;
}
