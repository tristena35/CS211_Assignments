#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   static int adj[8][5] = {
   {-1},                 // 0
   {0, -1},              // 1
   {0, 1, -1},           // 2
   {0, 2, -1},           // 3     <-- neighbor list for square 3
   {1, 2, -1},           // 4
   {1, 2, 3, 4, -1},     // 5
   {2, 3, 5, -1},        // 6
   {4, 5, 6, -1}         // 7
    };

   for(int i = 0; i < c;i++){
        if(q[c] == q[i])//If the number you are writing in square c has already been used, return false.
            return false;
   }

   for(int i = 0;adj[c][i]!=-1;i++){ //For each neighbor of square c,
      if(q[adj[c][i]]+1 == q[c] || q[adj[c][i]]-1 == q[c])
        return false;
   }

   return true;
}

void print(int q[]) {
   static int solutions = 1; //Initialized once and only once.

   cout << "Solutions #" << solutions << ":" << endl;
   cout << " " << " " << q[1] << q[4] << endl;
   cout << " " << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " " << " " << q[3] << q[6] << endl;

   cout << endl;
   solutions++;
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}