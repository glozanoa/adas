 /*
 * Testing bubble sorting algorithm in DLList<T> data structure
 *
 * Status: DEBUGGED - date: May 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include<boost/program_options.hpp>
namespace po = boost::program_options;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/algorithm/sort/serial.hpp"
namespace asos = adas::algorithm::sort::serial;

#include "adas/ds/double_linked_list.hpp"
namespace ads = adas::ds;

int main(int argc ,char* argv[])
{

  // PARSING CMD ARGUMENTS (ONLY FOR TESTING PURPOSES)
  po::options_description test("Options for serial bubble algorithm for DLList<T> structure");
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
  ads::DLList<int> list = au::read::from_file<DLList<int>, int>(args["input"].as<string>());
  bool verbose = args["verbose"].as<bool>();
  // END - READING PARSED CMD OPTIONS

  Timer time;

  time.start();
  // bubble with custom interchange function
  asos::bubble<ads::DLList<int>>(list.begin(), list.end(), verbose);
  time.stop();
  time.report("Elapsed time (bubble sorting algorithm in DLList<T> ds)");

  au::print::to_stdout("Sorted:\n", list, "\n");
  //au::write::to_file(list.begin(), list.end(), "sorted_dllist_bubble.txt");

  return 0;
}
