#include "Heuristics.h"

double ManhattanDistance::estimatedCost(Position curr, Position goal)
{
    double sum = 0;
    int result_x = curr.getPositionX() - goal.getPositionX();
    int sum_x = abs(result_x);
    int result_y = curr.getPositionY() - goal.getPositionY();
    int sum_y = abs(result_y);
    sum = sum_x + sum_y - 1;
    return sum;
}

double AirialDistance::estimatedCost(Position curr, Position goal)
{
    double sum = 0;
    int result_x = curr.getPositionX() - goal.getPositionX();
    double sum_x = pow(result_x, 2);
    int result_y = curr.getPositionY() - goal.getPositionY();
    double sum_y = pow(result_y, 2);
    sum = sqrt(sum_x + sum_y);
    return sum;
}
