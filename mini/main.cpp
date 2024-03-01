#include <iostream>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void printBoad()
{
    std::cout << std::endl
              << " -------------" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << " | " << board[i][j];
        }
        std::cout << " | " << std::endl
                  << " --------------" << std::endl;
    }
}

bool updateboard( char swap_symbol,std::string println)
{
    int posx, posy;
    std::cout<<println;
    std::cin >> posx >> posy;
    board[posx - 1][posy - 1] = swap_symbol;

    return ((posx > 0 && posx < 4) && (posy > 0 && posy < 4)) ? true : false;
}

bool checkWinner()
{
    int winnerCounterX = 1;
    int winnerCounterY = 1;

    // Horizontal check
    for (int i = 0; i < 3; i++)
    {
        winnerCounterY = 1;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'x')
                winnerCounterY++;
        }
    }

    // Vertical check
    for (int i = 0; i < 3; i++)
    {
        winnerCounterX = 1;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'x')
                winnerCounterX++;
        }
    }

    // Diagonal check
    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
        winnerCounterX++;
    if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
        winnerCounterX++;

    std::cout << "Winner count: " << winnerCounterX << std::endl;

    return (winnerCounterX >= 3 || winnerCounterY >= 3);
}


int main()
{
    bool runningLoop = true;
    bool winnerX = false;
    bool winnerO = false;
    char OPTION = 'n';
    
    system("cls");
    std::cout<<"YOU WANT TO PLAY IT ALONE (y/n)? \n";
    std::cin>> OPTION;
    while (runningLoop)
    {
        if (OPTION == 'n' || OPTION == 'N')
        {
        system("cls");
        printBoad();
        if (winnerX || winnerO)
        {
            break;
        }
        winnerX = checkWinner();
        
            runningLoop = (updateboard('O',"Enter coordination for O : ") && updateboard('X',"Enter coordination for X : "));
            
        }
    }

    if (winnerX)
    {
        std::cout << "X person won this Game !!" << std::endl;
    }
    if (winnerO)
    {
        std::cout << "O person won this Game !!" << std::endl;
    }

    std::cout << "\nThanks for playing this game!!" << std::endl;

    return 0;
}
