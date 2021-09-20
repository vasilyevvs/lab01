#include "iostream"
#include "string"
#include "iomanip"
#include "any"
using namespace std
using nlohmann::json
string filePath;

struct student_t {
    string name;
    any group;
    any avg;
    any debt;
}
void from_json(const json& j, student_t& s) {
    s.name = get_name(j.at("name"));
    s.group = get_group(j.at("group"));
    s.avg = get_avg(j.at("avg"));
    s.debt = get_debt(j.at("debt"));
}

auto get_name(const json& j) -> string {
    return j.get<string>();
}

auto get_debt(const json& j) -> any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<string>();
    else
        return j.get<vector<string> >();
}

auto get_avg(const json& j) -> any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<string>();
    else if (j.is_number_float())
        return j.get<double>();
    else
        return j.get<size_t>();
}

auto get_group(const json& j) -> any {
    if (j.is_string())
        return = j.get<string>();
    else
    return j.get<size_t>();
}

string stringi(any& item)
{
  stringstream ss;
  if(item.type() == typeid(nullptr_t))
    ss << "null";
  else if(item.type() == typeid(string))
    ss << any_cast<string>(item);
  else if(item.type() == typeid(int))
    ss << any_cast<int>(item);
  else if(item.type() == typeid(float))
    ss << any_cast<float>(item);

}

int main() {
    ifstream("../1.json");
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    vector<student_t> students;
    for (auto const& item : data.at("items")) {
        student_t s;
        from_json(item, s);
        students.push_back(student);
    }
    print(students, std::cout);
}

void print(string s1, string s2, string s3, string s4, std::ostream& os)
{
  os << "| " << setw(20) << std::left << s1 << "| "
     <<  setw(10) << std::left << s2 << "| "
     <<  setw(10) << std::left << s3 << "| "
     <<  setw(10) << std::left << s4 << "|\n"
     << "|---------------------|-----------|-----------|-----------|\n";
}
void print(student_t& student, std::ostream& os)
{
  print(student.name, student.group, student.avg,  student.debt, os);
}
void print(vector<student_t>& students, std::ostream& os)
{
  print( "name", "group", "avg", "debt", os);
  for (student_t& student : students) {
    print(student, os);
  }