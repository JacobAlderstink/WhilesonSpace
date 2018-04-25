#ifndef CHUNCKLIST_H
#define CHUNCKLIST_H


class chunck
{
public:
    chunck(int planetSize, int yLowerBound, int yUpperBound);

private:
    chunck();
    int startingY;
    int endingY;
    chunck* next;

};

#endif // CHUNCKLIST_H
