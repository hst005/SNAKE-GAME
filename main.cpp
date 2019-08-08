#include <iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;


bool gameover;
const int width=20,hgt=20;
int x,y,foodx,foody,score;

enum edirection{ stop=0,leftt,rightt,up,down};
edirection dir;

int tailx[100],taily[100];
int ntail;

void setup(){
    gameover=false;
    dir=stop;
    x=width/2;
    y=hgt/2;
    foodx=rand()%width;
    foody=rand()%hgt;
    score=0;

}

void draw(){
    system("cls");
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }

    cout<<endl;
    for(int i=0;i<hgt;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1){
                cout<<"#";
            }
            if(i==y && x==j){
                cout<<"0";
            }
            else if(i==foody && j==foodx){
                cout<<"F";
            }
            else{
                    bool printcheck=false;
                for(int k=0;k<ntail;k++){

                    if(taily[k]==i && tailx[k]==j){
                        cout<<"0";
                        printcheck=true;
                    }
                }
                if(printcheck==false){
                    cout<<" ";
                }
            }
            /*if(j==width-1){
                cout<<"#";
            }*/
        }
        cout<<endl;
    }
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }

    cout<<endl<<"score is "<<score<<endl;


}

void input(){
    if(_kbhit()){ //to check if any key is pressed on the keyboard , positive no if yes ;0 if no;

            switch(_getch()){   //ascii value of what we ll get
            case 'a':
                    dir=leftt;
                    break;
                case 'w':
                    dir=up;
                    break;
                case 'd':
                    dir=rightt;
                    break;
                case 's':
                    dir=down;
                    break;
                case 'q':
                    gameover=true;
                    break;
            }

    }
}
void logic(){
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;taily[0]=y;
    for(int i=1;i<ntail;i++){
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;

        prevy=prev2y;

    }

    switch(dir){
        case leftt:
            x--;
            break;
        case rightt:
            x++;
            break;
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        default:
            break;
    }
   /* if(x>width || x<0 || y>hgt || y<0 ){
        gameover=true;

    }*/ //if you want to over the game when it hits the wall then uncomment this otherwise
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= hgt) y = 0; else if (y < 0) y = hgt - 1;
    for(int i=0;i<ntail;i++){
        if(tailx[i]==x && taily[i]==y){
            gameover=true;
        }
    }
    if(x==foodx && y==foody){
        score++;
        foodx=rand()%width;
        foody=rand()%hgt;
        ntail++;
    }

}
int main()
{
    int n;
    cout<<"Enter the speed multiplier(lower the number more the speed ";
    cin>>n;
    setup();
    while(!gameover){
        draw();
        input();
        logic();

        Sleep(10*n); //tp slow down the game
    }
    return 0;
}
