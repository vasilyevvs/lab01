// Copyright 2021 Vasilyev  Danila
#include "header.hpp"
auto get_name(const json& j) -> std::string {
  return j.get<std::string>();
}
auto get_debt(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else
    return j.get<std::vector<std::string> >();
}
auto get_avg(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_float())
    return j.get<double>();
  else
    return j.get<size_t>();
}
auto get_group(const json& j) -> std::any {
  if (j.is_string())
    return j.get<std::string>();
  else
    return j.get<size_t>();
}
void from_json(const json& j, student_t& s) {
  s.name = get_name(j.at("name"));
  s.group = get_group(j.at("group"));
  s.avg = get_avg(j.at("avg"));
  s.debt = get_debt(j.at("debt"));
}
std::string toString(std::any& item)
{
  std::stringstream ss;
  if (item.type() == typeid(std::nullptr_t))
    ss << "null";
  else if (item.type() == typeid(std::string))
    ss << std::any_cast<std::string>(item);
  else if (item.type() == typeid(double))
    ss << std::any_cast<double>(item);
  else if (item.type() == typeid(std::vector<std::string>))
    ss << std::any_cast<std::vector<std::string> >(item).size();
  else if (item.type() == typeid(size_t))
    ss << std::any_cast<size_t>(item);
  else  ss << "unknown";
  return ss.str();
}
void print(std::string s1, std::string s2, std::string s3, std::string s4,
           std::ostream& os)
{
  os << "| " << std::setw(20) << std::left << s1 << "| "
     <<  std::setw(10) << std::left << s2 << "| "
     <<  std::setw(10) << std::left << s3 << "| "
     <<  std::setw(10) << std::left << s4 << "|\n"
     << "|---------------------|-----------|-----------|-----------|\n";
}
void print(student_t& student, std::ostream& os)
{
  print(student.name, toString(student.group),
        toString(student.avg),  toString(student.debt), os);
}
void print(std::vector<student_t>& students, std::ostream& os) {
  print("name", "group", "avg", "debt", os);
  for (student_t& student : students) {
    print(student, os);
  }
}
