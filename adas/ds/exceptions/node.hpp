/*
 * Exceptions to manage exceptions in Node and BinaryNode template classes
 */


#ifndef _NODE_EXCEPTIONS_H
#define _NODE_EXCEPTIONS_H

class NullParentNode : public std::exception
{
private:
  string warning;

   public:
  NullParentNode()
  {
    warning = "Parent node is a nullptr";
  }
  //InvalidIndex(int index, bool is_row_index);
  const char* what() const throw();
};

const char* NullParentNode::what() const throw()
{
  return warning.c_str();
}

#endif //_NODE_EXCEPTIONS_H
