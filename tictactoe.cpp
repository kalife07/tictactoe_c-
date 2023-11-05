#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

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
    cout<<"Nom du joueur 1: "<<endl;
    cin>>j1;
    cout<<"Nom du joueur 2: "<<endl;
    cin>>j2;
    
}

int main() {
    board_ui();
    return 0;
}