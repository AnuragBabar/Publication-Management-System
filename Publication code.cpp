#include<iostream>
#include<string>
#include<mysql.h>
#include<mysqld_error.h>

using namespace std;

const char* HOST = "127.0.0.1";
const char* USER ="root";
const char* PASS = "root123";
const char* DB = "publication";
MYSQL* con;

class Publication{
	protected:
		string price,genre,rating,r_date;
		string author;
		
	public:
		void input(){
			cout<<"\nEnter the genre :";
			cin>>genre;
			cout<<"\nEnter price :";
			cin>>price;
			fflush(stdin);
			cout<<"\nEnter name of author :";
			getline(cin,author);
			fflush(stdin);
			cout<<"\nEnter release data :";
			cin>>r_date;
			fflush(stdin);
			cout<<"\nEnter the rating :";
			cin>>rating;
		}
		
		void display(){
			cout<<"\nPrice of publication is :\t"<<price<<endl;
		}
};

class Book : public Publication{
	private:
		string b_id;
		string Page_Count;
		string b_name;
		
	public:
		void input(){
			cout<<"\nEnter ID number of book :";
			cin>>b_id;
			fflush(stdin);
			cout<<"\nEnter name of book :";
			getline(cin,b_name);
			cout<<"\nEnter number of pages :";
			cin>>Page_Count;	
			
			Publication::input();
			
			string ins= "insert into book (book_id,book_name,page_no,author_name,price,Release_Date,genre,rating) values ('"+b_id+"','"+b_name+"','"+Page_Count+"','"+author+"','"+price+"','"+r_date+"','"+genre+"','"+rating+"')";
			    if(mysql_query(con,ins.c_str())){
			    	cout<<"\n\nError..."<<mysql_error(con)<<endl;
			}
		    	else{
				   cout<<"\nData inserted successfuly"<<endl;
			}
			
		}
		
		void del(){
			cout<<"\nEnter the id of book :";
			cin>>b_id;
			string del="delete from book where book_id='"+b_id+"'";
			if(mysql_query(con,del.c_str())){
			    	cout<<"\n\nError..."<<mysql_error(con)<<endl;
			}
		    	else{
				   cout<<"\nData deleted successfuly"<<endl;
			}
		}
		
		void display(){
			string get = "select * from book";
			
			if(mysql_query(con,get.c_str())){
				cout<<"\n\nError..."<<mysql_error(con);
			}
			
			else{
				MYSQL_RES* result =mysql_store_result(con);
				if(result){
					int num = mysql_num_fields(result);
					MYSQL_ROW row;
					cout<<"\n\n";
					cout<<"\t\t book_id\t\t book_name\t\t page_no\t\t author_name\t\t price\t\t Release_Date\t\t genre\t\t rating"<<endl;
					cout<<"\t\t -------\t\t ---------\t\t -------\t\t -----------\t\t -----\t\t ------------\t\t -----\t\t ------"<<endl;
					while(row=mysql_fetch_row(result))
					for(int i=0;i<num;i++){
						cout<<"\t\t "<<row[i];
					}
					cout<<endl;
				}
				mysql_free_result(result);
			}
		}
};

class AudioBook : public Publication{
	private:
		string time,a_id;
		string a_name;
		
	public:
		void input(){
			cout<<"\nEnter ID number of audio book :";
			cin>>a_id;
			fflush(stdin);
			cout<<"\nEnter name of audio book :";
			getline(cin,a_name);
			cout<<"\nEnter duration of audio book in minutes :";
			cin>>time;
			Publication::input();
			
			string ins= "insert into audio_book (audio_id,audio_name,duration,author,price,Release_Date,genre,rating) values ('"+a_id+"','"+a_name+"','"+time+"','"+author+"','"+price+"','"+r_date+"','"+genre+"','"+rating+"')";
			    if(mysql_query(con,ins.c_str())){
			    	cout<<"\n\nError..."<<mysql_error(con)<<endl;
			}
		    	else{
				   cout<<"\nData inserted successfuly"<<endl;
			}
		}
		
		void del(){
			cout<<"\nEnter the id of audiobook :";
			cin>>a_id;
			string del="delete from audio_book where audio_id='"+a_id+"'";
			if(mysql_query(con,del.c_str())){
			    	cout<<"\n\nError..."<<mysql_error(con)<<endl;
			}
		    	else{
				   cout<<"\nData deleted successfuly"<<endl;
			}
		}
		
		void display(){
			string get = "select * from audio_book";
			
			if(mysql_query(con,get.c_str())){
				cout<<"\n\nError..."<<mysql_error(con);
			}
			
			else{
				MYSQL_RES* result =mysql_store_result(con);
				if(result){
					int num = mysql_num_fields(result);
					MYSQL_ROW row;
					cout<<"\n\n";
					cout<<"\t\t audiobook_id\t\t audiobook_name\t\t duration\t\t author_name\t\t price\t\t Release_Date\t\t genre\t\t rating"<<endl;
					cout<<"\t\t -------\t\t ---------\t\t -------\t\t -----------\t\t -----\t\t ------------\t\t -----\t\t ------"<<endl;
					while(row=mysql_fetch_row(result))
					for(int i=0;i<num;i++){
						cout<<"\t\t "<<row[i];
					}
					cout<<endl;
				}
				mysql_free_result(result);
			}
		}
};

int main(){
	int i=0,j=0;
    Book b1;
    AudioBook a1;
    
    int c;
    char b,a,val;
    
    con = mysql_init(NULL);
    
    if(!mysql_real_connect(con,HOST,USER,PASS,DB,3306,NULL,0)){
    	cout<<mysql_error(con);
	}
	else{
		cout<<"Logged in..."<<endl;
	}
	
    do{
    	cout<<"---------------MENU---------------"<<endl;
    	cout<<"1)Add book information."<<endl;
    	cout<<"2)Add audio book information."<<endl;
    	cout<<"3)Show book data."<<endl;
    	cout<<"4)Show audio book data."<<endl;
    	cout<<"5)Delete record."<<endl;
    	cout<<"6)Exit"<<endl;
    	
    	cout<<"Enter your choice :\n";
    	cin>>c;
    	fflush(stdin);
    	
    	switch(c){
    		case 1:
    			b1.input();
			break;
			
			case 2:
    			a1.input();
			break;
			
			case 3:
					b1.display();
					cout<<"\n---------------------------------------------"<<endl;
			break;
			
			case 4:
				a1.display();
					cout<<"\n---------------------------------------------"<<endl;
			break;
			
			case 5:
				cout<<"Enter 'b' or 'a' to delete the record of book or audiobook respectively :"<<endl;
				cin>>val;
				fflush(stdin);
				if(val=='b'){
					b1.del();
				}
				else if(val=='a'){
					a1.del();
				}
				else{
					cout<<"\nInvalid Input...";
				}
				break;
			
			case 6:
				cout<<"Program Exited..."<<endl;
				mysql_close(con);
				break;
			default:
				cout<<"Invalid input !!!"<<endl;
				break;
		}
	}
   while(c!=6);
   return 0;
}

