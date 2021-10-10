
#include "../include/header.hpp"

  int main()
  {
    string jsonPath;
    cin >> jsonPath ;
    ifstream file(jsonPath);
    if (!file) {
      throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    vector<student_t> students;
    for (auto const& item : data.at("items")) {
      student_t s;
      from_json(item, s);
      students.push_back(s);
    }
    print(students, std::cout);

  }