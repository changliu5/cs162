/*********************************************************************
 ** Program name: project1
 ** Author:chang liu
 ** Date:4/11/2018
 ** Description:main code for Langton's ant
 *********************************************************************/
#include "move.hpp"
#include <iostream>
#include <cstdlib> //random
#include <ctime> // random number
#include <cstdlib>
#include <stdio.h> //printf

using namespace std;

void menu(){
  cout<<endl<<endl<<endl<<"                  wellcome to Langton's ant!!!"<<endl<<endl<<endl<<endl;
  cout<<" 1. Start moving ant"<<endl;
  cout<<" 2. quit"<<endl;
}

void menu2(){
  cout<<" 4. Start playing again"<<endl;
  cout<<" 5. stop moving ant"<<endl;
}
  

int main(){
  int chs2,stp,row,col,chs,pr,pc,tem;
  char dir;
  bool r=false;
  
  menu();
  cin>>chs2;
  if(chs2==2)
    return 0;
  do{

  do{
  cout<<"please enter row"<<endl;
  cin>>row;
  cout<<"please enter col"<<endl;
  cin>>col;
  if(row<0 || col<0){
    r=false;
  }
  else
    r=true;
  }while(r==false);
  
  cout<<"do you want a ramdom initial position?1for yes 2 for no"<<endl;
  cin>>chs;
  if(chs==1){
    srand(time(NULL));
    pr=rand()%(row-1);
    pc=rand()%(col-1);   //generate random position
  }
  else{
  do{
    cout<<"please enter row"<<endl;
  cin>>pr;
  cout<<"please enter col"<<endl;
  cin>>pc;
  if(row<0 || col<0){
    r=false;
  }
  else
    r=true;
  }while(r==false);
  }
  
  // rules and how to run the program:
  char **brd=new char*[row];
  for (int i=0; i<row; i++)
    brd[i] = new char[col];
    
  for (int i=0; i<row; i++)
      for (int j=0; j<col; j++)
        brd[i][j]=' ';
 
  
  ant ant(pr,pc);
        
  cout<<"how many step do you want"<<endl;
  cin>>stp;
  
//first step 
  if(stp==1){
  ant.dir2('d');
    ant.getrow2(pc); 
    ant.getcol2(pc);
    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow()][ant.getcol()+1]==' ')
      ant.clor2(' ');
    else if(brd[ant.getrow()][ant.getcol()+1]=='#')
      ant.clor2('#');
    ant.getrow2(ant.getrow());
    ant.getcol2(ant.getcol()+1);    
    brd[ant.getrow()][ant.getcol()]='*';
     cout<<endl<<endl<<endl<<"step "<<1<<endl<<endl<<endl;
    
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        cout<<brd[i][j]<<"|";
      }
      cout<<endl;
    }
    
  }
    
  else{
    ant.dir2('d');
    ant.getrow2(pc); 
    ant.getcol2(pc);
    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow()][ant.getcol()+1]==' ')
      ant.clor2(' ');
    else if(brd[ant.getrow()][ant.getcol()+1]=='#')
      ant.clor2('#');
    ant.getrow2(ant.getrow());
    ant.getcol2(ant.getcol()+1);    
    brd[ant.getrow()][ant.getcol()]='*';
     cout<<endl<<endl<<endl<<"step "<<1<<endl<<endl<<endl;
    
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        cout<<brd[i][j]<<"|";
      }
      cout<<endl;
    }
  for(int i=0;i<stp;i++){
  
    cout<<endl<<endl<<endl<<"step "<<i+1<<endl<<endl<<endl;
    
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        cout<<brd[i][j]<<"|";
      }
      cout<<endl;
    }
    
  if(ant.clor()=='#'){                        //for white space
   cout<<"black"<<endl;
  if(ant.dir()=='r' ){
    if(ant.getcol()+1>col-1)
      ant.getcol2(col/2);

    brd[ant.getrow()][ant.getcol()]=' ';
    if(brd[ant.getrow()][ant.getcol()+1]==' '){
      ant.clor2(' ');
      ant.dir2('d');
    }
    else if(brd[ant.getrow()][ant.getcol()+1]=='#'){
      ant.dir2('u');
      ant.clor2('#');
    }
    brd[ant.getrow()][ant.getcol()+1]='*';
 
    ant.getrow2(ant.getrow());
    ant.getcol2( ant.getcol()+1);
      cout<<"black1"<<endl;

  }
  else if(ant.dir()=='d' ){
    if(ant.getrow()+1>row-1)
      ant.getrow2(row/2);

    brd[ant.getrow()][ant.getcol()]=' ';
    if(brd[ant.getrow()+1][ant.getcol()]==' '){
      ant.clor2(' ');
      ant.dir2('l');
    }
    else if(brd[ant.getrow()+1][ant.getcol()]=='#'){
      ant.dir2('r');
      ant.clor2('#');
    }
    brd[ant.getrow()+1][ant.getcol()]='*';
 
    ant.getrow2(ant.getrow()+1);
    ant.getcol2( ant.getcol());
 
   cout<<"black2"<<endl;
  }
  else if(ant.dir()=='l' ){
    if( ant.getcol()-1<0)
       ant.getcol2(col/2);

    brd[ant.getrow()][ant.getcol()]=' ';
    if(brd[ant.getcol()][ant.getcol()-1]==' '){
      ant.clor2(' ');
      ant.dir2('u');
    }
    else if(brd[ant.getrow()][ant.getcol()-1]=='#'){
      ant.dir2('d');
      ant.clor2('#');
    }
    brd[ant.getrow()][ant.getcol()-1]='*';
 
    ant.getrow2(ant.getrow());
    ant.getcol2( ant.getcol()-1);
    cout<<"black3"<<endl;
  }
  else if(ant.dir()=='u' ){
    if(ant.getrow()-1<0)
      ant.getrow2(row/2);
 
    brd[ant.getrow()][ant.getcol()]=' ';
    if(brd[ant.getrow()+1][ant.getcol()]==' '){
      ant.clor2(' ');
      ant.dir2('r');
    }
    else if(brd[ant.getrow()+1][ant.getcol()]=='#'){
      ant.dir2('l');
      ant.clor2('#');
    }
    brd[ant.getrow()-1][ant.getcol()]='*';
 
    ant.getrow2(ant.getrow()-1);
    ant.getcol2( ant.getcol());
     cout<<"black4"<<endl;
   }
  }

  else if(ant.clor()==' '){                 //for black space
   cout<<"white"<<endl;
  if(ant.dir()=='l'  ){
    if(ant.getcol()-1<0)
      ant.getcol2(0);
 
    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow()][ant.getcol()-1]==' '){
      ant.clor2(' ');
      ant.dir2('u');
    }
    else if(brd[ant.getrow()][ant.getcol()-1]=='#'){
      ant.dir2('d');
      ant.clor2('#');
    }
    brd[ant.getrow()][ant.getcol()-1]='*';
    ant.getrow2(ant.getrow());
    ant.getcol2( ant.getcol()-1);
 cout<<"white1"<<endl;

  }  
  else if(ant.dir()=='d'  ){
    if(ant.getrow()+1 >row-1)
      ant.getrow2(row/2);

    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow()+1][ant.getcol()]==' '){
      ant.clor2(' ');
      ant.dir2('l');
    }
    else if(brd[ant.getrow()+1][ant.getcol()]=='#'){
      ant.dir2('r');
      ant.clor2('#');
    }
    brd[ant.getrow()+1][ant.getcol()]='*';
    ant.getrow2(ant.getrow()+1);
    ant.getcol2( ant.getcol());
    ant.nrow2( ant.getrow()+1);
    ant.ncol2(ant.getcol());
 cout<<"white2"<<endl;

  }
  
   
  
  else if(ant.dir()=='r'  ){
    if(ant.getcol()+1>col-1)
      ant.getcol2(col/2);
 
    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow() ][ant.getcol()+1]==' '){
      ant.dir2('d');
      ant.clor2(' ');
      
    }
    else if(brd[ant.getrow() ][ant.getcol()+1]=='#'){
      ant.dir2('u');
      ant.clor2('#');
    }
    brd[ant.getrow()][ant.getcol()+1]='*';
 
    ant.getrow2(ant.getrow());
    ant.getcol2( ant.getcol()+1);
    ant.nrow2( ant.getrow());
    ant.ncol2(ant.getcol()+1);
 cout<<"white3"<<endl;
  }
  else if(ant.dir()=='u'  ){
    if(ant.getrow()-1<0)
      ant.getrow2(row/2);
 
    brd[ant.getrow()][ant.getcol()]='#';
    if(brd[ant.getrow()-1][ant.getcol()]==' '){
        ant.dir2('r');      
       ant.clor2(' ');
    }
    else if(brd[ant.getrow()-1][ant.getcol()]=='#'){
      ant.dir2('l');
      ant.clor2('#');
    }
    brd[ant.getrow()-1][ant.getcol()]='*';
    ant.getrow2(ant.getrow()-1);
    ant.getcol2( ant.getcol());
cout<<"white4"<<endl;
 
    }
   }
  }
 }
   menu2();
   cin>>chs2;  
 }while(chs2==1 || chs2==4);
  
}