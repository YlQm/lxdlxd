#include <iostream>
#include <fstream>
#include <string>
#include "player.hpp"
//#include "deck.hp"

int main(int argc, char *argv[]){
        player player1, player2;

        string player1name, player2name;
        string initfilename;

        string s;
        int turn = 0;
        int i = 0;

        s = argv[i+1];

        initfilename = argv[i+2];

        ifstream initfile{initfilename};
        initfile >> player1name;
        initfile >> player2name;
        player1.setname(player1name);
        player2.setname(player2name);
        try {
        while (1){
                if (turn == 0) {
                        cout << player1.getname()<<endl;
                        while(1){
                        cin >> s;

                        if (s == "quit") {
                                turn = 2;
                                break;
                        }
                        if (s == "minus") {
                                player1.changehealth("minus", 20);  //this is for testing the case when player's health lower than 0
                        }

                        if (s == "end") break;
                        }       
                }
                if (turn == 1) {
                        cout << player2.getname()<<endl;
                        while(1){
                        cin >> s;

                        if (s == "quit") {
                                turn = 2;
                                break;
                        }
                        if (s == "minus") {
                                player1.changehealth("minus", 20);
                        }

                        if (s == "end") break;
                        }
                        
                }
                
                if (turn == 2) break;
                turn = 1 - turn;
        }}
        catch (string name){
                cout << name << "lose" << endl;
        }
}
