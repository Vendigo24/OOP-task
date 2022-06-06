#ifndef OOP_TASK_FILM_H
#define OOP_TASK_FILM_H

#include <string>
#include <iostream>


class Film{
private:
    std::string name;
    int censorAge;
public:
    Film(std::string _name, int _censorAge): name(_name), censorAge(_censorAge){}
    int Get_Censor_Age() { return this->censorAge; }
    std::string Get_Name() {return this->name;}
    friend std::ostream& operator<<(std::ostream& os, const Film& film) {
        os<<film.name<<" ("<<film.censorAge<<"+)";
        return os;
    }
};


#endif //OOP_TASK_FILM_H
