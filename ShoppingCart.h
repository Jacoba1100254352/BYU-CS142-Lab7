#ifndef LAB_7_SHOPPINGCART_H
#define LAB_7_SHOPPINGCART_H

#include "ItemToPurchase.h"

class ShoppingCart {
public:

    /******************
    *   CONSTRUCTOR   *
    ******************/
    ShoppingCart();
    ShoppingCart( std::string, std::string );

    /****************************
    *   GET AND SET FUNCTIONS   *
    ****************************/
    [[maybe_unused]] void SetCustomerName( std::string );
    std::string GetCustomerName();
    [[maybe_unused]] void SetCartCreationDate( std::string );
    std::string GetCartCreationDate();

    /************************
    *   Control FUNCTIONS   *
    ************************/
    void AddItem( ItemToPurchase );
    void RemoveItem( const std::string& );
    void UpdateItemQuantity( const std::string&, unsigned );
    unsigned GetCartSize();
    void TotalCartCost();

    /**********************
    *   Print FUNCTIONS   *
    **********************/
    void PrintCustomerInfo();
    void PrintItemDescriptions();
    void PrintCartInfo();

    /************************
    *   PRIVATE VARIABLES   *
    ************************/
private:
    std::string customerName;
    std::string cartDate;
    std::vector<ItemToPurchase> cartContents;
};


#endif //LAB_7_SHOPPINGCART_H
