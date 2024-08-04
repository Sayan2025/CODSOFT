#include<iostream>
#include<cstdlib>

using namespace std;

int main(){

    srand(time(0));
    int rand_num = rand() % 100 + 1;
    int guess_num = 0;
    int count = 0;
    cout<<"This is a Number Guessing game"<<endl;
    cout<<"Can you guess the number"<<endl;
    while(true){
            if (count == 5){
                cout << "You Lost unable to guess correct in 5 attemps"<<endl;
                cout << "Actual number was " << rand_num<<endl;
            }
            cout<<"Enter the number : ";
            cin>>guess_num;
            count++;
            if(guess_num<rand_num)
            {
                cout<<"The number is too low"<<endl;
            }
            else if(guess_num>rand_num)
            {
                cout<<"The number is too high"<<endl;;
            }
            else{
                cout<<"guessed correct in " << count << " attempts";
                break;
            }
    }
    return 0;
}