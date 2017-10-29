#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for(int i = 1;i <= c; i ++){ //each i from 0 to c-1
      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+i) //there is a conflict between the queens in columns i and c
         return false;
   }
   return true;
}
void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   // Print the array
   for(int i = 0; i < 8; i++)
      cout << q[i];

   cout << "\n";
}

int main() {
   int q[8]={0};   // Initialize the array to 0.

   // Start in the 1st row, 1st column
   int r = 0, c = 0;

   while (c >= 0){
      //if(c < 0)
        // break;             // End the loop if you backtrack from the first column
      c++;                    // Move to the next column
      if(c > 7){              // If you have passed the last column,
         print(q);            // Call the print function and backtrack
         c--;
         r = q[c];           // Otherwise, move to one before the first row
      }
      else
         r = -1;

      while (c >= 0) {
         r++;
         q[c] = r;                       // Move to the next row

         if(r > 7){
            c --;
            r = q[c];        // If you have passed the end of the column, backtrack
         }

         else if(ok(q,c)){   //Why does this have to be else if? <----
            break;
         }                  // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.

      }
   }
   return 0;
}
