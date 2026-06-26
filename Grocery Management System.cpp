/*****************************************************************
 * @file        Grocery Management System.cpp
 * @brief       Interactive Console-Based Grocery Shopping Application
 * @author      Saad Ayub
 * @institution UET Lahore (University of Engineering and Technology)
 * @department  Computer Science and Engineering
 * @date        June 2026
 * 
 * @details     An object-oriented C++ program utilizing class inheritance, 
 *              encapsulation, and dynamic vector stream structures to 
 *              simulate real-time inventory and shopping cart management.
 *****************************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;
class Product {
public:
    string name;
    double price;

    Product(string itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
    }
};
class Item : public Product {
public:
    int quantity;

    Item(string itemName, double itemPrice, int itemQuantity)
        : Product(itemName, itemPrice) {
        quantity = itemQuantity;
    }
};


class Cart 
 {
 	
private:
    vector<Item> items;
    vector<int> quantities;

public:
    void addItem(Item item, int quantity)
	 {
	 	
        bool found = false;
        for (size_t i = 0; i < items.size(); i++)
		 {
		 	
            if (items[i].name == item.name)
			 {
			 	
                quantities[i] += quantity;
                found = true;
                break;
                
            }
            
        }


        if (!found)
		 {
		 	
            items.push_back(item);
            quantities.push_back(quantity);
            
        }
        
    }


    void removeItem(int index, int removeQuantity, vector<Item>& inventory) 
	{
		
        if (removeQuantity <= 0 || removeQuantity > quantities[index]) 
		{
			
			cout<<endl;
            cout << "Invalid quantity!";
            cout<<endl;
            return;
            
        }


        quantities[index] -= removeQuantity;
        for (size_t i = 0; i < inventory.size(); i++) 
		{
			
            if (inventory[i].name == items[index].name)
			 {
			 	
                inventory[i].quantity += removeQuantity;
                break;
                
            }
            
        }


        if (quantities[index] == 0) 
		{
			
            items.erase(items.begin() + index);
            quantities.erase(quantities.begin() + index);
            
        }
        
    }


    void displayCart()
	 {
	 	
        double totalCost = 0.0;
        cout<<endl;
        cout << "Your Selected Items:";
        cout<<endl;
        cout << "_____________________________________________________________";
        cout<<endl;
        cout << "| No  | Item Name                           | Price   | Qty |";
        cout<<endl;
        cout << "_____________________________________________________________";
        cout<<endl;


        for (size_t i = 0; i < items.size(); i++)
		 {
		 	
            cout << "| " << setw(3) << left << i + 1 << " | "
                 << setw(35) << left << items[i].name << " | $"
                 << setw(6) << fixed << setprecision(2) << items[i].price << " | "
                 << setw(3) << quantities[i] << " |" << endl;
            totalCost += items[i].price * quantities[i];
            
        }

        cout << "_____________________________________________________________";
        cout<<endl;
        cout << "Total: $" << fixed << setprecision(2) << totalCost;
        cout<<endl;
        
    }


    vector<Item> getItems()
	 {
        return items;
     }


    double getTotalCost()
	 {
	 	
        double totalCost = 0.0;
        for (size_t i = 0; i < items.size(); i++)
		 {
		 	
            totalCost += items[i].price * quantities[i];
            
        }
        return totalCost;
        
    }
    
};


class Shop 
{
	
private:
	
    vector<Item> vegetables;
    vector<Item> fruits;
    vector<Item> bakery;
    Cart cart;
    double budget;

public:
	
    Shop(double userBudget)
    
	 {
	 	
        budget = userBudget;

        vegetables =
        
		 {
             Item("Carrot", 2.99, 50), Item("Potato", 1.99, 60), Item("Tomato", 2.49, 55),
            Item("Cucumber", 1.89, 40), Item("Broccoli", 3.29, 30), Item("Spinach", 2.59, 45),
            Item("Onion", 1.59, 70), Item("Garlic", 3.99, 60), Item("Lettuce", 2.99, 50),
            Item("Bell Pepper", 2.49, 40), Item("Zucchini", 1.89, 30), Item("Eggplant", 2.79, 25),
            Item("Sweet Potato", 2.99, 45), Item("Cauliflower", 3.49, 30), Item("Kale", 2.19, 50),
            Item("Green Beans", 2.39, 60), Item("Asparagus", 4.49, 25), Item("Peas", 1.99, 70),
            Item("Cabbage", 1.79, 65), Item("Radish", 1.59, 90), Item("Chili", 1.79, 40),
            Item("Artichoke", 4.19, 30), Item("Leeks", 2.59, 35), Item("Parsnip", 2.69, 40),
            Item("Celery", 1.89, 50), Item("Chard", 2.99, 30), Item("Brussels Sprouts", 3.79, 25),
            Item("Turnip", 1.69, 60), Item("Mustard Greens", 2.19, 30), Item("Fennel", 3.39, 40),
            Item("Rutabaga", 2.49, 50)
            
        };


        fruits =
        
		 {
           Item("Apple", 1.99, 100), Item("Banana", 0.79, 120), Item("Orange", 2.49, 90),
            Item("Grapes", 2.99, 85), Item("Mango", 3.49, 50), Item("Pineapple", 4.99, 25),
            Item("Peach", 2.89, 60), Item("Watermelon", 5.99, 20), Item("Strawberry", 4.49, 50),
            Item("Blueberry", 3.79, 30), Item("Raspberry", 5.19, 20), Item("Cherry", 3.99, 45),
            Item("Kiwi", 2.29, 70), Item("Plum", 2.79, 80), Item("Papaya", 3.49, 60),
            Item("Apricot", 3.99, 50), Item("Pear", 2.59, 90), Item("Lemon", 1.99, 100),
            Item("Cantaloupe", 4.49, 25), Item("Fig", 5.49, 30), Item("Dragon Fruit", 6.99, 15),
            Item("Blackberry", 4.19, 40), Item("Clementine", 3.49, 50), Item("Tangerine", 2.89, 70),
            Item("Nectarine", 3.59, 40), Item("Pomegranate", 5.19, 25), Item("Jackfruit", 7.49, 20),
            Item("Grapefruit", 2.69, 60), Item("Pluot", 3.99, 30), Item("Goji Berries", 9.99, 15)
            
        };


        bakery =
        
		 {
          Item("Bread", 1.99, 100), Item("Cake", 5.99, 50), Item("Cookies", 3.99, 75),
            Item("Croissant", 2.49, 60), Item("Donut", 1.49, 90), Item("Muffin", 2.19, 70),
            Item("Bagel", 1.69, 80), Item("Biscuit", 1.89, 85), Item("Cupcake", 2.99, 45),
            Item("Pie", 4.49, 25), Item("Brownie", 3.79, 40), Item("Cinnamon Roll", 2.79, 30),
            Item("Scone", 2.59, 55), Item("Danish", 3.29, 60), Item("Tart", 3.49, 20),
            Item("Eclair", 3.19, 50), Item("Shortbread", 2.99, 65), Item("Churro", 2.79, 30),
            Item("Strudel", 4.19, 40), Item("Pancake", 3.49, 50), Item("Lemon Cake", 5.29, 20),
            Item("Carrot Cake", 4.89, 30), Item("Apple Pie", 3.79, 25), Item("Peach Cobbler", 4.99, 15),
            Item("Cheesecake", 6.49, 10), Item("Pumpkin Bread", 3.59, 30), Item("Raisin Bread", 2.69, 40),
            Item("Chocolate Chip Cookies", 4.29, 50), Item("Baklava", 5.49, 15), Item("Madeleine", 3.89, 25)
            
        };
        
    }


    void displayItems(const vector<Item>& items) 
	{
		
		cout<<endl;
        cout << "Available items:";
        cout<<endl;
        cout << "_____________________________________________________________";
        cout<<endl;
        cout << "| No  | Item Name                           | Price   | Qty |";
        cout<<endl;
        cout << "_____________________________________________________________";
        cout<<endl;


        for (size_t i = 0; i < items.size(); i++)
		 {
		 	
            cout << "| " << setw(3) << left << i + 1 << " | "
                 << setw(35) << left << items[i].name << " | $"
                 << setw(6) << fixed << setprecision(2) << items[i].price << " | "
                 << setw(3) << items[i].quantity << " |";
                 cout<<endl;
                 
        }
        
        cout << "_____________________________________________________________";
        cout<<endl;
    }


    vector<Item>& findInventory(const string& itemName)
	 {
	 	
        for (Item& item : vegetables)
            if (item.name == itemName) return vegetables;
        for (Item& item : fruits)
            if (item.name == itemName) return fruits;
        return bakery;
        
    }


    vector<Item> getItems()
	 {
        return cart.getItems();
     }


    void shop()
	 {
	 	
        char mainMenuChoice;
        do 
		{
			
            char continueShopping = 'y';
            while (continueShopping == 'y' || continueShopping == 'Y')
			 {
			 	
                int categoryChoice;
                cout << "\nSelect a category:";
                cout<<endl;
                cout << "1. Vegetables\n2. Fruits\n3. Bakery";
                cout<<endl;
                cout<<endl;
                cout << "Enter your choice (1, 2, or 3): ";
                cin >> categoryChoice;


                vector<Item>* selectedCategory = nullptr;
                if (categoryChoice == 1) selectedCategory = &vegetables;
                else if (categoryChoice == 2) selectedCategory = &fruits;
                else if (categoryChoice == 3) selectedCategory = &bakery;
                else
				 {
				 	
				 	cout<<endl;
                    cout << "Invalid selection!";
                    cout<<endl;
                    continue;
                    
                }


                displayItems(*selectedCategory);

                int itemNumber, itemQuantity;
                cout<<endl;
                cout << "Enter the item number to add to your cart: ";
                cin >> itemNumber;
                if (itemNumber < 1 || itemNumber > selectedCategory->size())
				 {
				 	
				 	cout<<endl;
                    cout << "Invalid selection!";
                    cout<<endl;
                    continue;
                    
                }


                cout<<endl;
                cout << "Enter the quantity you want to add: ";
                cin >> itemQuantity;
                if (itemQuantity <= 0 || itemQuantity > (*selectedCategory)[itemNumber - 1].quantity) 
				{
					
					cout<<endl;
                    cout << "Invalid quantity!";
                    cout<<endl;
                    continue;
                    
                }


                (*selectedCategory)[itemNumber - 1].quantity -= itemQuantity;
                cart.addItem((*selectedCategory)[itemNumber - 1], itemQuantity);


                double totalCost = cart.getTotalCost();
                if (totalCost > budget) 
				{
					
					cout<<endl;
                    cout << "Warning: Your total amount has exceeded your budget!";
                    cout<<endl;


                    char confirm;
                    cout<<endl;
                    cout << "Do you still want to continue shopping? (y/n): ";
                    cin >> confirm;

                    if (confirm != 'y' && confirm != 'Y')
					 {
					 	
					 	cout<<endl;
                        cout << "\nShopping session ended due to budget limit.\n";
                        return;  // Ends the shop() function early
                        
                    }
                    
                }


                cart.displayCart();

                cout<<endl;
                cout << "Do you want to add more items to your cart? (y/n): ";
                cin >> continueShopping;
                
            }


            char removeItemChoice;
            cout<<endl;
            cout << "Do you want to remove any items from your cart? (y/n): ";
            cin >> removeItemChoice;


            if (removeItemChoice == 'y' || removeItemChoice == 'Y') 
			{
				
                int removeItemNumber, removeQuantity;
                cart.displayCart();
                cout<<endl;
                cout << "Enter the item number to remove: ";
                cin >> removeItemNumber;


                if (removeItemNumber < 1 || removeItemNumber > cart.getItems().size()) 
				{
					
					cout<<endl;
                    cout << "Invalid selection!" << endl;
                    
                } 
				else
				 {
				 	
				 	cout<<endl;
                    cout << "Enter the quantity to remove: ";
                    cin >> removeQuantity;
                    Item selectedItem = cart.getItems()[removeItemNumber - 1];
                    vector<Item>& inventory = findInventory(selectedItem.name);
                    cart.removeItem(removeItemNumber - 1, removeQuantity, inventory);
                    cart.displayCart();
                    
                }
                
            }


            cout<<endl;
            cout << "\nDo you want to go back to the main menu? (y/n): ";
            cin >> mainMenuChoice;


        } 
		
		while (mainMenuChoice == 'y' || mainMenuChoice == 'Y');
    }

    double getCartTotal() 
	{
        return cart.getTotalCost();
    }
    
};


int main()
 {
 	
    string userName;
    double budget;

    cout << "Enter your name: ";
   
    getline(cin, userName);

     cout<<endl;
    cout << "Enter your budget: $";
    cin >> budget;

    cout << endl;
    cout << "Enjoy a 15% discount on purchases over $30!" << endl;

    Shop shop(budget);
    shop.shop();


    double finalTotal = shop.getCartTotal();
    double discount = 0.0;
    double discountedTotal = finalTotal;


    if (finalTotal >= 30.0) 
	{
		
        discount = finalTotal * 0.15;
        discountedTotal = finalTotal - discount;
        
    }



    ofstream outFile("purchase_summary.txt", ios::app);  // Appending mode
    
    if (outFile.is_open()) 
	{
        outFile << "\n================ CUSTOMER ENTRY =================\n";
        outFile << "Customer Name: " << userName << endl;
        outFile << "Budget: $" << fixed << setprecision(2) << budget << endl;
        outFile << "--------------------------------------------" << endl;
        outFile << "Purchased Items:" << endl;


        vector<Item> items = shop.getItems();
        for (const Item& item : items)
		 {
            outFile << "- " << item.name
                    << " | Price: $" << fixed << setprecision(2) << item.price
                    << " | Quantity: " << item.quantity << endl;
        }


        outFile << "--------------------------------------------" << endl;
        outFile << "Total Before Discount: $" << fixed << setprecision(2) << finalTotal << endl;
        if (discount > 0.0)
		 {
		 	
            outFile << "Discount (15%): -$" << fixed << setprecision(2) << discount << endl;
            
        }
		 else 
		 {
		 	
            outFile << "Discount: $0.00 (Not eligible)" << endl;
            
        }
        
        outFile << "Final Amount: $" << fixed << setprecision(2) << discountedTotal << endl;
        outFile << "=================================================\n";
        outFile.close();
        cout << "\nYour purchase summary has been saved to 'purchase_summary.txt'" << endl;
    }
	 else 
	 {
	 	
        cout << "Error writing to file!" << endl;
        
    }


    cout << "\n====================================" << endl;
    if (discount > 0.0)
	 {
	 	
        cout << "You spent $" << fixed << setprecision(2) << finalTotal << " in total." << endl;
        cout << "You got a 15% discount of $" << fixed << setprecision(2) << discount << "!" << endl;
        cout << "Total amount after discount: $" << fixed << setprecision(2) << discountedTotal << endl;
        
    }
	 else 
	 {
	 	
        cout << "Total amount spent: $" << fixed << setprecision(2) << finalTotal << endl;
        cout << "No discount applied (minimum $30 required)." << endl;
        
    }
    
    cout << "====================================" << endl;

    return 0;
}
    

