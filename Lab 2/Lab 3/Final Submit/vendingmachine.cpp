#include <iostream>
using namespace std;

#define types 3
#define initial_quantity 5

class VendingMachine {
	int drink_quantity_list[types];			//list of items
	int chips_quantity_list[types];			//alongwith quantity available
	int chocolate_quantity_list[types];		
	int price;

public:

	VendingMachine(){	//constructor. initialises as per macros
		for(int i=0; i<types; i++){
			drink_quantity_list[i]=initial_quantity;
			chips_quantity_list[i]=initial_quantity;
			chocolate_quantity_list[i]=initial_quantity;
		}
		price=0;
	}
	void resetprice(){
		price=0;
	}

	void select_drink();		//provide list and selection
	void select_chips();		//by the user from the list
	void select_chocolate();	//5 options available
	
	void order(int selection, int type);//Fetch the item & add cost;

	void addprice(int cost){
		price+=cost;
	}
	int bill_amount(){
		return price;
	}
};

void VendingMachine::select_drink(){
		int selection; 

		cout<<"Please enter the drink number-\n";
		cout<<"0- Fanta\n"
			<<"1- Sprite\n"
			<<"2- Coca-Cola\n"
			<<"3- Pepsi\n"
			<<"4- 7-Up\n";

		cin>>selection;
		if(selection==-1){
			return;
		}
		order(selection, 1);
}

void VendingMachine::select_chips(){
		int selection; 

		cout<<"Please enter the chips number-\n";
		cout<<"0- Lays\n"
			<<"1- Kurkure\n"
			<<"2- Bingo\n"
			<<"3- Pringles\n"
			<<"4- Doritos\n";

		cin>>selection;
		if(selection==-1){
			return;
		}
		order(selection, 2);
}

void VendingMachine::select_chocolate(){
		int selection; 

		cout<<"Please enter the chocolate number-\n";
		cout<<"0- Dairy Milk\n"
			<<"1- Milky Bar\n"
			<<"2- Bournville\n"
			<<"3- Perk\n"
			<<"4- 5 Star\n";

		cin>>selection;
		if(selection==-1){
			return;
		}
		order(selection, 3);
}

void VendingMachine::order(int selection, int type){//checks for availability of item and price management

	if(type==1){	//for drink
		if(drink_quantity_list[selection]>0){
			cout<<"It's Ready! That costs 100 rupees\n";
			addprice(100);
			drink_quantity_list[selection]--;
		}
		else{
			cout<<"Oh sorry! We are out. Please enter a different number or enter -1 to go back to main menu.";
			select_drink();
	}}
		
	else if(type==2){	//for chips
		if(chips_quantity_list[selection]>0){
			cout<<"It's Ready! That costs 20 rupees\n";
			addprice(20);
			chips_quantity_list[selection]--;
		}
		else{
			cout<<"Oh sorry! We are out. Please enter a different number or enter -1 to go back to main menu.";
			select_chips();
	}}

	else if(type==3){	//for chocolate
		if(chocolate_quantity_list[selection]>0){
			cout<<"It's Ready! That costs 50 rupees\n";
			addprice(50);
			chocolate_quantity_list[selection]--;
		}
		else{
			cout<<"Oh sorry! We are out. Please enter a different number or enter -1 to go back to main menu.";
			select_chocolate();
		}}
	

}



int main () {

	VendingMachine v1;

	char cmd; 		//manage input
	int money_entered;
	int balance;
	bool balance_less=true;

cout<<"Hello, Welcome to the Vending Machine.\n";

while(balance_less){

cout<<"Please enter the money amount into the machine.\n";

cin>>money_entered;

cout<<"Enter d to order a drink.\n"
	<<"Press c to order a packet of chips.\n"
	<<"Press b to order a bar of chocolate.\n"
	<<"Press f to finish the order\n";

cin>>cmd;

    while(cmd!='f'){

        switch(cmd) {  

            case 'd':       //drink
				v1.select_drink();
                break;

            case 'c':		//chips
				v1.select_chips();
				break;
            case 'b':		//chocolate
				v1.select_chocolate();
				break;
            default:
                cout<<"Please follow the instructions.\n";
        }
		cout<<"Press d, c or b to order more. f to checkout\n";
		cin>>cmd;
	}

	balance=money_entered-v1.bill_amount();

	if(balance>=0){
		balance_less=false;
		cout<<"Here is the balance amount "<<balance<<" Rupees.\n";
	}
	else{
		cout<<"Sorry, your order exceeds you initial amount. Please start again.\n";
		cout<<"Here are your initial "<<money_entered<<" Rupees.\n";
	}
}
cout<<"Thank you for visiting! Have a nice day!\n";

v1.resetprice();

}
