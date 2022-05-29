#ifndef OOP_TASK_CASH_DESK_H
#define OOP_TASK_CASH_DESK_H

#include <memory>
#include "hall.h"
#include "film.h"
#include "person.h"

class Action{
protected:
    Hall* hall;
public:
    Action() = default;
    virtual void Do(int num1, int num2) = 0;
};

class Booking: public Action{

public:
    Booking(Hall* h);
    void Do(int num1, int num2) override;
};

class UnBooking: public Action{
public:
    UnBooking(Hall* h);
    void Do(int num1, int num2) override;
};

class UnderAge: public Action{
public:
    UnderAge(Hall* h);
    void Do(int num1, int num2) override;
};

class CashDesk{
    Person* buyer;
    Film* film;
    Hall* hall;
    template<bool B>
    void BookPlaceHelper(int num1, int num2) {
        typedef typename std::conditional<B, Booking, UnderAge>::type Type;
        Type action = Type(hall);
        action.Do(num1, num2);
    }
    template<bool B>
    void UnBookPlaceHelper(int num1, int num2){
        typedef typename std::conditional<B, UnBooking, UnderAge>::type Type;
        Type action = Type(hall);
        action.Do(num1, num2);
    }
public:
    CashDesk(Hall* h):hall(h), buyer(nullptr), film(nullptr){};
    ~CashDesk();
    void SetCustomer(Person* person);
    void SetFilm(Film* filmName);
    void SetHall(Hall* h);
    void BookPlace(int num1, int num2);
    void UnBookPlace(int num1, int num2);
};
#endif //OOP_TASK_CASH_DESK_H
