#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#define clrscr() system("cls");
using namespace std;

//Admin Class Starts here>>>>>>>>>>>>>>>.
class admin
{
	string user;
	int log,ch;
	string password;
	string passwd;
	string line;
	string line1;
	string line2;
	string line3;
	int rate;
	string Empid;
	string Passwd;
	string Fname;
	string Lname;
	string designation;
	int num;
	string nameanDdesig;
	bool flag;
	
void Update()
	{   char ch='Y';
		char subchoice;
		while(ch=='y'||ch=='Y')
		{
		go:
		
		cout<<endl<<"\t\t\tChoose What you Want to Do?"<<endl;
		cout<<"\n\t\t[1] Add New Employee"<<endl;
		cout<<"\n\t\t[2] Delete Existing Employee"<<endl;
		cout<<"\n\t\t[3] Update Existing Employee Data"<<endl;
		cout<<"\n\t\t[4] Go to Previous Menu"<<endl;
		cout<<">>"<<" ";
		cin>>subchoice;
		switch(subchoice)
		{
			  case '1':add();
			  break;
			  case '2':del();
			  break;
			  case '3':alter();
			  break;
			  case '4':
			  cout<<"\n\t\tOops! You Need to login Again!!!"<<endl;
			  adminlogin();
			  break;
			  default:
			  	cout<<endl<<"\n\t\t<<Please Enter Correct Choice>>>"<<endl;
			  	goto go;
			  	break;
		}
		cout<<endl<<"\n\t\tWant To Continue?(Y/N):";
		cin>>ch;
	   }
	}
	
void add()
	{
	ofstream id("userid.txt",ios::app);
	ofstream pass("userpass.txt",ios::app);
	ofstream ra("ratecard.txt",ios::app);
	ofstream name("userdesignation.txt",ios::app);
	ifstream check("userid.txt");
	cout<<endl<<"How Many Emplyee Record you Want to Add:";
	cin>>num;
	for(int i=0;i<num;i++)
	{ 
	
	label:
		Empid="";
	cout<<endl<<"\n\t\tEnter Employee Id:";
	cin>>Empid;
	cout<<"\n\t\tEnter Password of Employee:";
	cin>>Passwd;
	cout<<"\n\t\tEnter Hourly Rate of Employee:";
	cin>>rate;
	cout<<"\n\t\tEnter First Name of Employee:";
	cin>>Fname;
	cout<<"\n\t\tEnter Last Name of Employee:";
	cin>>Lname;
	cout<<"\n\t\tEnter Designation of Employee:";
    cin>>designation;
	nameanDdesig=Fname+" "+Lname+" "+designation;
	while(!check.eof())
	{
	getline(check,line);
	if((Empid)==line)
	{
		cout<<"\n\t\t!!!!!!!!!!Duplicate Employee Id not allowed!!!!!!!!!!!"<<endl;
		cout<<"\n\t\tPlease Add Genuine Employee"<<endl;
		goto label;
		
	}
	else
	continue;
   }
    if(!id.eof())  
    {
    	flag=true;
	id<<endl<<Empid;
	pass<<endl<<Passwd;
	ra<<endl<<rate;
	name<<endl<<nameanDdesig;
    }
}
    if(flag==true)
    cout<<endl<<"\t\tRecord of "<<num<<" Employee has been Successfully Written"<<endl;
	id.close();
    ra.close();
    pass.close();
    name.close();
    check.close();  
}

void del()
{
	flag=false;
	fstream id("userid.txt",ios::in|ios::out);
	ifstream pass("userpass.txt");
	ifstream ra("ratecard.txt");
	ifstream name("userdesignation.txt");
    ofstream temp1("temp1.txt");
    ofstream temp2("temp2.txt");
    ofstream temp3("temp3.txt");
    ofstream temp4("temp4.txt");
    cout<<endl<<"\n\t\tEnter Employee Id to be Deleted:";
    cin>>Empid;
    if(!id || !pass || !ra || !name)
    {
    	cout<<endl<<"\t\tCannot Fetch Data"<<endl<<"\n\t\tExiting From System.............................";
    	exit(0);
	}
	while(id || pass || ra || name)
	{
		getline(id,line);
		getline(pass,line1);
		getline(ra,line2);
		getline(name,line3);
		if(line!=Empid)
		{
			temp1<<line<<endl;
			temp2<<line1<<endl;
			temp3<<line2<<endl;
			temp4<<line3<<endl;	
			
		}
		else if(line==Empid)
		{
			flag=true;
			continue;
		}
		else if(line=="")
		break;
		} 
		id.close(); pass.close();  ra.close();  name.close();
		temp1.close(); temp2.close(); temp3.close(); temp4.close();
		remove("userid.txt");
		remove("userpass.txt");  
		remove("ratecard.txt");  
		remove("userdesignation.txt");   
		rename("temp1.txt","userid.txt");  
		rename("temp2.txt","userpass.txt"); 
		rename("temp3.txt","ratecard.txt"); 
		rename("temp4.txt","userdesignation.txt"); 
		if(flag==true)
		cout<<endl<<"\t!!!!!!!!Employee Has been Removed From Database!!!!!!!!!"<<endl<<endl;
		else
		cout<<endl<<"\t Employee is not In Database "<<endl<<endl;
		
}

void alter()
{
    char ch;
	fstream id("userid.txt",ios::in|ios::out);
	ifstream pass("userpass.txt");
	ifstream ra("ratecard.txt");
	ifstream name("userdesignation.txt");
    ofstream temp1("temp1.txt");
    ofstream temp2("temp2.txt");
    ofstream temp3("temp3.txt");
    ofstream temp4("temp4.txt");
    cout<<endl<<"Enter Employee Id to be Altered:";
    cin>>Empid;
    if(!id || !pass || !ra || !name)
    {
    	cout<<endl<<"\t\tCannot Fetch Data"<<endl<<"\n\t\tExiting From System....................";
    	exit(0);
	}
	while(id || pass || ra || name)
	{
		getline(id,line);
		getline(pass,line1);
		getline(ra,line2);
		getline(name,line3);
		if(Empid==line)
		{
		cout<<"\n\n\tHere are the Details Of Employee: "<<Empid;
		cout<<"\n\n\tName and Designation: "<<line3<<endl;
		cout<<"\n\tPassword: "<<line1<<"\n\n\tDaily Rate: "<<line2<<endl;
		cout<<"\n\n\tAre you Sure To change Data of Employee "<<line<<" ?(Y/N): ";
		cin>>ch;
		  if(ch=='Y' || ch=='y')
		  {
		  	cout<<endl<<"\t\tEnter New Data:\n\n";
		    cout<<endl<<"\n\t\tEnter Employee Id:";
	        cin>>Empid;
	        cout<<"\n\t\tEnter Password of Employee:";
	        cin>>Passwd;
	        cout<<"\n\t\tEnter Hourly Rate of Employee:";
         	cin>>rate;
        	cout<<"\n\t\tEnter First Name of Employee:";
 	        cin>>Fname;
	        cout<<"\n\t\tEnter Last Name of Employee:";
	        cin>>Lname;
	        cout<<"\n\t\tEnter Designation of Employee:";
            cin>>designation;
            
			temp1<<Empid<<endl;
			temp2<<Passwd<<endl;
			temp3<<rate<<endl;
			temp4<<(Fname+" "+Lname+" "+designation)<<endl;				
			cout<<"\n\n\t!!!!!!!!Employee Records Has Been Successfully Updated!!!!!!!!!!!"<<endl<<endl;
	      }
		} 
		else
		{
			temp1<<line<<endl;
			temp2<<line1<<endl;
			temp3<<line2<<endl;
			temp4<<line3<<endl;	
		}
	}
		id.close(); pass.close();  ra.close();  name.close();
		temp1.close(); temp2.close(); temp3.close(); temp4.close();
		remove("userid.txt");
		remove("userpass.txt");  
		remove("ratecard.txt");  
		remove("userdesignation.txt");   
		rename("temp1.txt","userid.txt");  
		rename("temp2.txt","userpass.txt"); 
		rename("temp3.txt","ratecard.txt"); 
		rename("temp4.txt","userdesignation.txt"); 	
    
}

void Read()
{   
    char ch='Y';
	char option;
	while(ch=='Y'|| ch=='y')
    {
    	
    	label:
	cout<<endl<<"\t\tPlease Choose:"<<endl;
	cout<<"\n\t\t[1]Read Record of Specific Employee"<<endl;
	cout<<"\n\t\t[2]Read Record of All Employees"<<endl;
	cout<<"\n\t\t[3]Go Back To Previous Menu"<<endl;
	cout<<"\n\t\t[4]Exit From Payroll System"<<endl;
	cout<<">>"<<" ";
	cin>>option;
	switch(option)
	{
		case '1': few();
			break;
		case '2': all();
		    break;
		case '3': cout<<"\n\t\tOops You Need To login Again"<<endl;
		       adminlogin();
		    break;
		case '4': 
		cout<<"\n\n\t\tExiting from the System.............";
		exit(0);
		    break;
		default:
			cout<<"\n\t\tPlease Enter Correct Option"<<endl;
			goto label;
		    break; 
	}
	cout<<endl<<"\tWant to Continue?(Y/N):";
	cin>>ch;
   }   
}

void all()
{ 
    
	ifstream readuser("userid.txt");
	ifstream readpass("userpass.txt");
	ifstream readrate("ratecard.txt");
	ifstream readdesig("userdesignation.txt");
		    cout<<"\t\t\t\t\t>>>>>>Here is Record of All Employees>>>>>>"<<endl<<endl;
			cout<<endl<<"\t\tEmployee Id"<<"\t"<<"PassWord"<<"\t\t"<<"Hourly Rate"<<"\t\tUser Name   Designation "<<endl;
			cout<<"\t\t----------------------------------------------------------------------------------------"<<endl;
		while(!readuser.eof())
		{  
			getline(readuser,line);
			getline(readpass,line3);
			getline(readrate,line1);
			getline(readdesig,line2);
			if(line=="")
			continue;
			cout<<"\t\t"<<line<<"\t\t  "<<line3<<"\t\t\t  "<<line1<<"\t\t\t"<<line2<<endl;
			cout<<"\t\t----------------------------------------------------------------------------------------"<<endl;
			
		}
		readuser.close();
		readpass.close();
		readrate.close();
		readdesig.close();
}

void few()
{
	flag=false;
	int count=0;
	int loop_count=0;
	cout<<"\n\t\tEnter Employee Id:";
	cin>>Empid;
	ifstream readuser("userid.txt");
	if(!readuser)
	{
	cout<<"\n\t\tCannot Get User Details"<<endl;
	Read();
    }
    while(!readuser.eof())
    {
    getline(readuser,line);
    count++;
	if((Empid)==line)	
	{  
	    flag=true;
	    cout<<"\n\nHere Are The Details of Employee:"<<Empid<<endl;
	    cout<<"\n\tEmployee Id:"<<Empid<<endl;
	    ifstream readpass("userpass.txt");
		ifstream readrate("ratecard.txt");
		ifstream readdesig("userdesignation.txt");
		
		while(getline(readrate,line) && getline(readdesig,line1) && getline(readpass,line2))
	   {	
	    loop_count++;
		if(loop_count==count)
		{
			cout<<"\n\tPassword:"<<line2;
			cout<<endl<<"\n\tName and Designation:"<<line1<<endl<<"\n\tDaily Salary Rate:"<<line<<endl;
			goto label;
		}
		else
		continue;
		}
		label:
		readrate.close();
		readdesig.close();
		break;
		}
	}
		if(flag==false)
		cout<<endl<<">>>>\n\t\tRecord Not Found"<<endl;
readuser.close();	
	
}
	
	public:
	
	admin()
		{
			log=0;
			passwd="";
			flag=false;
		}
		
void adminlogin()
{
	
	char admchoice;
	cout<<endl<<endl<<endl;
	cout<<"\n\t>>>>     WELCOME    <<<<<"<<endl;
	cout<<"\n\t>>>>  Please Login  <<<<<"<<endl;
	wrong:
		cout<<"\n   Enter Admin Id:";
		cin>>user;
		cout<<"\n   Enter Password:";
		while(ch=getch())
		{
			if(ch==13)
			{   
				if((password=="hello")&&(user=="admin"))
				{   
				    password="";
					cout<<endl<<endl<<"\t-------------------------------------------------------------------------------------"<<endl;
					cout<<"\t\tHello "<<user<<endl<<endl;
					opt:
					cout<<"\t\tEnter Your Choice:"<<endl;
					cout<<"\n\t[1] Update Employee Details"<<endl;
					cout<<"\n\t[2] Read Employee Details"<<endl;
					cout<<"\n\t[3] Exit"<<endl<<endl;
					cout<<">>"<<" ";
					cin>>admchoice;
					switch(admchoice)
					{
						case '1':Update();
						     exit(0);
						break;
						case '2':Read();
						    exit(0);
						break;
						case '3':exit(0);
						break;
						default:
							cout<<"\t\tPlease Choose out of (1,2,3)"<<endl;
			                goto opt;
			                break;
					}
					break;
				}
				else
				{
					cout<<"\n\tWrong User name or Password Input again\n";
					password="";
					log+=1;
					if(log==3)
					{
						cout<<"\n\t\tYou have entered wrong 3 times";
						cout<<"\n\t\tGood bye";
						exit(0);
					}
					goto wrong;
				}
			}
			else if(ch==8)
			{
			if(password.length()>0)
			{
			cout<<'\b'<<" "<<'\b';
			password.erase(password.length()-1);
			}
		}
			else
			{
				cout<<"*";
				password+=ch;
			}
		}
}


};

//Employee Class Starts Here>>>>>>>>>>>>>>>>>

class Emp
{
	string employee;
    int count;
	int ch,login;
	string passwd;
	bool flag;
	float Rate;
	string designation;
	int days;
	int hours;
	float salary;
	float SSS;
	float gst;
	float health; 
	
public:
		
	Emp()
		{   
		    flag=false;
			login=0;
			count=0;
			passwd="";
			days=0;
			hours=0;
			salary=0.0;
			SSS=0.0;
			gst=0.0;
			health=0.0;
		}
	
	void userlogin()
	{
		
		cout<<endl<<endl<<endl;
	    cout<<"\n\t>>>>     WELCOME    <<<<<"<<endl;
	    cout<<"\n\t>>>>  Please Login  <<<<<"<<endl;
	incorrect:
		count=0;
		cout<<"\n     Enter Employee ID:";
		cin>>employee;
		cout<<"\n     Enter Password:";
		while(ch=getch())
		{
			if(ch==13)
			{	
			    string userAndPass = employee+passwd; // Search pattern
                string line,line1;
                ifstream usersFile;
                usersFile.open ("userid.txt");
                ifstream userpass("userpass.txt");
                if(!usersFile || !userpass)
                {
                cout<<endl<<">>>>\n\tCannot Open Users File!!";
                cout<<endl<<">>>>\n\t\t\tExiting From System ....................";
                exit(0);
                }
                else
                {
				while(!usersFile.eof())
				{   
                    getline(usersFile,line);
                    getline(userpass,line1);
                    count++;
                    if (userAndPass==line+line1)         // if login data is found
					 {       
					 flag=true;
					                   
                     cout << "\n\n\t\t<<<<<<<<<<<<<<Welcome " << employee<<" >>>>>>>>>>>>>"<< endl;
                     //cout<<"\n"<<count;
                      computeSalary();   //allowing valid user to compute its salary 
					  exit(0);   
                    }
				   else
				   continue;
			    }
				   if(flag==false)
				   {
					cout<<"\n\n>>>>Wrong Employee ID or Password Input again\n";
					passwd="";
					login+=1;
					if(login==3)
					{
						cout<<">>>>\n\t\tYou have entered wrong 3 times";
						cout<<">>>>\n\n\t\tGood bye";
						exit(0);
					}
					else goto incorrect;
				   }
		         
				 }
		      	usersFile.close();		
			}
			else if(ch==8)
			{
			if(passwd.length()>0)
			{
			cout<<'\b'<<" "<<'\b';
			passwd.erase(passwd.length()-1);
			}
		}
			else
			{
				cout<<"*";
				passwd+=ch;
			}
		}
	}

void computeSalary()
{  
  cout<<endl<<"\n\t<<<<<Enter Your Details To Compute Your Salary>>>>>"<<endl<<endl;
  cout<<"\n\t\tEnter Days of work:";
  cin>>days;
  cout<<"\n\t\tEnter Hours of work:";
  cin>>hours;
  ifstream rate("ratecard.txt");
  ifstream desig("userdesignation.txt");
  if(!rate || !desig)
  {
  	cout<<"\n\t\t\tCannot get User Details"<<endl<<endl;
  	cout<<"\t\tExiting From System............";
  	exit(0);
  }
  else
  {
  	int line_no=0;
  	while(line_no!=count && (rate>>Rate) && (getline(desig, designation)))
  	++line_no;
  	if(line_no==count)
  	{
  	salary=days*hours*(Rate);
  	SSS=salary*.05;
  	gst=salary*.05;
  	health=salary*.05;
  	salary=salary-(SSS+gst+health);
  	cout<<endl<<endl<<"\t\t\t      Here is Your Generated Salary"<<endl<<endl;
  	cout<<"\t  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
  	cout<<"\t |\t\tName And Designation:"<<designation<<"\t\t|"<<endl<<endl;
  	cout<<"\t |\t\tTotal Working Hours In a Day:"<<hours<<"\t\t\t\t|"<<endl<<endl;
  	cout<<"\t |\t\tTotal Number of Working Days:"<<days<<"\t\t\t\t|"<<endl<<endl;
  	cout<<"\t |\t\tDeductions In Salary ->"<<"\t\t\t\t\t|"<<endl<<endl;
  	cout<<"\t |\t\t\tSSS Deduction:"<<SSS<<"\t\t\t\t|"<<endl<<endl<<"\t |\t\t\tGST Deduction:"<<gst<<"\t\t\t\t|"<<endl<<endl;
	cout<<"\t |\t\t\tHealth Tax Deduction:"<<health<<"\t\t\t|";
  	cout<<"\n\n\t |\t\t\t"<<">>>>Total Deductions:"<<(SSS+gst+health)<<"\t\t\t|"<<endl<<endl;
  	cout<<"\t |\t\t\tTotal Salary:"<<salary<<"\t\t\t\t|"<<endl;
  	cout<<"\t  - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - -"<<endl<<endl;
  }
}
}
};

int main()
{
	admin objad;
	Emp objemp;
	char choose;
	cout<<endl<<endl<<endl<<"\t\t\t!!!!!!!!Welcome To Salary Cheque Generation System!!!!!!!!!"<<endl<<endl;
	option:
	cout<<"\n\t\t\tEnter Your Choice:\n";
	cout<<"\n\t\t[1] Admin Login\n";
	cout<<"\n\t\t[2] Employee Login\n";
	cout<<"\n\t\t[3] Exit from Payroll System\n"<<endl<<endl;
	cout<<">>"<<" ";
	cin>>choose; 
	 switch(choose)
	{
		case '1': objad.adminlogin();
		        break;
		case '2': objemp.userlogin();
		        break;
		case '3':
			cout<<endl<<"\n\t\t\tExiting From System ....................";
		     exit(0);
		       break;
		default:
			cout<<"\t\tPlease Choose out of (1,2,3)"<<endl;
			goto option;
			break;
	}	
return 0;	
}
