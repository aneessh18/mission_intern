#include <bits/stdc++.h>
using namespace std;
int x;
void variable_scope()
{
    int x=10;
    cout<<::x<<endl;
    cout<<x<<endl;
}
class Buffer{
    // all varibles and methods are private by default
    //declare a function here and define anywhere
    static int x;
    public: 
    static int y;
    void func();
    void setXY(int x, int y)
    {
        Buffer ::x = x;
        Buffer ::y = y;
        printf("came here");
    }
};
void Buffer:: func()
{
    cout<<":: is awesome"<<endl;
} 
int Buffer::y = 10;
int Buffer::x = 20;
// static variables and objects have lifetime as long as the program
// static variables in class are shared across the object instances
// static methods in class are also shared by object instanced and should be invoked by scope resolution operator
int main()
{
   Buffer buf;
   buf.func();
    // buf.setXY(1,0);
    cout<<Buffer::y<<endl;
}