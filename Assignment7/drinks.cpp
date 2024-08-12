// Declare and initialize global variables
// Declare and initialize Struct named Drink that contains drink name, drink cost, number of drinks in the machine
// Declare function prototypes
// Program will via a loop that will display a menu of drinks on the screen and allow user to select a drink or quit
// Prompt the user to select a drink and store user's input 
// Prompt the user for the amount of money that is to be inserted into the drink machine
// Display the amount of change to be returned to the user and subtract one from the number of that drink left in the machine
// If user selects a drink that is sold out, display sold out message
// When the user chooses to quit the program, display total amount of money earned by machine

#include <iostream>
#include <iomanip>
using namespace std;

// Define structs
struct Drink {
    string name;
    float cost;
    int qty;
};

// Declare and initialize array of structs
const int DRINKSNUM = 5;
Drink drinks[] = {
    {"Cola", 0.65, 20},
    {"Root Beer", 0.70, 20},
    {"Grape Soda", 0.75, 20},
    {"Lemon-Lime", 0.85, 20},
    {"Water", 0.90, 20}
};

// Function prototypes
int menuSelection();
float userFunds();

int main() {

    // Declare local variables
    int menuChoice;
    float funds, change, totalRevenue;
    
    do {
        // Display the drinks menu, store and validate user's response
        menuChoice = menuSelection();

        // If user selects 6, break loop and end program
        if (menuChoice == 6) {
            break;
        }

        // Prompt the user for how much money they want to put in the machine
        funds = userFunds();


        switch(menuChoice) {
            case 1: // cola
                if (drinks[0].cost <= funds && drinks[0].qty > 0) {
                    change = funds - drinks[0].cost; // compute user's change
                    cout << endl << "Change: " << change << endl; // display user's change
                    totalRevenue += drinks[0].cost; // add to total revenue
                    drinks[0].qty--;
                    break;
                } else if (drinks[0].cost > funds) {
                    cout << endl << "Insufficient funds. Please make another selection or enter more money" << endl;
                } else if (drinks[0].qty == 0) {
                    cout << endl << "SOLD OUT" << endl;
                }
                break;
            case 2: // rootbeer
                if (drinks[1].cost <= funds && drinks[1].qty > 0) {
                    change = funds - drinks[1].cost;
                    cout << endl << "Change: " << change << endl; 
                    totalRevenue += drinks[1].cost;                   
                    drinks[1].qty--;

                    break;
                } else if (drinks[1].cost > funds) {
                    cout << endl << "Insufficient funds. Please make another selection or enter more money" << endl;
                } else if (drinks[1].qty == 0) {
                    cout << endl << "SOLD OUT" << endl;
                }
                break;           
            case 3: // grape soda
                if (drinks[2].cost <= funds && drinks[2].qty > 0) {
                    change = funds - drinks[2].cost;
                    cout << endl << "Change: " << change << endl;
                    totalRevenue += drinks[2].cost;
                    drinks[2].qty--;
                    break;
                } else if (drinks[2].cost > funds) {
                    cout << endl << "Insufficient funds. Please make another selection or enter more money" << endl;
                } else if (drinks[2].qty == 0) {
                    cout << endl << "SOLD OUT" << endl;
                }
                break; 
            case 4: // lemon lime
                if (drinks[3].cost <= funds && drinks[3].qty > 0) {
                    change = funds - drinks[3].cost;
                    cout << endl << "Change: " << change << endl;
                    totalRevenue += drinks[3].cost;
                    drinks[3].qty--;
                    break;
                } else if (drinks[3].cost > funds) {
                    cout << endl << "Insufficient funds. Please make another selection or enter more money." << endl;
                } else if (drinks[3].qty == 0) {
                    cout << endl << "SOLD OUT" << endl;
                }
                break; 
            case 5: // water
                if (drinks[4].cost <= funds && drinks[4].qty > 0) {
                    change = funds - drinks[4].cost;
                    cout << endl << "Change: " << change << endl;
                    totalRevenue += drinks[4].cost;
                    drinks[4].qty--;
                    break;
                } else if (drinks[4].cost > funds) {
                    cout << endl << "Insufficient funds. Please make another selection or enter more money" << endl;
                } else if (drinks[4].qty == 0) {
                    cout << endl << "SOLD OUT" << endl;
                }
                break; 
        }

    } while (menuChoice != 6);

    // Display the total revenue and the inventory of each drink item
    cout << endl << "Total Revenue: " << totalRevenue << endl << endl;

    cout << "Drink " << setw(30) << "Number Remaining " << endl
         << "-----------------------------------" << endl
         << drinks[0].name << setw(17) << drinks[0].qty << endl
         << drinks[1].name << setw(12) << drinks[1].qty << endl
         << drinks[2].name << setw(11) << drinks[2].qty << endl
         << drinks[3].name << setw(11) << drinks[3].qty << endl
         << drinks[4].name << setw(16) << drinks[4].qty << endl;

    return 0;
}

// Function definitions

// -------- MENU DISPLAY -------- //
int menuSelection()
{
    int menu;
    while(true) {

        cout << endl << "Drink Name " << setw(10) << " Cost " << setw(25) << " Number in Machine" << endl 
             << "1) " << drinks[0].name << setw(10) << " $" << setprecision(2) << fixed << drinks[0].cost << setw(10) << drinks[0].qty << endl 
             << "2) " << drinks[1].name << setw(5)  << " $" << setprecision(2) << fixed << drinks[1].cost << setw(10) << drinks[1].qty << endl
             << "3) " << drinks[2].name << setw(4)  << " $" << setprecision(2) << fixed << drinks[2].cost << setw(10) << drinks[2].qty << endl 
             << "4) " << drinks[3].name << setw(4)  << " $" << setprecision(2) << fixed << drinks[3].cost << setw(10) << drinks[3].qty << endl  
             << "4) " << drinks[4].name << setw(9) << " $" << setprecision(2) << fixed << drinks[4].cost << setw(10) << drinks[4].qty << endl;
        cout << endl << "Select a drink (1-5) or enter 6 to quit: " << endl;
        cin >> menu;

        // To prevent infinite loop, if cin fails, clear input, ignore entire line
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Validate user response
        if (menu >= 1 && menu <= 6) {
            return menu;
        } else {
            cout << "Invalid selection. Please try again." << endl << endl;
        }
    }
}

// -------- USER FUNDS -------- //
float userFunds()
{
    float money;
    while (true) {
        cout << "Enter the amount of money you would like to insert: " << endl;
        cin >> money;

        // To prevent infinite loop, if cin fails, clear input, ignore entire line
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Validate user response
        if (money > 0 && money <= 1) {
            return money;
        } else {
            cout << endl << "This machine only accepts a value equal to or less than $1." << endl;
        }
    
    }
}