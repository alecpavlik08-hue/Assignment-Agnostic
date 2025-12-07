// Programming_Assignment_ASpect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <map>

using namespace std;
const string OUTPUT_FILE = "report.txt";
const string INPUT_FILE = "report.txt";

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

struct TeamReport {
    string team;
    string conference;
    string lastWon;
    int wins;
    int losses;
    int winPercent;
};

int main()
{
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    int MenuChoice = 0;
    bool LeaveMenu = false;

    do
    {
        cout << "\n--- Main Menu ---\n";
        cout << "1. BaseBall team Questionnaire\n";
        cout << "2. Weekly submission report\n";
        cout << "3. Exit Main Menu\n";
        cout << "Enter your choice: ";

        cin >> MenuChoice;
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

        switch (MenuChoice)
        {
        case 1:
        {
            string str1, str2, str3;
            int wins = 0, losses = 0, WLpercent = 0;
            cout << "You selected BaseBall team Questionnaire.\n";
            cout << "Please list your favorite Baseball team: ";
            getline(cin, str1);
            cout << endl;

            enum class Team {
                Arizona_Diamondbacks,
                Athletics,
                Atlanta_Braves,
                Baltimore_Orioles,
                Boston_Red_Sox,
                Chicago_Cubs,
                Chicago_White_Sox,
                Cincinnati_Reds,
                Cleveland_Guardians,
                Colorado_Rockies,
                Detroit_Tigers,
                Houston_Astros,
                Kansas_City_Royals,
                Los_Angeles_Angels,
                Los_Angeles_Dodgers,
                Miami_Marlins,
                Milwaukee_Brewers,
                Minnesota_Twins,
                New_York_Mets,
                New_York_Yankees,
                Philadelphia_Phillies,
                Pittsburgh_Pirates,
                San_Diego_Padres,
                San_Francisco_Giants,
                Seattle_Mariners,
                St_Louis_Cardinals,
                Tampa_Bay_Rays,
                Texas_Rangers,
                Toronto_Blue_Jays,
                Washington_Nationals,
                Unknown  // fallback for invalid input
            };

            struct TeamInfo {
                string conference;
                string lastWon;
                int wins;
                int losses;
            };
            const map<string, TeamInfo> TEAM_DATA = {
                {"Arizona Diamondbacks", {"NL_West", "2001", 92, 70}},
                {"Athletics", {"AL_West", "1989", 99, 63}},
                {"Atlanta Braves", {"NL_East", "2021", 88, 73}},
                {"Baltimore Orioles", {"AL_East", "1983", 98, 64}},
                {"Boston Red Sox", {"AL_East", "2018", 108, 54}},
                {"Chicago Cubs", {"NL_Central", "2016", 103, 58}},
                {"Chicago White Sox", {"AL_Central", "2005", 99, 63}},
                {"Cincinnati Reds", {"NL_Central", "1990", 91, 71}},
                {"Cleveland Guardians", {"AL_Central", "1948", 97, 58}},
                {"Colorado Rockies", {"NL_West", "N/A (last appearance was 2007)", 90, 73}},
                {"Detroit Tigers", {"AL_Central", "1984", 104, 58}},
                {"Houston Astros", {"AL_West", "2022", 106, 56}},
                {"Kansas City Royals", {"AL_Central", "2015", 95, 67}},
                {"Los Angeles Angels", {"AL_West", "2002", 99, 63}},
                {"Los Angeles Dodgers", {"NL_West", "2025", 93, 69}},
                {"Miami Marlins", {"NL_East", "2003", 91, 71}},
                {"Milwaukee Brewers", {"NL_Central", "N/A (last appearance was 1982)", 95, 67}},
                {"Minnesota Twins", {"AL_Central", "1991", 95, 67}},
                {"New York Mets", {"NL_East", "1986", 108, 54}},
                {"New York Yankees", {"AL_East", "2009", 103, 59}},
                {"Philadelphia Phillies", {"NL_East", "2008", 92, 70}},
                {"Pittsburgh Pirates", {"NL_Central", "1979", 98, 64}},
                {"San Diego Padres", {"NL_West", "N/A (last appearance was 1998)", 98, 64}},
                {"San Francisco Giants", {"NL_West", "2014", 88, 74}},
                {"Seattle Mariners", {"AL_West", "N/A (closest year to appearing was 2025)", 90, 72}},
                {"St. Louis Cardinals", {"NL_Central", "2011", 90, 72}},
                {"Tampa Bay Rays", {"AL_East", "N/A (last appearance was 2020)", 40, 20}},
                {"Texas Rangers", {"AL_West", "2023", 90, 72}},
                {"Toronto Blue Jays", {"AL_East", "1993", 95, 67}},
                {"Washington Nationals", {"NL_East", "2019", 93, 69}}
                };

            if (TEAM_DATA.count(str1) == 0) {
                cout << "Team not found. Please enter a valid MLB team.\n";
                break;
            }

            TeamInfo info = TEAM_DATA.at(str1);

            str2 = info.conference;
            str3 = info.lastWon;
            wins = info.wins;
            losses = info.losses;

            WLpercent = (wins * 100) / (wins + losses);

            cout << "Your favorite team is: " << str1 << endl;
            cout << "Your favorite team plays in the: " << str2 << endl;
            cout << "Your favorite team last won the world series back in: " << str3 << endl;
            cout << "That year they had a win percentage of: " << WLpercent << "%" << endl;

            ofstream outputFile(OUTPUT_FILE);
            if (!outputFile.is_open()) {
                cout << "Error: Could not open the OUTPUT_FILE." << endl;
                return 1;
            }

            outputFile << "Results" << endl;

            TeamReport report;
            report.team = str1;
            report.conference = str2;
            report.lastWon = str3;
            report.wins = wins;
            report.losses = losses;
            report.winPercent = WLpercent;

            outputFile << "Team: " << report.team << endl;
            outputFile << "Conference: " << report.conference << endl;
            outputFile << "Year Won: " << report.lastWon << endl;
            outputFile << "Wins: " << report.wins << endl;
            outputFile << "Losses: " << report.losses << endl;
            outputFile << "Win Percentage: " << report.winPercent << "%" << endl;

            outputFile.close();

            cout << "Data written out to Report.txt file" << endl;
            cout << "Thank you for completing Al's Questionnaire!" << endl;
            break;
        }
        case 2:
        {
            ifstream inputFile(INPUT_FILE);
            if (!inputFile.is_open()) {
                cout << "Error: Could not open the INPUT_FILE." << endl;
                return 1;
            }
            string line;
            auto pos = 0;
            while (getline(inputFile, line)) {
                cout << line << std::endl;
            }
            pos = inputFile.tellg();
            if (pos == 0 || pos == -1) {
                cout << "Please gather team stats first with option 1." << endl;
            }
            inputFile.close();
            break;
        }
        case 3:
            cout << "Exiting the program. Goodbye!\n";
            LeaveMenu = true;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (!LeaveMenu);

    return 0;
}
