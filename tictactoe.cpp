#include <iostream>
#include <stdlib.h>
using namespace std;



bool fin(char board[3][3], char joueur) {
    int index = 0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[i][j]==joueur) {
                index++;
            }        
        }
        if (index==3) {
            return true;
        }
        index = 0;
    }

    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[j][i]==joueur) {
                index++;
            }        
        }
        if (index==3) {
            return true;
        }
        index = 0;
    }

    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        return true;
    }

    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        return true;
    }

    return false;
}

void jouer(char joueur, char board[3][3], string jn, int boardint[3][3]) {
    int posint;
    cout <<"("<<jn<<")"<<" Entrer la position: "<<endl;
    cin >> posint;
    while (posint<1 || posint>9) {
        cout << "invalid input"<<endl;
        cout << "Entrer la position: "<<endl;
        cin >> posint;
    }

    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if(1<=posint && posint<=3) {
                if(board[0][j]=='0'+posint){
                    board[0][j] = joueur;
                }
            }
            else if(4<=posint && posint<=6) {

                if(board[1][j]=='0'+posint){
                    board[1][j] = joueur;
                    break;
                }
            }
            else {
                if(board[2][j]=='0'+posint){
                    board[2][j] = joueur;
                }
            }
        }
    }
        
    
    
}

void board_ui(){
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int boardint[3][3];
    cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"\t-----------------"<<endl;
    cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"\t-----------------"<<endl;
    cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    string j1;
    string j2;
    cout<<"Nom du joueur 1 (X): "<<endl;
    cin>>j1;
    cout<<"Nom du joueur 2 (O): "<<endl;
    cin>>j2;
    bool gameover = false;
    int round = 1;
    int score1 = 0;
    int score2 = 0;
    while (!gameover) {
        char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        int boardint[3][3];
        round = 1;
        gameover = false;
        while (true) {
            cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
            cout<<"\t-----------------"<<endl;
            cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
            cout<<"\t-----------------"<<endl;
            cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
            if (round>9) {
                cout << "Fin du jeu"<<endl;
                break;
            }
            cout << endl;
            if (round%2!=0) {
                jouer('X',board,j1,boardint);
                if (fin(board,'X')) {
                    cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
                    cout<<"\t-----------------"<<endl;
                    cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
                    cout<<"\t-----------------"<<endl;
                    cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
                    score1++;
                    cout<<j1<<" a gagne!"<<endl;
                    cout<<j1<<": "<<score1<<", "<<j2<<": "<<score2<<endl;
                    char choix_user;
                    cout<<"Continuer? (Y/N) ";
                    cin>>choix_user;
                    if (choix_user=='N') {
                        gameover = true;
                        break;
                    }
                    else {
                        char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
                        int boardint[3][3];
                        round = 1;
                        gameover = false;
                        break;
                    }
                        
                }
            }
            else {
                jouer('O',board,j2,boardint);
                if (fin(board,'O')) {
                    cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
                    cout<<"\t-----------------"<<endl;
                    cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
                    cout<<"\t-----------------"<<endl;
                    cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
                    score2++;
                    cout<<j2<<" a gagne!"<<endl;
                    cout<<j1<<": "<<score1<<", "<<j2<<": "<<score2<<endl;
                    char choix_user;
                    cout<<"Continuer? (Y/N) ";
                    cin>>choix_user;
                    if (choix_user=='N') {
                        gameover = true;
                    }
                }
            }
            
            round++;
        }
    }
    if (score1>score2) {
        cout<<j1<<" a gagner la partie!"<<endl;
    }
    else if(score1<score2) {
        cout<<j2<<" a gagner la partie!"<<endl;
    }
    else {
        cout<<"Match nul!"<<endl;
    }
        
    
}



int main() {
    board_ui();
    return 0;
}