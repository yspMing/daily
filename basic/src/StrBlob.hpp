#include <vector>
#include <memory>
#include <string>
#include <exception>

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    typedef std::vector<std::string> elem_type;
    StrBlob(/* args */);
    StrBlob(std::initializer_list<std::string> il);

    /* realized */
    bool empty() const { return data->empty(); }
    size_type size() const { return data->size(); }
    void push_back(const std::string &t) { data->push_back(t); }

    /*unrealized*/
    void pop_back();
    const std::string &front();
    const std::string &back();
    ~StrBlob();

private:
    std::shared_ptr<elem_type> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(/* args */)
{
    data = std::make_shared<elem_type>();
}

StrBlob::StrBlob(std::initializer_list<std::string> il)
{
    data = std::make_shared<elem_type>(il);
}

StrBlob::~StrBlob()
{
}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i > data->size())
        throw std::out_of_range(msg);
}

const std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob!");
    return data->front();
}

const std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob!");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob!");
    data->pop_back();
}