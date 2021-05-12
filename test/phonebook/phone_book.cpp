/*
 * phonebook
 */

#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include <boost/algorithm/string.hpp>
#include<boost/program_options.hpp>
namespace po = boost::program_options;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/algorithm/sort/serial.hpp"
namespace ass = adas::algorithm::sort::serial;


#include "contact.hpp"

vector<Contact> read_phone_book(string filename)
{
  vector<Contact> phone_book;

  ifstream file(filename);
  string line = "";
  string delimiter = ",";
  // Iterate through each line and split the content using delimeter
  while (getline(file, line))
    {
      vector<string> data;
      boost::algorithm::split(data, line, boost::is_any_of(delimeter));
      phone_book.push_back(Contact(data));
    }
  // Close the File
  file.close();

  return phone_book;
}

int main(int argc, char* argv[])
{
  // PARSING CMD ARGUMENTS (ONLY FOR TESTING PURPOSES)
  po::options_description test("Options for serial bubble algorithm");
  test.add_options()
    ("help,h", "Show help.")
    ("input,i", po::value<string>(), "CSV file - phone book data.")
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
  vector<Contact> phone_book = read_phone_book(args["input"].as<string>());
  bool verbose = args["verbose"].as<bool>();
  // END - READING CMD PARSED OPTIONS


  // printing the 10 first contacts
  au::print::to_stdout("First 10 contacts:\n", phone_book.begin(), phone_book.begin()+10);


  return 0;
}
