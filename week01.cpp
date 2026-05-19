#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Store basketball answers
    string favoritePlayer;
    string favoriteTeam;
    int hoursPlayedPerWeek;

    // Ask for user input
    cout << "What is your favorite basketball player? ";
    getline(cin, favoritePlayer);

    cout << "What is your favorite basketball team? ";
    getline(cin, favoriteTeam);

    cout << "How many hours do you play basketball each week? ";
    cin >> hoursPlayedPerWeek;

    // Calculate yearly basketball hours
    int yearlyHours = hoursPlayedPerWeek * 52;

    // Display results
    cout << "\n----- Basketball Profile -----\n";
    cout << "Your favorite player is " << favoritePlayer
         << " and your favorite team is " << favoriteTeam << ". "
         << "You play basketball for about "
         << hoursPlayedPerWeek << " hours each week, which equals approximately "
         << yearlyHours << " hours per year!" << endl;

    cout << "Keep practicing and dominating on the court!" << endl;

    return 0;
}