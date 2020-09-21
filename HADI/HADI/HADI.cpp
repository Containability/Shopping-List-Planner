/*

Shopping List Planner

Description of the project: ..........
*/


#include <iostream>
#include <vector>
#include <string>
#include<limits>
using namespace std;
class ShoppingList
{
public:
	
	int list_id=0;
	string listname;
	
};
class Products: public ShoppingList
{ 
public:
	int amount=0;
	string name;
	bool done = false;
	
};
bool validName(string name)
{
	if (name.length() == 0)
	{
		cout << "This is emptyness!";
		return false;
	}
		

	
	if (name[0] >= '0' && name[0] <= '9' && name.length() < 2) //So i programmed this function as i supposed that no one enter more then 3-digit number because my one product list can has max 200 products.
	{
		cout << "there is number in it";
		return false;
	}
	return true;
}


int main() {
	
	vector<ShoppingList> List (10);
	vector<Products> P(200);
	vector<vector<Products>> Product(10);
	bool first_time = true;
	int index_l = 0;
	int index_p = 0;
	
	/* BeeCay is kind of an abbreviation/nickname for "BK" which are the first letters of my name&surname.So just wanted to set my planner's name up as it is.*/
ListsMenu:
	if (first_time) {
		cout << "Welcome to your beloved shopping list BeeCay to save your day! ";


		cout << "Before creating a list, Enter the name you wish for your list: ";

		string list_name;



		getline(cin, list_name);
		cin.clear();
		cout << "Your list's name : " << list_name << "\n";
		List[index_l].listname = list_name;
		List[index_l].list_id = index_l + 1;
		first_time = false;
	}
	else {
		int counter = 0;
		cout << "List Id" << "	|	" << "List Name \n";
		for (std::vector<ShoppingList>::iterator it = List.begin(); it != List.end(); ++it) {
			if (List[counter].list_id == 0)
			{
				break;
			}
			cout << counter + 1 << "	|	" << List[counter].listname << "	   | \n";

			counter++;
		}
		cout << "If you would like to create a new list type 'New' \n";


		cout << "If you would like to enter a list type it's name \n";

		cout << "If you would like to delete a list. Type 'Delete' and program will ask you it's name \n";
		cout << "To exit type exit \n";
		cout << "Your command: "<<"\n";
		string list_name;
		string says;

		getline(cin, says,'\n');
		
		cin.clear();

		if (says == "New" || says == "new")
		{
			index_l++;
			cout << "Please enter your list's name: ";
			
			getline(cin, list_name,'\n');
			
			cout << "Your list's name : " << list_name << "\n";
			List[index_l].listname = list_name;
			List[index_l].list_id = index_l + 1;
			P.clear();
			P.resize(200);
		} 
		else if (says == "Delete" || says == "delete")
		{
			string id_delete;
			cout << "Type your list's id: ";
			cin >> id_delete;
			cin.ignore();
			int digits2 = 1;
			int sum2 = 0;
			for (int a = id_delete.length(); a > 0; a--) //This loop is for turning string to a number . Digit is the length of the string. the variable 'digits' is the numbers on the digits. Not the digit of id.
			{
				digits2 = (id_delete[id_delete.length() - a] - '0');
				for (int x = 1; x < a; x++)
				{
					digits2 *= 10;
				}
				sum2 += digits2;
			}
			List.erase(List.begin() + sum2-1);
			index_l--;
		
			goto ListsMenu;
		}
		else if (says == "Exit" || says == "exit")
		{
			return 0;
		}
		else 
		{
			
			bool flag = false;
			cout << "You entered to the list : "<<says;
			int ii = 0;
			for (std::vector<ShoppingList>::iterator it = List.begin(); it != List.end(); ++it) {
				if (List[ii].listname == says)
				{
					P = Product[List[ii].list_id - 1];
					
					flag = true;
					break;
				}
				ii++;

			}
			if (!flag)
			{
				cout << "You entered wrong name.";
				goto ListsMenu;
		}
		
		}
	
	
	}
	  InListMenu:
	   cout << "Now you can write or edit products for your list. To write a new product: write it's name then program will ask you some other informations \n To edit: write it's number and you will see the further instructions there.\n If you want to go back to lists menu type 'Back' . \n To exit type 'exit' \n";
	  
	   string product_in="";
	   int aa=-1;
	   while (1){
		   
		  
		   for (std::vector<Products>::iterator it = P.begin(); it != P.end(); ++it) {
			   aa++;
			   if (P[aa].amount == 0)
			   {
				   break;
			   }
			   

			  
		   }
		   string status1;
		   int print=0;
		   for (std::vector<Products>::iterator it = P.begin(); it != P.end(); ++it) {
			   status1 = P[print].done ? "(X)" : "( )";
			   if (P[print].amount == 0)
			   {
				   break;
			   }
		cout << print  + 1 << "	|	" << P[print].name << "	   |		" << status1 << "	|		" << P[print].amount << "		| 		 \n";

			   print++;
		   }
		   index_p = aa;
		   cout << "To new product: it's name \n To edit product(Has delete in it): it's id \n";
		   getline(cin, product_in,'\n');
		   
		   P[index_p].list_id = index_l + 1;
		   P[index_p].name = product_in;
		   if (product_in == "Exit" || product_in=="exit") {
			   return 0;
		        }
		   if (validName(product_in) && product_in!="Exit")
		   {
			   if (product_in == "print")
			   {
				   break;
			   }
			   if (product_in == "Back") {
				   Product[P[0].list_id - 1] = P;
				   goto ListsMenu;



			}
				   cout << "Please type the requirements for your new product.\n";
			  

			 

			   cout << "\n What is the amount of your product: ";
			   cin >> P[index_p].amount;
			   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			   index_p++;
		        }



		   else if (product_in.length() > 0) {
			   string decision;
			   int digits = 1;
			   int sum = 0;
			   for (int a = product_in.length(); a > 0; a--) //This loop is for turning string to a number with ASCII representatives. Digit is the length of the string. the variable 'digits' is the numbers on the digits. Not the digit of id.
			   {
				   digits = (product_in[product_in.length() - a] - '0');
				   for (int x = 1; x < a; x++)
				   {
					   digits *= 10;
				   }
				   sum += digits;
			   }
			   index_p = sum - 1; //This is the index for vector P and that is the vector of products in a list.




			   cin.clear();
			   string status;
			   status = P[index_p].done ? "(X)" : "( )";
			   cout << "This is your product: \n ";
			   cout << "Name	 |		Done	|		Amount		| 		 " << "\n";

			  

			   cout << "\n What do you want to edit for this product?\n Type Name or Done or Amount or Delete to delete the product: \n 1.Name \n 2.Do Mark checked\n 3.Amount\n 4. Delete\n";
			   cin >> decision, '\n';

			   if (decision == "1")
			   {
				   cout << "Type the name you want: ";
				   cin >> P[index_p].name;


			   }
			   else  if (decision == "2") {

				   cout << "The item checked.\n";
				   P[index_p].done = true;

			   }
			   else if (decision == "3") {

				   cout << "Type the amount you want: ";
				   cin >> P[index_p].amount;

			   }
			   else if (decision == "4")
			   {
				   P.erase(P.begin() + index_p);
				   cout << "Product deleted from list.";
			   }
			   else {

				   cout << "You typed something wrong.";

			   }

		   }
		   else { 
			   
			   goto InListMenu; 
		   }
	  }  
		   cout << "\n";
			cout << "This is what you get : \n";
	   cout<<"Id"<<"	|	" << "Name	   |		Category	|		Amount		| 		 " << "\n";
	   int i = 0;
	   
	   
	   

	   string status1;
	   for (std::vector<Products>::iterator it= P.begin(); it != P.end(); ++it) {
		   status1 = P[i].done ? "(X)" : "( )";
		   if (P[i].amount == 0)
		   {
			   break;
		   }
		   cout<<i+1<<"	|	" << P[i].name << "	   |		" << status1<< "	|		" << P[i].amount << "		| 		 \n";
		  
		   i++;
	   }
	  
	  
	   
		   Product[P[0].list_id - 1] = P;
		   goto InListMenu;
	   
	   

	   


	return 0;
}

