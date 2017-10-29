#include <iostream>

using namespace std;

int main()
{
    int x=1;

    while(x<=100){
        int y = x*x;
        if((y%10)%2 == 1){
            if(((y/10)%10)%2 == 1)
                cout << y << endl;
        }
        x++;
        if(x>100)
            cout<<"There is no such number that exist"<<endl;
    }

    //cout<<"Error, there is no answer"<<endl;

    return 0;
}
