#include <iostream>
using namespace std;
class complex
{
int x; //real
int y; //imag
public :
complex()//constructor
{
x=0;
y=0;
}
friend istream &operator >>(istream &i ,complex &a)
{
    cout<<"Enter real part";
    i>>a.x;
    cout<<"Enter Imaginary part";
    i>>a.y;  
}
friend ostream &operator <<(ostream &o ,complex &a)
{
o<<a.x<<"+"<<a.y<<"i\n";

}

complex operator +(complex a)
{
    complex add;
    add.x=x+a.x;
    
    add.y=y+a.y;
    return add; 
}
complex operator *(complex a)
{
    complex mult;
    mult.x=(x*a.x)-(y*a.x);
    mult.y=(y*a.y)+(x*a.y);
    return mult;
}
};
int main()
{
complex c1,c2,c3,c4;//obj
cout<<"DEfault constructor : "<<c1;
cout<<"Enter 1st complex number :";
cin>>c1;
cout<<"Enter 2nd complex number :";
cin>>c2;
c3=c1+c2;
c4=c1*c2;
cout<<c3;
cout<<c4;
return 0;
}
