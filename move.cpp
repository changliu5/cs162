/***************************************************
 * Function: move.cpp;
 * Description: function of change direction, row and col changes to #, row or col gets incremented, row and col changes to *,
 * Parameters: no more than input row and col
 * Pre-Conditions: get input from main calculate by many ant function
 * Post-Conditions: None
 ***************************************************/

#include"move.hpp"
#include <iostream> 
#include <cstdlib> //random
#include <ctime> // random number
#include <cstdlib>
#include <stdio.h> //printf



ant::ant(){
}

ant::ant(int pr,int pc){
  getrow2(pr);
  getcol2(pc);
  clor2(' ');
  dir2('d');

}
void ant::getrow2(int row1){
  pr=row1;
}
int ant::getrow(){
  return pr;
}


void ant::getcol2(int col1){
  pc=col1;
}
int ant::getcol(){ 
  return pc;
}
void ant::clor2(char clr){
  clrr=clr;
}
char ant::clor(){
  return clrr;
}
void ant::dir2(char dr){
  d=dr;
}
char ant::dir(){
  return d;
}
void ant::nrow2(int row2){
      row=row2;
    } 
int ant::nrow(){
      return row;
    }
    
void ant::ncol2(int col2){
      col=col2;
    }
int ant::ncol(){
      return col;
    }
