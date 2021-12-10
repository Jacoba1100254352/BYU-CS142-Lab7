#ifndef LAB_7_ITEMTOPURCHASE_H
#define LAB_7_ITEMTOPURCHASE_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <iomanip>

class ItemToPurchase
{
public:

    /*******************
    *   CONSTRUCTORS   *
    *******************/
    ItemToPurchase();
    ItemToPurchase( std::string, std::string, double, unsigned);

    /****************************
    *   GET AND SET FUNCTIONS   *
    ****************************/
    [[maybe_unused]] void SetName( std::string );
    std::string GetName();

    [[maybe_unused]] void SetDescription( std::string );
    std::string GetDescription();

    [[maybe_unused]] void SetPrice( double );
    [[nodiscard]] double GetPrice() const;
    void SetQuantity( unsigned );
    [[nodiscard]] unsigned GetQuantity() const;

    /**********************
    *   PRINT FUNCTIONS   *
    **********************/
    void PrintItemCost();//Print the cost of an item - Prints the item name followed by the quantity, price, and subtotal (see example)
    void PrintItemDescription();//Print the description of an item - Prints the item name and description (see example)

    /************************
    *   PRIVATE VARIABLES   *
    ************************/
private:
    std::string itemName;
    std::string itemDescription;
    double itemPrice;
    unsigned itemQuantity;
};


#endif //LAB_7_ITEMTOPURCHASE_H
