#ifndef MODEL_H
#define MODEL_H

#include <core/bnb.h>
#include <core/qontainer.h>

#include <gui/query.h>

#include <QString>


class Model {
public:
    Model(QString path);

    ~Model();

    void filter(Query query) const;

    void resetFilter() const;

    Qontainer<BnB *> *getData() const;

    Qontainer<BnB *> *getResult() const;

    void addItem(BnB *);

    void deleteItem(BnB *, bool = true);

    void save();

    void load(QString path) const;

    bool getIsEdited() const;

private:
    QString path;
    Qontainer<BnB *> *data;
    Qontainer<BnB *> *filteredResult;
    bool isEdited;

};

#endif // MODEL_H
