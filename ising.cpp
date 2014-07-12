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

void output(const char* filename, double* x, double* y, int N)
{
  FILE *f;
  f = fopen(filename, "w");
  for (int i=0; i<N; i++)
    fprintf(f,"%le %le\n", x[i], y[i]);
  fclose(f);

}

int main(int argc, char *argv[])
{ 
  int L=36; // length of square
  int mc_step=10000;

  //double T=4.0; // temperature
  double Tmin =1;
  double Tmax =4;
  int Tstep=50;
  double H=0.; //magnetic field 

  double T_array[Tstep];
  double M_array[Tstep];
  double E_array[Tstep];

  for(int i=0; i<Tstep; i++)
  {
    double T = Tmax -i*(Tmax-Tmin)/Tstep;
    T_array[i]=T;
    Lattice lattice(L,T,H);

    for(int j=0; j<mc_step; j++)
    {
      //cout<<"MC Step="<< j <<endl;
      lattice.MC();
      //double M = lattice.get_M();
      //cout<< j <<"  "<< M <<endl;
    }
    M_array[i]=lattice.get_M();
    E_array[i]=lattice.get_E();
    //cout<< T <<" "<< abs(M) << endl;
  }

  output("m_T.dat",T_array, M_array, Tstep);
  output("E_T.dat",T_array, E_array, Tstep);
  
  return 0;
}
