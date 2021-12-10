#include "ItemToPurchase.h"


/*******************
*   CONSTRUCTORS   *
*******************/

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase( std::string name, std::string description, double price, unsigned quantity)
{
    itemName = std::move(name);
    itemDescription = std::move(description);
    itemPrice = price;
    itemQuantity = quantity;
}


/****************************
*   GET AND SET FUNCTIONS   *
****************************/

[[maybe_unused]] void ItemToPurchase::SetName( std::string name )
{
    itemName = std::move(name);
}
std::string ItemToPurchase::GetName()
{
    return itemName;
}
[[maybe_unused]] void ItemToPurchase::SetDescription( std::string description )
{
    itemDescription = std::move(description);
}
std::string ItemToPurchase::GetDescription()
{
    return itemDescription;
}
[[maybe_unused]] void ItemToPurchase::SetPrice( double price )
{
    itemPrice = price;
}
double ItemToPurchase::GetPrice() const
{
    return itemPrice;
}
void ItemToPurchase::SetQuantity( unsigned quantity )
{
    itemQuantity = quantity;
}
unsigned ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}


/**********************
*   PRINT FUNCTIONS   *
**********************/

void ItemToPurchase::PrintItemCost() //Print the cost of an item - Prints the item name followed by the quantity, price, and subtotal (see example)
{
    double itemTotalPrice = GetPrice() * GetQuantity();
    std::cout << GetName() << " " << std::fixed << std::setprecision(2) << GetQuantity() << " @  $" << GetPrice() << " = $" << itemTotalPrice << std::endl;
}
void ItemToPurchase::PrintItemDescription() //Print the description of an item - Prints the item name and description (see example)
{
    std::cout << GetName() << ": " << GetDescription() << std::endl;
}
