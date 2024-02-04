#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;

const int Rows = 5;
const int Cols = 5;
const int MaxShips = 5;
int grid[Rows][Cols];
int RemShips = MaxShips;

void Clear()
{
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Cols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void SetShips()
{
    int s = MaxShips;
    srand(time(NULL));    
    int x,y;
    while(s)
    {
        
        x = rand() % Rows;
        y = rand() % Cols;
        if(grid[x][y]!=1)
        {
            grid[x][y]=1;
            s--;
        }
    }
}

void Show()
{
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Cols; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Attack(int pos1,int pos2)
{
    if(grid[pos1][pos2] == 1)
    {
        RemShips--;
        grid[pos1][pos2] = 2;
        return true;
    }

    return false;
}

int main()
{
    Clear();
    SetShips();

    int pos1,pos2;
    char GiveUp;
    while(RemShips)
    {
        system("cls");
        cout<<"Enter position to Attack: ";
        cin>>pos1>>pos2;
        if(Attack(pos1,pos2))
            cout<<"Woohoo you got it!"<<endl;
        else
            cout<<"No ship at that location :("<<endl;

        cout<<"Remaining Ships: "<<RemShips<<endl;
        cout<<"#-----------------------#"<<endl;
        cout<<"Continue to play?(y/n): ";
        cin>>GiveUp;
        if(GiveUp == 'n')
        break;
    }

    Show();
}