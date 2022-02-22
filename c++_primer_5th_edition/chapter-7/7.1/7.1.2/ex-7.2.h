//Exercise 7.2 Add isbn and combine 
#ifndef SALES_DATA_WITH_DISCOUNT_H
#define SALES_DATA_WITH_DISCOUNT_H
#include <string>
// My customized "Sales_data" class with a new data member "discount"
struct Sales_data_with_discount{
	std::string isbn() const{ return bookNo; }
	Sales_data_with_discount& combine(Sales_data_with_discount &rhs);
	double avg_price() const;
	double PriceAfterDiscount() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
	double discountRate = 0.0;
};

// wrap up the add part
Sales_data_with_discount& Sales_data_with_discount::combine(Sales_data_with_discount &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.PriceAfterDiscount() * rhs.units_sold;
    price = avg_price(); 
	return *this;
}

// wrap up the get average price part
double Sales_data_with_discount::avg_price() const{
	if(units_sold){
		return revenue / units_sold;
	}else{
		return 0;
	}
}

double Sales_data_with_discount::PriceAfterDiscount() const{
	return price * (1 - discountRate);
}
#endif