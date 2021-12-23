#include<iostream>
using namespace std;
class xyz
{
    public:
    int a=5;

    void friend operator ++(xyz &obj,int);
   
    void show()
    {
        cout<<a<<endl;
    }
};
void operator ++(xyz &obj,int)
    {
        obj.a=obj.a+1;
    }
int main()
{
    xyz obj1;
    obj1++;
    
    obj1.show();
    return 0;
}