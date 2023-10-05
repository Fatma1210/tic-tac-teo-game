#include <bits/stdc++.h>
using namespace std;
char XO[3][3] = {{'1' , '2' , '3'} , {'4' , '5' , '6'} , {'7' , '8' , '9'}};
bool checkemptycells(){
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(XO[i][j] == 'x' || XO[i][j] == 'y') continue;
            else return true ;
        }
    }
    return false ;
}
bool checkifsomeonewon(int x , int y){
    if(x == 0 and y == 0){
        if((XO[0][0] == XO[0][1] and XO[0][1] == XO[0][2]) || (XO[0][0] == XO[1][0] and XO[1][0] == XO[2][0]) || (XO[0][0] == XO[1][1] and XO[1][1] == XO[2][2]))
            return true ;
    }
    else if (x == 0 and y == 1 ){
        if((XO[0][0] == XO[0][1] and XO[0][1] == XO[0][2]) || (XO[0][1] == XO[1][1] and XO[1][1] == XO[2][1])) return true ;
    }
    else if (x == 0 and y == 2){
        if((XO[0][0] == XO[0][1] and XO[0][1] == XO[0][2]) || (XO[0][2] == XO[1][2] and XO[1][2] == XO[2][2]) || ((XO[0][2] == XO[1][1] and XO[1][1] == XO[2][0])))
            return true ;
    }
    else if (x == 1 and y == 0){
        if((XO[1][0] == XO[1][1] and XO[1][1] == XO[1][2]) || XO[0][0] == XO[1][0] and XO[1][0] == XO[2][0])
            return true ;
    }
    else if (x == 1 and y == 1){
        if((XO[1][0] == XO[1][1] and XO[1][1] == XO[1][2]) || XO[0][1] == XO[1][1] and XO[1][1] == XO[2][1])
            return true ;
        else if ((XO[0][0] == XO[1][1] and XO[1][1] == XO[2][2]) || (XO[0][2] == XO[1][1] and XO[1][1] == XO[2][0]))
            return true ;
    }
    else if (x == 1 and y == 2){
        if((XO[0][2] == XO[1][2] and XO[1][2] == XO[2][2]) || (XO[1][0] == XO[1][1] and XO[1][1] == XO[1][2]))
            return true ;
    }
    else if (x == 2 and y == 0){
        if((XO[2][0] == XO[2][1] and XO[2][1] == XO[2][2]) || (XO[2][0] == XO[1][0] and XO[1][0]  == XO[0][0]) || (XO[2][0] == XO[1][1] and XO[1][1] == XO[0][2]))
            return true ;
    }
    else if (x == 2 and y == 1){
        if((XO[2][0] == XO[2][1] and XO[2][1] == XO[2][2]) || (XO[0][1] == XO[1][1] and XO[1][1] == XO[2][1]))
            return true ;
    }
    else if (x == 2 and y == 2){
        if((XO[0][0] == XO[1][1] and XO[1][1] == XO[2][2]) || (XO[0][2] == XO[1][2] and XO[1][2] == XO[2][2]) || (XO[2][0] == XO[2][1] and XO[2][1] == XO[2][2]))
            return true ;
    }
    return false ;
}
void printgrid(){
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; j++) {
            cout << XO[i][j] << ' ' ;
            if(j != 2) cout << "| " ;
            else cout << endl;
        }
        cout << "_______" << endl;
    }
}
bool checkValidIndex (int x , int y){
    if(XO[x][y] == 'x' || XO[x][y] == 'y') return false ;
    return true ;
}
int main() {
char turn = 'x' ;
char winner ;
int x , y ;
while(checkemptycells()){
    if(turn == 'x'){
        cout << "it's player x turn , Enter a Cell index :  \n" ;
       winner = 'x' ;
       turn = 'y' ;
    }
    else {
        cout << "it's player y turn , Enter a Cell index :  \n" ;
        winner = 'y' ;
        turn = 'x' ;
    }
    bool flag = 0 ;
    while(!flag){
        cin >> x >> y ;
        if(checkValidIndex(x , y)) {
            XO[x][y] = winner ;
            break;
        }
        else {
            cout << "Enter a Valid index : \n" ;
        }
    }
    printgrid() ;
    if(checkifsomeonewon(x , y))
        break;
}
if(checkifsomeonewon(x , y)){
    if(XO[x][y] == 'x') cout << "PLAYER X WON !" << endl;
    else cout << "PLAYER Y WON !" << endl ;
}
else cout << "G A M E  O V E R ! \n" ;

    return 0;
}
