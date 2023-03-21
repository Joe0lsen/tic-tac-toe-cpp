#include <iostream>
#include <fstream>

using namespace std;

char spot[] = {'0','1','2','3','4','5','6','7','8','9'};

void drawBoard(char player) {

    system("cls"); //this clears the "screen" after every turn

    cout << "\nTic-Tac-Toe!\n" << endl;
    cout << "It's " << player << "\'s turn\n" << endl;

    cout << "     |     |     " << endl;

    cout << "  " << spot[7] << "  |  " << spot[8] << "  |  " << spot[9] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << spot[4] << "  |  " << spot[5] << "  |  " << spot[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << spot[1] << "  |  " << spot[2] << "  |  " << spot[3] << endl;

    cout << "     |     |     " << endl;
}

bool checkForWinner() {
    if ((spot[1] == spot[2] && spot[2] == spot[3]) ||
        (spot[4] == spot[5] && spot[5] == spot[6]) ||
        (spot[7] == spot[8] && spot[8] == spot[9]) ||
        (spot[1] == spot[4] && spot[4] == spot[7]) ||
        (spot[2] == spot[5] && spot[5] == spot[8]) ||
        (spot[3] == spot[6] && spot[6] == spot[9]) ||
        (spot[1] == spot[5] && spot[5] == spot[9]) ||
        (spot[3] == spot[5] && spot[5] == spot[7])){
        return true;
    } else {
        return false;
    }
}

int main()
{
    char playerTurn = 'X';
    char playerChoice;
    int turn = 1;
    bool won = false;

    while (turn <= 9 && !won) {
        drawBoard(playerTurn);

        bool validChoice = false;
        while(!validChoice) {

            cout << "\nEnter a spot to put " << playerTurn << ": ";
            cin >> playerChoice;

            if (playerChoice == '1' && spot[1] == '1') {
                spot[1] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '2' && spot[2] == '2') {
                spot[2] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '3' && spot[3] == '3') {
                spot[3] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '4' && spot[4] == '4') {
                spot[4] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '5' && spot[5] == '5') {
                spot[5] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '6' && spot[6] == '6') {
                spot[6] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '7' && spot[7] == '7') {
                spot[7] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '8' && spot[8] == '8') {
                spot[8] = playerTurn;
                validChoice = true;
            } else if (playerChoice == '9' && spot[9] == '9') {
                spot[9] = playerTurn;
                validChoice = true;
            } else {
                cout << "\nThat isn\'t a valid choice, let's try that again...";
                cin.ignore();
                cin.get(); // these two cin methods cause the console to wait for the user to press 'Enter'
            }
        }
        won = checkForWinner();

        if (!won) {
            playerTurn = (playerTurn == 'X' ? 'O' : 'X'); // switch whose turn it is
            turn++;
        }
    }

    drawBoard(playerTurn);
    if (!won && turn > 9) {  // determine if there it's a tie
            cout << "\nCat's game!" << endl;
    } else {
        cout << "\n" << playerTurn << " is the winner!" << endl; // Whoever's turn it was when the winning move was played is the winner

        string playerName;
        cout << "Player " << playerTurn << ", enter your name: ";
        cin >> playerName;

        cout << "Congratulations, " << playerName << "!" << endl;

        string recentWinners[5];
        recentWinners[0] = playerName;
        int len = end(recentWinners) - begin(recentWinners); // we can change the length, and still get it here.

        // put recent winners in recentWinners list, after most recent winner
        fstream winnerBoard;
        winnerBoard.open("winner_board.txt", ios::in);
        if (winnerBoard.is_open()) {
            for (int i = 1; i < len; i++) {
                string name;
                getline(winnerBoard, name);
                recentWinners[i] = name;

                if (winnerBoard.eof())
                    break;
            }
            winnerBoard.close();
        } else {
            cout << "[No winner board file]";
        }

        // write new recent winners to file
        winnerBoard.open("winner_board.txt", ios::out);
        if (winnerBoard.is_open()) {
            for (int i = 0; i < len; i++)
                winnerBoard << recentWinners[i] << "\n";
            winnerBoard.close();
        } else {
            cout << "No winner board file";
        }

        // print out recent winners
        cout << "\nMost Recent Winners:" << endl;
        for (int i = 0; i < len; i++) {
            cout << i+1 << ". " << recentWinners[i] << endl;
        }
    }

    return 0; // fin
}


















