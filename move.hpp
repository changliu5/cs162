
#ifndef MOVE_H 
#define MOVE_H
#include <iostream> 
#include <cstdlib> //random
#include <ctime> // random number


#include <cstdlib>
#include <stdio.h> //printf

using namespace std;


class ant{
  private:
    int pc, pr, row,col;
    char d;
    char clrr;
 
  public:
    ant();
    ant(int pr,int pc);
    
    void getrow2(int row1);
    int getrow();

    void getcol2(int col1);
    int getcol();

    void clor2(char clr);
    char clor();

    void dir2(char dr);
    char dir();
    
    void nrow2(int row2);
    int nrow();
    
    void ncol2(int col2);
    int ncol();
};

#endif
