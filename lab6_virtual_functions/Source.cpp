#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std;

class Factory
{
protected:
	string City;
	string Factory_name;

public:
	Factory(string City = "", string Factory_name = "") :
		City(City), Factory_name(Factory_name) {}
	Factory(Factory& other)
	{
		this->City = other.City;
		this->Factory_name = other.Factory_name;
	}
	virtual ~Factory()
	{
		City.clear();
		Factory_name.clear();
	}
	const string& getCity() const
	{
		return City;
	}
	void setCity(const string& city)
	{
		City = city;
	}
	const string& getFactory_name() const
	{
		return Factory_name;
	}
	void setFactory_name(const string& factory_name)
	{
		Factory_name = factory_name;
	}
	virtual void inputData() = 0;
	virtual void show()=0;
};

class Industry : virtual public Factory
{
protected:
	string Industry_name;

public:
	Industry(string Factory_name = "", string City = "", string Industry_name = "") :Factory(City, Factory_name), Industry_name(Industry_name) {};
	~Industry()
	{
		Industry_name.clear();
	}

	const string& getInductry_name() const
	{
		return Industry_name;
	}
	void setIndustry_name(const string& industry_name)
	{
		Industry_name = industry_name;
	}
	virtual void inputData() override
	{
		cout << endl;
		cout << "Enter the Factory's name: ";
		cin >> Factory_name;
		cout << "Enter the city: ";
		cin >> City;
		cout << "Enter the inductry: ";
		cin >> Industry_name;
		cout << endl;
	}
	virtual void show() override
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << "The inductry is " << Industry_name << endl;
	}
};

class CEO : virtual public Factory
{
protected:
	string Name;
	int Age;
public:
	CEO(string Factory_name = "", string City = "", string Name = "", int Age = 0) :Factory(City, Factory_name), Name(Name), Age(Age) {};
	~CEO()
	{
		Name.clear();
	}
	const string& getName() const
	{
		return Name;
	}
	void setName(const string& name)
	{
		Name = name;
	}
	int getAge() const
	{
		return Age;
	}
	void setAge(int age)
	{
		Age = age;
	}
	virtual void inputData() override
	{
		cout << endl;
		cout << "Enter the Factory's name: ";
		cin >> Factory_name;
		cout << "Enter the city: ";
		cin >> City;
		cout << "Enter the CEO's name: ";
		cin >> Name;
		cout << "Enter his age: ";
		cin >> Age;
		cout << endl;
	}
	virtual void show() override
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << "The CEO name is " << Name << endl;
		cout << "He's age is " << Age << endl;
	}
};

class Worker :virtual public CEO
{
protected:
	int Experience;
public:
	Worker(string City = "", string Factory_name = "", string Name = "", int Age = 0, int Experience = 0) :Factory(City, Factory_name),
		CEO(City, Factory_name, Name, Age), Experience(Experience) {};
	~Worker() {}

	int getExperience() const
	{
		return Experience;
	}
	void setExperience(int experience)
	{
		Experience = experience;
	}
	virtual void inputData() override
	{
		cout << endl;
		cout << "Enter the Factory's name: ";
		cin >> Factory_name;
		cout << "Enter the city: ";
		cin >> City;
		cout << "Enter the worker name: ";
		cin >> Name;
		cout << "Enter his age: ";
		cin >> Age;
		cout << "Enter the experience: ";
		cin >> Experience;
		cout << endl;
	}
	virtual void show() override
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << "His name is " << Name << endl;
		cout << "He's age is " << Age << endl;
		cout << "Experience is " << Experience << endl;
	}
};

int main()
{
	int sum;
	int IndAmount;
	int CEOAmount;
	int WorkAmount;
	cout << "Enter the amount of factories: " << endl;
	cout << " " << endl;
	cout << "Enter the amount of industries: " << endl;
	cin >> IndAmount;
	cout << "Enter the amount of CEOs: " << endl;
	cin >> CEOAmount;
	cout << "Enter the amount of workers: " << endl;
	cin >> WorkAmount;
	sum = IndAmount + CEOAmount + WorkAmount;
	Factory** ptr = new Factory*[sum];
	
	for (int i = 0; i < IndAmount; i++)
	{
		ptr[i] = new Industry;
		cout << "Fill in the informstion about [" << i + 1 << "] industry" << endl;
		ptr[i]->inputData();
	}

	for (int i = 0; i < CEOAmount; i++)
	{
		ptr[i + IndAmount] = new CEO;
		cout << "Fill in the informstion about [" << i + 1 << "] CEO" << endl;
		ptr[i + IndAmount]->inputData();
	}

	for (int i = 0; i < WorkAmount; i++)
	{
		ptr[i + IndAmount + CEOAmount] = new Worker;
		cout << "Fill in the informstion about [" << i + 1 << "] Worker" << endl;
		ptr[i + IndAmount + CEOAmount]->inputData();
	}

	for (int i = 0; i < sum; i++)
	{
		cout << " " << endl;
		ptr[i]->show();
		delete ptr[i];
	}
	system("pause");
	return 0;
}

