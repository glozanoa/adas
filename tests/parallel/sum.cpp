/*
 * Multi thread example to test GDB debuger
 *
 * This examples perform a reduction(+) to the numbers vector
 * and save partial sum in partial_sum vector;
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "omp.h"


int main()
{
  vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  unsigned int nthreads = omp_get_max_threads();
  vector<int> partial_sum = vector<int>(nthreads, 0);

#pragma omp parallel shared(partial_sum) firstprivate(numbers, nthreads)
    {
      unsigned int idthread = omp_get_thread_num();

      for(int i=idthread; i<numbers.size(); i+=nthreads)
        partial_sum[idthread] += numbers[i];
    }

    int total_sum = 0;
    for(int element : partial_sum)
      total_sum += element;

    cout << "Sum: " << total_sum << endl;

    return 0;
}
