#include "../headers/emp.h"

Employee::Employee()
{
    std::strcpy(fname, "No name");
    std::strcpy(lname, "No name");
    std::strcpy(job, "No job");
}

Employee::Employee(char *fn, char *sn, char *j)
{
    std::strncpy(fname, fn, std::strlen(fn) > SLEN ? SLEN : std::strlen(fn));
    std::strncpy(lname, sn, std::strlen(sn) > SLEN ? SLEN : std::strlen(sn));
    std::strncpy(job, j, std::strlen(j) > SLEN ? SLEN : std::strlen(j));
}

Employee::Employee(const Employee& e)
{
    std::strncpy(fname, e.fname, std::strlen(e.fname) > SLEN ? SLEN : std::strlen(e.fname));
    std::strncpy(lname, e.lname, std::strlen(e.lname) > SLEN ? SLEN : std::strlen(e.lname));
    std::strncpy(job, e.job, std::strlen(e.job) > SLEN ? SLEN : std::strlen(e.job));
}

void Employee::show_all() const
{
    std::cout << "Employee's firstname is " << fname << std::endl;
    std::cout << "Lastname is " << lname << std::endl;
    std::cout << "Job is " << job << std::endl;
}

void Employee::set_all()
{
    std::cout << "Enter the employee's firstname, lastname and job:\n";
    std::cin >> fname;
    std::cin >> lname;
    std::cin >> job;
}

std::ostream& operator<<(std::ostream& os, const Employee& e)
{
    os << e.fname;
    os << " " << e.lname;
    os << ", " << e.job << std::endl;
    return os;
}

Manager::Manager()
{
    Employee();
    inchargeof = 0;
}

Manager::Manager(char *fn, char *sn, char *j, int inch) : Employee(fn, sn, j)
{
    inchargeof = inch;
}

Manager::Manager(const Employee& e, int inch) : Employee(e)
{
    inchargeof = inch;
}

Manager::Manager(const Manager& m) : Employee(m)
{
    inchargeof = m.inchargeof;
}

void Manager::show_all() const
{
    Employee::show_all();
    std::cout << "Inchargeof is " << inchargeof << std::endl;
}

void Manager::set_all()
{
    Employee::set_all();
    std::cout << "Enter the manager's inchargeof: ";
    std::cin >> inchargeof;
}

Fink::Fink() : Employee()
{
    std::strcpy(reportsto, "No name");
}

Fink::Fink(char *fn, char *sn, char *j, char *rpo) : Employee(fn, sn, j)
{
    std::strncpy(reportsto, rpo, std::strlen(rpo) > SLEN ? SLEN : std::strlen(rpo));
}

Fink::Fink(const Employee& e, char *rpo) : Employee(e)
{
    std::strncpy(reportsto, rpo, std::strlen(rpo) > SLEN ? SLEN : std::strlen(rpo));
}

Fink::Fink(const Fink& f) : Employee(f)
{
    std::strncpy(reportsto, f.reportsto, std::strlen(f.reportsto) > SLEN ? SLEN : std::strlen(f.reportsto));
}

void Fink::show_all() const
{
    Employee::show_all();
    std::cout << "Reports to " << reportsto << std::endl;
}

void Fink::set_all()
{
    Employee::set_all();
    std::cout << "Enter who is reported to: ";
    std::cin >> reportsto;
}

Highfink::Highfink() : Employee(), Manager(), Fink()
{}

Highfink::Highfink(char *fn, char *sn, char *j, int inch, char *rpo) :
    Employee(fn, sn, j), Manager(fn, sn, j, inch), Fink(fn, sn, j, rpo)
{}

Highfink::Highfink(const Employee& e, int inch, char *rpo) : Employee(e), Manager(e, inch), Fink(e, rpo)
{}

Highfink::Highfink(const Manager& m, char *rpo) : Employee(m), Manager(m), Fink(m, rpo)
{}

Highfink::Highfink(const Fink& f, int inch) : Employee(f), Manager(f, inch), Fink(f)
{}

Highfink::Highfink(const Highfink& f) : Employee(f), Manager(f), Fink(f)
{}

void Highfink::show_all() const
{
    Employee::show_all();
    std::cout << "Inchargeof is " << inchargeof << std::endl;
    std::cout << "Reports to " << reportsto << std::endl;
}

void Highfink::set_all()
{
    Employee::set_all();
    std::cout << "Enter the inchargeof: ";
    std::cin >> inchargeof;
    std::cout << "Enter who is reported to: ";
    std::cin >> reportsto;
}
