#include <iostream>

using namespace std;

//加号运算符重载
class Person
{
public:
    Person() = default;
    Person(int ma, int mb) : m_A(ma), m_B(mb){};
    //1.成员函数重载+号
    Person operator+(Person const &p) const
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    Person &operator+(int const &num)
    {
        this->m_A += num;
        this->m_B += num;
        return *this;
    }

    //Person p3 = p1.operator+(p2);
    int m_A;
    int m_B;
};

//全局函数重载 加号
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

//加法
void test01()
{
    // Person p1(0, 1);
    // Person p2(10, 20);
    // Person p3 = p1 + p2;
    // cout << "p3.m_a=" << p3.m_A << ",p3.m_b=" << p3.m_B << endl;

    // Person p4 = p1.operator+(p2); //函数重载的本质
    // cout << "p4.m_a=" << p4.m_A << ",p4.m_b=" << p4.m_B << endl;

    // Person p5(0, 10);
    // p5 + 1;                                                      //执行了
    // cout << "p5.m_a=" << p5.m_A << ",p5.m_b=" << p5.m_B << endl; //输出 1，11

#if 1
    Person p6(1,10);
    Person p7(0,2);
    Person p8  =p6+p7;//注释类内的，也可以用类外的，类内类外可以共存
    cout<<"p8.m_A= "<<p8.m_A<<",p8.m_B="<<p8.m_B<<endl;
#endif
}

int main()
{
    test01();
}