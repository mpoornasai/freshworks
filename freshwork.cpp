#include<fstream>
#include<iostream>
using namespace std;
class person
{
	protected:
		char name[40];
		int age;
		public:
			void getData(void)
			{
				cout<<"\n enter last name: ";cin>>name;
				cout<<" Enter age:";cin>>age;
							}
							void showData(void)
							{
								cout<<"\n Name:"<<name;
								cout<<"\n age:"<<age;
							}
							void diskIn(int);
							void diskOut();
							static int diskcount();
};
void person::diskIn(int pn)
{
	ifstream infile;
	infile.open("PERSFILE.DAT",ios::binary);
	infile.seekg(pn*sizeof(person));
	infile.read((char*)this,sizeof(*this));
	
}
void person::diskOut()
{
	ofstream outfile;
	outfile.open("PERSFILE.DAT",ios::app|ios::binary);
    outfile.write((char*)this,sizeof(*this));
	
}
int person::diskcount()
{
	ifstream infile
	infile.open("PERSFILE.DAT",	ios::binary);
	infile.seekg(0,ios::end);
	return(int)infile.tellg()
}
int main()
{
	person p;
	char ch,ch1;
	do{
		cout<<"Enter data for person:";
		p.getData();
		p.diskOut();
		cout<<"Do another(y/n)?";
		cin>>ch;
	}while(ch=='y');
	int n=person::diskcount();
	int a;
	cout<<"there are"<<n<<"person in file\n";
	cout<<"enter the key number from o to"<<n-1;
	cin>>a;
	do
	{
		cout<<"person"<<a;
		p.diskIn(a);
		p.showData();
		cout<<"Do another(y/n)?";
		cin>>ch1;
	}
	while(ch=='y');
	
}
