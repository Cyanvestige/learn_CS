//Exercise 7.3  Revise transaction-processing program with isbn, combine...
#include <iostream>
#include <string>
#include "ex-7.2.h"
// My customized "Sales_data" class with a new data member "discount"

int main(){
	// variable to hold data for the next transaction
    Sales_data_with_discount total;
	// as long as there is a new input, the transaction process keeps going
	if(std::cin >> total.bookNo >> total.units_sold >> total.price >> total.discountRate){ 
		// we get the input, so we need to initialize the values for the current transaction
        total.revenue = total.PriceAfterDiscount() * total.units_sold;
		// variables to hold the running sum
		Sales_data_with_discount trans;
		while(std::cin >> trans.bookNo >> trans.units_sold >> trans.price >> trans.discountRate){
			// if "total" and "trans" refer to the same book
			if(total.isbn() == trans.isbn()){
			//update the running total
				total.combine(trans);
            }
            else{
			    // print the last transaction
                std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue <<  " " << total.price << std::endl;
                // refer to the next book
                total = trans;
	    	}
		}
	}
	else{
		std::cerr << "No data?!" << std::endl;
		// indicate failure
		return -1;
	}
	return 0;
}