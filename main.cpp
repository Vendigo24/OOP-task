#include <iostream>
#include <map>
#include <string>
#include <concepts>
#include <utility>


class Person{
protected:
std::string name;
std::string surname;
int age;

public:
    Person() = default;
    Person(std::string&& _name, std::string&& _surname, int _age):
    name(std::move(_name)), surname(std::move(_surname)), age(_age){

    }
    void Show(){
        std::cout<<"Name: "<<this->name<<std::endl;
        std::cout<<"Surname: "<<this->surname<<std::endl;
        std::cout<<"Age: "<<this->age<<std::endl;
    }
};

class Male: public Person{
public:
    Male():Person(){
        this->name = "Ivan";
        this->surname = "Ivanov";
        this->age = 30;
    }
    Male(std::string&& _name, std::string&& _surname, int _age):
    Person(std::move(_name), std::move(_surname), _age){}


    void static Testosterone(){
        std::cout<<"My hormone is testosterone";
    }
};

class Female: public Person{
public:
    Female():Person(){
        this->name = "Olga";
        this->surname = "Ivanova";
        this->age = 30;
    }
    Female(std::string&& _name, std::string&& _surname, int _age):
    Person(std::move(_name), std::move(_surname), _age){}
    void static Oestrogen(){
        std::cout<<"My hormone is oestrogen";
    }
};

template <class Human>
concept IsMan = requires(Human human){
    human.Testosterone();
};

template <class Human>
concept IsWoman = requires(Human human){
    human.Oestrogen();
};

class Company{
private:
    std::string name;
protected:
    double wages;
    std::map<Person, double> Workers;

public:
    Company(): name("SomeCorp."), wages(10000.0){}
    Company(std::string _name, double _wages):name(std::move(_name)), wages(_wages){}
    void RecruitPerson(const Person& person){
        Workers[person] = wages;
    }

    void virtual ChangeWages(double percentage);

    void Dismiss(){
        Workers.clear();
    }
};

//TODO добавить классы компаний по шахте и сурагатному материнству
//TODO реализовать концепты для компаний
//TODO реализовать паттерн command


int main() {
    return 0;
}
