//Author: Class
//11/26/17
#include <cstdlib>
#include <iostream>
#include"Grid.h"
using namespace std;

int main(int argc, char *argv[])
{
    Grid game = Grid(6,7);
    bool in, won = false;
    int col, at, bt;
    at = bt = 0;
    cout <<game.view();
    do
    {
         cout <<"Player A, enter a column: ";
         cin >> col;
         in = game.insert('A', col);  
         if (!in)
         	continue;
         cout <<game.view();
         at = at + game.win('A');
         system("CLS");
         if (won)
         {
            cout <<game.view();
            cout <<"Player A won!\n";
         }
         else
         {
             cout <<game.view();
             do
             {
	             cout <<"Player B, enter a column: ";
	             cin >> col;
	             in = game.insert('B', col);
	         }while(!in);
             system("CLS");
             cout <<game.view();
             bt = bt + game.win('B');
             if (won)
                cout <<"Player B won!\n";
             else
             {	 
             	system("CLS");
    	 		cout << "Player A has " << at << " points." << endl
    	 	  		 << "Player B has " << bt << " points." << endl;
    	 		Sleep(2000);
                 system("CLS");
                 cout <<game.view();
             }
         }
         
         
    }while(!won);
    
    if (!in)
       cout <<"Game ended after column was filled!\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
