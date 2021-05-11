 /*
 * Testing bubble sorting algorithm
 *
 * Status: DEBUGGED - date: May 10 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm/sort.hpp"
namespace ass = adas::algorithm::sort::serial;

// ONLY FOR TESTING PURPOSE
#include<boost/program_options.hpp>
namespace po = boost::program_options;
#include "../cmd_options.hpp"

int main(int argc ,char* argv[])
{

  po::variables_map args = parse_cmd_options(argc, argv);

  Timer time;
  // READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
  //vector<int> numbers = read::from_file<int>(args["file"].as<string>());
  vector<int> numbers = random::uniform<int>(1, 300, 100);
  bool verbose = args["verbose"].as<bool>();

  time.start();
  ass::bubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (bubble sort)");

  //printing sorted numbers
  print::to_stdout("Sorted:", numbers);

  return 0;
}
