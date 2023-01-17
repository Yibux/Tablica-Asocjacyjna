//
// Created by root on 1/17/23.
//

#ifndef TABLICA_ASOCJACYJNA_MAP_H
#define TABLICA_ASOCJACYJNA_MAP_H
#include <iostream>

using namespace std;

template <class Number, class Employee> class Map{
    struct array
    {
        Employee data;
        Number ID;
    };
    vector<array> data;
public:
    Map(): {};

#endif //TABLICA_ASOCJACYJNA_MAP_H
