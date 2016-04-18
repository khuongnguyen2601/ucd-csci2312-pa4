//
// Created by kai on 4/17/16.
//
#include<iomanip>
#include"Simple.h"

namespace Gaming
{
    const char Simple::SIMPLE_ID = 'S';

    Simple::Simple(const Game &g, const Position &p, double energy): Agent(g,p,energy) {
    }

    Simple::~Simple() {
    }

    void Simple::print(std::ostream &os) const
    {
        os << SIMPLE_ID << std::left << std::setw(4) << __id << std::setw(0);
    }

    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        std::vector<int> res, empt;
        Position cur(1,1);
        for(int i = 0; i < 9; ++i)
        {
            if(s.array[i] == FOOD || s.array[i] == ADVANTAGE)
                res.push_back(i);
            else if (s.array[i] == EMPTY)
                empt.push_back(i);
        }
        if(res.size())
            return __game.reachSurroundings(cur, Game::randomPosition(res));
        else if (empt.size())
            return __game.reachSurroundings(cur, Game::randomPosition(empt));
        else
            return STAY;
    }
}
