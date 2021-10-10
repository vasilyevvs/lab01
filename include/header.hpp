// Copyright 2021 Your Name <Vasilyev  Danila>
#include <nlohmann/json.hpp>
#include <sstream>
#include "any"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
using namespace std;
using nlohmann::json;
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
struct student_t {
  string name;
  any group;
  any avg;
  any debt;
};
auto get_name(const json& j)-> string ;
auto get_debt(const json& j)-> any;
auto get_avg(const json& j)-> any;
auto get_group(const json& j)-> any;
void from_json(const json& j, student_t& s);
std::string toString(std::any& item);
void print(string s1, string s2, string s3, string s4, std::ostream& os);
void print(student_t& student, std::ostream& os);
void print(vector<student_t>& students, std::ostream& os);
#endif // INCLUDE_HEADER_HPP_
