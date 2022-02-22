//exercise 7.1
// My customized "Sales_data" class with a new data member "discountRate", and the price will be the value after the discount is applied
#include <iostream>
struct Sales_data_with_discount{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
	double discountRate = 0.0;
};

int main(){
	// variable to hold data for the next transaction
    Sales_data_with_discount total;
	// as long as there is a new input, the transaction process keeps going
	if(std::cin >> total.bookNo >> total.units_sold >> total.price >> total.discountRate){ 
		// we get the input, so we need to initialize the values for the current transaction
        total.revenue = total.price * (1 - total.discountRate) * total.units_sold;
		// variables to hold the running sum
		Sales_data_with_discount trans;
		while(std::cin >> trans.bookNo >> trans.units_sold >> trans.price >> trans.discountRate){
			// if "total" and "trans" refer to the same book
			if(total.bookNo == trans.bookNo){
			//update the running total
                total.units_sold += trans.units_sold;
				total.revenue += trans.price *(1 - trans.discountRate) * trans.units_sold;
                total.price = total.revenue / total.units_sold;  
            }
            else{
			    // print the last transaction
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue <<  " " << total.price << std::endl;
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

