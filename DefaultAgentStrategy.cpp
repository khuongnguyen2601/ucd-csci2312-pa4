//
// Created by kai on 4/17/16.
//
#include<vector>
#include"Game.h"
#include"DefaultAgentStrategy.h"

namespace Gaming
{
    DefaultAgentStrategy::DefaultAgentStrategy()
    {}

    DefaultAgentStrategy::~DefaultAgentStrategy()
    {}

    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
    {
        std::vector<int> Simple, Strategy, Advantage, Food, Empty;
        Position pos(1,1);
        for(unsigned i = 0; i < 9; ++i)
            switch(s.array[i])
            {

                case SIMPLE: Simple.push_back(i);
                    break;
                case STRATEGIC: Strategy.push_back(i);
                    break;
                case ADVANTAGE: Advantage.push_back(i);
                    break;
                case FOOD: Food.push_back(i);
                    break;
                case EMPTY: Empty.push_back(i);
                    break;
            }

        if(Advantage.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Advantage));

        if(Food.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Food));

        if(Empty.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Empty));

        if(Simple.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Simple));

        return STAY;

    }
}
