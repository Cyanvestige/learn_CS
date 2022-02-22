//Exercise 7.6 Define own version of add, read and input
#include <iostream>
#include <string>
// My customized "Sales_data" class with a new data member "discount"
struct Sales_data_with_discount{
	Sales_data_with_discount() = default;
	Sales_data_with_discount(const std::string &s): bookNo(s){ }
	Sales_data_with_discount(const std::string &s, unsigned n, double p, double d): 
								bookNo(s), units_sold(n), revenue(p*n), price(p), discountRate(d){ }
	std::string isbn() const{ return bookNo; }
	Sales_data_with_discount& combine(const Sales_data_with_discount &rhs);
	double avg_price() const;
	double PriceAfterDiscount() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
	double discountRate = 0.0;
};

// nonmember functions: add, read and print
Sales_data_with_discount add(const Sales_data_with_discount&, const Sales_data_with_discount&);
std::ostream &print(std::ostream&, const Sales_data_with_discount&);
std::istream &read(std::istream&, Sales_data_with_discount&);

// wrap up the add part
Sales_data_with_discount& Sales_data_with_discount::combine(const Sales_data_with_discount &rhs) {
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

Sales_data_with_discount add(const Sales_data_with_discount& lhs, const Sales_data_with_discount& rhs){
    Sales_data_with_discount sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data_with_discount& item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue <<  " " << item.avg_price();
    return os; 
}

std::istream &read(std::istream& is, Sales_data_with_discount& item){
    is >> item.bookNo >> item.units_sold >> item.price >> item.discountRate;
    item.revenue = item.PriceAfterDiscount() * item.units_sold;
    return is;
}

int main(){
	Sales_data_with_discount sdwd1;
	Sales_data_with_discount sdwd2("A");
	Sales_data_with_discount sdwd3("B", 2, 1, 0);
	print(std::cout, sdwd1);
	std::cout << std::endl;
	print(std::cout, sdwd2);
	std::cout << std::endl;
	print(std::cout, sdwd3);
	std::cout << std::endl;
}