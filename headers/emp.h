#pragma once

#include <cstring>
#include <iostream>
#include <fstream>

enum post_t{
    EMPLOYEE,
    MANAGER,
    FINK,
    HIGHFINK
};

const int SLEN = 20;
const std::string post_names[] = {"Employee", "Manager", "Fink", "Highfink"};

int empPost(const std::string post);

class Employee
{
protected:
    char fname[SLEN];
    char lname[SLEN];
    char job[SLEN];
    post_t post;

public:
    Employee();
    Employee(char *fn, char *sn, char *j);
    Employee(const Employee& e);
    virtual void show_all() const;
    virtual void set_all();
    virtual void write_all(std::ofstream& fout);
    virtual void read_all(std::ifstream& fout);
    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
};

class Manager : virtual public Employee
{
protected:
    int inchargeof;
public:
    Manager();
    Manager(char *fn, char *sn, char *j, int inch = 0);
    Manager(const Employee& e, int inch);
    Manager(const Manager& m);
    void show_all() const override;
    void set_all() override;
    void write_all(std::ofstream& fout) override;
    void read_all(std::ifstream& fout) override;
};

class Fink : virtual public Employee
{
protected:
    char reportsto[SLEN];
public:
    Fink();
    Fink(char *fn, char *sn, char *j, char *rpo);
    Fink(const Employee& e, char *rpo);
    Fink(const Fink& f);
    void show_all() const override;
    void set_all() override;
    void write_all(std::ofstream& fout) override;
    void read_all(std::ifstream& fout) override;
};

class Highfink : public Manager, public Fink
{
public:
    Highfink();
    Highfink(char *fn, char *sn, char *j, int inch, char *rpo);
    Highfink(const Employee& e, int inch, char *rpo);
    Highfink(const Manager& m, char *rpo);
    Highfink(const Fink& f, int inch);
    Highfink(const Highfink& f);
    void show_all() const override;
    void set_all() override;
    void write_all(std::ofstream& fout) override;
    void read_all(std::ifstream& fout) override;
};
