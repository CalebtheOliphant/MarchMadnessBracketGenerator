#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<random>

using namespace std;

int main(int argc, char *argv[]) {
    ofstream fout;
    ifstream fin_lineup;
    ifstream fin_seed;
    int num_brackets = atoi(argv[1]);
    string line = "";

    random_device dev;
    mt19937 rng(dev());


    struct team {
        int id = -1;
        int seed = 0;
        string name = "";
    };

    fin_lineup.open("start_lineup.csv");
    fin_seed.open("seed_results.csv");
    fout.open("brackets.txt");

    int seed_stats[16][6];
    getline(fin_seed, line);
    getline(fin_seed, line, ',');

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 6; j++) {
            getline(fin_seed, line, ',');
            seed_stats[i][j] = stoi(line);
        }
    }

    team round_of_64[64];
    team round_of_32[32];
    team sweet_16[16];
    team elite_8[8];
    team final_4[4];
    team championship[2];

    
    for(int i = 0; i < 64; i++) {
        getline(fin_lineup, line, ',');
        round_of_64[i].name = line;
        getline(fin_lineup, line, ',');
        round_of_64[i].seed = stoi(line);
        getline(fin_lineup, line);
        round_of_64[i].id = stoi(line);

    }

    int stat1 = 0;
    int stat2 = 0;
    int pool = 0;
    int winInt = 0;
    team team1;
    team team2;

    for(int i = 0; i < num_brackets; i++) {

        for(int j = 0; j < 64; j+=2) {
            team1 = round_of_64[j];
            team2 = round_of_64[j + 1];
            stat1 = seed_stats[team1.seed - 1][0];
            stat2 = seed_stats[team2.seed - 1][0];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id << " ";
                round_of_32[j / 2] = team1;
                
            } else {
                fout << team2.id << " ";
                round_of_32[j / 2] = team2;
            }
            
        }
            for(int i = 0; i < 32; i++) {
            }

        for(int j = 0; j < 32; j+=2) {
            team1 = round_of_32[j];
            team2 = round_of_32[j + 1];
            stat1 = seed_stats[team1.seed - 1][1];
            stat2 = seed_stats[team2.seed - 1][1];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id << " ";
                sweet_16[j / 2] = team1;
            } else {
                fout << team2.id << " ";
                sweet_16[j / 2] = team2;
            }

            
        }

        for(int j = 0; j < 16; j+=2) {
            team1 = sweet_16[j];
            team2 = sweet_16[j + 1];
            stat1 = seed_stats[team1.seed - 1][2];
            stat2 = seed_stats[team2.seed - 1][2];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id << " ";
                elite_8[j / 2] = team1;
            } else {
                fout << team2.id << " ";
                elite_8[j / 2] = team2;
            }

            
        }

        for(int j = 0; j < 8; j+=2) {
            team1 = elite_8[j];
            team2 = elite_8[j + 1];
            stat1 = seed_stats[team1.seed - 1][3];
            stat2 = seed_stats[team2.seed - 1][3];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id << " ";
                final_4[j / 2] = team1;
            } else {
                fout << team2.id << " ";
                final_4[j / 2] = team2;
            }

            
        }

        for(int j = 0; j < 4; j+=2) {
            team1 = final_4[j];
            team2 = final_4[j + 1];
            stat1 = seed_stats[team1.seed - 1][4];
            stat2 = seed_stats[team2.seed - 1][4];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id << " ";
                championship[j / 2] = team1;
            } else {
                fout << team2.id << " ";
                championship[j / 2] = team2;
            }
            
        }


            team1 = championship[0];
            team2 = championship[1];
            stat1 = seed_stats[team1.seed - 1][5];
            stat2 = seed_stats[team2.seed - 1][5];
            pool = stat1 + stat2;

            uniform_int_distribution<std::mt19937::result_type> distribution(1, pool);

            winInt = distribution(rng);


            if(winInt <= stat1) {
                fout << team1.id;
            } else {
                fout << team2.id;
            }
            

        fout << endl;
        cout << "generated bracket " << i + 1 << endl; 
    }



}