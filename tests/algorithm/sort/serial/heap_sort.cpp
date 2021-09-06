/*
 * Testing heap sort algorithm
 *
 * Status: DEBUGGED - date: May 11 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#include<boost/program_options.hpp>
namespace po = boost::program_options;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/algorithm/sort/serial.hpp"
namespace ass = adas::algorithm::sort::serial;

int main(int argc ,char* argv[])
{

  // PARSING CMD ARGUMENTS (ONLY FOR TESTING PURPOSES)
  po::options_description test("Options for serial heapsort algorithm");
  test.add_options()
    ("help,h", "Show help.")
    ("input,i", po::value<string>(), "Input file with unsorted numbers.")
    ("verbose,v", po::bool_switch()->default_value(false), "Increase algorithm's verbosity.");

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

  // END - PARSING CMD ARGUMENTS

  // READING PARSED CMD OPTIONS
  vector<int> numbers = au::read::from_file<int>(args["input"].as<string>());
  bool verbose = args["verbose"].as<bool>();
  // END - READING CMD PARSED OPTIONS

  Timer time;

  time.start();
  vector<int> sorted = ass::heap_sort(numbers, verbose);
  time.stop();
  time.report("Elapsed time (heapsort sorting algorithm)");

  print::to_stdout("Sorted:", sorted);

  return 0;
}
