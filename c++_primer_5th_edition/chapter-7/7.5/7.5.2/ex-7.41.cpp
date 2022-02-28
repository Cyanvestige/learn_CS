/*Exercise 7.41: Rewrite your own version of the Sales_data class to use
delegating constructors. Add a statement to the body of each of the
constructors that prints a message whenever it is executed. Write
declarations to construct a Sales_data object in every way possible. Study
the output until you are certain you understand the order of execution among
delegating constructors.*/
#include <iostream>
#include <string>
// My customized "Sales_data" class with a new data member "discount"
class Sales_data_with_discount{
friend Sales_data_with_discount add(const Sales_data_with_discount&, const Sales_data_with_discount&);
friend std::ostream &print(std::ostream&, const Sales_data_with_discount&);
friend std::istream &read(std::istream&, Sales_data_with_discount&);
public:
	Sales_data_with_discount(const std::string &s, unsigned n, double p, double d): bookNo(s), units_sold(n), revenue(p*n), price(p), discountRate(d) { std::cout << "Delegated Root Constructor///";}
	Sales_data_with_discount(): Sales_data_with_discount("", 0, 0, 0){std::cout << "Default Constructor Called///"; }
    Sales_data_with_discount(const std::string &s): Sales_data_with_discount(s, 0, 0, 0){ std::cout << "One Parameter Constructor Called///"; }
	std::string isbn() const{ return bookNo; }
	Sales_data_with_discount& combine(const Sales_data_with_discount &rhs);
private:
	double avg_price() const;
	double PriceAfterDiscount() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
	double discountRate = 0.0;
};


/*
Output:
Delegated Root Constructor///Default Constructor Called///
Delegated Root Constructor///One Parameter Constructor Called///
Delegated Root Constructor///
*/
int main(){
    Sales_data_with_discount sdwd1;
    std::cout << std::endl;
	Sales_data_with_discount sdwd2("A");
    std::cout << std::endl;
	Sales_data_with_discount sdwd3("B", 2, 1, 0);
	return 0;
}