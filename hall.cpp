#include "hall.h"
#include <iostream>

void Hall::Set_Name(std::string _name) {
    this->name = _name;
}


void Hall::Set_Place(Vector<Vector<Place>>* _place) {
    places = Vector<Vector<Place>>(1, Vector<Place>(1, EmptyPlace));
    places = *_place;
}


void Hall::Set_Film_Type(FilmType _filmType) {
    this->filmType = _filmType;
}


void Hall::Show_hall() {
    std::cout<<this->name<<std::endl;
    auto begin = this->places.begin();
    auto end = this->places.end();
    for(; begin != end; ++begin) {
        for (auto place : *begin){
            switch(place){
                case 0:{
                    std::cout<<" "<<" ";
                    break;
                }
                case 1:{
                    std::cout<<"*"<<" ";
                    break;
                }
                case 2:{
                    std::cout<<"X"<<" ";
                    break;
                }
            }
        }
        std::cout<<std::endl;
    }
}


void Hall::Book_Place(int _row, int _col) {
    if(this->places[_row][_col] == EmptyPlace)
        this->places[_row][_col] = BookedPlace;
}


void Hall::Cancel_Booking(int _row, int _col) {
    if(this->places[_row][_col] == BookedPlace)
        this->places[_row][_col] = EmptyPlace;
}


void Hall::Reset_Hall() {
    for(auto & place : places)
        for(auto & col : place)
            if(col == BookedPlace)
                col = EmptyPlace;
}


void HallBuilder::Add_Film_Type(FilmType _filmType) {
    hall->Set_Film_Type(_filmType);
}


void HallBuilder::Add_Name(std::string _name) {
    hall->Set_Name(_name);
}


void TwoDFilmHall::Create_Placements(int row, int col) {
    hall->Set_Place(new Vector<Vector<Place>>(row, Vector<Place>(col, EmptyPlace)));
}


void TwoDFilmHall::Create_Hall(std::string name, int row, int col) {
    hall = new Hall();
    Add_Name(name);
    Create_Placements(row, col);
    Add_Film_Type(TwoDFilms);
}


Hall* HallBuilder::Get_Hall() {
    return hall;
}


void ThreeDFilmHall::Create_Placements(int row, int col) {
    auto place = Vector<Vector<Place>>(row, Vector<Place>(col, EmptyPlace));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if((i == (row/4) || i == (3 * row)/4 - 1) || (j == (col/4) || j == (3 * col)/4 - 1))
                place[i][j] = NotSitingPlace;
    hall->Set_Place(&place);
}


void ThreeDFilmHall::Create_Hall(std::string name, int row, int col) {
    hall = new Hall();
    Add_Name(name);
    Create_Placements(row, col);
    Add_Film_Type(ThreeDFilms);
}


void IMaxFilmHall::Create_Placements(int row, int col) {
    auto place = Vector<Vector<Place>>(row, Vector<Place>(col, EmptyPlace));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(i + j < col/2 || j > (col/2 + i) - 1 || i > (row/2 + j) -1 || i + j - 4 > row)
                place[i][j] = NotSitingPlace;
    hall->Set_Place(&place);
}


void IMaxFilmHall::Create_Hall(std::string name, int row, int col) {
    hall = new Hall();
    Add_Name(name);
    Create_Placements(row, col);
    Add_Film_Type(IMaxFilms);
}
