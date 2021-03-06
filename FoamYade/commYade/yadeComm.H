#ifndef yadeComm_H 
#define yadeComm_H 

#include <vector> 
#include "PstreamGlobals.H"

namespace Foam 
{
  class yadeComm
  {
    
    private:
      const int sendTag=500; 
      MPI_Status status; 
    protected:
    public:
      int rank; 
      int commSize; 
      yadeComm();
      void send_data(int, std::vector<double>&); 
      void recv_data(int, std::vector<double>&); 
      void cast_double_array_data(int, std::vector<double>&);
      void cast_integer_data(int, int&); 
      void sendOneDouble(int, double& ); 
      void procReduceMaxInt(int&, int&);
      void procReduceSumDouble(double&, double&); 
      void cast_one_double(int, double&);  
      void sendTerminate(); 
      void recvTerminate();
      void castTerminate();    
      ~yadeComm(){}; 
  }; 
}
 
#endif 
