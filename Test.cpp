#include "doctest.h"
#include "mat.hpp"

TEST_CASE("Check site results validity")
{
  //https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
    int c=9;
    int r=7;
    char s1='@';
    char s2='-';
    
  std::string mat1 = ariel::mat(c,r,s1,s2);

 CHECK_EQ(mat1,"@@@@@@@@@\n"
               "@-------@\n"
               "@-@@@@@-@\n"
               "@-@---@-@\n"
               "@-@@@@@-@\n"
               "@-------@\n"
               "@@@@@@@@@");


  c=13 ,r=5, s1='@', s2='-';//invoking new parameters for function  
  std::string mat2 = ariel::mat(c,r,s1,s2);

CHECK_EQ(mat2,"@@@@@@@@@@@@@\n"
              "@-----------@\n"
              "@-@@@@@@@@@-@\n"
              "@-----------@\n"
              "@@@@@@@@@@@@@");


  c=3, r=5, s1='$', s2='+';
  std::string mat3 = ariel::mat(c,r,s1,s2);//invoking new parameters for function 

CHECK_EQ(mat3,"$$$\n"
              "$+$\n"
              "$+$\n"
              "$+$\n"
              "$$$");  

  c=1, r=1, s1='#', s2=')';
  std::string mat4 = ariel::mat(c,r,s1,s2);//invoking new.....

  CHECK_EQ(mat4, "#");

  //////////////////////////////////////////////////////////////////////
  /*checking test site result, only this time the order of symbols is reversed*/
  /////////////////////////////////////////////////////////////////////

  c=9, r=7, s1='-',s2='@';
  mat1 = ariel::mat(c,r,s1,s2);

  CHECK_EQ(mat1, "---------\n"
                 "-@@@@@@@-\n"
                 "-@-----@-\n"
                 "-@-@@@-@-\n"
                 "-@-----@-\n"
                 "-@@@@@@@-\n"
                 "---------");


  c=13, r=5,s1='-', s2='@';
  mat2 = ariel::mat(c,r,s1,s2);

CHECK_EQ(mat2,"-------------\n"
              "-@@@@@@@@@@@-\n"
              "-@---------@-\n"
              "-@@@@@@@@@@@-\n"
              "-------------");


  c=3, r=5, s1='+', s2='$';
  mat3 = ariel::mat(c,r,s1,s2);

CHECK_EQ(mat3,"+++\n"
              "+$+\n"
              "+$+\n"
              "+$+\n"
              "+++"); 


  c=1, r=1, s1=')', s2='#';
  std::string mat4 = ariel::mat(c,r,s1,s2);

  CHECK_EQ(mat4, ")");                                                 
}


