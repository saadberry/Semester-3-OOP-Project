// 04/12/20 - work on checkDetails class. getting info and writng to file has already been implemented. 

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
//#include "displaytime.h"
#include <cstring>
#include <fstream>

using namespace std;
//#define RAND_MAX 1000

//name,DOB,address,

class customer{
    private: string name,address; // name,address of customer
   string status;
   static int balance ; // decalaring balance of user as static 
    int d,m,y; // DOB of customer
    long int creditCardNum;
    int cnic;
    int choice,amount;

    public: customer(){}; // default constructor
    int welcome(){
      int i=0;
        cout<< "\t\t\t\t\t\t\tWelcome to XYZ Online Portal!";
        while(i<1000000000){
            i++;
            if(i==999999900){
            system("CLS");
        }
    }
}
    int customerStatus(){
        cout << "Are you an existing customer or a new customer?: " ;
        getline(cin,status);
       // cout<< tolower(status); 
      // putchar(tolower(status));
        if(status == "new" || status == "New" || status == "NEW"){
            get_details();
        }
        else{
            check_details(); 
        }

    }
    int get_details(){  // if customer -> new
        cout << "Enter your name: " ;
        getline(cin,name);
        cout << "Enter your address: ";
        getline(cin,address);
        cout << "Enter your age: [DD/MM/YYYY]: " ;
        cin>> d>>m>>y;
        cout << "Enter your CNIC number: " ;
        cin >> cnic ; 
        
        generate(); // generating a random credit card number 

        writeToFile(); // writing all contents including random credit card number to the customers respective file 
    }
    int check_details(){ // if customer -> returning 
    string choice; 
    string info; 
    cout << "Enter your name: ";
    getline(cin,name);  
    ifstream file(name);
    if(!file.is_open()){
        cout << endl << "Your name does not exist on our database. Please make a new account";
    }
    else{
        cout << endl << "Welcome back, Mr " << name ; 
    }

    operation(); 
    while(choice!="stop"){

    
    cout << endl << "Anything else we can help you with?[yes/no]: ";
    cin >> choice; 
    if(choice == "yes"){
        operation();
    }
    else if(choice=="no"){
        cout << endl << "Thank you for choosing us as your bank! we look forward to seeing you again. " ; 
    }
}
if(choice=="stop"){
    cout << endl <<  "Thank you for choosing us as your bank! we look forward to seeing you again. " ; 
}
    }

    int operation(){
        cout << endl <<  "How can we help you?" << endl ;
    cout << "Press 1 to deposit an amount: " << endl ;
    cout << "Press 2 to withdraw an amount: " << endl ; 
    cout << "Press 3 to view your balance: " ;
    cin >> choice ; 
    switch(choice){
        case 1: cout << endl << "Enter the amount you wish to deposit: " ;
        cin >>  amount ; 
        balance = balance + amount ;
        cout << balance;
        break ;

        case 2: cout << endl << "Enter the amount you wish to withdraw: " ;
        cin >> amount ;
        balance = balance - amount ; 
        break ;

        case 3: cout << endl << "Your current balance is: " << balance ;
        break; 

        default:  cout << endl << "Oops! an error occured. Please try again." ;
        break; 
    }
    }
    long int generate(){
     creditCardNum = (rand()*98089);
     cout << "That should be all!"<<endl << "Your credit card number is: "<<creditCardNum ; 
     cout << endl << "Happy shopping!" ;
    }

    int display(){
        cout << name << endl << address << endl << d << "/" << m << "/" << y << endl << cnic << endl << creditCardNum ;
    }
    int writeToFile(){
        string fileName = name ;
        
        ofstream file(fileName);

        //file handling protocol: to check if wether file actually opened or not

        if(!file.is_open()){
            cout << endl <<"Error in File creation. Please retry" ;
        }
        else{
            cout << endl <<"File created successfully!" ; 
        }

  // Write to the file
  file <<"Name: "<< name<<endl<<"Address: " << address << endl << "DOB: " << d << "/" << m << "/" << y << endl << "CNIC: " << cnic << endl << "Credit Card Number: " << creditCardNum ;
        
        file.close();
    }
    //time();
};

int customer :: balance = 0 ; // setting balance = 0 initially 