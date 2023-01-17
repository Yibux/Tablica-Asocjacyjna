//
// Created by root on 1/17/23.
//

#ifndef TABLICA_ASOCJACYJNA_EMPLOYEE_H
#define TABLICA_ASOCJACYJNA_EMPLOYEE_H
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Employee{
    string name;
    string postion;
    int age;
public:
    Employee(string a="", string b="", int c=0) : name(a), postion(b), age(c) {}
    friend ostream& operator<<(ostream& s, const Employee& e)
    {
        const char * Name = e.name.c_str();
        const char * Position = e.position.c_str();
        printf("%-20s%-20s%-5d",Name, Position, e.age);
        return s;
    }
};
#endif //TABLICA_ASOCJACYJNA_EMPLOYEE_H
