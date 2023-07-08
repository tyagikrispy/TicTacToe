#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool check = false;
string n1 = "";
string n2 = "";

void functionOne()
{
    system("clear");
    cout << "    |    |   " << endl;
    cout << " " << board[0][0] << "  | " << board[0][1] << "  | " << board[0][2] << "   " << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |   " << endl;
    cout << " " << board[1][0] << "  | " << board[1][1] << "  | " << board[1][2] << "   " << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |   " << endl;
    cout << " " << board[2][0] << "  | " << board[2][1] << "  | " << board[2][2] << "   " << endl;
    cout << "    |    |    " << endl;
    cout << endl;
}

void functionTwo()
{
    int digit;

    if (token == 'x')
    {
        cout << n1 << " [x] please enter" << endl;
        cin >> digit;
    }
    if (token == '0')
    {
        cout << n2 << " [0] please enter" << endl;
        cin >> digit;
    }
    switch (digit)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid!!!";
        break;
    }

    if (token == 'x' && board[row][column] != 'x' && board[row][column] != '0')
    {
        board[row][column] = 'x';
        token = '0';
    }
    else if (token == '0' && board[row][column] != 'x' && board[row][column] != '0')
    {
        board[row][column] = '0';
        token = 'x';
    }
    else
    {
        cout << "Box already filled !" << endl
             << " Please try again!";
        functionTwo();
    }
    functionOne();
}

bool functionThree()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
        {
            return false;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != '0')
            {
                return true;
            }
        }
    }
    check = true;
    return false;
}

int main()
{
    cout << "Enter the name of first player [x]" << endl;
    getline(cin, n1);
    cout << "Enter the name of second player [0]" << endl;
    getline(cin, n2);

    cout << n1 << " is the first player so he/she will play first [x]" << endl;
    cout << n2 << " is the second player so he/she will play second [0]" << endl;

    while (functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }
    if (token == 'x' && check == false)
    {
        cout << n2 << " [0] wins!!!" << endl;
    }
    else if (token == '0' && check == false)
    {
        cout << n1 << " [x] wins!!!" << endl;
    }
    else
    {
        cout << " GAME DRAW!" << endl;
    }
}
