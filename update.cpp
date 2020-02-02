#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <chrono>

using data_t = float;  //Useful for checking the runtime against various data types as mentioned in Part(3)
using namespace std;
// /usr/bin/time -lp ./a 1048576 1000

void print_array(data_t arr[],int size) // Function for printing the elements of an array, useful for debugging
{

  cout << "The length of the array is: " << size<<endl;
  for (int i = 0;i<size;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

data_t* generate_random_list(double size,data_t bound) //Similar to the generate_random_list function in Python
{
    data_t *list = new data_t[size];
    if (!list)
    {
      //bad
      cout<<"Invalid size"<<endl;
      exit(-1);
    }
    std::uniform_real_distribution<data_t> uniform_dist(-bound, bound);
    std::default_random_engine e1(size);

    for (unsigned int i=0; i < size; i++)
     {
        data_t mean = uniform_dist(e1); //Put a random number in the list
        //cout<<mean<<endl;
    	  list[i] = mean;
      }

    /*
    cout<<"Printing list now"<<endl;
    for (unsigned int i = 0; i < size; i++)
        cout << list[i] << endl;
    cout<<"Finished printing list"<<endl;
    */
    return list;

}

//Similar to the Update Co-ordinate function in c++
void update_coords(double size, data_t* x, data_t* y, data_t* z, data_t* vx, data_t* vy, data_t* vz)
{
  /*
    std::cout << "Printing x"<< '\n';
    print_array(x,size);
    std::cout << "Printing y"<< '\n';
    print_array(y,size);
    std::cout << "Printing z"<< '\n';
    print_array(z,size);

    std::cout << "Printing vx"<< '\n';
    print_array(vx,size);
    std::cout << "Printing vy"<< '\n';
    print_array(vy,size);
    std::cout << "Printing vz"<< '\n';
    print_array(vz,size);
    */

    for (int i=0; i<size; i++)
    {
        x[i] = x[i] + vx[i];
        y[i] = y[i] + vy[i];
        z[i] = z[i] + vz[i];
    }

  /*
    cout<<"Again"<<endl;
    std::cout << "Printing x"<< '\n';
    print_array(x,size);
    std::cout << "Printing y"<< '\n';
    print_array(y,size);
    std::cout << "Printing z"<< '\n';
    print_array(z,size);
  */

}

//utility function to sum the contents of an array.
data_t sum(data_t* xs, double size)
{
    data_t total = 0;
    for (int i=0; i < size; i++)
    {
	     total = total + xs[i];
    }
    //cout<<"total = "<<total;
    return total;
}

int main(int argc, char *argv[]) //Tried to mimic the Python file as much as possible
{
  //cout<<"GOES HERE"<<endl;
  if (argc!= 3)
  {
    cout<<"We need 2 arguments, number of objects and number of iterations"<<endl;
  }
  const int size = atoi(argv[1]);
  //cout<<"SIZE="<<size<<endl;
  const int iters = atoi(argv[2]);


  auto xs = generate_random_list(size, 1000.);
  auto ys = generate_random_list(size, 1000.);
  auto zs = generate_random_list(size, 1000.);
  auto vx = generate_random_list(size, 1.);
  auto vy = generate_random_list(size, 1.);
  auto vz = generate_random_list(size, 1.);

  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iters; i++)
	{
		update_coords(size,xs, ys, zs, vx, vy, vz);
	}
  auto t2 = std::chrono::high_resolution_clock::now();

  double duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count())/double(1000000);
  //std::cout <<"DURATION is"<< duration;
  data_t chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
	double num_of_coords = size * iters;
	double mean_time = (10000000*duration) / num_of_coords;
	cout<<"Mean time per coordinate:"<<mean_time<<endl;
	cout<<"Final checksum is:"<<chksum<<endl;

  delete[] xs;
  delete[] ys;
  delete[] zs;
  delete[] vx;
  delete[] vy;
  delete[] vz;
  return 0;
}
