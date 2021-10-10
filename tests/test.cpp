// Copyright 2021 Your Name <vasilyev.jpg@yandex.ru>

#include <gtest/gtest.h>

#include <header.hpp>

TEST(printTest, StudentsArray) {
  std::stringstream ss;
  std::vector<student_t> students;
  student_t t;
  t.name = "test";
  t.avg = (std::string)"test";
  t.debt = std::vector<std::string>();
  t.group = (size_t)3;

  students.push_back(t);
  t.name = "test";
  t.avg = (std::string)"test";
  t.debt = std::vector<std::string>();
  t.group = (size_t)3;
  students.push_back(t);
  print(students, ss);
  ASSERT_EQ("| name                | group     | avg       | debt      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| test                | 3         | test      | 0         |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| test                | 3         | test      | 0         |\n"
      "|---------------------|-----------|-----------|-----------|\n",  ss.str());
}
TEST(printTest, StudentItem)
{
  student_t t;
  t.name = "test";
  t.avg = (std::string)"test";
  t.debt = std::vector<std::string>();
  t.group = (size_t)3;
  std::stringstream ss;
  student_t s(t);
  print(s, ss);
  ASSERT_EQ("| test                | 3         | test      | 0         |\n"
      "|---------------------|-----------|-----------|-----------|\n",  ss.str());
}

