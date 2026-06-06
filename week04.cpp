#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string playerName;
    int menuChoice;
    int sessions;
    int totalShots = 0;
    int totalMakes = 0;
    double practiceHours;
    double shootingPercent;

    cout << "=====================================\n";
    cout << "     Basketball Practice Tracker\n";
    cout << "=====================================\n\n";

    cout << "Enter player name: ";
    getline(cin, playerName);

    do
    {
        cout << "\nMenu\n";
        cout << "1. Add practice sessions\n";
        cout << "2. View weekly report\n";
        cout << "3. Recommend level\n";
        cout << "4. Quit\n";
        cout << "Enter choice: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            cout << "\nHow many practice sessions did you complete this week? ";
            cin >> sessions;

            while (sessions <= 0)
            {
                cout << "Invalid. Enter a number greater than 0: ";
                cin >> sessions;
            }

            cout << "How many total hours did you practice? ";
            cin >> practiceHours;

            while (practiceHours <= 0)
            {
                cout << "Invalid. Enter hours greater than 0: ";
                cin >> practiceHours;
            }

            for (int i = 1; i <= sessions; i++)
            {
                int shots;
                int makes;

                cout << "\nSession " << i << " shots attempted: ";
                cin >> shots;

                while (shots <= 0)
                {
                    cout << "Invalid. Enter shots greater than 0: ";
                    cin >> shots;
                }

                cout << "Session " << i << " shots made: ";
                cin >> makes;

                while (makes < 0 || makes > shots)
                {
                    cout << "Invalid. Makes must be between 0 and shots attempted: ";
                    cin >> makes;
                }

                totalShots = totalShots + shots;
                totalMakes = totalMakes + makes;
            }

            shootingPercent = (static_cast<double>(totalMakes) / totalShots) * 100;

            cout << "\nPractice data saved.\n";
            break;

        case 2:
        {
            if (totalShots == 0)
            {
                cout << "\nNo practice data entered yet.\n";
            }
            else
            {
                shootingPercent = (static_cast<double>(totalMakes) / totalShots) * 100;

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
            break;
        }

        case 3:
            if (totalShots == 0)
            {
                cout << "\nEnter practice data first.\n";
            }
            else
            {
                shootingPercent = (static_cast<double>(totalMakes) / totalShots) * 100;

                if (shootingPercent >= 70 && totalShots >= 50)
                {
                    cout << "\nRecommendation: Advanced shooter.\n";
                }
                else if (shootingPercent >= 50 && totalShots >= 25)
                {
                    cout << "\nRecommendation: Intermediate shooter.\n";
                }
                else
                {
                    cout << "\nRecommendation: Keep practicing fundamentals.\n";
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