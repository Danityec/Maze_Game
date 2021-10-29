#include "Algorithm.h"
using namespace std;

bool CommonSearcher::openListCheck(Position *pos, double f)
{
    auto pair = make_pair(pos->getPositionX(), pos->getPositionY());
    it_mapOpenList = mapOpenList.find(pair);
    if (it_mapOpenList != mapOpenList.end())
    {
        if (it_mapOpenList->second > f)
        {
            mapOpenList.erase(it_mapOpenList);
            auto p = make_pair(pair, f);
            mapOpenList.insert(p);
            return true;
        }
        else
            return false;
    }
    auto p = make_pair(pair, f);
    mapOpenList.insert(p);
    return true;
}

double Astar::f(double h, double g, double cost)
{
    double f = h + g + cost;
    return f;
}

string *Astar::search(Heuristics *heuristic, Maze *maze)
{
    int findl = 0, findr = 0, findu = 0, findd = 0;
    string *solution = new string;
    Position current = maze->getStartPosition();
    Position goal = maze->getGoalPosition();
    maze->setCurrPosition(current);
    Node n(current);
    n.setF(heuristic->estimatedCost(current, goal));
    openList.push(&n);
    openListCheck(&current, heuristic->estimatedCost(current, goal));
    Node *curr = new Node;
    string *pos_moves = new string;

    while (!openList.empty())
    {
        curr = openList.top();
        current = curr->getPos();
        maze->setCurrPosition(curr->getPos());
        openList.pop();

        if (current == goal)
            break;

        pos_moves->clear();
        pos_moves = maze->getPossibleMoves();
        findl = pos_moves->find("L");
        findr = pos_moves->find("R");
        findu = pos_moves->find("U");
        findd = pos_moves->find("D");
        double h = 0;
        double f = 0;

        if (findl != (-1))
        { 
            Position left = current;
            left.setPositionY(current.getPositionY() - 1);
            h = heuristic->estimatedCost(left, goal);
            f = Astar::f(h, curr->getG(), 1);

            if (openListCheck(&left, f))
            {
                Node *L = new Node;
                L->setPos(left);
                L->setParent(curr);
                L->setF(f);
                L->setG(curr->getG() + 1);
                openList.push(L);
            }
        }
        if (findr != (-1))
        {
            Position right = current;
            right.setPositionY(current.getPositionY() + 1);
            h = heuristic->estimatedCost(right, goal);
            f = Astar::f(h, curr->getG(), 1);

            if (openListCheck(&right, f))
            {
                Node *R = new Node;
                R->setPos(right);
                R->setParent(curr);
                R->setF(f);
                R->setG(curr->getG() + 1);
                openList.push(R);
            }
        }
        if (findu != (-1))
        {
            Position up = current;
            up.setPositionX(current.getPositionX() - 1);
            h = heuristic->estimatedCost(up, goal);
            f = Astar::f(h, curr->getG(), 1);

            if (openListCheck(&up, f))
            {
                Node *U = new Node;
                U->setPos(up);
                U->setParent(curr);
                U->setF(f);
                U->setG(curr->getG() + 1);
                openList.push(U);
            }
        }
        if (findd != (-1))
        {
            Position down = current;
            down.setPositionX(current.getPositionX() + 1);
            h = heuristic->estimatedCost(down, goal);
            f = Astar::f(h, curr->getG(), 1);

            if (openListCheck(&down, f))
            {
                Node *D = new Node;
                D->setPos(down);
                D->setParent(curr);
                D->setF(f);
                D->setG(curr->getG() + 1);
                openList.push(D);
            }
        }
        closedList.push(curr);
    }
    while (curr->getPos() != maze->getStartPosition())
    {
        if (curr->getParent()->getPos().getPositionX() < curr->getPos().getPositionX())
            *solution += "D";
        else if (curr->getParent()->getPos().getPositionX() > curr->getPos().getPositionX())
            *solution += "U";
        else if (curr->getParent()->getPos().getPositionY() < curr->getPos().getPositionY())
            *solution += "R";
        else if (curr->getParent()->getPos().getPositionY() > curr->getPos().getPositionY())
            *solution += "L";

        curr = curr->getParent();
    }
    reverse(solution->begin(),solution->end());

    delete curr, pos_moves;
    return solution;
}

double BestFirstSearch::f(double g)
{
    double f = g;
    return f;
}

string *BestFirstSearch::search(Heuristics *heuristic, Maze *maze)
{
    int findl = 0, findr = 0, findu = 0, findd = 0;
    string *solution = new string;
    Position current = maze->getStartPosition();
    Position goal = maze->getGoalPosition();
    maze->setCurrPosition(current);
    Node n(current);
    n.setF(1);
    openList.push(&n);
    openListCheck(&current, 1);
    Node *curr = new Node;
    string *pos_moves = new string;

    while (!openList.empty())
    {
        curr = openList.top();
        current = curr->getPos();
        maze->setCurrPosition(curr->getPos());
        openList.pop();
        if (current == goal)
            break;

        pos_moves->clear();
        pos_moves = maze->getPossibleMoves();

        findl = pos_moves->find("L");
        findr = pos_moves->find("R");
        findu = pos_moves->find("U");
        findd = pos_moves->find("D");
        double f = 0;

        if (findl != (-1))
        {
            Position left = current;
            left.setPositionY(current.getPositionY() - 1);
            f = BestFirstSearch::f(curr->getG() + 1);

            if (openListCheck(&left, f))
            {
                Node *L = new Node;
                L->setPos(left);
                L->setParent(curr);
                L->setF(f);
                L->setG(curr->getG() + 1);
                openList.push(L);
            }
        }
        if (findr != (-1))
        {
            Position right = current;
            right.setPositionY(current.getPositionY() + 1);
            f = BestFirstSearch::f(curr->getG() + 1);

            if (openListCheck(&right, f))
            {
                Node *R = new Node;
                R->setPos(right);
                R->setParent(curr);
                R->setF(f);
                R->setG(curr->getG() + 1);
                openList.push(R);
            }
        }
        if (findu != (-1))
        {
            Position up = current;
            up.setPositionX(current.getPositionX() - 1);
            f = BestFirstSearch::f(curr->getG() + 1);

            if (openListCheck(&up, f))
            {
                Node *U = new Node;
                U->setPos(up);
                U->setParent(curr);
                U->setF(f);
                U->setG(curr->getG() + 1);
                openList.push(U);
            }
        }
        if (findd != (-1))
        {
            Position down = current;
            down.setPositionX(current.getPositionX() + 1);
            f = BestFirstSearch::f(curr->getG() + 1);

            if (openListCheck(&down, f))
            {
                Node *D = new Node;
                D->setPos(down);
                D->setParent(curr);
                D->setF(f);
                D->setG(curr->getG() + 1);
                openList.push(D);
            }
        }
        closedList.push(curr);
    }

    while ((curr->getPos() != maze->getStartPosition()))
    {
        if (curr->getParent()->getPos().getPositionX() < curr->getPos().getPositionX())
            *solution += "D";
        else if (curr->getParent()->getPos().getPositionX() > curr->getPos().getPositionX())
            *solution += "U";
        else if (curr->getParent()->getPos().getPositionY() < curr->getPos().getPositionY())
            *solution += "R";
        else if (curr->getParent()->getPos().getPositionY() > curr->getPos().getPositionY())
            *solution += "L";

        curr = (curr->getParent());
    }
    reverse(solution->begin(), solution->end());

    delete curr, pos_moves;
    return solution;
}
