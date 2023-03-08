#include <iostream>
#define size 90
using namespace std;

class HashEntry
{
	long int mobNo;
	string name;

public:
	HashEntry()
	{
		mobNo = 0;
		name = "";
	}
	HashEntry(long int key, string value)
	{
		mobNo = key;
		name = value;
	}
	bool isEmpty()
	{
		if(mobNo == 0)
			return true;
		else
			return false;
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Number: "<<mobNo<<endl;
	}
	string getname()
	{
		return name;
	}
	long int getkey()
	{
		return mobNo;
	}
};

class phonebook
{
	HashEntry directory[size];

public:
	int hashfunction(long int key)
	{
		int sum = 0;
		for(int i=0; i<10; i++)
		{
			sum = sum + key%10;
			key = key / 10;
		}
		sum = sum % size;
		return sum;
	}

	void insert_wo_replacement(long int key, string value)
	{
		HashEntry obj(key, value);
		int hashcode = hashfunction(key);
		if(directory[hashcode].isEmpty())
		{
			directory[hashcode] = obj;
			cout<<"Number added successfully"<<endl;
		}
		else
		{
			while(!directory[hashcode].isEmpty())
			{
				hashcode = hashcode + 1;
				hashcode = hashcode % size;
			}
			directory[hashcode] = obj;
			cout<<"Number added successfully"<<endl;
		}
	}

	void insert_w_replacement(long int key, string value)
	{
		HashEntry obj_original(key, value);
		int obj_code = hashfunction(key);
		if(directory[obj_code].isEmpty())
		{
			directory[obj_code] = obj_original;
			cout<<"Number added successfully"<<endl;
		}
		else
		{
			int key = hashfunction(directory[obj_code].getkey());
			if(key != obj_code)
			{
				HashEntry temp = directory[obj_code];
				directory[obj_code] = obj_original;
				while(!directory[obj_code].isEmpty())
				{
					obj_code += 1;
					obj_code = obj_code % size;
				}
				directory[obj_code] = temp;
				cout<<"Number added successfully"<<endl;
			}
			else
			{
				while(!directory[obj_code].isEmpty())
				{
					obj_code += 1;
					obj_code = obj_code % size;
				}
				directory[obj_code] = obj_original;
				cout<<"Number added successfully"<<endl;
			}
		}
	}

	void display_directory()
	{
		for(int i=0; i< size; i++)
		{
			if(!directory[i].isEmpty())
			{
				cout<<i<<")";
				directory[i].display();
				cout<<endl;
			}
		}
	}

	void search(long int mob)
	{
		bool found = false;
		int comparison = 1;
		int code = hashfunction(mob);
		if(directory[code].getkey() == mob)
		{
			found = true;
			cout<<"-------------------------------"<<endl;
			directory[code].display();
			cout<<"-------------------------------"<<endl;
			cout<<"Number of comparisons:"<<comparison<<endl;
			cout<<"-------------------------------"<<endl;
		}
		else
		{
			int count = 0;
			while(directory[code].getkey() != mob)
			{
				code += 1;
				code = code % size;
				count += 1;
				comparison += 1;
				if(count == size + 1)
				{
					found = false;
					break;
				}
				else
					found = true;
			}
			if(found)
			{
				cout<<"-------------------------------"<<endl;
				directory[code].display();
				cout<<"-------------------------------"<<endl;
				cout<<"Number of comparisons:"<<comparison<<endl;
				cout<<"-------------------------------"<<endl;
			}
			else
			{
				cout<<"There is no name associated with this number!!"<<endl;
			}
		}
	}
};

int main()
{
	int choice, dir_choice;
	phonebook obj1, obj2;
	while(true)
	{
		cout<<"1.Work with phonebook 1"<<endl;
		cout<<"2.Work with phonebook 2"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter the number corresponding to the operation you want to perform:";
		cin>>dir_choice;
		if(dir_choice == 1)
		{
			while(true)
			{
				cout<<"Main Menu"<<endl;
				cout<<"1.Add data without replacement"<<endl;
				cout<<"2.Display data"<<endl;
				cout<<"3.Search data"<<endl;
				cout<<"4.Exit"<<endl;
				cout<<"Enter the number corresponding to the operation you want to perform:";
				cin>>choice;
				if(choice == 1)
				{
					string value;
					long int no;
					cout<<"Enter mobile number: ";
					cin>>no;
					cout<<"Enter the name: ";
					cin.ignore();
					getline(cin, value);
					obj1.insert_wo_replacement(no, value);
				}
				else if(choice == 2)
				{
					obj1.display_directory();
				}
				else if(choice == 3)
				{
					long int num;
					cout<<"Enter the mobile number:";
					cin>>num;
					obj1.search(num);
				}
				else if(choice == 4)
				{
					break;
				}
				else
				{
					cout<<"Please enter proper input!!"<<endl;
				}
			}
		}
		else if(dir_choice == 2)
		{
			while(true)
			{
				cout<<"Main Menu"<<endl;
				cout<<"1.Add data with replacement"<<endl;
				cout<<"2.Display data"<<endl;
				cout<<"3.Search data"<<endl;
				cout<<"4.Exit"<<endl;
				cout<<"Enter the number corresponding to the operation you want to perform:";
				cin>>choice;
				if(choice == 1)
				{
					string value;
					long int no;
					cout<<"Enter mobile number: ";
					cin>>no;
					cout<<"Enter the name: ";
					cin.ignore();
					getline(cin, value);
					obj2.insert_w_replacement(no, value);
				}
				else if(choice == 2)
				{
					obj2.display_directory();
				}
				else if(choice == 3)
				{
					long int num;
					cout<<"Enter the mobile number:";
					cin>>num;
					obj2.search(num);
				}
				else if(choice == 4)
				{
					break;
				}
				else
				{
					cout<<"Please enter proper input!!"<<endl;
				}
			}
		}
		else if(dir_choice == 3)
		{
			cout<<"Thank You!!"<<endl;
			break;
		}
	}
	return 0;
}