#include <iostream>
#include <vector>
#include <cmath>

const int N = 50;
//const int NSTEPS = 500;
const double L = 10.35345;
const double DELTA = L/(N-1);

void initial_conditions(std::vector<double> & mat);
void boundary_conditions(std::vector<double> & mat);
void print(const std::vector<double> & mat);
void print_gnuplot(const std::vector<double> & mat);
void relax(std::vector<double> & mat);
void start_gnuplot(void);
double densidad(int ii, int jj);
double cambio(const std::vector<double> & mat , const std::vector<double> & mat1);

int main (void)
{
  std::vector<double> mat(N*N);
  std::vector<double> mat1(N*N); //Vector auxiliar para calcular la diferencia 
  

  initial_conditions(mat);
  initial_conditions(mat1);  // Inicializa el vector auxiliar 
  boundary_conditions(mat);
  //print(mat);

  start_gnuplot();
  
  /* for (int ii = 0; ii < NSTEPS; ++ii) {
    relax(mat);
    print_gnuplot(mat);
    }*/
  //print(mat);


  while( cambio (mat,mat1) > 0.01){
    mat1=mat;
    relax(mat);
    print_gnuplot(mat);
    cambio(mat, mat1);
  }
  
  return 0; 
}

void initial_conditions(std::vector<double> & mat)
{
  for(int ii = 0; ii < N; ++ii){
    for(int jj = 0; jj < N; ++jj){
      mat[ii*N + jj] = 0.0;
    }
  }
}

void start_gnuplot(void)
{
  std::cout << "set contour" << std::endl;  
  std::cout << "set title 'Laplace' " << std::endl;
  std::cout << "set terminal gif animate " << std::endl;
  std::cout << "set out 'miprimeraanimacion.gif' " << std::endl;
}


void boundary_conditions(std::vector<double> & mat)
{
  int ii, jj;

  ii = 0;
  for(jj = 0; jj < N; ++jj){
      mat[ii*N + jj] = 0.0;
  }
  ii = N-1;
  for(jj = 0; jj < N; ++jj){
      mat[ii*N + jj] = 0.0;
  }
  jj = 0;
  for(ii = 1; ii < N; ++ii){
      mat[ii*N + jj] = 100*sin(M_PI*ii*DELTA/(0.5*L));
  }
  jj = N-1;
  for(ii = 1; ii < N; ++ii){
    mat[ii*N + jj] = 100*sin(M_PI*ii*DELTA/(0.5*L));
  }


  ii = 3*N/4;
  for(jj = N/3; jj <= 2*N/3; ++jj){
    mat[ii*N + jj] =100.0*sin(jj) ;
  }

  ii = N/4;
  for(jj = N/3; jj <= 2*N/3; ++jj){
    mat[ii*N + jj] = -100.0*cos(jj);
  }

  
}

void relax(std::vector<double> & mat)
{
  for(int ii = 1; ii <= N-2; ++ii){
    for(int jj = 1; jj <= N-2; ++jj){
      if (ii == 3*N/4 && N/3 <= jj && jj <= 3*N/4) continue;
      if (ii == N/4 && N/3 <= jj && jj <= 3*N/4) continue;
      mat[ii*N + jj] = (mat[(ii+1)*N + jj] + mat[(ii-1)*N + jj] + mat[ii*N + jj + 1] + mat[ii*N + jj - 1])/4.0 + M_PI*densidad(ii,jj)*(DELTA)*(DELTA)    ;
    }
  }
}


void print_gnuplot(const std::vector<double> & mat)
{
  std::cout << "splot '-' w pm3d " << std::endl;
  
  print(mat);
  
  std::cout << "e" << std::endl;
 
}

void print(const std::vector<double> & mat)
{
  double x, y;
  for(int ii = 0; ii < N; ++ii){
    x = 0.0 + ii*DELTA;
    for(int jj = 0; jj < N; ++jj){
      y = 0.0 + jj*DELTA;
      std::cout << x << "  " << y << "  " << mat[ii*N + jj] << std::endl;
    }
    std::cout << std::endl;
  }  
}


double densidad(int ii, int jj){
  double rho;
  if  (ii== N/2 & jj==N/2) return 0 ;

  return 0;

}


double cambio(const std::vector<double> & mat , const std::vector<double> & mat1){
  double a=0;
  double b=0;
  for(int ii = 0; ii < N; ++ii){
    for(int jj = 0; jj < N; ++jj){
      a=a+ pow(mat[ii*N + jj],2);
      b=b+ pow(mat1[ii*N +jj],2);
    }
  }

  double c=std::abs(a/(N*N)-b/(N*N));
  return c;



}

