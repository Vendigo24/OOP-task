#include <iostream>
#include "cash_desk.h"

Booking::Booking(Hall *h) {
    hall = h;
}

void Booking::Do(int num1, int num2) {
    hall->Book_Place(num1, num2);
}

Cancel::Cancel(Hall *h) {
    hall = h;
}

void Cancel::Do(int num1, int num2) {
    hall->Cancel_Booking(num1,num2);
}

Underage::Underage(Hall *h) {
    hall = h;
}

void Underage::Do(int num1, int num2) {
    std::cout<<"You cannot watch this film!"<<std::endl;
}


void CashDesk::BookPlace(int num1, int num2) {
    if(buyer->Get_Age() >= film->Get_Censor_Age())
        Book_Place_Helper<true>(num1, num2);
    else
        Book_Place_Helper<false>(num1, num2);
}

void CashDesk::Set_Customer(Person* person) {
    buyer = person;
}

void CashDesk::Set_Film(Film* filmName) {
    film = filmName;
}

void CashDesk::SetNewHall(Hall *h) {
    hall = h;
}

void CashDesk::UnBookPlace(int num1, int num2) {
    if(buyer->Get_Age() >= film->Get_Censor_Age())
        Cancel_Booked_Place_Helper<true>(num1, num2);
    else
        Cancel_Booked_Place_Helper<false>(num1, num2);
}


CashDesk::~CashDesk() {
    delete buyer;
    delete film;
    delete hall;
    buyer = nullptr;
    film = nullptr;
    hall = nullptr;
}
