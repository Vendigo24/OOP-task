#ifndef OOP_TASK_HALL_H
#define OOP_TASK_HALL_H

#include <string>
#include "vector.h"

enum Place{
    NotSitingPlace = 0,
    EmptyPlace = 1,
    BookedPlace = 2
};

enum FilmType{
    TwoDFilms = 0,
    ThreeDFilms = 1,
    IMaxFilms = 2
};


class Hall{
private:
    int row, col;
    std::string name;
    Vector<Vector<Place>> places;
    FilmType filmType;

public:
    Hall(): places(Vector<Vector<Place>>(0, Vector<Place>(0, NotSitingPlace))), row(0), col(0), filmType(static_cast<FilmType>(EmptyPlace)){}
    ~Hall();
    void Set_Name(std::string _name);
    void Set_Place(Place** _place, int _row, int _col);
    void Set_Film_Type(FilmType _filmType);
    void Book_Place(int _row, int _col);
    void Cancel_Booking(int _row, int _col);
    void Show_hall();
};

class HallBuilder{
protected:
    Hall* hall;
    virtual Place** Create_Place(int row, int col) = 0;
    void Add_Film_Type(FilmType _filmType);
    void Add_Name(std::string _name);
    void Create_Placements(int row, int col);
public:
    HallBuilder(): hall(nullptr){}
    virtual ~HallBuilder() {}
    virtual void Create_Hall(int row, int col) = 0;
    Hall* Get_Hall();
};

class TwoDFilmHall : public HallBuilder{
protected:
    Place** Create_Place(int row, int col) override;
public:
    TwoDFilmHall() : HallBuilder(){}
    ~TwoDFilmHall() {}
    void Create_Hall(int row, int col) override;
};



#endif //OOP_TASK_HALL_H


