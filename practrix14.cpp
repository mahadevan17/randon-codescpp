//made by mahadevan arul 
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Travels{
    protected:
    string name,address,phoneno,from,to,doj;
    int passengers,billamount;
    public:
    void getinput(){
        cout<<"enter your name: ";
        cin.ignore();
        getline(cin,name);     
		cout<<"the address is: ";
        cin.ignore();    
    	getline(cin,address);
        cout<<"the phone o is: " ;
        cin>>phoneno;
        cout<<"the departure place is: ";
        cin>>from;
        cout<<"the arrival place at: "; 
        cin>>to;
        cout<<"the date of journey is: ";
        cin>>doj;
        cout<<"the no of passengers are: ";
        cin>>passengers;
    }
    void disp(){
        cout<<"the name is: "<<name<<endl;
        cout<<"the address is: "<<address<<endl;
        cout<<"the phone no is: "<<phoneno<<endl;
        cout<<"the departure is: "<<from<<endl;
        cout<<"the arrival at: "<<to<<endl;
        cout<<"the date of journey is: "<<doj<<endl;
        cout<<"the no of passengers are: "<<passengers<<endl;
        cout<<"the total bill amount is: "<<billamount<<endl;
    } 
};
class Bus:public Travels{
    protected:
    int seatNo;
    string seatType,busNo,boardPoint,depatureTime;
    public:
    void reservation(){
        Travels::getinput();
        cout<<"enter the seatno: ";
        cin>>seatNo;
        cout<<"enter the busNo: ";
        cin>>busNo;
        cout<<"enter the pick up Point: ";
        cin.ignore();
        getline(cin,boardPoint);
        cout<<"enter the departure time: ";
        cin>>depatureTime;
        cout<<endl<<endl;
        bill();
        disp();
        cout<<"thankyou for reserving your ticket"<<endl;
    }
    void cancellation(){
        string n1;
        cout<<"enter your name: ";
        cin.ignore();
        getline(cin,n1);
        if (n1==name){
         billamount=0;
            to="NULL";
            from="NULL";
            doj="NULL";
            passengers=0;
            cout<<"your ticket has been successufullly cancelled"<<endl;
            cout<<"the details are: "<<endl;
            disp();
        }
        else{
            cout<<"please enter a valid passenger"<<endl;
        }        
    } 
    void disp(){
        Travels::disp();
        if(billamount==0){
            cout<<"no passenger with this name was found "; //seatNo;
            seatNo=0;
            seatType="";
            busNo="";
            boardPoint="";
            depatureTime="";         
        }
        else{
            cout<<"your seat no is: "<<seatNo<<endl;
            cout<<"your seat type: "<<seatType<<endl;
            cout<<"your bus type is: "<<busNo<<endl;
            cout<<"your boardPoint is: "<<boardPoint<<endl;
            cout<<"your departure time is: "<<depatureTime<<endl;
        }

    }  
    void bill(){
        int a;
        cout<<"available bus types and price are: "<<endl;
        cout<<setw(10)<<"1)AC bus "<<setw(15)<<"Rs 700/-"<<endl;
        cout<<setw(10)<<"2)non AC bus "<<setw(15)<<"Rs 370/- "<<endl;
        cout<<"enter your choice: ";
        cin>>a;
        switch(a){
            case 1:
            seatType="AC bus";
            billamount=700;
            break;
            case 2:
            seatType="non AC bus";
            billamount=370;
            break;
        }
    } 
};
class Train:public Travels{
    protected:
    int seatNo;
    string coachType,trainNo,boardPoint,depatureTime;
    public:
    void reservation(){
        Travels::getinput();
        cout<<"enter the seatNo: ";
        cin>>seatNo;
        cout<<"enter the trainNo: ";
        cin>>trainNo;
        cout<<"enter the pick up Point: ";
        cin.ignore();
        getline(cin,boardPoint);
        cout<<"enter the departure time: ";
        cin>>depatureTime;
        cout<<endl<<endl;
        bill();
        disp();
        cout<<"thankyou for reserving your ticket"<<endl;
    }
    void cancellation(){
        string n1;
        cout<<"enter your name: ";
        cin.ignore();
        getline(cin,n1);
        if (n1==name){
            billamount=0;
            to="NULL";
            from="NULL";
            doj="NULL";
            passengers=0;
            cout<<"your ticket has been successufullly cancelled"<<endl;
            cout<<"the details are: "<<endl;
            disp();
        }
        else{
            cout<<"please enter a valid passenger"<<endl;
        }        
    } 
    void disp(){
        Travels::disp();
        if(billamount==0){
            cout<<"no passenger with this name was found "; 
            seatNo=0;
            coachType="";
            trainNo="";
            boardPoint="";
            depatureTime="";         
        }
        else{
            cout<<"your seat no is: "<<seatNo<<endl;
            cout<<"your coach type: "<<coachType<<endl;
            cout<<"your train type is: "<<trainNo<<endl;
            cout<<"your boardPoint is: "<<boardPoint<<endl;
            cout<<"your departure time is: "<<depatureTime<<endl;             
        }

    }
    void bill(){
        int a;
        cout<<"available bus types and price are: "<<endl;
        cout<<setw(10)<<"1)2 seater "<<setw(15)<<"Rs 370/-"<<endl;
        cout<<setw(10)<<"2)2 sleeper "<<setw(15)<<"Rs 450/- "<<endl;
        cout<<setw(10)<<"3)3 AC "<<setw(15)<<"Rs 1500/- "<<endl;
        cout<<setw(10)<<"4)2 AC "<<setw(15)<<"Rs 2450/- "<<endl;
        cout<<"enter your choice: ";
        cin>>a;
        switch(a){
            case 1:
            coachType="2 seater";
            billamount=370;
            break;
            case 2:
            coachType="2 sleeper";
            billamount=450;
            break;
            case 3:
            coachType="3 AC";
            billamount=1500;
            break;
            case 4:
            coachType="2 AC";
            billamount=2450;
            break;
        }
    }
};
class billAmount:public Bus,public Train{
    protected:
    int ticketNo;
    string bookDate;
    public:
    void bookTicket(){
        int ch;
        cout<<"1)Bus "<<endl;
        cout<<"2)Train"<<endl;
        cout<<"enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                Bus::reservation();
                break;
            case 2:
                Train::reservation();
                break;
            default:
                cout<<"please enter a valid input";
                break;
        }
   }
    void cancelTicket(){
        int ch;
        cout<<"1)Bus "<<endl;
        cout<<"2)Train"<<endl;
        cout<<"enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                Bus::cancellation();
                break;
            case 2:
                Train::cancellation();
                break;
            default:
                cout<<"please enter a valid input";
                break;
        }

    }
};
int main(){
    billAmount t[50];
    int n,nn;
    cout<<"enter the number of costumers booking: ";
    cin>>nn;
    for(int i=0;i<nn;i++){
    cout<<"1)Reservation "<<endl;
    cout<<"2)cancellation"<<endl;
    cout<<"enter your choice: ";
    cin>>n;
    switch (n){
        case 1:
            t[i].bookTicket();
            break;
        case 2:
            t[i].cancelTicket();
            break;
        default:
            cout<<"enter the valid input";
            break;
       }   
    }
}
