#include <iostream>
#include <fstream>
#include <string>
#include "player.hpp"
#include "deck.hpp"
#include "controller.hpp"

int main(int argc, char *argv[]){
        deck deck1, deck2;
        string player1name, player2name;
        string initfilename;
        string deck1name = "default.deck";
        string deck2name = "default.deck";
        string s;
        bool test = 0;
        bool graphics = 0;
        int turn = 0;
        int i = 0;
        for (int i = 0; i < argc - 1 ; i++){
                s = argv[i+1];
                if (s == "-init"){
                        initfilename = argv[i+2];
                        i++;
                } else if (s == "-deck1"){
                        deck1name = argc[i+2];
                        i++;
                } else if (s == "-deck2"){
                        deck2name = argc[i+2];
                        i++;
                } else if (s == "-testing"){
                        test = 1;
                } else {
                        graphics = 1;
                }

        }
        
        ifstream initfile{initfilename};
        initfile >> player1name;
        initfile >> player2name;
        player player1= new player(player1name);
        player player2= new player(player2name);
        string newcard;
        while (deck1name >> newcard){
                deck1.addtodeck(newcard);
        }
        while (deck2name >> newcard){
                deck2.addtodeck(newcard);
        }

        player1.setdeck(deck1);
        player2.setdeck(deck2);

        try {
                controller.run(test);
                }
        catch (string name){
                cout << name << "lose" << endl;
        }
}
