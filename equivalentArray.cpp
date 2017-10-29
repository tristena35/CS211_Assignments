#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n) {

    int x = 0;

    while(x < n){//Loop to go through the array every time the previous b[whatever] has been tested.
        int count = 0;

        for(int y = 0; y < n; y++){ //Loop to go through the array and test every element in array B to array A.

            if(a[y%n] == b[(x+y)%n]) //Array A stays the same while array B is constantly changing its starting position.
                count ++;

        }
        if(count == n) //This makes sure that at the end of all checks, there were the same amount of shift equivalents as elements in the array.
            return true;

        x++;
    }

    return false;

}

int main() {
   cout << boolalpha; // to print bool values as true/false instead of 1/0

   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true

   int b1[3] = {1, 2, 3};
   int b2[3] = {2, 3, 3};
   cout << equivalent(b1, b2, 3) << endl; // false

   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};
   cout << equivalent(c1, c2, 4) << endl; // false

   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};
   cout << equivalent(d1, d2, 4) << endl; // true

   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};
   cout << equivalent(e1, e2, 5) << endl; // true

   return 0;
}
