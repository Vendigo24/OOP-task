#include <iostream>
#include "cash_desk.h"

Booking::Booking(Hall *h) {
    hall = h;
}

void Booking::Do(int num1, int num2) {
    hall->Book_Place(num1, num2);
}

UnBooking::UnBooking(Hall *h) {
    hall = h;
}

void UnBooking::Do(int num1, int num2) {
    hall->Cancel_Booking(num1,num2);
}

UnderAge::UnderAge(Hall *h) {
    hall = h;
}

void UnderAge::Do(int num1, int num2) {
    std::cout<<"You cannot watch this film!"<<std::endl;
}


void CashDesk::BookPlace(int num1, int num2) {
    if(buyer->Get_Age() >= film->Get_Censor_Age())
        BookPlaceHelper<true>(num1, num2);
    else
        BookPlaceHelper<false>(num1, num2);
}

void CashDesk::SetCustomer(Person* person) {
    buyer = person;
}

void CashDesk::SetFilm(Film* filmName) {
    film = filmName;
}

void CashDesk::SetHall(Hall *h) {
    this->hall = h;
}

void CashDesk::UnBookPlace(int num1, int num2) {
    if(buyer->Get_Age() >= film->Get_Censor_Age())
        UnBookPlaceHelper<true>(num1, num2);
    else
        UnBookPlaceHelper<false>(num1, num2);
}


CashDesk::~CashDesk() {
    delete buyer;
    delete film;
    delete hall;
    buyer = nullptr;
    film = nullptr;
    hall = nullptr;
}
