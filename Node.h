#pragma once
#include <stdio.h>
#include "Maze.h"

class Node
{
private:
    double f;
    double g;
    Node* parent;
    Position pos;
public:
    Node() { parent = nullptr; f = 0; g = 0; }
    Node(Position p) { pos = p; parent = nullptr; f = 0; g = 0; }
    Node(const Node& node) { pos = node.getPos(); parent = new Node; parent = node.getParent(); f = node.getF(); g = node.getG(); }
    Node& operator=(const Node &node) {  if(&node == this) return *this; pos = node.getPos(); parent = new Node; parent = node.getParent(); f = node.getF(); g = node.getG(); return *this; };
    ~Node(){ delete parent; };
    void setParent(Node* p) { parent = new Node; parent = p; }
    void setPos(Position p) { pos = p; }
    Node* getParent() const { return parent; }
    void setF(double _f) { f =_f; }
    double getF() const { return f; }
    void setG(double _g) { g =_g; }
    double getG() const { return g; }
    Position getPos() const { return pos; }
};


class myComperator
{
public:
   int operator() (Node* p1, Node* p2 ) { return p1->getF() > p2->getF(); }
};