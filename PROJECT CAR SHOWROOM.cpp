#include<iostream>
#include<conio.h>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<fstream>
using namespace std;
string fileName;
void Starline();
void car_show(bool instalment);
void car_install(int price);
void Sign_up();
int choiceNo(string prompt);
void main_page();
void Help();
void About();
string Booked();
void Login();
void Homepage(string name);
void Exit();
void Book();
string console (string prompt);
void carSpecification(string name , int lowerMilage , int upperMileage , int horsepower,string mode,int price);

//----------------------------------------------------MAIN FUNCTION----------------------------------------------------------------------

int main(){
	cout<<" "<<setw(60)<<"*** HONDA ***"<<endl;
	cout<<"--------------------------------------------Welcome To Honda (Pakistan)-------------------------------------------------";
	Starline();
	cout<<"                 "<<"Experience the better version of power and speed with luxury cars from Honda Pakistan."<<endl;
	main_page();
}
/*This is the Defination of Main Page function this will be displayed at the begginning of the program.This will ask the user 
  if they want to register the new account of they want to login. With other options like : Help , About Us , Exit
*/
void main_page(){
	Starline();
	cout<<"\n-------MAIN MENU-------"<<endl;
    cout<<"\nChoose the Menu"<<endl;
    cout<<"(1) ===> Register "<<endl;
    cout<<"(2) ===> Log-in "<<endl;
    cout<<"(3) ===> Help "<<endl;
    cout<<"(4) ===> About us "<<endl;
    cout<<"(5) ===> Exit "<<endl;
    int Select = choiceNo("Enter the option: ");
    cout<<endl;
	if(Select==1)
	Sign_up();
    else if(Select==2)
    Login();
    else if(Select==3)
    Help();
    else if(Select==4)
    About();
    else if (Select==5)
    Exit();
    else
    cout<<"Please Select a Correct Option";
}
/* This will ask the user to input there detail like User-name , email , cnic and phone number and create a account for user */
void Sign_up(){    	
	string username,password,email,number,cnic,allData,filename;
	char check;
	Starline();
	cout<<"\n-----SIGN-UP------\n"<<endl;	
	cout<<"Enter the following information:"<<endl;
	username = console("User-name : ");
	password = console("Password : ");
	email = console("Email : ");
	number = console("Ph# : ");
	cnic = console("CNIC no: (Without \"-\"): ");
	allData = username +"\n"+password+"\n"+email+"\n"+number+"\n"+cnic;
	cout<<"\nIf you want to save the following information Press [Y]\nFor returning to the menu press [X]"<<endl;
	cin.sync();
	cin>>check;
	if(check=='Y'||'y'){
		filename = email+","+password+".txt";
	    ofstream file(filename.c_str());
	    file<<allData;
	    file.close();
	    cout<<"\nLOADING.....\nProcessing 100%\nYou have registered Successfully!\n"<<endl;
	    main_page();
	}
	else{
	    cout<<"\nRegistration denied return back to main menu\n"<<endl;
	    main_page();
	}
}
/* This will ask the user to input there email and password if the information is correct then the user get the access to buy car made by Zoha */
void Login(){                               
    Starline();
    cout<<"\n-------LOG IN-------"<<endl;
    string email, password , name;
    email = console("Enter your Email: ");
    password = console("Enter Your Password: ");
    string token =  email+","+password+".txt";
    fileName =   email+","+password;
    ifstream file(token.c_str());
    if(file.is_open()){
        file>>name;
    	cout<<"LOGGED IN\n"<<endl;
    	Homepage(name);
	}
        
    else{
        cout<<"Incorrect Email Address Or Password , Please try again"<<endl;
        int choice = choiceNo("Press 1 For Try Again /nPress 2 for returning to the Home Page");
        if(choice==1)
        Login();
        if(choice==2)
        main_page();
	}
}										//ZOHA
/* This function will ask the user if the want to Book a car or See their Booked Cars*/
void Homepage(string name){
	Starline();
	cout<<"\n-------HOME PAGE-------"<<endl;
    cout<<"\nWelcome Mr."<<name<<" to the HONDA showroom.\n\nSelect from following options."<<endl;
    cout<<"(1) ===> Book now"<<endl;
    cout<<"(2) ===> Booked Cars"<<endl;
    cout<<"(3) ===> Main Menu"<<endl;
    int Select = choiceNo("Select option: ");
    if(Select==1)
    Book();
    else if(Select==2){
        string booked = Booked();
        cout<<booked;
	}
           
    else if (Select==3)
    main_page();
    else
    cout<<"INVALID OPERATION"<<endl;
}
//This will help the user by providing the real website of honda car Showroom
void Help(){
    Starline();
    cout<<"\n-------HELP CENTER-------"<<endl;
    cout<<"\nFor Professional support visit our website: "<<endl;
    cout<<"https://www.honda.com.pk"<<endl;
    char check;
	cout<<"\n\n\n for Returning to the main menu press [X] : ";
	cin>>check;
	if(check=='X'||'x')
    main_page();
    else
    cout<<"INVALID OPERATION"<<endl;
}
//This function display who devloped this program
void About(){
    Starline();
    cout<<"\n-------ABOUT US-------\n\n";
	cout<<"HONDA SHOWROOM \nCP Project Program \nVersion:0.1"<<endl;
	cout<<"\nMembers:\nAreeb(20CS027)\nBhavesh(20CS065)\nZoha(20CS043)\nAlishba(20CS023)"<<endl;
	cout<<"\nFor queries contact us: \n20CS027@students.muet.edu.pk"<<endl;
	char check;
	cout<<"\n\n\n for Returning to the main menu press [X] : ";
	cin>>check;
	if(check=='X'||'x')
    main_page();
    else
    cout<<"INVALID OPERATION"<<endl;
}

/* This will ask the user if the want to buy a car on cash or  installment*/
void Book(){
	Starline();
	cout<<"\n-------BOOKING MENU-------"<<endl;
    cout<<"(1) ===> Purchase on installments"<<endl;
    cout<<"(2) ===>  Purchase by Cash-Payment"<<endl;
    int Check = choiceNo("Enter the option: ");
	if(Check==1){
    	Starline();
        cout<<"\n-------Booking by Installment-------"<<endl;
        car_show(true);	
}
    else if(Check==2){
    	Starline();
        cout<<"\n-------Booking by Cash-Payment-------"<<endl;
		car_show(false);
    }
    else{
    	Starline();
        cout<<"\nInvalid Entry , Please Try again"<<endl;
        Book();
    }
}
//This function will displlay the message of thankyou when some one exit the car showroom (Program)
void Exit(){
    Starline();
    cout<<"\nThanks for Visiting Honda (PAKISTAN)"<<endl;
}
//This will display lines of stars
void Starline(){
    cout<<setfill('*')<<setw(119)<<"";
}
/* This function will show the list of car and ask the usert which car they want to buy and ask the user which colour of car do you want*/
void car_show(bool instalment){
	char ch;
	int car_price[5]={2899000,11999000,3614000,3159000,4564000};
	string cars[5]={"Honda City 1.5LAS","Honda Accord", "Honda Civic 1.8L ","Honda BR-V","Honda Civic RS-Turbo"};
	int carprice[5] = {28990000,3300000,3500000,3200000,1200000};
	string payment[3]={"Cash","Debit Card", "Bank Transfer"};
	for(int i = 0; i < 5; i++){
 		cout <<i+1<<"\t"<<cars[i] << "\n";
	}
	cout<<"Let's Find Your Vechile First ! "<<endl;     
	int no = choiceNo("Press 1-5 to select your car: ");
	switch (no){
		case 1:
			carSpecification(cars[0],12,16,118,"Automatic",carprice[0]);
			break;
		case 2:
			carSpecification(cars[1],12,14,160,"Manual",carprice[1]);
			break;
		case 3:
			carSpecification(cars[2],10,12,180,"Manual",carprice[2]);
			break;
		case 4 :
			carSpecification(cars[3],10,14,150,"Automatic",carprice[3]);
			break;
		case 5:
			carSpecification(cars[4],16,18,100,"Manual",carprice[4]);
			break;
		default :
		cout<<"Please Select a Correct option"<<endl ;
	}
	cout<<"Avaible Colors: \n 1) Crystal Black\n 2) Taffeta White\n 3) Lunar Silver\n 4) Carnelian Red"<<endl;
	int no1 = choiceNo("Which Colour You Do you want to buy it? ");
	if(instalment)
	car_install(carprice[no-1]);
	
	cout<<"\nWe will send you car as per your Requirement  "<<endl;
	cout<<"\nDo you want to buy it  Y/N ? ";
	cin>>ch;
	if(ch=='y' || ch=='Y'){
		string fileName1 = fileName+","+"BookedCars.txt";
		string data = cars[no-1] +"\n"+ Booked()+"@"; 
		ofstream bookedcar(fileName1.c_str());
		bookedcar<<data;
		bookedcar.close();
		cout<<"\nCongratulation!  Thanks For Purchasing Our Car ."<<endl;
	}
	if(ch=='n' || ch=='N'){
	cout<<"Thanks for Visiting Us! "<<endl;
	main_page();
	}
}

//This function will genrate the installment plan if the user want to buy car with istallment made By Alishba Khan
void car_install(int price){
	Starline();
 	cout<<"\nInstalment Planes : "<<endl;
 	cout<<"How many year of instalment do you want"<<endl;
	int check = choiceNo("Enter no of your selected plan :");
	int months = 12*check;
	cout<<"You have to pay "<<price/months<<" every month for next "<<months<<" months"<<endl;	
}
//This function is used for prompting and taking input of string
string console(string prompt){
 	string data ;
 	cin.sync();
 	cout<<prompt;
 	getline(cin,data);
 	return data;
}
//This function is used for taking the choice from user
int choiceNo(string prompt){
	cout<<prompt<<endl;
	int no;
	cin>>no;
	return no;
}
//This function take the specfication of car as a parameter and diplayy it in formatted form.
void carSpecification(string name , int lowerMilage , int upperMileage , int horsepower,string mode,int price){
	cout<<"Car Name: "<<name<<"\t";
	cout<<"Fuel Average: "<<lowerMilage<<" to "<<upperMileage<<" MILEAGE (KM/LITER)"<<endl;
	cout<<"Horse Power: "<<horsepower<<"\t"<<"\t";
	cout<<"Mode: "<<mode<<endl;
	cout<<"Price: PKR "<<price<<"\n"<<endl;
}
//This function will read the file of booked car ofcurrrent user login
string Booked(){
	string books;
	string fileName2 = fileName+","+"BookedCars.txt";
	ifstream bookedcars(fileName2.c_str());
	if(bookedcars.is_open()){
		getline(bookedcars,books,'@');
		return books;
	}
	else
	return "";
}
