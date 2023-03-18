#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int age;
};

bool sort_age(Student &left, Student &right) {
    return left.age > right.age;
}

bool sort_name(Student &left, Student &right) {
    return left.name < right.name;
}

void Ludi_V_Pravilnom_Poryadke(vector<Student> &People) {
    sort(People.begin(), People.end(), sort_name);
}

void Ludi_Po_Starosti(vector<Student> &People) {
    sort(People.begin(), People.end(), sort_age);
}

int main(int argc, char *argv[]) {
    vector<Student> People;
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; j < strlen(argv[i]) + 1; ++j) {
            string name = "";
            while (argv[i][j] != ':') {
                name.push_back(argv[i][j]);
                ++j;
            }
            ++j;
            string age = "";
            while (argv[i][j] != '\0') {
                age.push_back(argv[i][j]);
                ++j;
            }
            uint8_t skolko_let = stoi(age);
            People.push_back({name, skolko_let});
        }
    }
    ofstream pain;
    pain.open("sorted.json.txt");
    pain << "{" << endl;
    pain << '\t' << '\"' << "sorted_by_name_gt" << '\"' << " : [";
    Ludi_V_Pravilnom_Poryadke(People);
    for (int j = 0; j < People.size(); ++j) {
        pain << "{ \"name\": \"" << People[j].name << "\", \"age\": " << People[j].age << "}";
        if (j != People.size() - 1) {
            pain << ", "
        }else{

        }
    }
    pain.close();
    return 0;
}