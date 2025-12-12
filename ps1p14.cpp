#include <iostream>
#include <string>
using namespace std;

// =========================
// BASE CLASS: Employee
// =========================
class Employee
{
public:
    Employee();
    ~Employee();

    void FirstName(string fn);
    string FirstName();

    void LastName(string ln);
    string LastName();

    void Salary(float s);
    float Salary();

    virtual float Bonus();    // virtual so Manager can override

protected:
    string m_fn, m_ln;
    float m_salary;
    float m_bonus;
};

// =========================
// Employee Methods
// =========================
Employee::Employee()
{
    m_salary = 0.0f;
    m_bonus = 0.0f;
}

Employee::~Employee()
{
    cout << "Destructor: Employee object removed." << endl;
}

void Employee::FirstName(string fn)
{
    m_fn = fn;
}

string Employee::FirstName()
{
    return m_fn;
}

void Employee::LastName(string ln)
{
    m_ln = ln;
}

string Employee::LastName()
{
    return m_ln;
}

void Employee::Salary(float s)
{
    m_salary = s;
}

float Employee::Salary()
{
    return m_salary;
}

float Employee::Bonus()
{
    if (m_salary > 100000.0f)
        m_bonus = m_salary * 0.20f;
    else
        m_bonus = m_salary * 0.10f;

    return m_bonus;
}

// =========================
// DERIVED CLASS: Manager
// =========================
class Manager : public Employee
{
public:
    float Bonus() override;         // override base bonus method
    float Long_Term_Bonus();        // new method 50% of salary
};

// =========================
// Manager Methods
// =========================
float Manager::Bonus()
{
    // Override: managers always get 50% of salary
    m_bonus = m_salary * 0.50f;
    return m_bonus;
}

float Manager::Long_Term_Bonus()
{
    // long-term bonus also 50%
    return m_salary * 0.50f;
}

// =========================
// MAIN PROGRAM
// =========================
int main()
{
    Manager mgr;

    // Load data
    mgr.FirstName("Yan");
    mgr.LastName("Mamboleo");
    mgr.Salary(120000.0f);

    // Display object info
    cout << "----- MANAGER INFO -----\n";
    cout << "First Name: " << mgr.FirstName() << endl;
    cout << "Last Name: " << mgr.LastName() << endl;
    cout << "Salary: $" << mgr.Salary() << endl;

    cout << "Annual Bonus (Overridden): $" << mgr.Bonus() << endl;
    cout << "Long-Term Bonus (50%): $" << mgr.Long_Term_Bonus() << endl;

    cout << "\nProgram complete.\n";
    system("pause");
    return 0;
}
