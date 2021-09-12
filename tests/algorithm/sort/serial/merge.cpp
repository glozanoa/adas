/*
 * Testing merge algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include<boost/program_options.hpp>
namespace po = boost::program_options;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/algorithm/sort/serial.hpp"
namespace ass = adas::algorithm::sort::serial;

int main(int argc ,char* argv[])
{

  // PARSING CMD ARGUMENTS (ONLY FOR TESTING PURPOSES)
  po::options_description test("Options for serial bubble algorithm");
  test.add_options()
    ("help,h", "Show help.")
    ("input,i", po::value<string>(), "Input file with unsorted numbers.");

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
  vector<string> files = args["input"].as<vector<string>>();
  if(files.size() != 2)
    {
      cout << "Invalid number of input files (Supplied only 2)" << endl;
      return 1;
    }

  //sels: sorted elements
  vector<int> sels1 = au::read::from_file<int>(files[0]);
  vector<int> sels2 = au::read::from_file<int>(files[1]);
  // END - READING CMD PARSED OPTIONS

  vector<int> result = vector<int>(sels1.size()+sels2.size());


  Timer time;

  time.start();
  ass::merge(sels1.begin(), sels1.end(),
             sels2.begin(), sels2.end(),
             result.begin());
  time.stop();
  time.report("Elapsed time (merge algorithm)");

  print::to_stdout("merged:", result);

  return 0;
}
