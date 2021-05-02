#include <vector>
#include <iostream>

using namespace std;



template<typename ForwardIterator>
void print(ForwardIterator first, ForwardIterator last)
{
  for(ForwardIterator itr=first; itr!=last; itr++)
    {
      cout << *itr << " ";
    }
  cout << endl;
}


template<class RandomAccessIterator>
void interchange(RandomAccessIterator first, RandomAccessIterator last, bool verbose)
{
  RandomAccessIterator itr, inner;

  for(itr=first; itr!= last-1; itr++)
    {
      for(inner=itr+1; inner!=last; inner++)
        {
          if(*itr > *inner)
            {
              auto value = *inner;
              *inner = *itr;
              *itr = value;
            }
        }
      if(verbose)
        print(first, last);
    }
}

int main()
{
  vector<int> numbers = {8, 4, 6, 2};

  interchange(numbers.begin(), numbers.end(), true);
}
