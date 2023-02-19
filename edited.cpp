#include<iostream>
#include<fstream>
using namespace std;
class shopping{
	public:
	int pcode;
	float price;
	float dis;
	string pname;
};
class shop : public shopping{
	public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
	void user();
	void login();
    void registration();
    void forgot();
    void page();
};
void shop::menu(){
	m:
	int option;
	string email;
	string password;
	cout<<"\t\t\t  *****************************\n";
	cout<<"\t\t\t  *                          *\n";
	cout<<"\t\t\t   * Supermarket Main Menu *   \n";
	cout<<"\t\t\t   *                        * \n";
	cout<<"\t\t\t  ****************************\n";
	cout<<"\t\t\t  *  1)    Administrator     *\n";
	cout<<"\t\t\t  *                          *\n";
	cout<<"\t\t\t  *  2)   Login page         *\n";
	cout<<"\t\t\t  *                          *\n";
	cout<<"\t\t\t  ****************************\n";
	cout<<"\n\n\t Please enter your option: ";
	cin>>option;
	switch(option){
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email  \n";
			cin>>email;
			cout<<"\t\t\t Password     \n";
			cin>>password;
			if(email=="boss@gmail.com" &&password=="boss@127"){
				administrator();
			}
			else{
				cout<<"Invalid email/password"<<endl;
			}
			break;
		case 2:
			page();								
		default:
			cout<<"Please select from the given options"<<endl;
}
goto m;
} 
void shop ::administrator(){
	m:
	int option;
	cout<<"\t\t\t\t****************************\n";	
	cout<<"\t\t\t\t*     Administrator menu   *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  1) Add the product      *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  2) Modify the product   *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  3) Delete the product   *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  4) Back to main menu    *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t****************************\n";
	cout<<"\n\n\t Please enter your option: ";
	cin>>option;
		switch(option){
		case 1:
			add();
			break;
		case 2:			
			edit();
			break;			
	
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;				
		default:
			cout<<"Invalid choice!!!"<<endl;
}
goto m;
}
void shop ::add(){
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t Add new product: ";
	cout<<"\n\n\t\t Product code of the product: ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product: ";
	cin>>pname;
	cout<<"\n\n\t Price of the product: ";
	cin>>price;
	cout<<"\n\n\t Discount on product: ";
	cin >>dis;
   
   data.open("database.txt",ios::in);
	if(!data)
	{
	 	data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();	
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c ==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
			
		}
		data.close();
       if(token==1)
           goto m;
       else
       { 
	    data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	   }
}
cout<<"\n\n\t\t*******Record inserted******"<<endl;
}
void shop :: edit()
{
   fstream data,data1;
   int pkey;
   int token=0;
   int c;
   float p;
   float d;
   string n;
   
   cout<<"\n\t\t\t Modify the record ";
   cout<<"\n\t\t\t Product code: ";
   cin>>pkey;
   
   data.open("database.txt",ios::in);
   if(!data)
   {
	cout<<"\n\n|File doesn't exist ";   	
   }	
   else
   {
   	data1.open("database1.txt",ios::app|ios::out);
   	
	data>>pcode>>pname>>price>>dis;
   	while(!data.eof())
   	{
	if(pkey==pcode){
		cout<<"\n\t\t Product new code:";
		cin>>c;
		cout<<"\n\t\t Name of the product:";
		cin>>n;
		cout<<"\n\t\t Price :";
		cin>>p;
		cout<<"\n\n\t\t Discount:";
		cin>>d;
		data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
		cout<<"\n\n\t\t Record edited "<<endl;
		token++;
	}
	else
	{
		data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
	}
	data>>pcode>>pname>>price>>dis;
   }
   data.close();
   data1.close();

   remove("database.txt");
   rename("database1.txt","database.txt");
    if(token==0){
    	cout<<"\n\n Record not found sorry!"<<endl;
	}
   }
}
	
void shop :: rem()
{
   fstream data,data1;
   int pkey;
   int token=0;

   cout<<"\n\t\t\t Delete product ";
   cout<<"\n\t\t\t Product code: ";
   cin>>pkey;
   
   data.open("database.txt",ios::in);
   if(!data)
   {
	cout<<"\n\n|File doesn't exist ";   	
   }	
   else
   {
   	data1.open("database1.txt",ios::app|ios::out);
   	data>>pcode>>pname>>price>>dis;
   	while(!data.eof()){
	if(pcode==pkey){
		
		cout<<"\n\n\t\t Product deleted successfully ";
		token++;
	}
	else
	{
		data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
	}
	data>>pcode>>pname>>price>>dis;
   }
   data.close();
   data1.close();

   remove("database.txt");
   rename("database1.txt","database.txt");
    if(token==0){
    	cout<<"\n\n Record not found sorry!";
	}
	   }
 }
 void shop ::list(){
 	fstream data;
 	data.open("database.txt",ios::in);
 	cout<<"\n\n|*************************\n";
 	cout<<"proNO \t\tName \t\tPrice \n";
 	cout<<"\n\n|*************************\n";
 	data>>pcode>>pname>>price>>dis;
 	while(!data.eof()){
 		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
 		data>>pcode>>pname>>price>>dis;
	 }
 	data.close();
 }
 void shop:: receipt(){
 	fstream data;
 	int arrc[100];
 	int arrq[100];
 	char choice;
 	int c=0;
 	float amount=0;
 	float dis=0;
 	float total=0;
 	int i;
 	cout<<"\n\n\t\t\t\tReceipt";
 	data.open("database.txt",ios::in);
 	if(!data){
 		cout<<"\n\n Empty database";
	 }
	 else
	 {
	 data.close();
	list();	
	cout<<"\n*****************************\n";	
	cout<<"\n*                           *\n";
	cout<<"\n*                           *\n";
	cout<<"\n*  Please place the order   *\n";
	cout<<"\n*                           *\n";
	cout<<"\n*                           *\n";
	cout<<"\n*****************************\n";
	do
	{
 	    m:
		cout<<"\n\nEnter Product code:";
		cin>>arrc[c];
		cout<<"\n\nEnter the product quantiy:";
		cin>>arrq[c];
		for(i=0;i<c;i++){
			if(arrc[c]==arrc[i]){
				cout<<"\n\n Duplicate product code.Please try again!";
				goto m;
			}
		}
		c++;
		cout<<"\n\n Do you want to buy another product? if yes then press y else n: ";
		cin>>choice;
	}while(choice =='y');	
		cout<<"\n\n\t\t************Receipt************\n";
		cout<<"\n Product No\tProduct Name\tProduct quantity\tprice\tAmount\tAmount with discount\n";
		
	for(i=0;i<c;i++){
		data.open("database.txt",ios::in);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
	        data.close();
		}
	}
	cout<<"\n\n**********************************";
	cout<<"\n Total Amount:"<<total<<endl;
 }
 void shop:: buyer(){
		m:
	int option;
	cout<<"\t\t\t\t****************************\n";	
	cout<<"\t\t\t\t*       Buyer              *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  1) Buy product          *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t*  2) Go back              *\n";
	cout<<"\t\t\t\t*                          *\n";
	cout<<"\t\t\t\t****************************\n";
	cout<<"\n\n\t Please enter your option: ";
	cin>>option;
		switch(option){
		case 1:
			receipt();
			break;
		case 2:			
			menu();
			break;						
		default:
			cout<<"Invalid choice!!!";
}
goto m;	
}
void shop :: page(){
		int option;
	cout<<"\t\t\t  ********************************\n";
	cout<<"\t\t\t  *                             * \n";
	cout<<"\t\t\t   * Welcome to the login page *  \n";
	cout<<"\t\t\t  ********************************\n";
	cout<<"\t\t\t     *          Menu          * \n";
	cout<<"\t\t\t  *************************************\n";
	cout<<"\t\t\t  *  1) to login                      *\n";
	cout<<"\t\t\t  *                                   *\n";
	cout<<"\t\t\t  *  2) to register                   *\n";
	cout<<"\t\t\t  *                                   *\n";
	cout<<"\t\t\t  *  3) if you forgot your password   *\n";
	cout<<"\t\t\t  *                                   *\n";
	cout<<"\t\t\t  *  4) to exit                       *\n";
	cout<<"\t\t\t  *                                   *\n";
	cout<<"\t\t\t  *************************************\n";
		cout<<"\n\n\t Please enter your option: ";
	cin>>option;
	switch(option){
		case 1:
			login();
			break;
		case 2:
		registration();			
		case 3:
		 forgot();
		 break;		
		case 4:
		 cout<<"\t\t\t Thankyou!\n\n";
		default:
			cout<<"Please select from the given options";
			page();	
          }
}
void shop ::login(){
	int count=0;
	string userid,password,id,pass;
	system("cls");
	cout<<"\t\t\t please enter the username and password: "<<endl;
	cout<<"\t\t\tusername: ";
	cin>>userid;
	cout<<"\t\t\t password:";
	cin >>password;
	ifstream input("records.txt");
	while(input>>id>>pass){
		if(id==userid&&pass==password)
		{
				count=1;
			system("cls");
		}
	}
	input.close();
		if(count==1){
		cout<<userid<<"\t\t"<<"Welcome!!\n";
			shop s;
	        s.buyer(); 
	}
	else{
		cout<<"Invalid username/password!!!!"<<endl;
		page();
	}
}
void shop::registration(){
		string ruserid,rpassword,rid,rpass;
	system("cls");
	cout<<"\t\t\t enter the username:";
	cin>>ruserid;
	cout<<"\t\t\t enter the password:";
	cin>>rpassword;
	ofstream f1("records.txt",ios::app);
	f1<<ruserid<<' '<<rpassword<<endl;
	system("cls");
	cout<<"\n\t\t\t Registration is successfull!\n";
	login();
}
void shop::forgot(){
	int option;
	system("cls");
	cout<<"\t\t\t you forgot the password? no worries\n";
	cout<<"press 1 to search your id by username"<<endl;
	cout<<"press 2 to go back to the main menu"<<endl;
	cout<<"\t\t\t enter your option:";
	cin>>option;
	switch(option){
		case 1:
		{
			int count=0;
			string suserid,sid,spass;
			cout<<"\n\t\t enter the username which you remember:";
			cin>>suserid;
			ifstream f2("records.txt");
			while(f2>>sid>>spass){
				if(suserid==sid){
					count=1;
					break;
				}
			}
			f2.close();
			if(count==1){
				cout<<"\n\n your account is found!\n";
				cout<<"\n\n your password is :"<<spass<<endl;
				login();
			}
			else{
				cout<<"\n\t sorry! your account is not found!\n";
				page();
			}
			break;
		}
	case 2:
		{
		
		page();
	}
	  default:
		cout<<"\t\t wrong choice! please try again"<<endl;
		forgot();
	
}
}
int main(){
	shop s;
	s.menu();
}
