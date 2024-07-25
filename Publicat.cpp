#include<iostream>
#include<string>
using namespace std;

class Publication{
	protected:
		float price;
		
	public:
		void input(){
			cout<<"\nEnter price :";
			cin>>price;
			fflush(stdin);
		}
		
		void display(){
			cout<<"\nPrice of publication is :\t"<<price<<endl;
		}
};

class Book : public Publication{
	private:
		int Page_Count;
		string b_name;
		
	public:
		void input(){
			cout<<"\nEnter name of book :";
			getline(cin,b_name);
			cout<<"\nEnter number of pages :";
			cin>>Page_Count;
			Publication::input();
		}
		
		void display(){
			cout<<"\nBook Name :\t"<<b_name;
			cout<<"\nNumber of pages is :\t"<<Page_Count<<endl;
			Publication::display();
		}
};

class AudioBook : public Publication{
	private:
		float time;
		string a_name;
		
	public:
		void input(){
			cout<<"\nEnter name of audio book :";
			getline(cin,a_name);
			cout<<"\nEnter duration of audio book in minutes :";
			cin>>time;
			Publication::input();
		}
		
		void display(){
			cout<<"\nBook Name :\t"<<a_name;
			cout<<"\nDuration of audio book is :\t"<<time<<"\tminutes"<<endl;
			Publication::display();
		}
};

int main(){
	int i=0,j=0;
    Book b1[10];
    AudioBook a1[10];
    
    int c;
    do{
    	cout<<"---------------MENU---------------"<<endl;
    	cout<<"1)Add book information."<<endl;
    	cout<<"2)Add audio book information."<<endl;
    	cout<<"3)Show book data."<<endl;
    	cout<<"4)Show audio book data."<<endl;
    	cout<<"5)Exit"<<endl;
    	
    	cout<<"Enter your choice :\n";
    	cin>>c;
    	fflush(stdin);
    	
    	switch(c){
    		case 1:
    				b1[i].input();
    				i++;
			break;
			
			case 2:
    				a1[j].input();
    				j++;
			break;
			
			case 3:
				for(int k=0;k<i;k++){
					b1[k].display();
					cout<<"\n---------------------------------------------"<<endl;
				}
			break;
			
			case 4:
				for(int k=0;k<j;k++){
					a1[k].display();
					cout<<"\n---------------------------------------------"<<endl;
				}
			break;
			
			case 5:
				cout<<"Program Exited..."<<endl;
				break;
			default:
				cout<<"Invalid input !!!"<<endl;
				break;
		}
	}
   while(c!=5);
   return 0;
}

