#ifndef OOP_TASK_PERSON_H
#define OOP_TASK_PERSON_H

#include <string>
#include <concepts>

class Person{
protected:
    std::string name;
    int age;
public:
    Person(): name("Ivan"), age(30){}
    Person(std::string _name, int _age): name(_name), age(_age){}
    int Get_Age();
};

template<class Human>
concept OverEighteen = requires (Human h){
    h.Get_Age > 18;
};

template<class Human>
concept OverSixteen = requires (Human h){
    h.Get_Age > 16;
};
#endif //OOP_TASK_PERSON_H
