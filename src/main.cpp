#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "../headers/queue.h"

const int MIN_PER_HOUR = 60;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    std::cout << "Bank of Heather\n";
    std::cout << "Enter maximum size of queue: ";
    int max_line;
    std::cin >> max_line;

    std::queue<Item> line;
    std::cout << "Enter the number of simulation hours: ";
    int hours;
    std::cin >> hours;
    long cyclelimit = MIN_PER_HOUR * hours;
    std::cout << "Enter the average number of customers per hour: ";
    double cust_per_hour;
    std::cin >> cust_per_hour;
    double min_per_cust = MIN_PER_HOUR / cust_per_hour;

    Item cust;
    long turnaways = 0; //ушедших клиентов от полной очереди
    long customers = 0; //присоединений к очереди
    long served = 0;    //обслуженных клиентов
    long sum_line = 0;  //совокупная длина очереди
    int wait_time = 0;  //период времени когда автоотвечтик свободен
    long line_wait = 0; //общее время в линии

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (new_customer(min_per_cust))
        {
            if (line.size() == max_line)
                turnaways++;
            else
            {
                customers++;
                cust.set(cycle);
                line.push(cust);
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
           cust = line.front();
           line.pop();
           wait_time = cust.ptime();
           line_wait += cycle - cust.when();
           served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    if(customers > 0)
    {
        std::cout << "\ncustomers accepted: " << customers << std::endl;
        std::cout << "customers served: " << served << std::endl;
        std::cout << "customers turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout.setf(std::ios_base::showpoint);
        std::cout << (double)sum_line / cyclelimit << std::endl;
        std::cout << "average line wait time: ";
        std::cout << (double)line_wait / served << std::endl;
    }
    else
        std::cout << "No customers!" << std::endl;

    return 0;
}
