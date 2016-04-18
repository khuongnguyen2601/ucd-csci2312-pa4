//
// Created by kai on 4/17/16.
//
#include<iomanip>
#include"Strategic.h"

namespace Gaming
{
    const char Strategic::STRATEGIC_ID = 'ST';

    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s):
            Agent(g,p,energy),
            __strategy(s)
    {

    }

    Strategic::~Strategic()
    {
        delete __strategy;
    }

    void Strategic::print(std::ostream &os) const
    {
        os << STRATEGIC_ID << std::left << std::setw(4) << __id << std::setw(0);
    }

    ActionType Strategic::takeTurn(const Surroundings &s) const
    {
        return (*__strategy)(s);
    }

}