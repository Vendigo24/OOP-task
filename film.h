#ifndef OOP_TASK_FILM_H
#define OOP_TASK_FILM_H

#include <string>
#include <concepts>

class Film{
private:
    std::string name;
    int censorAge;
public:
    Film(std::string _name, int _censorAge): name(_name), censorAge(_censorAge){}
    int Get_Censor_Age(){ return this->censorAge; }
};

template<class Film>
concept OnlyEighteen = requires(Film film){
    film.Get_Censor_Age() >= 18;
};

template<class Film>
concept OnlySixteen = requires(Film film){
    film.Get_Censor_Age() >= 16;
};

template<class Film>
concept AllAges = requires(Film film){
    film.Get_Censor_Age() >= 0;
};
#endif //OOP_TASK_FILM_H
