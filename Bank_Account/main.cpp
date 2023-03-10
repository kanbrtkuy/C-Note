#include<iostream>
#include<mutex>
using namespace std;

class Account
{
public:
    Account() :name(), money(0) {}
    Account(const string& na, int my) : name(na), money(my) {}
    ~Account() = default;
    const int GetMoney() const
    {
        return money;
    }
    void SetMoney(int m)
    {
        money = m;
    }
    const string& GetName()const
    {
        return name;
    }
private:
    string name;
    int money;
};

#if 1
mutex mtx1;
mutex mtx2;
void ThreadFun(Account& A, Account& B, int money)
{
    unique_lock<mutex> lock1(mtx1, defer_lock);
    unique_lock<mutex> lock2(mtx2, defer_lock);
    lock(lock1, lock2);

    if (A.GetMoney() >= money)
    {
        A.SetMoney(A.GetMoney() - money);
        B.SetMoney(B.GetMoney() + money);
    }
}

int main()
{
    Account A("xiaoming", 1000);
    Account B("zhangqiang", 2000);
    Account C("zq", 1500);
    thread tha(ThreadFun, std::ref(B), std::ref(A), 200); //A 1200 B 1800
    thread thb(ThreadFun, std::ref(B), std::ref(C), 500); //B 1300 C 2000
    thread thc(ThreadFun, std::ref(C), std::ref(A), 300); //A 1500 C 1700

    tha.join();
    thb.join();
    thc.join();
    //A 1500 B 1300 C 1700
    cout << A.GetName() << ": " << A.GetMoney() << endl;
    cout << B.GetName() << ": " << B.GetMoney() << endl;
    cout << C.GetName() << ": " << C.GetMoney() << endl;

    return 0;
}
#endif

