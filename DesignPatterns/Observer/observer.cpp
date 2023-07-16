#include <iostream>
#include <vector>
using namespace std;
#include <boost/any.hpp>
using namespace boost;

struct Person;

struct PersonListener
{
	virtual ~PersonListener() = default;
	virtual void PersonChanged(Person& p, const string& property_name, const any new_value) = 0;
};

struct Person
{
	explicit Person(const int age)
		: age(age)
	{
	}

	virtual int GetAge() const
	{
		return age;
	}

	virtual void SetAge(const int age) 
	{
		if (this->age == age) return;
		this->age = age;
		notify("age", this->age);
	}

	void subscribe(PersonListener* pl) 
	{
		listeners.push_back(pl);
	}

	void notify(const string& property_name, const any new_value)
	{
		for (const auto listener : listeners)
			listener->PersonChanged(*this, property_name, new_value);
	
	}

private:
	int age;
	vector<PersonListener*> listeners;
};

struct ConsoleListener : PersonListener
{
	// Inherited via PersonListener
	virtual void PersonChanged(Person& p, const string& property_name, const any new_value) override
	{
		cout << "person's " << property_name << " has been changed to ";
		if (property_name == "age")
		{
			cout << any_cast<int>(new_value);
		}
		cout << "\n";
	}
};

int main()
{
	Person p{ 14 };
	ConsoleListener cl;
	p.subscribe(&cl);
	p.SetAge(15);
	p.SetAge(16);
}
