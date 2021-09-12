/*
 * Generation of random numbers (integers and floating-point numbers) (ONLY FOR DEBUG PURPOSE)
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _RANDOM_H
#define _RANDOM_H

// #include <iostream>
// #include <vector>
// #include <random>
// using namespace std;

// #include "omp.h"

// #include "../exceptions/general.hpp"

// namespace random
// {
//   template<class T>
//   vecotr<T> uniform(T min_random, T max_random, unsigned int nrand)
//   /*
//    * Generate nrand random values of type T (only for integers and floting-point values) between min_random and max_random
//    */
//   {
//     try
//       {
//         if (is_same<T, int>::value)
//           uniform_int_distribution<T> distribution(min_random, max_random);

//         else if(is_same<T, double>::value)
//           uniform_real_distribution<T> distribution(min_random, max_random);

//         else
//           throw Exception("Invalid type");

//         default_random_engine generator;
//         vector<T> random_numbers = vector<T>(nrand);

// #pragma omp parallel for shared(distribution, generator, random_numbers) firstprivate(nrand)
//         for(int i=0; i<nrand; i++)
//           {
//             random_numbers[i] = distribution(generator);
//           }

//         return random_numbers;
//       }
//     catch(exception& error)
//       {
//         cout << error.what() << endl;
//         exit(EXIT_FAILURE);
//       }
//   }
// }

#endif //_RANDOM_H
