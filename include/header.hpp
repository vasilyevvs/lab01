// Copyright 2021 Vasilyev  Danila
#include <nlohmann/json.hpp>
#include <sstream>
#include "any"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
#include "vector"
using nlohmann::json;
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
struct student_t {
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};
auto get_name(const json& j)-> std::string;
auto get_debt(const json& j)-> std::any;
auto get_avg(const json& j)-> std::any;
auto get_group(const json& j)-> std::any;
void from_json(const json& j, student_t& s);
std::string toString(std::any& item);
void print(std::string s1, std::string s2, std::string s3, std::string s4,
           std::ostream& os);
void print(student_t& student, std::ostream& os);
void print(std::vector<student_t>& students, std::ostream& os);
#endif // INCLUDE_HEADER_HPP_
