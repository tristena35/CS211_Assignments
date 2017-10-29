#include <iostream>

using namespace std;

int main()
{
     // Initialize the board to 0
   int q[8][8] = {};

   // Start in the 1st row, 1st column, and place a queen there
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   c++; // Move to the next column

   if (c > 7)//IF you have passed the last column
      goto print;

   // Move to one before the first row
   r = -1;

nextRow:
   // Move to the next row
   r++;

   if (r > 7) //you have passed the end of the column
      goto backtrack;

   // If there is a queen in the same row (to the left), goto nextRow
   for(int i = 1;i <= c; i ++){ //each square to the left of the current square
      if (q[r][c-i]==1)//ere is a queen on that square
         goto nextRow;
   }
   // If there is a queen in the upper-left diagonal, goto nextRow
   for (int i = 1; i < 8; i++){// End the loop when you are above or left of the chessboard
      if((r-i) < 0 || (c-i) < 0) break;
      if (q[r-i][c-i] == 1) //there is a queen i spots above and left of the current square
         goto nextRow;
   }

   // If there is a queen in the lower-left diagonal, goto nextRow
   for (int i = 1; i < 8; i++){// End the loop when you are below or left of the chessboard
      if((r+i) > 7 || (c-i) <0) break;
      if (q[r+i][c-i] == 1) //there is a queen i spots below and left of the current square
         goto nextRow;
   }

   q[r][c] = 1;// Place a queen in the current square (2D version only)

   goto nextCol;

backtrack:
   // Move to the previous column
   c--;

   if (c < 0)
        return 0;//you have moved to the left of the chessboard exit the program

   for(int i = 0; i < 8; i++){
        if(q[i][c] == 1){
            r = i; // Find the square in the column with a queen in it and set r to the row number of that square
            break;
        }
   }

    q[r][c] = 0;

   // Remove the queen from the current square

   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";

   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << q[i][j];
        }
        cout << endl;
   }
   cout<<endl;
   // Use a nested loop to print the chessboard
   goto backtrack;

   return 0;
}
