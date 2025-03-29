#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getPizzaPrice(string size) {
	if (size == "Small") {
		return 10;
	}
	else if (size == "Medium") {
		return 15;
	}
	else if (size == "Large") {
		return 20;
	}
	return 0;
}

double getToppingPrice(string topping) {
	if (topping == "Cheese") {
		return 1.5;
	}
	else if (topping == "Pepperoni") {
		return 2.5;
	}
	else if (topping == "Mushrooms") {
		return 2.0;
	}
	else if (topping == "Olives") {
		return 1.0;
	}
	else if (topping == "Bacon") {
		return 3.0;
	}
	else if (topping == "Peppers") {
		return 1.5;
	}
	return 0;
}

double getDrinkPrice(string drink) {
	if (drink == "Water") {
		return 1;
	}
	else if (drink == "Soda") {
		return 2;
	}
	else if (drink == "Juice") {
		return 3;
	}
	return 0;
}

double getDessertPrice(string dessert) {
	if (dessert == "Brownie") {
		return 4.0;
	}
	else if (dessert == "Cookie") {
		return 3.5;
	}
	else if (dessert == "Cheesecake") {
		return 5.0;
	}
	else if (dessert == "None") {
		return 0;
	}
	return 0;
}

void calculateTotal(double& totalPrice, double& pizzaPrice,
	string size, string topping1, string topping2, string topping3,
	int toppingCount, string drink, string dessert) {

	if (toppingCount == 1) {
		pizzaPrice = getPizzaPrice(size) + getToppingPrice(topping1);
	}
	if (toppingCount == 2) {
		pizzaPrice = getPizzaPrice(size) + getToppingPrice(topping1) + getToppingPrice(topping2);
	}
	if (toppingCount == 3) {
		pizzaPrice = getPizzaPrice(size) + getToppingPrice(topping1) + getToppingPrice(topping2) + getToppingPrice(topping3);
	}
	totalPrice += pizzaPrice + getDrinkPrice(drink) + getDessertPrice(dessert);


}

double applyDiscount(double totalPrice, double pizzaPrice, int toppingCount, string discountCode, double& discountAmount) {
	discountAmount = 0;
	if (toppingCount == 3) {
		discountAmount += 0.1 * pizzaPrice;
		totalPrice -= discountAmount;
	}
	if (discountCode == "Yes") {
		totalPrice -= 5;
		discountAmount += 5;
	}
	return totalPrice;

}

void printOrderSummary(double totalPrice, double pizzaPrice, double discountAmount, string size,
	string topping1, string topping2, string topping3,
	int toppingCount, string drink, string dessert, string discountCode)
{

	cout << fixed << setprecision(2);


	cout <<endl <<"Your order:" << endl;
	cout << "- " << size << " Pizza: $" << getPizzaPrice(size) << endl;

	if (toppingCount == 1) {
		cout << "- " << topping1 << " Topping: $" << getToppingPrice(topping1) << endl;
	}
	if (toppingCount == 2) {
		cout << "- " << topping1 << " Topping: $" << getToppingPrice(topping1) << endl;
		cout << "- " << topping2 << " Topping: $" << getToppingPrice(topping2) << endl;
	}

	if (toppingCount == 3) {
		cout << "- " << topping1 << " Topping: $" << getToppingPrice(topping1) << endl;
		cout << "- " << topping2 << " Topping: $" << getToppingPrice(topping2) << endl;
		cout << "- " << topping3 << " Topping: $" << getToppingPrice(topping3) << endl;
	}

	cout << "- Drink: " << drink << " ($" << getDrinkPrice(drink) << ")" << endl;

	if (dessert != "None") {
		cout << "- Dessert: " << dessert << " ($" << getDessertPrice(dessert) << ")" << endl;
	}


	if (toppingCount == 3) {
		cout << "- 10% discount on pizza applied: -$" << 0.1 * pizzaPrice << endl;
	}
	if (discountCode == "Yes") {
		cout << "- Discount code applied: -$5.00" << endl;
	}
	cout << "Final Total: $" << totalPrice << endl;
}

int main() {

	string discountCode;
	double discountAmount;
	double totalPrice;
	double pizzaPrice;
	string size;
	string topping1;
	string topping2;
	string topping3;
	int toppingCount;
	string drink;
	string dessert;

	cout << "Choose pizza size (Small/Medium/Large): ";
	cin >> size;

	cout << "How many toppings would you like? (1-3): ";
	cin >> toppingCount;

	cout << "Enter first topping (Cheese, Pepperoni, Mushrooms, Olives, Bacon, Peppers): ";
	cin >> topping1;
	if (toppingCount == 2) {
		cout << "Enter second topping: ";
		cin >> topping2;
	}
	else if (toppingCount == 3) {
		cout << "Enter second topping: ";
		cin >> topping2;
		cout << "Enter third topping: ";
		cin >> topping3;
	}
	cout << "Choose a drink (Water, Soda, Juice): ";
	cin >> drink;

	cout << "Would you like a dessert? (Brownie, Cookie, Cheesecake, None): ";
	cin >> dessert;

	cout << "Do you have a discount code? (Yes/No): ";
	cin >> discountCode;

	calculateTotal(totalPrice, pizzaPrice, size, topping1, topping2, topping3,
		toppingCount, drink, dessert);

	totalPrice = applyDiscount(totalPrice, pizzaPrice, toppingCount, discountCode, discountAmount);

	printOrderSummary(totalPrice, pizzaPrice, discountAmount, size, topping1, topping2, topping3, toppingCount, drink, dessert, discountCode);

	return 0;
}
