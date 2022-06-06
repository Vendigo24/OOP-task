#ifndef OOP_TASK_CINEMA_H
#define OOP_TASK_CINEMA_H

#include "cash_desk.h"


class Cinema {
    CashDesk* desk;
    Hall* Create_Hall(HallBuilder* builder, std::string name, int row, int col);
    void Set_Customer();
    int Show_And_Get_Option_About_Hall(std::string text);
public:
    Cinema() : desk(nullptr){}
    void Start();
};


#endif //OOP_TASK_CINEMA_H
