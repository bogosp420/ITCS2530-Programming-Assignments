#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string playerName;
    string teamName;
    int gamesPlayed;
    int totalPoints;
    double minutesPlayed;

    cout << "=========================================\n";
    cout << "     Welcome to the Basketball Tracker\n";
    cout << "=========================================\n\n";

    cout << "Enter player name: ";
    getline(cin, playerName);

    cout << "Enter team name: ";
    getline(cin, teamName);

    cout << "Enter games played: ";
    cin >> gamesPlayed;

    if (cin.fail() || gamesPlayed <= 0)
    {
        cout << "Invalid input. Games played must be a positive number.\n";
        return 1;
    }

    cout << "Enter total points scored: ";
    cin >> totalPoints;

    if (cin.fail() || totalPoints < 0)
    {
        cout << "Invalid input. Total points cannot be negative.\n";
        return 1;
    }

    cout << "Enter total minutes played: ";
    cin >> minutesPlayed;

    if (cin.fail() || minutesPlayed <= 0)
    {
        cout << "Invalid input. Minutes played must be positive.\n";
        return 1;
    }

    double pointsPerGame = static_cast<double>(totalPoints) / gamesPlayed;
    double pointsPerMinute = totalPoints / minutesPlayed;

    cout << fixed << setprecision(2);

    cout << "\n=========================================\n";
    cout << "          Basketball Summary Report\n";
    cout << "=========================================\n";

    cout << left << setw(25) << "Player Name:" << playerName << endl;
    cout << left << setw(25) << "Team Name:" << teamName << endl;
    cout << left << setw(25) << "Games Played:" << gamesPlayed << endl;
    cout << left << setw(25) << "Total Points:" << totalPoints << endl;
    cout << left << setw(25) << "Minutes Played:" << minutesPlayed << endl;
    cout << left << setw(25) << "Points Per Game:" << pointsPerGame << endl;
    cout << left << setw(25) << "Points Per Minute:" << pointsPerMinute << endl;

    ofstream reportFile;
    reportFile.open("report.txt");

    reportFile << fixed << setprecision(2);

    reportFile << "=========================================\n";
    reportFile << "          Basketball Summary Report\n";
    reportFile << "=========================================\n";

    reportFile << left << setw(25) << "Player Name:" << playerName << endl;
    reportFile << left << setw(25) << "Team Name:" << teamName << endl;
    reportFile << left << setw(25) << "Games Played:" << gamesPlayed << endl;
    reportFile << left << setw(25) << "Total Points:" << totalPoints << endl;
    reportFile << left << setw(25) << "Minutes Played:" << minutesPlayed << endl;
    reportFile << left << setw(25) << "Points Per Game:" << pointsPerGame << endl;
    reportFile << left << setw(25) << "Points Per Minute:" << pointsPerMinute << endl;

    reportFile.close();

    cout << "\nReport saved to report.txt\n";

    return 0;
}