#include "ShoppingCart.h"


/******************
*   CONSTRUCTOR   *
******************/

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    cartDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart( std::string name, std::string date )
{
    customerName = std::move(name);
    cartDate = std::move(date);
}


/****************************
*   GET AND SET FUNCTIONS   *
****************************/

[[maybe_unused]] void ShoppingCart::SetCustomerName( std::string name )
{
    customerName = std::move(name);
}
std::string ShoppingCart::GetCustomerName()
{
    return customerName;
}

[[maybe_unused]] void ShoppingCart::SetCartCreationDate( std::string date )
{
    cartDate = std::move(date);
}
std::string ShoppingCart::GetCartCreationDate()
{
    return cartDate;
}


/************************
*   Control FUNCTIONS   *
************************/

void ShoppingCart::AddItem( ItemToPurchase item )
{
    bool itemInCart = false;
    for (auto & cartContent : cartContents)
    {
        if ( cartContent.GetName() == item.GetName() )
        {
            itemInCart = true;
        }
    }
    if (itemInCart)
    {
        std::cout << "Item is already found in the cart. It will not be added." << std::endl;
    }
    else
    {
        cartContents.push_back( item );
    }
}
void ShoppingCart::RemoveItem( const std::string& item )
{
    unsigned itemLocation = 0;
    bool itemInCart = false;
    for (unsigned i = 0; i < GetCartSize(); i++)
    {
        if ( cartContents.at(i).GetName() == item )
        {
            itemInCart = true;
            itemLocation = i;
        }
    }
    if (itemInCart)
    {
        cartContents.erase( cartContents.begin() + itemLocation );
    }
    else
    {
        std::cout << "Item not found in cart. It will not be removed." << std::endl;
    }
}
void ShoppingCart::UpdateItemQuantity( const std::string& item, unsigned quantity )
{
    unsigned itemLocation = 0;
    bool itemInCart = false;
    for (unsigned i = 0; i < GetCartSize(); i++)
    {
        if ( cartContents.at(i).GetName() == item )
        {
            itemInCart = true;
            itemLocation = i;
        }
    }
    if (itemInCart)
    {
        cartContents.at(itemLocation).SetQuantity( quantity );
    }
    else
    {
        std::cout << "Item not found in cart. It will not be modified." << std::endl;
    }
}
unsigned ShoppingCart::GetCartSize()
{
    return cartContents.size();
}
void ShoppingCart::TotalCartCost()
{
    double totalCost = 0.0;
    for ( auto & cartContent : cartContents )
    {
        cartContent.PrintItemCost();
        totalCost += cartContent.GetQuantity() * cartContent.GetPrice();
    }
    std::cout << "\n" << "Total: $" << totalCost << std::endl;
}


/**********************
*   Print FUNCTIONS   *
**********************/

void ShoppingCart::PrintCustomerInfo()
{
    std::cout << GetCustomerName() << "\'s Shopping Cart - " << GetCartCreationDate() << std::endl;
}
void ShoppingCart::PrintItemDescriptions()
{
    PrintCustomerInfo();
    if ( cartContents.empty() )
    {

        std::cout << "Shopping cart is empty." << std::endl;
    }
    else
    {
        std::cout << "\n" << "Item Descriptions" << std::endl;

        for ( auto & cartContent : cartContents )
        {
            cartContent.PrintItemDescription();
        }
    }
}
void ShoppingCart::PrintCartInfo()
{
    unsigned totalQuantity = 0;
    PrintCustomerInfo();
    if ( cartContents.empty() )
    {
        std::cout << "Shopping cart is empty." << std::endl;
    }
    else
    {
        for ( auto & cartContent : cartContents )
        {
            totalQuantity += cartContent.GetQuantity();
        }

        std::cout << "Number of Items: " << totalQuantity << std::endl
                  << std::endl;
        TotalCartCost();
    }
}
