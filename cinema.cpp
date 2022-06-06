#include "cinema.h"

#include <utility>
#include "vector.h"
void Cinema::Start() {
    Vector<Hall*> halls;
    halls.add(Create_Hall(new TwoDFilmHall(), "Ocean", 15, 15));
    halls.add(Create_Hall(new ThreeDFilmHall(), "Summer times", 18, 20));
    halls.add(Create_Hall(new IMaxFilmHall(), "Joyful", 21, 25));
    Vector<Film*> films;
    films.add(new Film("Scream", 18));
    films.add(new Film("Soul", 6));
    films.add(new Film("Matrix", 16));
    desk = new CashDesk();
    for(auto film:films) {
        std::cout<<"Started booking session for "<<*film<<std::endl;
        for(auto hall: halls)
            hall->Reset_Hall();
        desk->Set_Film(film);
        int choice = -1;
        int row, col;
        while(choice != 0){
            std::cout<<"Choose one of this option:"<<std::endl;
            std::cout<<"0 - stop session"<<std::endl;
            std::cout<<"1 - book place"<<std::endl;
            std::cout<<"2 - cancel booking"<<std::endl;
            std::cout<<"3 - show halls' places"<<std::endl;
            std::cin>>choice;
            switch (choice) {
                case 0:
                    std::cout<<"Session ended!"<<std::endl;
                    break;
                case 1:
                    desk->Set_New_Hall(halls[Show_And_Get_Option_About_Hall("Which hall do you want to watch film in?:")]);
                    Set_Customer();
                    std::cout<<"Row: ";
                    std::cin>>row;
                    std::cout<<"Col: ";
                    std::cin>>col;
                    desk->Book_Place(row, col);
                    break;
                case 2:
                    desk->Set_New_Hall(halls[Show_And_Get_Option_About_Hall("Which hall are you going to cancel booking in?:")]);
                    Set_Customer();
                    std::cout<<"Row: ";
                    std::cin>>row;
                    std::cout<<"Col: ";
                    std::cin>>col;
                    desk->Cancel_Booking(row, col);
                    break;
                case 3:
                    for(auto hall:halls)
                        hall->Show_hall();
                    break;
                default:
                    std::cout<<"Wrong option!"<<std::endl;
            }
        }
    }

}

Hall *Cinema::Create_Hall(HallBuilder *builder, std::string name, int row, int col) {
    auto director = new Director();
    director->Set_Builder(builder);
    director->Build_Hall(std::move(name), row, col);
    return director->Get_Hall();
}

void Cinema::Set_Customer() {
    std::string name;
    int age;
    std::cout<<"Customer's name: ";
    std::cin>>name;
    std::cout<<"Customer's age: ";
    std::cin>>age;
    desk->Set_Customer(new Person(name, age));
}

int Cinema::Show_And_Get_Option_About_Hall(const std::string& text) {
    int hallIndex;
    std::cout<<text<<std::endl;
    std::cout<<"1 - Ocean"<<std::endl;
    std::cout<<"2 - Summer times"<<std::endl;
    std::cout<<"3 - Joyful"<<std::endl;
    std::cin>>hallIndex;
    return hallIndex -1;
}

