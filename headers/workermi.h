#ifndef WORKERMI_H
#define WORKERMI_H

#include "../headers/strings.h"

class Worker
{
private:
    Strings fullname;
    long id;
protected:
    virtual void data() const;
    virtual void get();
public:
    Worker() : fullname("no one"), id(0L){}
    Worker(const Strings& s, long n) : fullname(s), id(n){}
    virtual ~Worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void data() const;
    void get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const Strings& s, long n, int p = 0) : Worker(s, n), panache(p){}
    Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p){}
    ~Waiter() {};
    void set();
    void show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void data() const;
    void get();
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const Strings& s, long n, int v = other) : Worker(s, n), voice(v){}
    Singer(const Worker& wk, int v = other) : Worker(wk), voice(v){}
    ~Singer() {};
    void set();
    void show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
    void data() const;
    void get();
public:
    SingingWaiter() {}
    SingingWaiter(const Strings& s, long n, int p = 0, int v = Singer::other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
    SingingWaiter(const Worker& wk, int p = 0, int v = Singer::other) : Waiter(wk, p), Singer(wk, v){}
    SingingWaiter(const Waiter& wt, int v = Singer::other) : Worker(wt), Waiter(wt), Singer(wt, v){}
    SingingWaiter(const Singer& wt, int p = 0) : Worker(wt), Singer(wt), Waiter(wt, p){}
    void set();
    void show() const;
};

#endif // WORKERMI_H
