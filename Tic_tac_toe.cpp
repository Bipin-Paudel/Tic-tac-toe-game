#include <iostream>
using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
string n1;
string n2;
int row;
int column;
char token = 'X';
bool tie=false;

void functionone()
{

  

    cout << "   |    |    \n";
    cout << " " << space[0][0] << "  |"
         << " " << space[0][1] << "  |"
         << " " << space[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[1][0] << "  |"
         << " " << space[1][1] << "  |"
         << " " << space[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[2][0] << "  |"
         << " " << space[2][1] << "  |"
         << " " << space[2][2] << " \n";
    cout << "    |    |    \n";

    cout<<endl;
}

void functiontwo()
{

    int digit;

    if (token == 'X')
    {
        cout << n1 << " please enter(number from 1-9): ";
        cin >> digit;
    }

    if (token == '0')
    {
        cout << n2 << " please enter(number from 1-9): ";
        cin >> digit;
    }

 
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if(digit<1 || digit>9)
    {
        cout << "invalid !!";
        
    }

    if (token =='X' && space[row][column] !='X' && space[row][column] !='0')
    {
        space[row][column] = 'X';
        token ='0';
    }
    else if (token =='0' && space[row][column] !='0' && space[row][column] !='X')
    {
        space[row][column] = '0';
        token = 'X';
    }

    else
    {
        cout << "There is no empty space! " << endl;
        functiontwo();
    }

  
   
    functionone();
}



    bool functionthree()
    {
        //  condition for wining the game
        for (int i = 0; i < 3; i++)
        {
            if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            {
                return true;
            }
        }

        if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][2])
        {
            return true;
        }
        // condition to check  wheather the game is still going on or is it finish

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (space[i][j] != 'X' && space[i][j] != '0')
                {
                    return false;
                }
            }
        }

        tie = true;
        return true;
    }

    int main()
    {
    cout << "enter the name of first player: \n";
    getline(cin, n1);
    cout << "enter the name of second player: \n";
    getline(cin, n2);

    cout << n1 << " is player-1 so he/she will play first.  \n ";
    cout << n2 << " is player-2 so he/she will play second.  \n ";


        while (!functionthree())
        {
           
            functiontwo();
            
        }

        if (token == 'X' && tie == false)
        {
            cout << n2 << " wins the game !!";
        }

        else if (token == '0' && tie == false)
        {
            cout << n1 << " wins the game!"<<endl;
        }

        else
        {
            cout << "The match was stopped at a tie !!" << endl;
        }

        return 0;
    }

      
