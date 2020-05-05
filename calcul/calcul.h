#ifndef CALCUL_H
#define CALCUL_H

typedef struct score {
    int type;
    int h1;
    int h2;
    int h3;
    int h4;
    int h5;

    static bool compare(score s1, score s2)
    {
        return true;
    }
} s_score;

class calcul
{
public:
    calcul();
    void score();
};

#endif // CALCUL_H
