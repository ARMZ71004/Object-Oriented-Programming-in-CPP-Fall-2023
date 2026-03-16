// S. Trowbridge 2023
#include <iostream>

void ticTacToe()
{
    std::cout << "You play TicTacToe.\n\n";
    // game code goes here
}
void sudoku()
{
    std::cout << "You play Sudoku.\n\n";    
    // game code goes here
}
void mineFields()
{
    std::cout << "You play Minefields.\n\n";    
    // game code goes here
}

int main() {
    std::cout << std::endl;

    int option;
    
    do {
        std::cout << "1) TicTacToe\n";
        std::cout << "2) Sudoku\n";
        std::cout << "3) Minefields\n";
        std::cout << "4) End program\n";
        std::cout << "Select: ";
        std::cin >> option;
        std::cout << std::endl;

        switch(option) {    // can use if/else-if instead but switch is faster, switch relies on value of option
            case 1:
                ticTacToe();
                break;
            case 2:
                sudoku();
                break;
            case 3:
                mineFields();
                break;
            case 4:
                std::cout << "Ending program.\n\n";            
                break;
            default:        // default case runs if option is not between 1 and 4 inclusive
                std::cout << "Invalid option.\n\n";
        }

    } while(option != 4);   // repeat until the user decides to exit the menu



    return 0;
    std::cout << std::endl;
}