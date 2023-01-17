//
// Created by root on 1/17/23.
//

#ifndef TABLICA_ASOCJACYJNA_MAP_H
#define TABLICA_ASOCJACYJNA_MAP_H
#include <iostream>

using namespace std;

template <class Number, class Data> class map_template{
    struct node
    {
        node* next;
        Data data;
        Number ID;
        node(Number id) : next(NULL), ID(id) {}
    };
    node* head;
public:
// konstruktor
    map_template(): head(NULL) {}
// konstruktor kopiujacy
    map_template(const map_template& database)
    {
        node *src, **dst;
        head = NULL;
        src = database.head;
        dst = &head;
        head = NULL;
        while (src)
        {
            *dst = new node (*src);
            src = src->next;
            dst = &((*dst)->next);
        }
    }
//destruktor
    ~map_template()
    {
        while (head)
        {
            node* t = head->next;
            delete head;
            head = t;
        }
    }
//operator przypisania
    map_template& operator=(const map_template& database)
    {
        if (&database == this)
            return *this;
        map_template t(database);
        node *a = head;
        head = t.head;
        t.head = a;
        return *this;
    }
//funkcja addd
    void Add(Number ID, Data date)
    {
        node* newNode = new node(ID);
        newNode->next = head;
        head = newNode;
        head->data = date;
    }
//funkcja find
    Data* Find(Number id) const
    {
        node* curr = head;
        while (curr)
        {
            if (curr->ID == id)
                return &curr->data;
            curr = curr->next;
        }
        return NULL;
    }
//wyswietlanie
    friend ostream& operator<<(ostream& s, const map_template& d)
    {
        node* curr = d.head;
        while (curr)
        {
            cout << curr->data;
            cout << curr->ID << endl;
            curr = curr->next;
        }
        return s;
    }
};
#endif //TABLICA_ASOCJACYJNA_MAP_H
