#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    string str1, str2, str3;
	int wins, losses, WLpercent;
	int MenuChoice = 0;
	bool LeaveMenu = false;
	
	ofstream outputFile("report.txt");
	
	ifstream inputFile("my_file.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }



    cout << "Welcome to Al's Questionnaire assignment!!" << endl;

	do 
	{
        cout << "\n--- Main Menu ---\n";
        cout << "1. BaseBall team Questionnaire\n";
        cout << "2. Weekly submission report\n";
        cout << "3. Exit Main Menu\n";
        cout << "Enter your choice: ";

        cin >> MenuChoice;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (MenuChoice) 
        {
            case 1:
                cout << "You selected BaseBall team Questionnaire.\n";
                cout << "Please list your favorite Baseball team: ";
                std::getline(std::cin, str1);
	            cout << endl; // here you are entering your favorite baseball team

                if (str1 == "Arizona Diamondbacks") { 
	                str2 = "NL_West", str3 = "2001", wins = 92, losses = 70;
                }

                if (str1 == "Athletics") { 
    	            str2 = "AL_West", str3 = "1989", wins = 99, losses = 63;
                }

                if (str1 == "Atlanta Braves") { 
    	            str2 = "NL_East", str3 = "2021", wins = 88, losses = 73;
                }

                if (str1 == "Baltimore Orioles") { 
    	            str2 = "AL_East", str3 = "1983", wins = 98, losses = 64;
                }

                if (str1 == "Boston Red Sox") { 
    	            str2 = "AL_East", str3 = "2018", wins = 108, losses = 54;
                }

                if (str1 == "Chicago Cubs") { 
    	            str2 = "NL_Central", str3 = "2016", wins = 103, losses = 58;
                }

                if (str1 == "Chicago White Sox") { 
    	            str2 = "AL_Central", str3 = "2005", wins = 99, losses = 63;
                }

                if (str1 == "Cincinnati Reds") { 
    	            str2 = "NL_Central", str3 = "1990", wins = 91, losses = 71;
                }

                if (str1 == "Cleveland Guardians") { 
    	            str2 = "AL_Central", str3 = "1948", wins = 97, losses = 58;
                }

                if (str1 == "Colorado Rockies") { 
    	            str2 = "NL_West", str3 = "N/A (last appearance was 2007)", wins = 90, losses = 73;
                }

                if (str1 == "Detroit Tigers") { 
    	            str2 = "AL_Central", str3 = "1984", wins = 104, losses = 58;
                }

                if (str1 == "Houston Astros") { 
    	            str2 = "AL_West", str3 = "2022", wins = 106, losses = 56;
                }

                if (str1 == "Kansas City Royals") { 
    	            str2 = "AL_Central", str3 = "2015", wins = 95, losses = 67;
                }

                if (str1 == "Los Angeles Angels") { 
                	str2 = "AL_West", str3 = "2002", wins = 99, losses = 63;
                }

                if (str1 == "Los Angeles Dodgers") { 
    	            str2 = "NL_West", str3 = "2025", wins = 93, losses = 69;
                }

                if (str1 == "Miami Marlins") { 
                	str2 = "NL_East", str3 = "2003", wins = 91, losses = 71;
                }

                if (str1 == "Milwaukee Brewers") { 
                	str2 = "NL_Central", str3 = "N/A (last appearance was 1982)", wins = 95, losses = 67;
                }

                if (str1 == "Minnesota Twins") { 
                	str2 = "AL_Central", str3 = "1991", wins = 95, losses = 67;
                }

                if (str1 == "New York Mets") { 
                	str2 = "NL_East", str3 = "1986", wins = 108, losses = 54;
                }

                if (str1 == "New York Yankees") { 
                	str2 = "AL_East", str3 = "2009", wins = 103, losses = 59;
                }

                if (str1 == "Philadelphia Phillies") { 
    	            str2 = "NL_East", str3 = "2008", wins = 92, losses = 70;
                }

                if (str1 == "Pittsburgh Pirates") { 
    	            str2 = "NL_Central", str3 = "1979", wins = 98, losses = 64;
                }

                if (str1 == "San Diego Padres") { 
                	str2 = "NL_West", str3 = "N/A (last appearance was 1998)", wins = 98, losses = 64;
                }

                if (str1 == "San Francisco Giants") { 
                	str2 = "NL_West", str3 = "2014", wins = 88, losses = 74;
                }

                if (str1 == "Seattle Mariners") { 
                	str2 = "AL_West", str3 = "N/A (closest year to appearing was 2025)", wins = 90, losses = 72;
                }

                if (str1 == "St. Louis Cardinals") { 
                	str2 = "NL_Central", str3 = "2011", wins = 90, losses = 72;
                }

                if (str1 == "Tampa Bay Rays") { 
    	            str2 = "AL_East", str3 = "N/A (last appearance was 2020)", wins = 40, losses = 20;
                }

                if (str1 == "Texas Rangers") { 
    	            str2 = "AL_West", str3 = "2023", wins = 90, losses = 72;
                }

                if (str1 == "Toronto Blue Jays") { 
    	            str2 = "AL_East", str3 = "1993", wins = 95, losses = 67;
                }

                if (str1 == "Washington Nationals") { 
    	            str2 = "NL_East", str3 = "2019", wins = 93, losses = 69;
                }

	            WLpercent = (wins * 100) / (wins + losses); // this is calculating the win/loss percentage

                cout << "Your favorite team is: " << str1 << endl;
                cout << "Your favorite team plays in the: " << str2 << endl;
                cout << "Your favorite team last won the world series back in: " << str3 << endl;
                cout << "That year they had a win percentage of: " << WLpercent << "%" << endl;
                
                outputFile << "Results" << endl;

	            outputFile << setw(3) << "Team:" << setw(15) << str1 << endl;
	            outputFile << setw(3) << "Conference:" << setw(15) << str2 << endl;
	            outputFile << setw(3) << "Year Won:" << setw(15) << str3 << endl;
	            outputFile << setw(3) << "Wins:" << setw(15) << wins << endl;
            	outputFile << setw(3) << "Losses:" << setw(15) << losses << endl;
	            outputFile << setw(3) << "Win Percentage:" << setw(11) << WLpercent << "%" << endl;

	            outputFile.close();

	            cout << "Data written out to Report.txt file" << endl;
	            cout << "Thank you for completing Al's Questionnaire!" << endl;
	            LeaveMenu = true;
                break;
            case 2:
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                LeaveMenu = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
                }
            }
    
                while (!LeaveMenu);
                {
        
                }
    
        return 0;
    }
