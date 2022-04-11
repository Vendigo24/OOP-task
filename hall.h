#ifndef OOP_TASK_HALL_H
#define OOP_TASK_HALL_H

#include <string>

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
    Place** places;
    FilmType filmType;
public:
    Hall() = default;
    ~Hall();
    void Set_Name(std::string _name);
    void Set_Place(Place** _place);
    void Set_Film_Type(FilmType _filmType);
    //TODO через консоль может быть?
    void Book_Place(int row, int col);
    void Cancel_Booking(int row, int col);
};

class HallBuilder{
private:
    Hall* hall;
    virtual Place** Create_Place(int row, int col);
public:
    HallBuilder() = default;
    ~HallBuilder() = default;
    virtual void Add_Film_Type();
    void Add_Name(std::string _name);
    virtual void Create_Placements(int row, int col);
    Hall* Get_Hall();
};


class TwoDFilmHall : public HallBuilder{
private:
    Place** Create_Place(int row, int col) override;
public:
    TwoDFilmHall() : HallBuilder() {};
    ~TwoDFilmHall() = default;
    void Add_Film_Type() override;
    void Create_Placements(int row, int col) override;
};

class ThreeDFilmHall : public HallBuilder{
private:
    Place** Create_Place(int row, int col) override;
public:
    ThreeDFilmHall() : HallBuilder() {};
    ~ThreeDFilmHall() = default;
    void Add_Film_Type() override;
    void Create_Placements(int row, int col) override;
};

class IMaxFilmHall : public HallBuilder{
private:
    Place** Create_Place(int row, int col) override;
public:
    IMaxFilmHall() : HallBuilder() {};
    ~IMaxFilmHall() = default;
    void Add_Film_Type() override;
    void Create_Placements(int row, int col) override;
};
#endif //OOP_TASK_HALL_H
