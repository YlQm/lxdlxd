//
//  controller.cpp
//  Sorcery
//
//  Created by 刘然 on  -03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "controller.hpp"
#include <sstream>



controller::~controller(){
    delete m;
    delete v;
}


void controller::run(bool test){
    player p1=m->get_player(1);
    player p2=m->get_player(2);
    int turn=1; // 1:p1, 2:p2
    string cmd;
    while(1){
        v->print_view();
        turn==1?p1.draw():p2.draw();
        turn==1?p1.add_magic():p2.add_magic();
        bool flag=false;
        while(1){
            if(flag==false)
                cin>>cmd;
            flag=false;
            if(cmd=="help"){
                cout<<"commands:"<<endl;
                cout<<"help -- Display this message."<<endl;
                cout<<"end -- End the current player’s turn."<<endl;
                cout<<"quit -- End the game."<<endl;
                cout<<"attack minion other-minion -- Orders minion to attack other-minion."<<endl;
                cout<<"attack minion -- Orders minion to attack the opponent."<<endl;
                cout<<"play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player."<<endl;
                cout<<"use minion [target-player target-card] -- Use minion’s special ability, optionally targeting target-card owned by target-player. inspect minion -- View a minion’s card and all enchantments on that minion."<<endl;
                cout<<"hand -- Describe all cards in your hand."<<endl;
                cout<<"board -- Describe all cards on the board."<<endl;
            }
            else if(cmd=="end")
                turn==1?turn=2:turn=1;
            else if(cmd=="quit"){
                cout<<"No winner!"<<endl;
            }
            else if(test==true&&cmd=="draw")
                turn==1?p1.draw():p2.draw();
            else if(test==true&&cmd=="discard"){
                int i;
                cin>>i;
                turn==1?p1.discard(i):p2.discard(i);
            }
            else if(cmd=="attack"){
                int i,j; string temp;
                cin>>i; cin>>temp;
                stringstream ss(temp);
                if(ss>>j)
                    turn==1?p1.attack(i, j):p2.attack(i, j);
                else{
                    turn==1?p1.attack(i):p2.attack(i);
                    flag=true;
                    cmd=temp;
                }
                v->print_view();
            }
            else if(cmd=="play"){
                int i,p,t; string temp1, temp2;
                cin>>i; cin>>temp1;
                stringstream ss(temp1);
                if(ss>>p){
                    cin>>temp2;
                    stringstream ss(temp2);
                    if((ss>>t)&&p==1)
                        turn==1?p1.play(i, "player1", t):p2.play(i, "player1", t);
                    else if((ss>>t)&&p==2)
                        turn==1?p1.play(i, "player2", t):p2.play(i, "player2", t);
                    else if(p==1)
                        turn==1?p1.play(i, "player1", -1):p2.play(i, "player1", -1);
                    else if(p==2)
                        turn==1?p1.play(i, "player2", -1):p2.play(i, "player2", -1);
                }
                else{
                    turn==1?p1.play(i):p2.play(i);
                    flag=true;
                    cmd=temp1;
                }
                v->print_view();
            }
            else if(cmd=="use"){
                
                
                
                v->print_view();
            }
            else if(cmd=="describe"){
                int i;
                cin>>i;
                turn==1?v->inspect(1,i):v->inspect(2,i);
            }
            else if(cmd=="print_hand"){
                turn==1?v->hand(1):v->inspect(2);
            }
            else if(cmd=="board"){
                v->print_view();
            }
        }
    }
}



















