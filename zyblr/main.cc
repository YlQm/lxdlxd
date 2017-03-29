#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "deck.h"

int main(int argc, char *argv[]){
        player player1, player2;
        deck deck1,deck2;
        string player1name, player2name;
        string initfilename;
        string deck1filename,deck2filename;
        string s;
        int turn;
        for (int i = 0, i <= argc , i++){
                s = argv[i+1]
                if (s == "-init") {
                        initfilename = argv[i+2];
                        i++;
                }
                if (s == "-deck1"){
                        deck1filename = argc[i+2];
                        i++;
                }
                if (s == "-deck2"){
                        deck2filename = argc[i+2];
                        i++;
                }
        }
        ifstream deck1file{deck1filename};
        string newcard;
        while(deck1filename >> newcard){
                deck1.addtodeck(newcard);
        }
        while(deck2filename >> newcard){
                deck2.addtodeck(newcard);
        }
        ifstream initfile{initfilename};
        initfile >> player1name;
        initfile >> player2name;
        player1.setname(player1name);
        player2.setname(player2name);

        
        cout << player2.getname()endl;
        while(initfile >> s){
                cout << s << endl;
        }
        while (1){
                if (turn == 0) {
                        cout << player1.getname()endl;
                        while(1){
                        cin >> s;
                        if (player1.gethealth() <= 0){
                                cout << player2.getname() << " Wins!" << endl;
                                break;
                        }
                        if (player2.gethealth() <= 0){
                                cout << player1.getname() << " Wins!" << endl;
                                break;
                        }
                        if (s == "quit") break;
                        cout << s <<endl;

                        if (s == "end") break;
                        }
                }
                if (turn == 1) {
                        cout << player1.getname()endl;
                        while(1){
                        cin >> s;
                        if (player1.gethealth() <= 0){
                                cout << player2.getname() << " Wins!" << endl;
                                break;
                        }
                        if (player2.gethealth() <= 0){
                                cout << player1.getname() << " Wins!" << endl;
                                break;
                        }
                        if (s == "quit") {
                                turn = 2;
                                break;
                        }

                        if (s == "end") break;
                        }
                }
                
                if (turn == 2) break;
                turn = 1 - turn;
        }


}
