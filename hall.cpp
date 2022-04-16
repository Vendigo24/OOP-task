#include "hall.h"
#include <iostream>
#include <utility>

Hall::~Hall() {
    for(auto i = 0; i < row; i++){
        delete[] places[i];
        this->places[i] = nullptr;
    }
    delete[] this->places;
    this->places = nullptr;
}


void Hall::Set_Name(std::string _name) {
    this->name = std::move(_name);
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

void HallBuilder::Add_Name(std::string _name) {
    this->hall->Set_Name(std::move(_name));
}

void HallBuilder::Add_Film_Type(FilmType _filmType) {
    this->hall->Set_Film_Type(_filmType);
}

void HallBuilder::Create_Placements(int row, int col) {
    this->hall = nullptr;
}