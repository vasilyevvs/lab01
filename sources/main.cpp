#include "iostream"
#include "string"
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
        return j.get<std::size_t>();
}

auto get_group(const json& j) -> std::any {
    if (j.is_string())
        return = j.get<std::string>();
    else
    return j.get<std::size_t>();
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

void print(const vector<student_t>& students, ostream& os) {
    //stdw | name          | group  | avg  | debt          |
    for (auto const& student : students) {
        print(student, os);
    }
}
void print(const student_t& student, std::ostream& os) {
    //исключение строки, цифры, и так далее по условию
    //кусок кода написать где каждый столбец приводится к строке, по условию опять же
    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type() == typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
                << std::any_cast<std::vector<std::string> >(student.debt).size()
                << " items";
    }
}