#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int boardint[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

void jouer(char joueur, char board[3][3], string jn, int boardint[3][3]) {
    int posint;
    cout <<"("<<jn<<")"<<" Entrer la position: "<<endl;
    cin >> posint;
    while (posint<=1 || posint>=9) {
        cout << "invalid input"<<endl;
        cout << "Entrer la position: "<<endl;
        cin >> posint;
    }

    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (posint==boardint[i][j]) {
                board[i][j] = joueur;
            }
        }
    }
    
    
}

void board_ui(){
    /*for (int i=0;i<sizeof(board);i++) {
        for (int j=0;j<sizeof(board[i]);j++) {
            cout<<board[j];
            if (j%3!=0 && j!=0) {
                cout<<"|";
            }
            if (j%3==0) {
                cout<<endl;
            }
        }
    }*/
    //cout<<board;
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
    while (!gameover) {
        cout << endl;
        if (round%2!=0) {
            jouer('X',board,j1,boardint);
        }
        else {
            jouer('O',board,j2,boardint);
        }
        cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
        cout<<"\t-----------------"<<endl;
        cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
        cout<<"\t-----------------"<<endl;
        cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
        round++;
    }
    
}



int main() {
    board_ui();
    return 0;
}