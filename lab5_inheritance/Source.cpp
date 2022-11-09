/* Завод
 По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2←P21)
- во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
-- во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
-- во всех классах создать деструкторы;
-- во всех классах создать метод вывода объекта на экран (всех его параметров);
-- остальные методы создавать по необходимости.

Создать класс с множественным наследованием (P11 ← P3 → P21). Создать в этом классе выше описанные
функции (в коде функций не использовать доступ к данным через оператор разрешения зоны видимости ::).

В головной функции создать экземпляр класса P3. Вывести содержимое экземпляра класса P3 на экран.
Проверить, что получится, если не будет использовано виртуальное наследование.
*/

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
		City(City), Factory_name(Factory_name){}
	Factory(Factory& other)
	{
		this->City = other.City;
		this->Factory_name = other.Factory_name;
	}
	~Factory()
	{
		City.clear();
	}
	const string& getCity() const
	{
		return City;
	}
	void setCity(const string &city)
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
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
	}
};

class Industry : virtual public Factory
{
protected:
	string Industry_name;

public:
	Industry(string Factory_name="", string City="", string Industry_name="") :Factory(City, Factory_name), Industry_name(Industry_name) {};
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
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << "The inductry is " << Industry_name << endl;
	}
};

class CEO : virtual public Factory
{
private: 
	string CEOInfo = "CEO";

protected:
	string Name;
	int Age;
public:
	CEO(string Factory_name="", string City="", string Name="", int Age=0) :Factory(City, Factory_name), Name(Name), Age(Age) {};
	~CEO()
	{
		CEOInfo.clear();
	}
	const string& GetCEOInfo()const
	{
		return CEOInfo;
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
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << CEOInfo << endl;
		cout << "The CEO name is " << Name << endl;
		cout << "He's age is " << Age << endl;
	}
};

class Worker :virtual public CEO
{
protected:
	int Experience;
public:
	Worker(string City="", string Factory_name="", string Name="", int Age=0, int Experience=0) :Factory(City, Factory_name),
		CEO(City, Factory_name,Name,Age),Experience(Experience) {};
	~Worker(){}

	int getExperience() const
	{
		return Experience;
	}
	void setExperience(int experience)
	{
		Experience = experience;
	}
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is llocated in " << City << endl;
		cout << "The CEO name is " << Name << endl;
		cout << "He's age is " << Age << endl;
		cout << " Experience is" << Experience << endl;
	}
};

class Products :virtual public Industry
{
protected:
	string Products_name;
public:
	Products(string City="", string Factory_name="", string Industry_name="", string Products_name="") :Factory(City, Factory_name),
	Industry(City, Factory_name,Industry_name), Products_name(Products_name) {};
	~Products()
	{
		Products_name.clear();
	}
	string getProducts_name()const
	{
		return Products_name;
	}
	string setProducts_name(string products_name)
	{
		Products_name = products_name;
	}
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It is located in " << City << endl;
		cout << "The inductry name is " << Industry_name << endl;
		cout << "Products are " << Products_name << endl;
	}
};

class Consumers :public Worker, public Products
{
protected:
	int Amount;
public:
	Consumers(Consumers& other) :Worker(other), Products(other), CEO(other), Industry(other), Factory(other)
	{
		this->Factory_name = other.Factory_name;
		this->City = other.City;
		this->Industry_name = other.Industry_name;
		this->Name = other.Name;
		this->Age = other.Age;
		this->Experience = other.Experience;
		this->Products_name = other.Products_name;
	}
	Consumers(const string Factory_name = "", string City = "", string Industry_name = "", string Name = "", int Age = 0, int Experience = 0,
		string Products_name = "") :
		Factory(City, Factory_name), 
		Industry(City, Factory_name, Industry_name),
		CEO(City, Factory_name, Name, Age), 
		Worker(City, Factory_name, Name, Age, Experience),
		Products(City, Factory_name, Industry_name, Products_name), Amount(Amount) {}
	~Consumers() {}
	int getAmount()const
	{
		return Amount;
	}
	void setAmount(int amount)
	{
		Amount = amount;
	}
	void inputData()
	{
			cout << endl;
	        cout << "Enter the Factory's name: ";
			cin >> Factory_name;
			cout << "Enter the city: ";
			cin >> City;
			cout << "Enter the inductry: ";
			cin >> Industry_name;
			cout << "Enter the name of products ";
			cin >> Products_name;
			cout << "Enter the CEO's name: ";
			cin >> Name;
			cout << "Enter his age: ";
			cin >> Age;
			cout << "Enter the experience: ";
			cin >> Experience;
			cout << "Enter the amount: ";
			cin >> Amount;
			cout << endl;
	}
	virtual void show()
	{
		cout << "The factory's name is " << Factory_name << endl;
		cout << "It's located in " << City << endl;
		cout << " " << endl;
		cout << "The inductry is " << Industry_name << endl;
		cout << "The products are " << Products_name << endl;
		cout << " " << endl;
		cout << "The CEO name is " << Name << endl;
		cout << "He's age is " << Age << endl;
		cout << " " << endl;
		cout << "The amount is " << Amount << endl;
	}
	
};

int main()
{
	cout << "Input data for Consumers:" << endl;
	Consumers a;
	a.inputData();
	a.show();

	system("pause");
	return 0;
}