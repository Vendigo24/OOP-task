#include <iostream>
#include "cash_desk.h"
int main() {
    Director director;
    director.Set_Builder(new ThreeDFilmHall());
    director.Build_Hall("Ocean", 10, 20);
    auto* Ivan = new Person("Ivan", 21);
    Film* scream = new Film("Scream", 18);
    Hall* hall = director.Get_Hall();
    CashDesk cashDesk(hall);
    cashDesk.SetCustomer(Ivan);
    cashDesk.SetFilm(scream);
    cashDesk.BookPlace(0,0);
    hall->Show_hall();
    cashDesk.SetCustomer(new Person("Olga", 12));
    cashDesk.BookPlace(1,0);
    return 0;
}
