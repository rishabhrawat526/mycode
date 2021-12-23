#include<iostream>
using namespace std;
class complex
{
    int a;
    public:
    void* operator new(size_t size)
    {
        cout<<"operator overloaded := "<<size<<endl;
        void* p= malloc(size);
        return p;
    }
    void operator delete(void *p)
    {
        cout<<"delete operator"<<endl;
        free(p);
    }

};

int main()
{
    complex *ptr=new complex();
    delete ptr;
    complex *atr=new complex();
    delete atr;
    return 0;
}