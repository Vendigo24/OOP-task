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
    std::string name;
    Vector<Vector<Place>> places;
    FilmType filmType;
public:

    ~Hall() = default;
    void Set_Name(std::string _name);
    void Set_Place(Vector<Vector<Place>>* _place);
    void Set_Film_Type(FilmType _filmType);
    void Book_Place(int _row, int _col);
    void Cancel_Booking(int _row, int _col);
    void Show_hall();
    void Reset_Hall();
    Hall() = default;
};


class HallBuilder{
protected:
    Hall* hall;
    void Add_Film_Type(FilmType _filmType);
    void Add_Name(std::string _name);

    virtual void Create_Placements(int row, int col) = 0;
public:
    HallBuilder():hall(nullptr) {}
    virtual ~HallBuilder() {}

    virtual void  Create_Hall(std::string name, int row, int col) = 0;
    Hall* Get_Hall();
};


class TwoDFilmHall : public HallBuilder{
protected:
   void Create_Placements(int row, int col) override;
public:
    TwoDFilmHall() : HallBuilder(){}
    ~TwoDFilmHall() override { delete hall; hall = nullptr;}
    void Create_Hall(std::string name, int row, int col) override;
};


class ThreeDFilmHall: public HallBuilder{
protected:
    void Create_Placements(int row, int col) override;
public:
    ThreeDFilmHall() : HallBuilder(){}
    ~ThreeDFilmHall() override { delete hall; hall = nullptr;}
    void Create_Hall(std::string name, int row, int col) override;
};


class IMaxFilmHall: public HallBuilder{
protected:
    void Create_Placements(int row, int col) override;
public:
    IMaxFilmHall() : HallBuilder(){}
    ~IMaxFilmHall() override { delete hall; hall = nullptr;}
    void Create_Hall(std::string name, int row, int col) override;
};

#endif //OOP_TASK_HALL_H


