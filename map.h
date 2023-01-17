//
// Created by root on 1/17/23.
//

#ifndef TABLICA_ASOCJACYJNA_MAP_H
#define TABLICA_ASOCJACYJNA_MAP_H
#include <iostream>
#include <vector>

using namespace std;

template <class Number, class Value> class Map {
    struct array {
        Value info;
        Number id;
    };
    vector<array> data;
public:
    Map() {};

    Map &operator=(const Map &database) {
        this->data = database.data;
        return *this;
    }

    void add(Number id, Value date) {
        if (find(id)) {
            return;
        }
        struct array pom;
        pom.info = date;
        pom.id = id;
        data.push_back(pom);
    }

    //find
    Value *find(Number id) {
        if (data.empty()) {
            return NULL;
        }
        for (unsigned int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                return &data[i].info;
            }
        }
        return NULL;
    }

    //wypisanie
    friend ostream &operator<<(ostream &os, const Map &x) {
        for (unsigned int i = 0; i < x.data.size(); i++) {
            os << x.data[i].info<<endl;
        }
        return os;
    }
    ~Map(){};
};
#endif //TABLICA_ASOCJACYJNA_MAP_H
