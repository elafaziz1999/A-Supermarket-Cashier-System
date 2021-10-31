#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;


string product [10]={"Milk", "Bread", "Chocolate", "Towel", "Toothpaste", "Soap", "Pen", "Biscuits", "Lamp", "Battery"};
string listofbarcode [10]={"0120001", "0120002", "0120003", "0120004", "0120005", "0120006", "0120007", "0120008", "0120009", "0120010"};
double price [10]={10.5, 5.50, 8.00, 12.10, 6.75, 5.20, 2.00, 4.45, 20.5, 10.00};



int main()
{
    // char inputChar;
    // int number;
    // char answer;
    double cash;
    string barcode;

    char nextCustomer;


    int buyIndex[100];
    int itemCount;



    cout << "****************************************************" << endl;
    cout << "*   WELCOME TO HERTS SUPERMARKET CHECKOUT SYSTEM   *" << endl;
    cout << "* Scan the barcode or manually type the barcode ID *" << endl;
    cout << "****************************************************" << endl;

    do
    {


        double totalPrice = 0.0;
        itemCount =0;
        while(true)
        {

            cout << "Barcode (Type 'F' to finish):" << endl;
            cin >> barcode;
            if (barcode == "f" ||barcode=="F")
                break;

            //if not exit check barcode
            bool isFound = false;
            for(int i=0;i<10;i++)
            {
                //item found
                if(listofbarcode[i]==barcode)
                {
                    totalPrice=totalPrice+price[i];
                    isFound = true;
                    buyIndex[itemCount]=i;
                    itemCount=itemCount+1;
                    break;

                }
            }

            //display message if item is not found
            if(isFound==false)
            {
                cout<<"Invalid bar code";
            }

        }//while true  bar code entry


        //once finish entering bar code ask for payment
        cout << "--------------------------------------------------------"<< endl;
        cout << "Total price:" << totalPrice << endl;
        double cashPaid = 0.0;
        cout << "Cash received:";
        cin >> cash;
        cashPaid = cashPaid+cash;
        while(cashPaid <totalPrice)
        {
            cout << "\n[!] More cash needed :" << endl;
            cin>>cash;
            cashPaid = cashPaid+cash;
        }//cash payment





        cout << "Total Cash recieved:" << cashPaid << endl;
        cout << "Change given?:" << (cashPaid-totalPrice) << endl;



        cout << "--------------------------------------------------------" << endl;
        cout << "                        RECEIPT                         " << endl;
        cout << "Barcode          Product          Price                 " << endl;
        for(int i=0;i<itemCount;i++)
        {
                    int currIndex = buyIndex[i];
                cout << listofbarcode[currIndex] << "          ";
                cout << product[currIndex] <<       "          ";

                cout << price[currIndex] <<         "          " << endl;

        }
        cout << "--------------------------------------------------------" << endl;
        cout << "Total:" << totalPrice << endl;


        cout << "Next customer (Y/N)";
        cin>>nextCustomer;

    }while(nextCustomer=='Y'||nextCustomer=='y');
        return 0;
}
