#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.hpp"

using std::shared_ptr;
using std::make_shared;
using std::string;

namespace basic{

struct Item
{
    int val = 1234;

    Item()
    {
        std::cout << "Item constrctor" <<std::endl;
    }
    ~Item()
    {
        std::cout << "Item destrctor" <<std::endl;
    }
};

static int constrct_deconstruct()
{
    std::shared_ptr<Item> item1(new Item());
    std::shared_ptr<Item> item2 = std::make_shared<Item>();
    std::shared_ptr<Item> item3(item1);
    std::weak_ptr<Item> item4 = item1;
    std::cout << item1.use_count() << std::endl;
    std::cout << item2.use_count() << std::endl;
    return 0;
}

/*
	share_ptr use example;
*/
static int ff()
{
	shared_ptr<int> p = make_shared<int>(1);
	shared_ptr<int> q = make_shared<int>(2);
	/*Notice that use_count cost much time, usually only used in debug mode*/
	std::cout<<"use_count for (p,q)="<<"("<<p.use_count()<<","<<q.use_count()<<")"<<std::endl;

	auto p1 = p;
	auto p2 = p;
	std::cout<<"use_count for (p,q)="<<"("<<p.use_count()<<","<<q.use_count()<<")"<<std::endl;

	p1 = q;
	std::cout<<"use_count for (p,q)="<<"("<<p.use_count()<<","<<q.use_count()<<")"<<std::endl;

	shared_ptr<string> p_str = make_shared<string>();
	if(p_str && p_str->empty())
	{
		std::cout<<"p_str: "<<p_str<<" is empty!"<<std::endl;
		*p_str = "hello world!";
		std::cout<<"now p_str is "<<*p_str<<std::endl;
	}

	return 0;

}

static shared_ptr<string> factory(char ch)
{
	shared_ptr<string> s = make_shared<string>(5,ch);
	return s;
}

static shared_ptr<string> use_factory(char ch)
{
	shared_ptr<string> s = factory(ch);
	std::cout<<"use_factory creating: "<<*s<<" ,use_count:"<<s.use_count()<<std::endl;
	return s;
}

static int call_function(int a, int b, int(*func)(int,int))
{
	int sum = func(a,b);
	return sum;
}

static int my_sum_function(int x, int y)
{
	return x + y;
}

void runSmartPointer()
{
	/*
	shared_ptr<string> s = use_factory('a');

	vector<string> v1;
	{
		vector<string> v2 = {"apple", "banana", "berry"};
		v1 = v2;
	}
	vector<string>::iterator it = v1.begin();
	vector<string>::size_type v1_len = v1.size();
	cout<<v1_len<<endl;
	while(it != v1.end())
	{
		cout<<*it<<endl;
		it++;
	}
	*/
	int call_func_res = call_function(3,5,my_sum_function);
	std::cout<<"call_function executed result: "<<call_func_res<<std::endl;

	StrBlob b1;
	{
		StrBlob b2({"apple","banana","berry"});
		b1 = b2;
		b2.push_back("peach");
	}
	std::cout<<"b1->front: "<<b1.front()<<std::endl;
	std::cout<<"b1->back: "<<b1.back()<<std::endl;
}

}