#include <iostream>
#include <cmath>
using namespace std;


 /*This works too
bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.

   for(int i = 0;i < c; i ++){ //each i from 0 to c-1
      if(q[c] == q[i] || abs(q[c]-q[i]) == c-i) //there is a conflict between the queens in columns i and c
         return false;
   }
   return true;
}
*/

bool ok(int q[], int c) {
   for(int i = 1;i <= c; i ++){ //each i from 0 to c-1
      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+i) //there is a conflict between the queens in columns i and c
         return false;
   }
   return true;
}


// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n and initialize the first element to 0.
   int* q = new int[n];
   q[0] = 0;
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   // Start in the 1st row, 1st column
   int r = 0, c = 0, solutions = 0;

   while (c >= 0){
      //if(c < 0)
        // break;             // End the loop if you backtrack from the first column
      c++;                    // Move to the next column
      if(c > n){              // If you have passed the last column,
         solutions ++;            // Call the print function and backtrack
         c--;
         r = q[c];           // Otherwise, move to one before the first row
      }
      else
         r = -1;

      while (c >= 0) {
         r++;
         q[c] = r;                       // Move to the next row

         if(r > n){
            c --;
            r = q[c];        // If you have passed the end of the column, backtrack
         }

         else if(ok(q,c)){   //Why does this have to be else if? <----
            break;
         }
      }
   }
   // Delete the array.
        delete [] q;
   // Return the number of solutions.
        return solutions;
}

int main() {
   int n = 12;
   for (int i = 0; i < n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i+1 << " queens problem.\n";
   return 0;
}
