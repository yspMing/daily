#pragma once
#include<iostream>
#include<string>

using std::string;

class person
{
public:
	person(const char* name="ZS")
		:_name(name)
	{
		std::cout << "default constructor for person\n";
	}
	person(const person& other)
		:_name(other._name),_age(other._age)
	{
		std::cout << "copy constructor for person: " << _name << "\n";
	}
	person& operator=(const person& p)
	{
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
	void print()
	{
		std::cout << "person name: " << _name << "\n";
		std::cout << "Person age: " << _age << "\n";
	}

protected:
	string _name = "ZS";
	int _age = 17;
};

class student : public person
{
public:
	student(const char* name = "LS", int num = 1)
		:person(name), _num(num)
	{
		std::cout << "default constructor for student\n";
	}
	student(const student& other)
		:person(other), _num(other._num)
	{}
	student& operator=(const student& s)
	{
		if (this != &s)
		{
			person::operator=(s);
			_num = s._num;
		}
		return *this;
	}
	void print(int x)
	{
		std::cout << "student name: " << _name << "\n";
		std::cout << "student age: " << _age << "\n";
		std::cout << "student num: " << _num << "\n";
	}
protected:
	string _name = "LS";
	int _age = 18;
	int _num = 12;
};

void personTest()
{
	student s;
	s.print(0);
	std::cout << std::endl;
	s.person::print();
}