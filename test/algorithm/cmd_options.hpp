/*
 * Command line options (ONLY FOR DEBUG PURPOSE)
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include<boost/program_options.hpp>
namespace po = boost::program_options;


po::variables_map parse_cmd_options(int argc ,char* argv[])
{
  po::options_description debug("Options to test an algorithm");
  debug.add_options()
    ("file,f", po::value<vector<string>>(), "File with unsorted numbers.")
    ("verbose,v", po::value<vector<string>>(), "File with unsorted numbers.");


  po::variables_map vm;

  store(po::command_line_parser(argc, argv).
        options(debug).run(), vm);

  return vm;
}
