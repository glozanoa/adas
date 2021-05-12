/*
 * Contact class definition - Customized data structure
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _CONTACT_H
#define _CONTACT_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Contact
{
private:
  string first_name;
  string last_name;
  string company;
  string address;
  string city;
  string province;
  string postal;
  vector<string> phones;
  string email;
  string web;

public:
  Contact(vector<string> data);
  string get_fullname(){return first_name + " " + last_name;}
  string get_city(){return city;}
  string get_address(){return address;}
  vector<string> get_phones(){return phones;}

  bool operator<(Contact contact); // sort alphabetically by full_name
  ostream& operator<<(ostream& out, Contact contact);
}

#endif //_CONTACT_H
