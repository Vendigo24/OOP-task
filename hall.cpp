#include <iostream>
#include "hall.h"


Hall::~Hall() {
    for(auto i = 0; i < row; i++){
        delete[] places[i];
        this->places[i] = nullptr;
    }
    delete[] this->places;
    this->places = nullptr;
}


void Hall::Set_Name(std::string _name) {
    this->name = _name;
}


void Hall::Set_Place(Place** _place, int _row, int _col) {
    this->places = _place;
    this->row = _row;
    this->col = _col;
}


void Hall::Set_Film_Type(FilmType _filmType) {
    this->filmType = _filmType;
}


void Hall::Book_Place(int _row, int _col) {
    if(places[_row][_col] == EmptyPlace)
        places[_row][_col] = BookedPlace;
    else
        std::cout<<"You can't book this place!\n";
}


void Hall::Cancel_Booking(int _row, int _col) {
    if(places[_row][_col] == BookedPlace)
        places[_row][_col] = EmptyPlace;
    else
        std::cout<<"You can't cancel booking of this place!\n";
}


void Hall::Show_hall() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            std::cout<<places[i][j]<<" ";
        std::cout<<"\n";
    }
}


HallBuilder::~HallBuilder() {
    delete hall;
    hall = nullptr;
}


void HallBuilder::Add_Name(std::string _name) {
    hall->Set_Name(_name);
}


Hall* HallBuilder::Get_Hall() {
    return hall;
}


Place** TwoDFilmHall::Create_Place(int row, int col){
    Place** place;
    place = new Place*[row];
    for(int i = 0; i<row; i++)
        place[i] = new Place[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            place[i][j] = EmptyPlace;

    return place;
}


void TwoDFilmHall::Add_Film_Type() {
    this->hall->Set_Film_Type(TwoDFilms);
}


void TwoDFilmHall::Create_Placements(int row, int col) {
    Place** place = Create_Place(row, col);
    this->hall->Set_Place(place, row, col);
}


Place** ThreeDFilmHall::Create_Place(int row, int col){
    Place** place;
    place = new Place*[row];
    for(int i = 0; i<row; i++)
        place[i] = new Place[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if ((j != (int) (col / 4) && j != (int) (3 * col / 4)) ||
            (i != (int) (row / 4) &&  i != (int) (3 * row / 4)))
                place[i][j] = EmptyPlace;
            place[i][j] = NotSitingPlace;
        }

    return place;
}


void ThreeDFilmHall::Add_Film_Type() {
    this->hall->Set_Film_Type(ThreeDFilms);
}


void ThreeDFilmHall::Create_Placements(int row, int col) {
    Place** place = Create_Place(row, col);
    this->hall->Set_Place(place, row, col);
}


Place** IMaxFilmHall::Create_Place(int row, int col){
    Place** place;
    place = new Place*[row];
    for(int i = 0; i<row; i++)
        place[i] = new Place[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            place[i][j] = EmptyPlace;

    return place;
}


void IMaxFilmHall::Add_Film_Type() {
    this->hall->Set_Film_Type(IMaxFilms);
}


void IMaxFilmHall::Create_Placements(int row, int col) {
    Place** place = Create_Place(row, col);
    this->hall->Set_Place(place, row, col);
}