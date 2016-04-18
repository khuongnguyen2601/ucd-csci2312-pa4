//
// Created by kai on 4/17/16.
//
#include"Game.h"
#include"AggressiveAgentStrategy.h"

namespace Gaming
{
    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;

    AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy)
    {
        __agentEnergy=agentEnergy;
    }

    AggressiveAgentStrategy::~AggressiveAgentStrategy() {
    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const
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
        if(Simple.size() && __agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD)
            return Game::reachSurroundings(pos, Game::randomPosition(Simple));

        if(Advantage.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Advantage));

        if(Food.size())
            return Game::reachSurroundings(pos, Game::randomPosition(Food));

        return STAY;
    }

}
