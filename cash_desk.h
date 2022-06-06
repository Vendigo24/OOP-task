#ifndef OOP_TASK_CASH_DESK_H
#define OOP_TASK_CASH_DESK_H

#include "hall.h"
#include "film.h"
#include "person.h"

class Action{
protected:
    Hall *hall;
public:
    Action() = default;
    virtual void Do(int num1, int num2) = 0;
};

class Booking: public Action{
public:
    Booking(Hall *h);
    void Do(int num1, int num2) override;
};

class Cancel: public Action{
public:
    Cancel(Hall *h);
    void Do(int num1, int num2) override;
};

class Underage: public Action{
public:
    Underage(Hall *h);
    void Do(int num1, int num2) override;
};

class CashDesk{
    Person* buyer;
    Film* film;
    Hall* hall;
    template<bool B>
    void Book_Place_Helper(int num1, int num2) {
        typedef typename std::conditional<B, Booking, Underage>::type Type;
        Type action = Type(hall);
        action.Do(num1, num2);
    }
    template<bool B>
    void Cancel_Booked_Place_Helper(int num1, int num2){
        typedef typename std::conditional<B, Cancel, Underage>::type Type;
        Type action = Type(hall);
        action.Do(num1, num2);
    }
public:
    CashDesk():hall(nullptr), buyer(nullptr), film(nullptr){};
    ~CashDesk();
    void Set_Customer(Person* person);
    void Set_Film(Film* filmName);
    void Set_New_Hall(Hall* h);
    void Book_Place(int num1, int num2);
    void Cancel_Booking(int num1, int num2);
};
#endif //OOP_TASK_CASH_DESK_H
