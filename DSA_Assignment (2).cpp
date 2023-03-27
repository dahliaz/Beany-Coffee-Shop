/******************************************************************************
  Subject code : CSEB3213/CSEB324/CSNB344 Data Structure & Algorithms 
  Section      : 03
  Student name : Nur Adilah binti Zainal Abidin
		             Ahmad 'Ariff bin Anwar
		             Muhammad Naim Mustaqim bin Rajhan
  Student ID   : SW01081031
		             SW0106690
		             CS01081220
  Title        : Beany Coffee Order System
  Proposed ADT : Queue (FIFO)
*******************************************************************************/
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;    

//Add Function - Chang
struct Order {
    public:
    int orderID = 0;
    int orderQty = 0;
    float total = 0.00;
    Order *next;
};

Order *orderData(int no) {
    
    int item, num, i = 0;
    float price;
    Order *o = new Order();
    o->orderID = no;
    
    cout << "\n1. Espresso\t:\tRM 4.00"
            "\n2. Latte\t:\tRM 4.50"
            "\n3. Cappuccino\t:\tRM 4.50"
            "\n4. Boba\t\t:\tRM 5.10";
    
    cout << "\nHow many drinks you would you like to order?: ";
    cin >> num;
    while (i < num) {
        while (1) {
            cout << "\nEnter the number for the item: ";
            cin >> item;
            if(item == 1 || item == 2 || item == 3 || item == 4){
                cout << "You ordered a/an: ";
                if(item == 1){
                    cout << "Espresso\n";
                    price = 4.00;
                    break;
                }
                    
                else if(item == 2){
                    cout << "Latte\n";
                    price = 4.50;
                    break;
                }
                    
                else if(item == 3){
                    cout << "Cappuccino\n";
                    price = 4.50;
                    break;
                }
                else if(item == 4){
                    cout << "Boba\n";
                    price = 5.10;
                    break;
                }
            }
                else{
                    cout << "Invalid input. Please enter 1-4 for items.\n";
                }
        }
        while (1) {
            cout << "Quantity: ";
            cin >> o->orderQty;
            if (o->orderQty > 0) 
                break;
        }
        
        o->total += o->orderQty * price;
        i++;
    }
    o->next = NULL;
    
    return o;
}

void addOrder(Order** front, Order** rear, int no) {
    
    Order *o = orderData(no); // no comes from for loop when ask how many orders 
    
    if (*front == NULL) {
        *front = *rear = o;
    }

    else {
        (*rear)->next = o;
        *rear = o;
    }
}

//Update Function - Adilah 
void updateOrder(Order** front) {
    
    int id, cate;
    Order *o = *front;
    cout << "Enter order ID: ";
    cin >> id;
    while (o->orderID != id) {
        o = o->next;
        if (o == NULL) {
            cout << "Order ID doesn't exist." << endl;
            break;
        }
    }
    cout << "\n1. Alumni\t:\t35%\n2. Lecturer\t:\t45%\n3. Student\t:\t15%" << endl;
    do{
        cout << "Enter the category: ";
        cin >> cate;
        switch(cate){
            case 1:
                o->total = o->total-(o->total*0.35);
                break;
            case 2:
                o->total = o->total-(o->total*0.45);
                break;
            case 3:
                o->total = o->total-(o->total*0.15);
                break;
            default:
                cout << "Invalid input. Please enter 1-3 for items.\n";
                break;
        }
    }while(cate != 1 && cate != 2 && cate != 3);
}

//Delete Function - Adilah
void deleteOrder(Order** front, Order** rear) {
    Order *temp;
    while(*front != NULL){
        temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    if(*front == NULL){
        *rear = NULL;
    }
    cout << "==ALL RECORDS HAVE BEEN DELETED==" << endl;
}

//Display Function - Naim 
void displayOrder(Order** front) {
    Order* o = *front;
    cout<<"\nYour Order Details:- \n";
    if (*front == NULL) {
        cout<<"\nQueue is empty"<<endl;
    }
    while (o != NULL) {
        cout << endl;
        cout <<"Order ID: "<< o-> orderID<<endl;
        cout <<"Order Quantity: " << o->orderQty<<endl;
        cout <<"Total: RM"<< fixed << setprecision(2) << o->total<<endl; 

        o = o->next;
    }
    cout<<endl;
}

//Menu Function - Chang
int Menu() {
	int choice;
	
	cout << "\n::Beany Coffee Order System::\n";
	
	cout << "1. Add order\n";
	cout << "2. Update order(Discount)\n";
	cout << "3. Delete order\n";
	cout << "4. Display/Print order\n";
	cout << "5. Exit program\n";
	cout << "Enter choice: ";
	cin >> choice;
	
	return choice;
}

//Main Function - Naim
int main () {

    int choice, no = 0;
    float gross = 0.00;
	Order *front = NULL;
	Order *rear = NULL;
	do {
		choice = Menu();
		switch (choice) {
		    
		    case 1: 
	        no += 1; 
	        addOrder(&front, &rear, no);
		    break;
		    
		    case 2:
		    updateOrder(&front);
		    break;
		    
		    case 3: 
		    deleteOrder(&front, &rear); 
		    break;
		    
		    case 4: 
		    displayOrder(&front);
		    break;
		    
		    default:
            cout << "Invalid input. Please enter 1-4 to navigate menu, 5 to exit.\n";
            break;
		    
		}
	} while (choice != 5);
	
	
	return 0;
}