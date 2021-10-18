
#include "../include/header.hpp"
  int main()
  {
    std::string jsonPath;
    std::cin >> jsonPath ;
    std::ifstream file(jsonPath);
    if (!file) {
      throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    std::vector<student_t> students;
    for (auto const& item : data.at("items")) {
      student_t s;
      from_json(item, s);
      students.push_back(s);
    }
    print(students, std::cout);
  }