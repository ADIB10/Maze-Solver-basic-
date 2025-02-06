#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<string>
#include<algorithm>
#include<math.h>
#include <numeric>
#include<windows.h>
#include<vector>
#include<conio.h>
#include<ctime>
#include<stdlib.h>

using namespace std;
int x=1,y=1,n=0,tx[10]={0},ty[10]={0},mtx=x,mty=y,t=0,m=0,MOVE_COUNTER=0,START=0,T=1,T_MOVE_COUNTER=0;
string s;

// Function to print the map
void MAP_DRAW(char map[8][40])
{
    // Print the map
    for(int i = 0; i < 10; i++) {n=0;
        for(int j = 0; j < 40; j++) {
            cout << map[i][j];}cout<<endl;}
}

void PATH_FINDING(char map[8][40])
{///cout<<"OK";
    if(map[x+1][y]=='0'||map[x-1][y]=='0'||map[x][y+1]=='0'||map[x][y-1]=='0'){t=-1;}
   if(map[x+1][y]==' '){n++;}
   if(map[x-1][y]==' '){n++;}
   if(map[x][y+1]==' '){n++;}
   if(map[x][y-1]==' '){n++;}
   if(n==2){MOVE_COUNTER=0;}
   if(n>=2){tx[t]=x;ty[t]=y;t++;}
   else{n=0;}
   //for(int i=0;i<3;i++){cout<<i<<" "<<tx[i]<<ty[i]<<endl;}
}
void MOVE(char map[8][40])
{
cout<<"current position "<<x<<y<<endl;//mtx=tx[t];mty=ty[t];cout<<mtx<<mty<<endl;
while(map[x+1][y]==' '||map[x-1][y]==' '||map[x][y+1]==' '||map[x][y-1]==' ')
{
    {START=1;}
    while(map[x+1][y]==' ')
    {
        if(n<2){PATH_FINDING(map);}

        x++;map[x][y]='.';
        if(START>0){MOVE_COUNTER++;}
        //map[x][y]=char(219);
        n=0;m++;s=s+"d";
    }

    while(map[x-1][y]==' ')
    {
        if(n<2){PATH_FINDING(map);}

        x--;map[x][y]='.';
        if(START>0){MOVE_COUNTER++;}
        //map[x][y]=char(219);
        n=0;m++;s=s+"u";
    }

    while(map[x][y+1]==' ')
    {
        if(n<2){PATH_FINDING(map);}

        y++;map[x][y]='.';
        if(START>0){MOVE_COUNTER++;}
        //map[x][y]=char(219);
        n=0;m++;s=s+"r";
    }

    while(map[x][y-1]==' ')
    {
        if(n<2){PATH_FINDING(map);}

        y--;map[x][y]='.';
        if(START>0){MOVE_COUNTER++;}
        //map[x][y]=char(219);
        n=0;m++;s=s+"l";
    }

}
cout<<"Move counter"<<MOVE_COUNTER<<endl;
    if(map[x+1][y]!=' '||map[x-1][y]!=' '||map[x][y+1]!=' '||map[x][y-1]!=' '){s.erase(s.size()-MOVE_COUNTER,MOVE_COUNTER);T_MOVE_COUNTER=MOVE_COUNTER;MOVE_COUNTER=0;}
    if(map[x+1][y]=='0'||map[x-1][y]=='0'||map[x][y+1]=='0'||map[x][y-1]=='0'||t<0){t=-1;cout<<"OK";}

    {x=tx[t-1];y=ty[t-1];tx[t-1]=0;ty[t-1]=0;t--;}cout<<"junction point "<<x<<y<<endl;

}
void SOLVER(char map[10][40])
{x=mtx;y=mty;
    system("cls");
    MAP_DRAW(map);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='d'){x++;}
        if(s[i]=='u'){x--;}
        if(s[i]=='r'){y++;}
        if(s[i]=='l'){x--;}
        map[x][y]=char(219);
    }
while(map[x+1][y]=='.'||map[x-1][y]=='.'||map[x][y+1]=='.'||map[x][y-1]=='.')
    {while(map[x+1][y]=='.'){x++;map[x][y]=char(219);}
    while(map[x-1][y]=='.'){x--;map[x][y]=char(219);}
    while(map[x][y+1]=='.'){y++;map[x][y]=char(219);}
    while(map[x][y-1]=='.'){y--;map[x][y]=char(219);}}
}

int main()
{

    char map[10][40] = {
        "########################0",
        "#   #   #   # # # #   ##1",
        "# # ##### ### # # # # ##2",
        "# # # #   # # # # #0# ##3",
        "# # # # # #   #   ###  #4",
        "# # #   #   # # # # ## #5",
        "# #   # # # #   #      #6",
        "########################7",
        "012345678911111111112222 ",
        "          01234567890123 ",
    };
MAP_DRAW(map);
cout<<"Value of y axis";cin>>x;
cout<<endl<<"Value of x axis";cin>>y;mtx=x;mty=y;
while(T>0)
{

    system("cls");

    /// Pass map by reference to MAP_DRAW
    MAP_DRAW(map);
    MOVE(map);
    if(t<0){SOLVER(map);cout<<mtx<<mty<<s;}
    //s.erase(s.size()-T_MOVE_COUNTER,T_MOVE_COUNTER);cout<<s;
    system("pause>nul");
}

    return 0;
}
