#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<random>
#include<sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin;
    ofstream fout;
    string actual_bracket = "";
    string predicted_bracket = "";


    cout << "paste the current bracket to see if any generated brackets match" << endl;
    getline(cin, actual_bracket);
    istringstream abss(actual_bracket);
    istringstream pbss(predicted_bracket);


    fin.open("brackets.txt");
    fout.open("perfect_brackets.txt");


    int actual;
    int predicted;
    bool failure = false;
    int score = 0;
    int high_score = 0;
    while(getline(fin, predicted_bracket)) {
        score = 0;
        istringstream pbss(predicted_bracket);
        istringstream abss(actual_bracket);
        failure = false;
        for(int i = 0; i < 32; i++) {
            abss >> actual;
            pbss >> predicted;
            if(actual != predicted) {
                failure = true;
            } else {
                score++;
            }
        }
        if(!failure) {
            cout << "This bracket is perfect!" << endl;
            fout << predicted_bracket << endl;
        } else {
            cout << "This bracket failed. It guessed " << score << " matchups correctly." << endl;
        }
        if(high_score < score) {
            high_score = score;
        }
        

    }

    cout << "The best bracket had " << high_score << " correct matchups." << endl;

}