#include "hall.h"

int main() {
    ThreeDFilmHall d3;
    d3.Create_Placements(10, 10);
    Hall* h = d3.Get_Hall();
    h->Show_hall();
    return 0;
}
