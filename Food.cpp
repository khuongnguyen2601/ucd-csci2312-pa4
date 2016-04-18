//
// Created by kai on 4/17/16.
//
#include<iomanip>
#include"Food.h"

namespace Gaming
{
    const char Food::FOOD_ID = 'F';

    Food::Food(const Game &g, const Position &p, double capacity): Resource(g,p,capacity)
    {

    }

    Food::~Food()
    {

    }

    void Food::print(std::ostream &os) const
    {
        os  << FOOD_ID << std::left << std::setw(4) << __id << std::setw(0);
    }

}
