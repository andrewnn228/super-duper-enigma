#include "functions.h"

int safeStoi(const std::string& input) {
    try {
        return std::stoi(input);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Oshibka: vvedite chislo, a ne stroky\n";
        return -1; // сигнал ошибки
    }
    catch (const std::out_of_range&) {
        std::cout << "Oshibka: chislo slishkom bolshoe\n";
        return -1;
    }
}

Auto readFile(const std::string& line) {

    std::stringstream ss(line);
    std::string str;
    std::vector<std::string> fields;

    while (std::getline(ss, str, ';')) {
        fields.push_back(str);
    }

    return Auto(fields[0], fields[1], static_cast<Color>(safeStoi(fields[2])), safeStoi(fields[3]), safeStoi(fields[4]), safeStoi(fields[5]), static_cast<Status>(safeStoi(fields[6])));
}

void writeFile(std::ofstream& file, const Auto& car) {
    file << car.get_mark() << ';' << car.get_model() << ';' << static_cast<int>(car.get_color()) << ';' << car.get_probeg() << ';' << car.get_count_vlad() << ';' << car.get_horse_force() << ';' << static_cast<int>(car.get_status()) << '\n';
}

void loadVector(std::vector<Auto>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push_back(readFile(line));
    }
}

void loadList(std::list<Auto>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push_back(readFile(line));
    }
}

void loadQueue(std::queue<Auto>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push(readFile(line));
    }
}

void loadVectorPtr(std::vector<Auto*>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push_back(new Auto(readFile(line)));
    }
}

void loadListPtr(std::list<Auto*>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push_back(new Auto(readFile(line)));
    }
}

void loadQueuePtr(std::queue<Auto*>& cars) {
    std::ifstream file("text.txt");
    std::string line;

    while (std::getline(file, line)) {
        cars.push(new Auto(readFile(line)));
    }
}
    
void saveVector(const std::vector<Auto>& cars) {
    std::ofstream file("text.txt");

    for (const Auto& car : cars) {
        writeFile(file, car);
    }
}

void saveList(const std::list<Auto>& cars) {
    std::ofstream file("text.txt");

    for (const Auto& car : cars) {
        writeFile(file, car);
    }
}

void saveQueue(std::queue<Auto> cars) {
    std::ofstream file("text.txt");

    while (!cars.empty()) {
        writeFile(file, cars.front());
        cars.pop();
    }
}

void saveVectorPtr(const std::vector<Auto*>& cars) {
    std::ofstream file("text.txt");

    for (const Auto* car : cars) {
        writeFile(file, *car);
    }
}

void saveListPtr(const std::list<Auto*>& cars) {
    std::ofstream file("text.txt");

    for (const Auto* car : cars) {
        writeFile(file, *car);
    }
}

void saveQueuePtr(std::queue<Auto*> cars) {
    std::ofstream file("text.txt");

    while (!cars.empty()) {
        writeFile(file, *cars.front());
        cars.pop();
    }
}