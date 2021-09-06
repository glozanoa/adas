/*
 * Testing efficiency of multithread algorithms against serial algorithms
 *
 * Task: sort 10000 random integer numbers
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/algorithm/sort/serial.hpp"
namespace ass = adas::algorithm::sort::serial;

#include "adas/algorithm/sort/multithread.hpp"
namespace asp = adas::algorithm::sort::parallel;

int main()
{
    /*
   * Random integer numbers were generated using intgen.py python script
   * python3 dgen/intgen.py -u 1 15000 10000  unsorted10000.txt
   * and using unsorted10000.txt as input parameter
   *
   * READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
   */

  // PARSING CMD ARGUMENTS (ONLY FOR TESTING PURPOSES)
  po::options_description test("Options for insertion algorithm benchmark");
  test.add_options()
    ("help,h", "Show help.")
    ("input,i", po::value<string>(), "Input file with unsorted numbers.")
    ("output,o", po::value<string>(), "File to write sorted numbers.")
    ("verbose,v", po::bool_switch()->default_value(false), "Increase algorithm's verbosity.")
    ("nthreads,n", po::value<unsigned int>()->default_value(1), "Number of threads");

  po::variables_map args;

  store(po::command_line_parser(argc, argv).options(test).run(), args);

  if(args.count("help"))
    {
      cout << test << endl;
      return 1;
    }

  if(!args.count("input"))
    {
      cout << "\"input\" option is required" << endl;
      cout << test << endl;
      return 1;
    }

  if(!args.count("output"))
    {
      cout << "\"output\" option is required" << endl;
      cout << test << endl;
      return 1;
    }


  // END - PARSING CMD ARGUMENTS

  // READING PARSED CMD OPTIONS
  vector<int> numbers = au::read::from_file<int>(args["input"].as<string>());
  bool verbose = args["verbose"].as<bool>();
  unsigned int nthreads = args["nthreads"].as<unsigned int>();
  // END - READING CMD PARSED OPTIONS

  vector<int> cnumbers(numbers.size()); // copy of numbers to test serial algorithm
  copy(numbers.begin(), numbers.end(), cnumbers.begin());


  Timer time;

  cout << "Running serial bibubble algorithm" << endl;
  time.start();
  ass::insertion(cnumbers.begin(), cnumbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (serial insertion algorithm)");

  cout << "Running multithread bibubble algorithm with " << nthreads << " threads" << endl;
  time.start();
  asp::insertion(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (multithread insertion algorithm)");

  // writing sorted numbers by multithread algorithms to check if they are sorted
  au::write::to_file(numbers.begin(), numbers.end(), args["output"].as<string>());

  return 0;
}
