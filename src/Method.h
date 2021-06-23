#include <iostream>

using namespace std;

// Отсутствие инкапсуляции
class Person
{
public:
    string Name;
    int age;

};

// Инкапсуляция с помощью set / get
class PersonName
{
private:
    string name;
public:
    void SetName(string Name)
    {
        if (Name.length() >= 2 && Name.length() <= 10)
            this->name = Name;
    }
    string GetName()
    {
        return name;
    }

};

//инкапсуляция с помощью специализированных протоколов/методов
class PersonAge
{
private:
    int age;
public:
    void aged ()
    {
        this->age = rand() % 30;
    }
    int getValue() const
    {
        return age;
    }
};

// Инкапсуляция за счёт абстракций
class Worker
{
public:
    virtual void setSalary(int salary) = 0;
    virtual void setSpent(int spent) = 0;
    virtual int getResult() const = 0;
    virtual void print() const = 0;
};

class WorkerOnFactory: public Worker {
private:
    int salary = 0;
    int spent = 0;
public:
    void setSalary(int salary) override {
        if (salary >= 0) {
            this->salary = salary;
        }
    }
    void setSpent(int spent) override
    {
        if (spent > salary){
            cout << "Dude, Change your work!" << endl;
        }
        else
        {
            this->spent = spent;
        }
    }

    int getResult() const override
    {
        int result = salary - spent;
        return result;
    }
    void print() const override
    {
        cout << "Factory Worker" << salary - spent << endl;
    }
};
// расширение поведения
class ModificatedWorker: public Worker
{
private:
    string Valuet = "";
    int salary = 0;
    int spent = 0;
public:
    void print() const override
    {
        cout << "Factory Worker" << salary - spent <<"Валюта:" << Valuet <<endl;
    }
    void setValuet(string Valuet_)
    {
        this->Valuet = Valuet_;
    }
};

// Замена поведения
class ChangedWorker: public Worker{
private:
    int salary = 0;
    int spent = 0;
public:
    void print() const override
    {
        for (int i = 0; i < 10; i++)
        {
            cout << salary << " <> " << spent << endl;
        }
    }
};
