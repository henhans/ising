/*Lattice data structure and methods
  Author: Tsung-Han Lee 7/12/2014
*/

#include "lattice.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>


/*-------------------------Constructor ------------------------------*/
Lattice::Lattice(int L_in, double T_in, double H_in)
{
  _T=T_in;
  _L=L_in;
  _N=_L*_L;
  _H=H_in;
  spin= new int[_N];
 
  srand((unsigned)time(NULL)); // initialize random seed 
  //initialize spin configuration
  for (int i=0; i<_N; i++)
  { 
    double random=((double) rand() / (RAND_MAX));
    //cout<<random<<endl ;
    if( random > 0.5 ) 
      {
        spin[i]=1;
        //cout<<"bigger"<<endl;
      }
    else
      {
        spin[i]=-1;
        //cout<<"smaller"<<endl;
      }
  }

  //for (int i=0; i<_N; i++){cout<<"spin["<<i<<"]="<<spin[i]<<endl; }

  /* precalculate the probability for spin flip here i=0 corresponding to spin=-1 and i=1 correspond to spin =1
     , j=0,1,2,3,4 correspond to total neiboring spin= -4, -2, 0 ,2 ,4 */
  for (int j=0; j<5; j++)  
  {
    pflip[0][j]=exp(+2 * ( (-4+j*2) + _H) / _T);
    pflip[1][j]=exp(-2 * ( (-4+j*2) + _H) / _T);
    //cout<< "pflip["<<-1+0*2<<"]["<<-4+j*2<<"]="<<pflip[0][j]<<endl;
    //cout<< "pflip["<<-1+1*2<<"]["<<-4+j*2<<"]="<<pflip[1][j]<<endl;
  }  
}

// Monte Carlo metropolis algorithm
void Lattice::MC()
{
  int accept=0;

  for(int i=0; i<_N; i++)
  {
    double random=((double) rand() / (RAND_MAX));
    int s=(int) (random*_N);
    //cout<< s << endl;
    int x=s%_L;
    int y=s/_L;
    //cout<< x <<"  "<< y<<endl;

    int s1=spin[ ( (x+1)%_L) + y*_L ];
    int s2=spin[ x + ( (y +1)%_L )*_L ];
    int s3=spin[ ( (x-1+_L)%_L) + y*_L ];
    int s4=spin[ x + (( y-1+_L)%_L )*_L ];
    if ( ((double) rand() / (RAND_MAX)) < pflip[(spin[s]+1)/2][(s1+s2+s3+s4+4)/2] ) 
    {
      spin[s]=-spin[s];
      accept++;
    }
  } 
  //cout<< "accepted=" << accept << endl; 
}

// get magnetization
double Lattice::get_M()
{
  int M=0;
  for(int i=0; i<_N; i++)
  {
    M+=spin[i];
  }

  return ((double) M/_N);
}
