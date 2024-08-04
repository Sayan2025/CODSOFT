#include<iostream>
using namespace std;
int main()
{
    double num1,num2,result;
    char op;
    cout<<"Enter the first Number : ";
    cin>>num1;
    cout<<"Enter the Second Number : ";
    cin>>num2;
    cout<<"Enter + for addition"<<endl;
    cout<<"Enter - for subtraction"<<endl;
    cout<<"Enter * for addition"<<endl;
    cout<<"Enter / for addition"<<endl;
    cin>>op;
    switch(op)
    {
        case '+':
        result=num1+num2;
        cout<<result;
        break;
        case '-':
        result=num1-num2;
        cout<<result;
        break;
        case '*':
        result=num1*num2;
        cout<<result;
        break;
        case '/':
        if(num2==0)
        {
            cout<<"A number cannot be divisible by 0..."<<endl;

        }
        else{
            result=num1/num2;
            cout<<result;
        }
        break;
        default:
        cout<<"Invalid Opeation"<<endl;
    }
    return 0;

}