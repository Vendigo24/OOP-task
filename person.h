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
    int Get_Age() { return this->age; }
    std::string Get_Name() { return this->name;}
};

#endif //OOP_TASK_PERSON_H
