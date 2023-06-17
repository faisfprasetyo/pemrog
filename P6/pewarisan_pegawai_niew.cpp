#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Employee
{
protected:
  string id_;
  int age_;
  int type_;
  int income_;

public:
  void set(string id, int age, int type)
  {
    id_ = id;
    age_ = age;
    type_ = type;
  }

  string get_id() { return id_; }

  void print() { cout << id_ << " " << type_ << " " << income_ << endl; }
};

class PermanentEmployee : public Employee
{
public:
  PermanentEmployee() { income_ = 0; }
  void set_overtime_pay(int amount) { income_ += amount; }
};

class DailyEmployee : public Employee
{
public:
  DailyEmployee() { income_ = 0; }
  void set_daily_pay(int amount) { income_ += amount; }
};

int main()
{
  vector<PermanentEmployee> permanent_employees;
  vector<DailyEmployee> daily_employees;
  int base_salary;
  int num_employees;
  cin >> num_employees;
  for (int i = 0; i < num_employees; i++)
  {
    string id;
    int age, type;
    PermanentEmployee perm_emp;
    DailyEmployee daily_emp;
    cin >> id >> age >> type;
    if (type == 1)
    {
      cin >> base_salary;
      perm_emp.set_overtime_pay(base_salary);
      perm_emp.set(id, age, type);
      permanent_employees.push_back(perm_emp);
    }
    else
    {
      daily_emp.set(id, age, type);
      daily_employees.push_back(daily_emp);
    }
  }
  while (true)
  {
    string id, get_id;
    int income;
    int status = 0;
    cin >> id;
    if (id == "END")
      break;
    for (int ct = 0; ct < permanent_employees.size(); ct++)
    {
      get_id = permanent_employees[ct].get_id();
      if (get_id == id)
      {
        cin >> income;
        permanent_employees[ct].set_overtime_pay(income);
        status = 1;
      }
    }
    if (status == 0)
    {
      for (int ch = 0; ch < daily_employees.size(); ch++)
      {
        get_id = daily_employees[ch].get_id();
        if (get_id == id)
        {
          cin >> income;
          daily_employees[ch].set_daily_pay(income);
        }
      }
    }
  }

  for (int i = 0; i < permanent_employees.size(); i++)
  {
    permanent_employees[i].print();
  }
  for (int j = 0; j < daily_employees.size(); j++)
  {
    daily_employees[j].print();
  }

  return 0;
}