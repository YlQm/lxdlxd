//
//  main.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "player.hpp"
#include "deck.hpp"
#include "controller.hpp"
#include "model.hpp"

int main(int argc, char *argv[]){
    deck deck1, deck2;
    string player1name, player2name;
    string initfilename;
    string deck1name = "default.deck";
    string deck2name = "default.deck";
    string s;
    bool test = 0;
    bool graphics = 0;
    for (int i = 0; i < argc - 1 ; i++){
        s = argv[i+1];
        if (s == "-init"){
            initfilename = argv[i+2];
            i++;
        } else if (s == "-deck1"){
            deck1name = argv[i + 2];
            i++;
        } else if (s == "-deck2"){
            deck2name = argv[i + 2];
            i++;
        } else if (s == "-testing"){
            test = 1;
        } else {
            graphics = 1;
        }
        
    }
    
    ifstream initfile{initfilename};
    ifstream deck1file{deck1name};
    ifstream deck2file{deck2name};
    initfile >> player1name;
    initfile >> player2name;
    player *player1= new player(player1name);
    player *player2= new player(player2name);
    model *m= new model(player1, player2);
    view *v= new view(m);
    controller *controll=new controller(m,v);
    string newcard;
    while (deck1file >> newcard){
        deck1.addtodeck(newcard, player1, player2);
    }
    while (deck2file >> newcard){
        deck2.addtodeck(newcard, player2, player1);
    }
    
    player1->setdeck(deck1.getdeck());
    player2->setdeck(deck2.getdeck());
    
    try {
        controll->run(test);
    }
    catch (string name){
        cout << name << "lose" << endl;
    }
}
