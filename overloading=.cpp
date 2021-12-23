#include<iostream>
using namespace std;
class complex
{
    int a;
    int b;
    public:
    complex(int c=0,int d=0)
    {
        a=c;
        b=d;
    }
       void print()
    {
        cout<<"value of a :"<<a<<endl;
        cout<<"value of b :"<<b<<endl;
    }
    void operator=(complex &obj)
    {
        a=obj.a;
        b=obj.b;
    }
};

int main()
{
    complex obj1(10,2);
    complex obj2;
    obj2=obj1;
    obj2.print();
    return 0;
}