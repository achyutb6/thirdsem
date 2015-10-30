#include <iostream>

using namespace std;

class Customer{
protected:
    int customerID;
    string customerName;
    string phoneNum;
    string custAdd1;
    string custAdd2;
public:
    Customer(int cID,string cName,string pnum,string cA1,string cA2)
    {   customerID=cID;
        customerName=cName;
        phoneNum=pnum;
        custAdd1=cA1;
        custAdd2=cA2;
    }
    int getCustomerID()
    {
        return customerID;
    }
    string getCustomerName()
    {
        return customerName;
    }
    string getPhoneNum()
    {
        return phoneNum;
    }
    string getCustAdd1()
    {
        return custAdd1;
    }
    string getCustAdd2()
    {
        return custAdd2;
    }
    virtual void printCustomerInfo()
    {
        cout<<"\nCustomer ID:"<<customerID<<endl;
        cout<<"\nCustomer Name:"<<customerName<<endl;
        cout<<"\nPhone Number:"<<phoneNum<<endl;
        cout<<"\nAddress 1:"<<custAdd1<<endl;
        cout<<"\nAddress 2:"<<custAdd2<<"\n"<<endl;
    }

};

class RegularCustomer:public Customer
{
protected:
    float discount;
public:
    RegularCustomer(int cID,string cName,string pnum,string cA1,string cA2,float dis):Customer(cID,cName,pnum,cA1,cA2)
    {
        discount=dis;
    }
    float getDiscount()
    {
        return discount;
    }
    void printCustomerInfo()
    {
        Customer::printCustomerInfo();
        cout<<"Discount:"<<discount<<"\n"<<endl;
    }
};

class PriviligedCustomer:public RegularCustomer
{
    string memCardType;
public:
    PriviligedCustomer(int cID,string cName,string pnum,string cA1,string cA2,float dis,string mct):RegularCustomer(cID,cName,pnum,cA1,cA2,dis)
    {
        memCardType=mct;
    }
    string getMemCardType()
    {
        return memCardType;
    }
    void printCustomerInfo()
    {
        RegularCustomer::printCustomerInfo();
        cout<<"Membership Card Type:"<<memCardType<<"\n"<<endl;

    }

};

int main()
{

    Customer c(1001,"Aa","900000","Keshwapur","Hubli");
    RegularCustomer rc(2002,"Bb","9100000","Vidyanagar","Hubli",20);
    PriviligedCustomer pc(3003,"Cc","9200000","Shanti Nagar","Hubli",30,"GOLD");
    Customer cus[]={rc,pc};
    cout<<"*******Using Array of base class*********"<<endl;
    cus[0].printCustomerInfo();
    cus[1].printCustomerInfo();

    cout<<"*******Using objects to display*********"<<endl;

    rc.printCustomerInfo();
    pc.printCustomerInfo();

    cout<<"*******Using pointers to functions to display*********"<<endl;

    Customer *cptr;
    cptr=&rc;
    cptr->printCustomerInfo();
    cptr=&pc;
    cptr->printCustomerInfo();
        return 0;
}
