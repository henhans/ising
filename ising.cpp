/* Ising model MC simulation using metropolis algorithm
   Author: Tsung-Han Lee  7/12/2014
*/

#include "lattice.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{ 
  int L=36; // length of square
  int mc_step=10000;

  //double T=4.0; // temperature
  double Tmin =1;
  double Tmax =4;
  double Tstep=50;
  double H=0.; //magnetic field 
 

  for(int i=0; i<Tstep; i++)
  {
    double T = Tmax -i*(Tmax-Tmin)/Tstep;
    Lattice lattice(L,T,H);

    for(int j=0; j<mc_step; j++)
    {
      //cout<<"MC Step="<< j <<endl;
      lattice.MC();
      //double M = lattice.get_M();
      //cout<< j <<"  "<< M <<endl;
    }
    double M=lattice.get_M();
    cout<< T <<" "<< abs(M) << endl;
  }
}
