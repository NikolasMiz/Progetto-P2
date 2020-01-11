#ifndef QONTAINER_H
#define QONTAINER_H
#include<iostream>

template<class T>
class Qontainer {

    class node;

public:

    Qontainer();
    Qontainer(Qontainer<T>&);
    Qontainer& operator= (const Qontainer &);
    ~Qontainer();

    void push_front(const T&);

    void remove(T&);
    unsigned int size() const;
    bool empty() const;
    void clear();

    class iterator;
    class const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator c_begin() const;
    const_iterator c_end() const;

    class iterator {
            friend class Qontainer<T>;

        public:
            iterator(node* = nullptr);

            T& operator* () const;
            T* operator->() const;

            iterator& operator++();
            iterator operator++(int);

            bool operator== (const iterator &) const;
            bool operator!= (const iterator &) const;

        private:
            node *p;

    };
    class const_iterator {
            friend class Qontainer<T>;

        public:
            const_iterator(node* = nullptr);

            const T& operator* () const;
            const T* operator->() const;

            const_iterator& operator++();
            const_iterator operator++(int);

            bool operator== (const const_iterator &) const;
            bool operator!= (const const_iterator &) const;

        private:
            const node *c_p;

    };

private:

    node *first;
    unsigned int elem;
    class node {
        public:
            node();
            node(const T&, node* = nullptr);
            ~node();

            static node* clone(node *);
            static node* last(node *); //navigazione fino all'ultimo nodo

            T data;
            node *next;
    };

};

template<class T>
Qontainer<T>::Qontainer() : first(nullptr), elem(0)
{}

template<class T>
Qontainer<T>::Qontainer(Qontainer<T> &q)
{
    if(q.first) {
        first = node::clone(q.first);
    }
}
template<class T>
Qontainer<T>& Qontainer<T>::operator=(const Qontainer<T> &q)
{
    if(this == &q) {
        delete first;
        first = Qontainer<T>::node::clone(q.first);
    }
    return *this;
}

template<class T>
Qontainer<T>::~Qontainer()
{
    delete first;
}

template<class T>
void Qontainer<T>::push_front(const T &data)
{
    first = new node(data, first);
    elem++;
}

template<class T>
void Qontainer<T>::remove(T& data)
{
    if(empty()) return;

    if(data == first->data) {
        node *tmp = first;
        first = first->next;

        if(!first) { elem = 0; return; }
        tmp->next = nullptr;
        delete tmp;
        elem--;

        return;
    }

    node* nav = first;
    node *prev = nullptr;

    while(nav && data != nav->data) {
        prev = nav;
        nav = nav->next;
    }

    if(nav) {
        prev->next = nav->next;
        nav->next = nullptr;
        delete nav;
        elem--;
    }

}

template<class T>
unsigned int Qontainer<T>::size() const
{
    return size;
}

template<class T>
bool Qontainer<T>::empty() const
{
    return elem == 0;
}

template<class T>
void Qontainer<T>::clear()
{
    elem = 0;
    delete first;
    first = nullptr;
}

template<class T>
typename Qontainer<T>::iterator Qontainer<T>::begin()
{
    return iterator(first);
}

template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::begin() const
{
    return const_iterator(first);
}

template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::c_begin() const
{
    return const_iterator(first);
}

template<class T>
typename Qontainer<T>::iterator Qontainer<T>::end()
{
    return iterator();
}

template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::end() const
{
    return const_iterator();
}

template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::c_end() const
{
    return const_iterator();
}

template <class T>
Qontainer<T>::iterator::iterator(Qontainer<T>::node *n) : p(n)
{}

template<class T>
T &Qontainer<T>::iterator::operator*() const
{
    return p->data;
}

template<class T>
T* Qontainer<T>::iterator::operator->() const
{
    return &(p->data);
}

template<class T>
typename Qontainer<T>::iterator &Qontainer<T>::iterator::operator++()
{
    if(p)
        p = p->next;
    return *this;
}

template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++(int)
{
    iterator tmp =*this;
    if(p)
        p = p->next;
    return tmp;
}

template<class T>
bool Qontainer<T>::iterator::operator==(const Qontainer<T>::iterator &i) const
{
    return p == i.p;
}

template<class T>
bool Qontainer<T>::iterator::operator!=(const Qontainer<T>::iterator &i) const
{
    return p != i.p;
}


template<class T>
Qontainer<T>::const_iterator::const_iterator(Qontainer<T>::node *n) : c_p(n)
{}

template<class T>
const T &Qontainer<T>::const_iterator::operator*() const
{
    return c_p->data;
}

template<class T>
const T* Qontainer<T>::const_iterator::operator->() const
{
    return &(c_p->data);
}

template<class T>
typename Qontainer<T>::const_iterator &Qontainer<T>::const_iterator::operator++()
{
    if(c_p)
        c_p = c_p->next;
    return *this;
}

template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator++(int)
{
    iterator tmp =*this;
    if(c_p)
        c_p = c_p->next;
    return tmp;
}

template<class T>
bool Qontainer<T>::const_iterator::operator==(const Qontainer<T>::const_iterator &i) const
{
    return c_p == i.c_p;
}

template<class T>
bool Qontainer<T>::const_iterator::operator!=(const Qontainer<T>::const_iterator &i) const
{
    return c_p != i.c_p;
}

template<class T>
Qontainer<T>::node::node() : next(nullptr)
{

}

template<class T>
Qontainer<T>::node::node(const T& data, Qontainer::node* n) : data(data), next(n)
{

}
template<class T>
Qontainer<T>::node::~node()
{
    delete next;
}

template<class T>
typename Qontainer<T>::node *Qontainer<T>::node::clone(Qontainer<T>::node *n)
{
    if(!n) {
        return nullptr;
    } else {
        auto nNode = new node(n->data, node::clone(n->next));
        nNode->elem = n->elem;
    }
}

template<class T>
typename Qontainer<T>::node *Qontainer<T>::node::last(Qontainer<T>::node *n)
{
    if(n) {
        auto nav = n;
        while(nav->next != nullptr){ nav = nav->next; }
        return nav;
    } else {
        return nullptr;
    }
}

#endif

