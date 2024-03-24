#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<random>
#include<sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin_lineup;
    string line = "";


    cout << "paste a bracket string to have it translated to a readable form" << endl;
    getline(cin, line);
    istringstream ss(line);


    struct team {
        int id = -1;
        int seed = 0;
        string name = "";
    };

    team teams[64];
    string team_id = "";
    team team;
    string lineup_line;

    fin_lineup.open("start_lineup.csv");

    for(int i = 0; i < 64; i++) {
        getline(fin_lineup, lineup_line, ',');
        teams[i].name = lineup_line;
        getline(fin_lineup, lineup_line, ',');
        teams[i].seed = stoi(lineup_line);
        getline(fin_lineup, lineup_line);
        teams[i].id = stoi(lineup_line);

    }

    cout << "BRACKET" << endl;
    cout << "Round Of 32: ";

    for(int i = 0; i < 32; i++) {
        ss >> team_id;
        team = teams[stoi(team_id)];
        cout << team.name << ", ";
    }
    cout << endl << "Sweet 16: ";

    for(int i = 0; i < 16; i++) {
        ss >> team_id;
        team = teams[stoi(team_id)];
        cout << team.name << ", ";
    }
    cout << endl << "Elite 8: ";

    for(int i = 0; i < 8; i++) {
        ss >> team_id;
        team = teams[stoi(team_id)];
        cout << team.name << ", ";
    }
    cout << endl << "Final 4: ";
    for(int i = 0; i < 4; i++) {
        ss >> team_id;
        team = teams[stoi(team_id)];
        cout << team.name << ", ";
    }
    cout << endl << "Championship: ";
        for(int i = 0; i < 2; i++) {
        ss >> team_id;
        team = teams[stoi(team_id)];
        cout << team.name << ", ";
    }

    cout << endl << "Champion: ";
    ss >> team_id;
    team = teams[stoi(team_id)];
    cout << team.name << endl;

}