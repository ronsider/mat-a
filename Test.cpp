#include "doctest.h"
#include "mat.hpp"
#include <ctime> //used to generate random number


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
  mat4 = ariel::mat(c,r,s1,s2);

  CHECK_EQ(mat4, ")");                                                 
}


TEST_CASE("Check number of symbols")//number of possible symbols is 3. symbol1, symbol2, '\n'- marking end of line
{
  int c,r;
  
  srand(time(NULL));//seed for generating random number

  c = rand()%20;//random odd number of columns
  if(c==1)
  {
    c+=4;
  }
  else if(c%2==0)
  {
  c+=3;
  }
  else
  {
    c+=0;
  }

  r = rand()%20;//random odd number of rows
  if(r==1)
  {
    r+=2;
  }
  else if(r%2==0)
  {
  r+=3;
  }
  else
  {
    r+=0;
  }

  std::string _test = ariel::mat(c,r,'+','-');

  int t=0;// if this variable is initialized to 1, it means carpet has more than 3 symbols

  for(int i=0;i<_test.size();i++)
  {
    if(_test[i]!='+' && _test[i]!='-' && _test[i]!='\n')
    {
     t++;
     break;
    }
  }
  CHECK(t==0);


  /*another check with random numbers*/

  int _c = rand()%20;
  if(_c==1)
  {
    _c+=6;
  }
  else if(c%2==0)
  {
    _c+=5;
  }
  else
  {
    _c+=0;
  }
  int _r = rand()%20;
  if(_r==1)
  {
    _r+=8;
  }
  else if(_r%2==0)
  {
    _r+=5;
  }
  else
  {
    _r+=0;
  }

  std::string _test1=ariel::mat(_c,_r,'@','$');

  int k = 0;
  for(int i=0;i<_test1.size();i++)
  {
    if(_test1[i]!='@' && _test1[i]!='$' && _test1[i]!='\n')
    {
      k++;
      break;
    }
  }
  CHECK(k==0);


  /*additional check with random numbers*/

  int cc = rand()%20;
  if(cc==1)
  {
    cc+=10;
  }
  else if(cc%2==0)
  {
    cc+=7;
  }
  else
  {
    cc+=0;
  }

  int rr = rand()%20;
  if(rr==1)
  {
    rr+=4;
  }
  else if(rr%2==0)
  {
    rr+=7;
  }
  else
  {
    rr+=0;
  }

  std::string _test2 = ariel::mat(cc,rr,'%','*');

  int y = 0;
  
  for(int i=0;i<_test.size();i++)
  {
    if(_test2[i]!='%' && _test2[i]!='*' && _test2[i]!='\n')
    {
      y++;
      break;
    }
  }

  CHECK(y==0);

}


TEST_CASE("Check that paramets are odd")//in case column or row is even number, user should throw an exception
{
  ////////////////
  ///////////////
  int c=4;
  int r=7;
  CHECK_THROWS(ariel::mat(c,r,'@','#'));
  ///////////////
  //////////////
  c=7;
  r=2;
  CHECK_THROWS(ariel::mat(c,r,'#','*'));
  /////////////
  ////////////
  c=8;
  r=4;
  CHECK_THROWS(ariel::mat(c,r,'(','%'));
  ///////////
  ///////////
  c=0;
  r=7;
  CHECK_THROWS(ariel::mat(c,r,'%','@'));
  ///////////////
  //////////////
  c=5;
  r=0;
  CHECK_THROWS(ariel::mat(c,r,'%','@'));

}

TEST_CASE("Column and row must initialized with positive values only")
{
  int r = -5;
  int c=9;
  CHECK_THROWS(ariel::mat(c,r,'&','$'));
  //////////////
  /////////////
  r=5;
  c=-1;
  CHECK_THROWS(ariel::mat(c,r,'-','+'));
  ////////////
  ////////////
  r = -3;
  c = 7;
  CHECK_THROWS(ariel::mat(c,r,'*','('));
  ////////////
  ////////////
  r = -5;
  c = -9;
  CHECK_THROWS(ariel::mat(c,r,'^','*'));
}

TEST_CASE("Check dimensions where m x 1 or 1 x m")//if one of dimensions is of size one, then user should have only one frame
{
  //this case where one of the dimension is of size 1 should only consist of a single frame ==> entire string consists of single symbol
  bool condition = false;

  int cols = 5;
  std::string star = ariel::mat(cols,1,'%','^');

  if(star == "%%%%%")
  {
    condition = true;
  }
  CHECK(condition == true);

  /////////////////
  ////////////////

  bool condition1 = false;
  cols = 7;
  std::string st = ariel::mat(cols,1,'@','*');

  if(st == "@@@@@@@")
  {
    condition1 = true;
  }

  CHECK(condition1 == true);

}

TEST_CASE("White space should also be considered as a symbol")
{
  char symbol1 = '$';
  char symbol2 = ' ';
  int col = 5;
  int rows = 7;

  std::string _s = ariel::mat(col,rows,symbol1,symbol2);

  CHECK(_s == "$$$$$\n"
              "$   $\n"
              "$ $ $\n"
              "$ $ $\n"
              "$ $ $\n"
              "$   $\n"
              "$$$$$");

    ///////////////
    //////////////

    symbol1 = ' ';
    symbol2 = '#';
    //rows and columns remain the same as previuos test case, only symbols have changed
    _s = ariel::mat(col,rows,symbol1,symbol2);
    CHECK(_s == "     \n"
                " ### \n"
                " # # \n"
                " # # \n"
                " # # \n"
                " ### \n"
                "     ");

}

TEST_CASE("Check for arbitrary test cases")//mixing previous TEST_CASES
{
  //no negative dimension
  CHECK_THROWS(ariel::mat(1,-1,'*','^'));
  CHECK_THROWS(ariel::mat(1,-7,'*','&'));
  CHECK_THROWS(ariel::mat(-3,-5,'&','1'));

  /////////////////
  /////////////////both dimensions must be an odd number
  CHECK_THROWS(ariel::mat(4,8,' ','^'));
  CHECK_THROWS(ariel::mat(3,6,' ','^'));

  ////////the symbols may be equal==>no such constraint was given in instructions that must be different
  std::string _str = ariel::mat(3,3,'*','*');
  CHECK(_str == "***\n"
                "***\n"
                "***");
                
  //numbers as symbols
  std::string sts = ariel::mat(5,3,'1','3');
  CHECK(sts == "11111\n"
              "13331\n"
              "11111");


   std::string tt = ariel::mat(5,5,'7','2');
   CHECK(tt == "77777\n"
               "72227\n"
               "72727\n"
               "72227\n"
               "77777\n");                        
}

