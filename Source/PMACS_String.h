#ifndef PMACS_STRING_H
#define PMACS_STRING_H

using namespace std;

string StringZeroFill(int required_field_length, int number);
string StringSpaceFill(int length, string fillMe);
int StringToInt(std::string in_string);
long long StringToLongLong(std::string in_string);
double StringToDouble(std::string in_string);
#endif