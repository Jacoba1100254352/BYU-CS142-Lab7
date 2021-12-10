#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

///   User Input Function Declarations   ///
std::string GetUserString(const std::string&);
double GetUserDouble(const std::string&);
unsigned GetUserInt(const std::string&);

///   Control Function Declarations   ///
void AddMenuOption(ShoppingCart&);
void RemoveMenuOption(ShoppingCart&);
void ChangeMenuOption(ShoppingCart&);
void DescriptionsMenuOption(ShoppingCart&);
void CartMenuOption(ShoppingCart&);
void OptionsMenuOption();
void QuitMenuOption();


/***********
*   Main   *
***********/

int main()
{

    ///   Variable Declarations   ///
    std::string userMenuChoice;
    bool continueMenuLoop = true;

    ///   Start Program, Set Name and Date   ///
    std::string name = GetUserString("Enter Customer's Name: ");
    std::string date = GetUserString("Enter Today's Date: ");

    ///   Constructor Call   ///
    ShoppingCart cart( name, date );


    ///   Main While Loop   ///
    while (continueMenuLoop)
    {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add")
        {
            AddMenuOption( cart );
        }
        else if (userMenuChoice == "remove")
        {
            RemoveMenuOption( cart );
        }
        else if (userMenuChoice == "change")
        {
            ChangeMenuOption( cart );
        }
        else if (userMenuChoice == "descriptions")
        {
            DescriptionsMenuOption( cart );
        }
        else if (userMenuChoice == "cart")
        {
            CartMenuOption( cart );
        }
        else if (userMenuChoice == "quit")
        {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else // Also, if userMenuChoice == "options"
        {
            OptionsMenuOption();
        }
    }

    return 0;
}


/***************************
*   User Input Funcitons   *
***************************/

std::string GetUserString(const std::string& prompt)
{
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
double GetUserDouble(const std::string& prompt)
{
    double userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;

    ///   Verify a valid input   ///
    while ( cin.fail() )
    {
        //system ( "clear");
        std::cout << prompt;
        cin.clear();
        cin.ignore ( 256, '\n' );
        std::cin >> userAnswer;
        std::cin.ignore();
        std::cout << std::endl;
    }

    return userAnswer;
}
unsigned GetUserInt(const std::string& prompt)
{
    unsigned userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;

    ///   Verify a valid input   ///
    while ( cin.fail() )
    {
        //system ( "clear");
        std::cout << prompt;
        cin.clear();
        cin.ignore ( 256, '\n' );
        std::cin >> userAnswer;
        std::cin.ignore();
        std::cout << std::endl;
    }

    return userAnswer;
}


/************************
*   Control Funcitons   *
************************/

void AddMenuOption(ShoppingCart& cart)
{
    std::string name = GetUserString("Enter the item name: ");
    std::string description = GetUserString("Enter the item description: ");
    double price = GetUserDouble("Enter the item price: ");
    unsigned quantity = GetUserInt("Enter the item quantity: ");

    ItemToPurchase item( name, description, price, quantity);
    cart.AddItem(item);
}

void RemoveMenuOption(ShoppingCart& cart)
{
    std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");

    cart.RemoveItem( nameOfItemToRemove );
}

void ChangeMenuOption(ShoppingCart& cart)
{
    std::string item = GetUserString("Enter the item name: ");
    unsigned quantity = GetUserInt("Enter the new quantity: ");

    cart.UpdateItemQuantity( item, quantity );
}

void DescriptionsMenuOption(ShoppingCart& cart)
{
    cart.PrintItemDescriptions();
}

void CartMenuOption(ShoppingCart& cart)
{
    cart.PrintCartInfo();
}

void OptionsMenuOption()
{
    std::cout << "MENU" << std::endl
              << "add - Add item to cart" << std::endl
              << "remove - Remove item from cart" << std::endl
              << "change - Change item quantity" << std::endl
              << "descriptions - Print the items' descriptions" << std::endl
              << "cart - Print the shopping cart" << std::endl
              << "options - Print the options menu" << std::endl
              << "quit - Quit" << std::endl << std::endl;
}

void QuitMenuOption()
{
    std::cout << "Goodbye." << std::endl;
}
