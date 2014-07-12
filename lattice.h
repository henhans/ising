/* Class for saving 2D spin configuration for MC and it's operations
   Author: Tsung-Han Lee 7/12/2014
*/

using namespace std;

class Lattice
{
  public:
        Lattice(int L_in, double T_in, double H_in);//constructor, using default destructor

        void MC(); // Monte Carlo Metropolis algorithm
        double get_M(); // get averaged magnetization <M>
        double get_E(); // get averaged energy <E>
  private:
        double _T; //temperature
        double _H; //magnetic field
        int   _L; //length of lattice
        int   _N; //number of spin
        //float rand_num; //random number

        int   *spin; //1D array for spin configuration
        double pflip[2][5]; // prestored probability for spin flip
};
