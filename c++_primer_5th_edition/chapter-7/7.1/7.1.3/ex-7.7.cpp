//Exercise 7.7 Revise transaction-processing program with add, read and input
#include <iostream>
#include <string>
#include "ex-7.6.h"
int main(){
	// variable to hold data for the next transaction
    Sales_data_with_discount total;
	// as long as there is a new input, the transaction process keeps going
	if(read(std::cin, total)){ 
		// variables to hold the running sum
		Sales_data_with_discount trans;
		while(read(std::cin, trans)){
			// if "total" and "trans" refer to the same book
			if(total.isbn() == trans.isbn()){
			//update the running total
				total.combine(trans);
            }
            else{
			    // print the last transaction
                print(std::cout, total);
				std::cout << std::endl; 
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

