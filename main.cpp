#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Function prototypes
void changeConsoleColor();
void displayBanner();
void displayMenu();
string getPlayerName();
int getValidInt(string prompt, int minValue);
double getValidDouble(string prompt, double minValue);
void addPracticeSessions(int &totalShots, int &totalMakes, double &practiceHours);
double calculateShootingPercent(int totalMakes, int totalShots);
void viewWeeklyReport(string playerName, int totalShots, int totalMakes);
void recommendLevel(int totalShots, int totalMakes, double practiceHours);
int findhighestshots(const int shots[], int size);

int main()
{
    string playerName;
    int menuChoice;
    int totalShots = 0;
    int totalMakes = 0;
    double practiceHours = 0.0;

    changeConsoleColor();
    displayBanner();

    playerName = getPlayerName();

    do
    {
        displayMenu();
        cin >> menuChoice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid. Enter a number from 1 to 4: ";
            cin >> menuChoice;
        }

        switch (menuChoice)
        {
        case 1:
            addPracticeSessions(totalShots, totalMakes, practiceHours);
            break;

        case 2:
            viewWeeklyReport(playerName, totalShots, totalMakes);
            break;

        case 3:
            recommendLevel(totalShots, totalMakes, practiceHours);
            break;

        case 4:
            cout << "\nThank you for using the Basketball Practice Tracker!\n";
            break;

        default:
            cout << "\nInvalid menu choice. Try again.\n";
        }

    } while (menuChoice != 4);

    return 0;
}

void changeConsoleColor()
{
    cout << "\033[36m";
}

void displayBanner()
{
    cout << "=====================================\n";
    cout << "     Basketball Practice Tracker\n";
    cout << "=====================================\n\n";
}

void displayMenu()
{
    cout << "\nMenu\n";
    cout << "1. Add practice sessions\n";
    cout << "2. View weekly report\n";
    cout << "3. Recommend level\n";
    cout << "4. Quit\n";
    cout << "Enter choice: ";
}

string getPlayerName()
{
    string playerName;

    cout << "Enter player name: ";
    getline(cin, playerName);

    while (playerName == "")
    {
        cout << "Invalid. Player name cannot be empty: ";
        getline(cin, playerName);
    }

    return playerName;
}

int getValidInt(string prompt, int minValue)
{
    int value;

    cout << prompt;
    cin >> value;

    while (cin.fail() || value < minValue)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter a number greater than or equal to "
             << minValue << ": ";
        cin >> value;
    }

    return value;
}

double getValidDouble(string prompt, double minValue)
{
    double value;

    cout << prompt;
    cin >> value;

    while (cin.fail() || value < minValue)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter a number greater than or equal to "
             << minValue << ": ";
        cin >> value;
    }

    return value;
}

void addPracticeSessions(int& totalShots, int& totalMakes, double& practiceHours)
{
    int sessions;
    const int max_sessions = 7;

    sessions = getValidInt("\nHow many practice sessions did you complete this week? ", 1);

    while (sessions > max_sessions)
    {
        cout << "Invalid. You cannot exceed the array capacity of " << max_sessions << " sessions.\n";
        cout << "Please enter a valid number of sessions (1-" << max_sessions << "): ";
        cin >> sessions;
    }

    practiceHours = getValidDouble("How many total hours did you practice? ", 0.1);

    int shotsArray[max_sessions];

    for (int i = 0; i < sessions; i++)
    {
        int makes;

        cout << "\nSession " << (i + 1) << " shots attempted: ";
        cin >> shotsArray[i];

        while (cin.fail() || shotsArray[i] <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid. Enter shots greater than 0: ";
            cin >> shotsArray[i];
        }

        cout << "Session " << (i + 1) << " shots made: ";
        cin >> makes;

        while (cin.fail() || makes < 0 || makes > shotsArray[i])
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid. Makes must be between 0 and shots attempted: ";
            cin >> makes;
        }

        totalShots = totalShots + shotsArray[i];
        totalMakes = totalMakes + makes;
    }

    int highestShots = findhighestshots(shotsArray, sessions);

    cout << "\nPractice data saved.\n";
    cout << "Your highest shooting volume in a single session was: " << highestShots << " shots.\n";
}

double calculateShootingPercent(int totalMakes, int totalShots)
{
    return (static_cast<double>(totalMakes) / totalShots) * 100;
}

void viewWeeklyReport(string playerName, int totalShots, int totalMakes)
{
    double shootingPercent;

    if (totalShots == 0)
    {
        cout << "\nNo practice data entered yet.\n";
    }
    else
    {
        shootingPercent = calculateShootingPercent(totalMakes, totalShots);

        cout << fixed << setprecision(2);
        cout << "\n========== Weekly Report ==========\n";
        cout << left << setw(20) << "Player:" << playerName << endl;
        cout << left << setw(20) << "Total Shots:" << totalShots << endl;
        cout << left << setw(20) << "Shots Made:" << totalMakes << endl;
        cout << left << setw(20) << "Shooting %:" << shootingPercent << "%" << endl;

        ofstream outFile;
        outFile.open("report.txt");

        outFile << fixed << setprecision(2);
        outFile << "========== Weekly Report ==========\n";
        outFile << left << setw(20) << "Player:" << playerName << endl;
        outFile << left << setw(20) << "Total Shots:" << totalShots << endl;
        outFile << left << setw(20) << "Shots Made:" << totalMakes << endl;
        outFile << left << setw(20) << "Shooting %:" << shootingPercent << "%" << endl;

        outFile.close();

        cout << "\nReport saved to report.txt\n";
    }
}

void recommendLevel(int totalShots, int totalMakes, double practiceHours)
{
    double shootingPercent;

    enum skillrating { BEGINNER, AMATEUR, PROFESSIONAL };

    skillrating skillchoice;

    if (totalShots == 0)
    {
        cout << "\nEnter practice data first.\n";
    }
    else
    {
        shootingPercent = calculateShootingPercent(totalMakes, totalShots);

        if (shootingPercent >= 70 && totalShots >= 50)
        {
            skillchoice = PROFESSIONAL;
        }
        else if (shootingPercent >= 50 && totalShots >= 25)
        {
            skillchoice = AMATEUR;
        }
        else
        {
            skillchoice = BEGINNER;
        }

        switch (skillchoice)
        {
        case PROFESSIONAL:
            cout << "\nRecommendation: Advanced shooter (PRO).\n";
            break;
        case AMATEUR:
            cout << "\nRecommendation: Intermediate shooter (AMATEUR).\n";
            break;
        case BEGINNER:
            cout << "\nRecommendation: Keep practicing fundamentals (BEGINNER).\n";
            break;
        }

        if (practiceHours >= 5 && shootingPercent >= 60)
        {
            cout << "Great work. You practiced a lot and shot well.\n";
        }
        else if (practiceHours < 5 || shootingPercent < 50)
        {
            cout << "Try adding more practice time or improving shot selection.\n";
        }
    }
}

int findhighestshots(const int shots[], int size)
{
    int highest = shots[0];
    for (int i = 1; i < size; i++)
    {
        if (shots[i] > highest)
        {
            highest = shots[i];
        }
    }
    return highest;
}