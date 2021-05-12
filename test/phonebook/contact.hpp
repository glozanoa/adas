/*
 * Contact class - Customized data structure
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
  Contact(string first_name, string last_name, string company, string address,
          string city, string province, string postal, vector<string> phones, string email, string web)
  {
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
    this->city = city;
    this->province = province;
    this->postal = postal;
    this->phones = phones;
    this->email = email;
    this->web = web;
  }

  string get_fullname(){return first_name + " " + last_name;}
  string get_city(){return city;}
  string get_address(){return address;}
  vector<string> get_phones(){return phones;}

  bool operator<(Contact contact) // sort alphabetically by full_name
  {
    string full_name_contact = contact.get_full_name();
    string full_name = this->get_full_name();
    return lexicographical_compare(full_name.begin(), full_name.end(),
                                   full_name_contact.begin(), full_name_contact.end());
  }

  ostream& operator<<(ostream& out, Contact contact)
  {
    out << "Contact(Name: " << contact.get_fullname();

    out << ", Phones: "
    for(string phone : contact.get_phones())
      {
        out << phone << ", ";
      }

    out << "City: " << contact.get_city()
        << ", Address: " << contact.get_address() <<  ")";

    return out;
  }
}

#endif //_CONTACT_H
