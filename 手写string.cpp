#include <iostream>
#include <cstring>

using namespace std;

class String
{

public:
    String(const char *str = nullptr);
    String(const String &other);
    ~String();
    String &operator=(const String &other);

    char *getdata() const;

    void push_back(const char& ch);

private:
    char *m_data;
    int capacity;
    int idx;
};
ostream &operator<<(ostream &cout, String &p)
{
    cout << p.getdata();

    return cout;
}
void test01()
{
    String str("hello");

    cout << str << endl;

    str.push_back('a');
    str.push_back('b');
    str.push_back('c');
    str.push_back('d');
    str.push_back('e');

    cout<<str<<endl;

    String str2 = str;
    cout<<"str2="<<str2<<endl;

    // const char *str="wenjx";
    // char *mystr = new char[10];

    // strcpy(mystr,str);
    // cout<<mystr<<endl;

    // mystr[5]='u';
    // cout<<mystr<<endl;

}

int main()
{
    test01();

    return 0;
}

String::String(const char *str)
{
    this->capacity = 10;
    this->idx = 0;
    if (!str)
    {
        this->m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        if (this->capacity < length)
            capacity = length * 2;
        m_data = new char[capacity];
        //strcpy_s需要的参数是(char *,const char *),但是我们这边的m_data 类型是char *String::类型
        strcpy(m_data, str);
        this->idx = length;
    }
}

String::String(const String &other)
{
  int length = strlen(other.m_data);
    this->capacity = other.capacity;
    m_data = new char[capacity];
    this->idx = other.idx;
    strcpy(m_data, other.m_data);
}

String::~String()
{
    delete[] m_data;
}

String &String::operator=(const String &other)
{
    if (this == &other)
        return *this; //检查自赋值
    delete[] m_data;
    
    this->capacity = other.capacity;
    m_data = new char[capacity];
    this->idx = other.idx;
    strcpy(m_data, other.m_data);
    return *this;
    // TODO: 在此处插入 return 语句
}
char *String::getdata() const
{
    return this->m_data;
}
void String::push_back(const char& ch)
{
    if (idx == capacity)
    {
        capacity *= 2;
    }
    char *temp = new char[idx + 2];
    strcpy(temp, this->m_data);
    delete[] m_data;

    m_data = new char[capacity];
    strcpy(m_data, temp);

    delete[] temp;

    this->m_data[idx] = ch;
    ++idx;
}
