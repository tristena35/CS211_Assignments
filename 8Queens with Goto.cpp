#include <iostream>
using namespace std;

int main() {

   int b[8]{0}, r = 0, c = 0;

nextCol:

   c++; //Goes to next column

   if (c > 7) //Checks if all columns have been checked.
      goto print;

   r = -1; //Sets row one spot above the board so that when we go to the next line, it sets it to 0

nextRow:
   r++; //Goes down next row
   b[c] = r; //Setting the value in the array equal to row

   if(r > 7) //Checks if all rows have been checked.
      goto backtrack;

   for(int i = 1; i < c+1; i++){ //Checks if there is a queens to the left
      if(b[c-i] == r) //b[c-i] represents the spot on the board of one column to the left, and you are checking that with the specific row.
         goto nextRow;
	}

   for (int i = 1; i < 8; i++){
      if((c-i) < 0 || (b[c]-i) < 0) //Checks if it is out of bounds either up or left. First Condition checks left side, Second Condition covers if Row - i is less than 0
         break;
      if(b[c-i] == b[c]-i) //If the previous column is equal to the previous row.
         goto nextRow; //b[c] alone is equal to the column
   }

   for (int i = 1; i<8; i++){
  	  if((c-i) < 0 || (b[c]+i) > 7) //First Condition checks if it goes of the board left, and Second Condition checks if it goes of the board down
         break;
	  if(b[c-i] == b[c]+i) //if the previous column value is equal to the row increased by one.
         goto nextRow;
   }

   goto nextCol;

backtrack:
   c--; //Going back a column.

   if(c < 0)
      return 0; //If all possibilities have been checked, return.

   r = b[c]; //Setting the row number with the queen in it equal to a 0;

   goto nextRow;

print:

   static int numSolutions = 0;

   cout << "Solution #" << ++numSolutions << ":\n";

   for(int i = 0; i < 8; i++)
       cout << b[i];

   cout << endl;

   goto backtrack;
}
