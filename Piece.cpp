//
// Created by kai on 4/17/16.
//
#include"Piece.h"

namespace Gaming
{
    unsigned int Piece::__idGen = 1000;

    Piece::Piece(const Game &g, const Position &p):
            __game(g),
            __position(p),
            __finished(false),
            __turned(false),
            __id(Piece::__idGen++)
    {

    }

    Piece::~Piece()
    {

    }

    std::ostream& operator<<(std::ostream& os, const Piece &other)
    {
        other.print(os);
        return os;
    }
}
