#ifndef MOVE_H
#define MOVE_H

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmore() const;
    Move add(const Move& m) const;
    void reset(double a = 0, double b = 0);
};

#endif // MOVE_H
