/*

Mauricio Jurado Spaltenstein 08/05/2020

Solution to the rocket problem. Formulation at https://github.com/juanma-brl/rocket
Asuming user not using -l flag means only show spike, no matter other input
Return 0 if user input 0 or negative number
Program asumes integer input to -l argument. Other not taken into account
Assuming no other possible flags other than -l & -i

*/

#include <iostream>
#include <string>

using namespace std;

// Prints X number of consecutive chars on the command prompt. Inputs: x -> number of chars c -> desired char to print
void addXCs(int x, char c);


int main(int argc, char** argv) {

    const char* flagL = "-l";
    const char* flagI = "-i";

    int bol = 1;
    int inp;

    // Input

    if (*argv[1] == *flagL) {
        inp = *argv[2] - '0';
        inp--;
        if (argv[3]) {
            if (*argv[3] == *flagI) {
                bol = 0;
            }
        }
    }
    else {
        
        cout << "|";
        return 1;

    }

    if (inp < 0) {
        return 0;
    }

    if (bol) {


        // Adds the spike to the rocket

        addXCs(inp, ' '); cout << "|"; addXCs(inp, ' '); cout << '\n';

        // Loop that prints out rocket

        for (int i = 0; i <= inp; i++) {

            addXCs(inp - i, ' '); addXCs((i*2)+1, 'X'); addXCs(inp - i, ' '); cout << '\n';

        }

        cout << "X"; addXCs(inp - 1, ' '); cout << "X"; addXCs(inp - 1, ' '); cout << "X";

    }
    else {

        // Inverse building of the rocket, starting from the bottom

        cout << "X"; addXCs(inp - 1, ' '); cout << "X"; addXCs(inp - 1, ' '); cout << "X"; cout << '\n';

        // Loop that prints out rocket

        for (int i = 0; i <= inp; i++) {

            addXCs(i, ' '); addXCs(((inp - i) * 2) + 1, 'X'); addXCs(i, ' '); cout << '\n';

        }

        addXCs(inp, ' '); cout << "|"; addXCs(inp, ' ');

    }

    return 1;
}

void addXCs(int x, char c) {

    for (int i = 0; i < x; i++) {
        cout << c;
    }

}