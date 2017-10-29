#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    static int mp[3][3] = { {0,2,1},  // Man#0's preferences
                            {0,2,1},  // Man#1's preferences
                            {1,2,0}
                          }; // Man#2's preferences

    static int wp[3][3] = { {2,1,0},  // Woman#0's preferences
                            {0,1,2},  // Woman#1's preferences
                            {2,0,1}
                          }; // Woman#2's preferences

    for(int i = 0; i < c; i++){ //Checks if woman i has already been assigned to a man.
        if(q[i] == q[c])
            return false;
    }

    for(int i = 0; i < c; i++){
        if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) //Checks if Man i like Woman c more than Man i likes woman i.
            return false;
    }

    for(int i = 0; i < c; i++){
        if(wp[q[i]][c] < wp[q[i]][i] && mp[c][q[i]] < mp[c][q[c]])
            return false;
    }

return true;
}

void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

void next(int q[], int c) {
   if (c == 3)
      print(q);
   else for (q[c] = 0; q[c] < 3; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[3];
   next(q, 0);
   return 0;
}
