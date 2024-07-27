#include "../headers/emp.h"

int empPost(const std::string post)
{
    for(int i = 0; i < 4; ++i)
        if (post == post_names[i])
            return i;
    exit(1);
}

Employee::Employee()
{
    std::strcpy(fname, "No name");
    std::strcpy(lname, "No name");
    std::strcpy(job, "No job");
    post = EMPLOYEE;
}

Employee::Employee(char *fn, char *sn, char *j)
{
    std::strncpy(fname, fn, std::strlen(fn) > SLEN ? SLEN : std::strlen(fn));
    std::strncpy(lname, sn, std::strlen(sn) > SLEN ? SLEN : std::strlen(sn));
    std::strncpy(job, j, std::strlen(j) > SLEN ? SLEN : std::strlen(j));
    post = EMPLOYEE;
}

Employee::Employee(const Employee& e)
{
    std::strncpy(fname, e.fname, std::strlen(e.fname) > SLEN ? SLEN : std::strlen(e.fname));
    std::strncpy(lname, e.lname, std::strlen(e.lname) > SLEN ? SLEN : std::strlen(e.lname));
    std::strncpy(job, e.job, std::strlen(e.job) > SLEN ? SLEN : std::strlen(e.job));
    post = e.post;
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

void Employee::write_all(std::ofstream& fout)
{
    if (!fout.is_open())
        return;
    fout << post_names[post] << '\n' << fname << " " << lname << '\n';
    fout << "Job is " << job << '\n';
}

void Employee::read_all(std::ifstream& fin)
{
    if (!fin.is_open())
        return;
    fin >> fname >> lname;
    while(fin.get() != ' ') continue;
    while(fin.get() != ' ') continue;
    fin >> job;
}

Manager::Manager()
{
    Employee();
    inchargeof = 0;
    post = MANAGER;
}

Manager::Manager(char *fn, char *sn, char *j, int inch) : Employee(fn, sn, j)
{
    inchargeof = inch;
    post = MANAGER;
}

Manager::Manager(const Employee& e, int inch) : Employee(e)
{
    inchargeof = inch;
    post = MANAGER;
}

Manager::Manager(const Manager& m) : Employee(m)
{
    inchargeof = m.inchargeof;
    post = m.post;
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

void Manager::write_all(std::ofstream& fout)
{
    if (!fout.is_open())
        return;
    Employee::write_all(fout);
    fout << "Inchargeof is " << inchargeof << '\n';
}

void Manager::read_all(std::ifstream& fin)
{
    if (!fin.is_open())
        return;
    Employee::read_all(fin);
    while(!isdigit(fin.peek()))
        fin.get();
    fin >> inchargeof;
}

Fink::Fink() : Employee()
{
    std::strcpy(reportsto, "No name");
    post = FINK;
}

Fink::Fink(char *fn, char *sn, char *j, char *rpo) : Employee(fn, sn, j)
{
    std::strncpy(reportsto, rpo, std::strlen(rpo) > SLEN ? SLEN : std::strlen(rpo));
    post = FINK;
}

Fink::Fink(const Employee& e, char *rpo) : Employee(e)
{
    std::strncpy(reportsto, rpo, std::strlen(rpo) > SLEN ? SLEN : std::strlen(rpo));
    post = FINK;
}

Fink::Fink(const Fink& f) : Employee(f)
{
    std::strncpy(reportsto, f.reportsto, std::strlen(f.reportsto) > SLEN ? SLEN : std::strlen(f.reportsto));
    post = f.post;
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

void Fink::write_all(std::ofstream& fout)
{
    if (!fout.is_open())
        return;
    Employee::write_all(fout);
    fout << "Reports to " << reportsto << '\n';
}

void Fink::read_all(std::ifstream& fin)
{
    if (!fin.is_open())
        return;
    Employee::read_all(fin);
    while(fin.get() != ' ') continue;
    while(fin.get() != ' ') continue;
    fin >> reportsto;
}

Highfink::Highfink() : Employee(), Manager(), Fink()
{
    post = HIGHFINK;
}

Highfink::Highfink(char *fn, char *sn, char *j, int inch, char *rpo) :
    Employee(fn, sn, j), Manager(fn, sn, j, inch), Fink(fn, sn, j, rpo)
{
    post = HIGHFINK;
}

Highfink::Highfink(const Employee& e, int inch, char *rpo) : Employee(e), Manager(e, inch), Fink(e, rpo)
{
    post = HIGHFINK;
}

Highfink::Highfink(const Manager& m, char *rpo) : Employee(m), Manager(m), Fink(m, rpo)
{
    post = HIGHFINK;
}

Highfink::Highfink(const Fink& f, int inch) : Employee(f), Manager(f, inch), Fink(f)
{
    post = HIGHFINK;
}

Highfink::Highfink(const Highfink& f) : Employee(f), Manager(f), Fink(f)
{
    post = f.post;
}

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

void Highfink::write_all(std::ofstream& fout)
{
    if (!fout.is_open())
        return;
    Employee::write_all(fout);
    fout << "Inchargeof is " << inchargeof << '\n';
    fout << "Reports to " << reportsto << '\n';
}

void Highfink::read_all(std::ifstream& fin)
{
    if (!fin.is_open())
        return;
    Employee::read_all(fin);
    while(!isdigit(fin.peek()))
        fin.get();
    fin >> inchargeof;
    while(fin.get() != ' ') continue;
    while(fin.get() != ' ') continue;
    fin >> reportsto;
}
