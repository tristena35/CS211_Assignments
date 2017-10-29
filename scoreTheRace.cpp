#include <iostream>
using namespace std;

int main() {
   while (true) {

      check:

      string outcome;
      cout << "Enter the race outcome: ";
      cin >> outcome;
      // If the user entered "done", exit the program
      if(outcome == "done") return 0;


      int numTeams = 0;       // The number of teams
      int scores['Z'+1] = {}; // scores[i] keeps track of the total score of team i
      int counts['Z'+1] = {}; // counts[i] keeps track of the number of runners on team i

      for (int i = 0; i < outcome.length(); ++i) { // For each runner in the race,
            if(scores[outcome[i]] == 0){
                numTeams++;
            }
            scores[outcome[i]] = i + 1 + scores[outcome[i]];
            counts[outcome[i]] ++;
         // Increase the team's score by the runner's rank (the rank is 1 more than the index)
         // If it's the first runner of that particular team, update the total number of teams
         // Update the number of runners on the team
      }


      for(int i = 0; i < ('Z' + 1); i++){
            if(counts[i]!= 0 && (counts[outcome[0]] != counts[i])){
                cout << "The teams are not equal, please re-enter your values." << endl;
                goto check;
            }
      // If the teams do not all have the same number of runners,
      // Print an error message and ask for input again (go back to the beginning of the loop)
      }

      cout << "There are " << numTeams << " teams." << endl;
      // Print the number of teams

      cout << "There are " << counts[outcome[0]] << " runners on each team." << endl;
      // Print the number of runners on each team

      double avg = (scores[outcome[0]])/(counts[outcome[0]] * 1.0);
      char win = outcome[0];
      for(int i = 'A'; i < ('Z' + 1); i++){
            if(scores[i]!=0){
                cout << "Average for team " << (char)(i) << " is: " << scores[i]/(counts[i] * 1.0) << endl;
                if(avg > (scores[i])/(counts[i] * 1.0)){
                    avg = (scores[i])/(counts[i] * 1.0);
                    win = i;
                }
            }
      }
      // For each letter from A-Z,
         // If that team participated,
            // Print the name of the team and its average score
            // Also keep track of which team(s) has the best score

            cout << "The winning team is '" << win << "' with a score of " << avg << endl;
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)

      cout << endl;
   }
   return 0;
}
