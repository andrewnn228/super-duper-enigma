#include "QueuePtr.h"
#include "vibor.h"
void vibor6(std::queue<Auto*>& AutoQueuePtr) {
    std::string marka_car;
    std::string model_car;
    std::string color_car;
    int probeg_car;
    Color color;
    int vlad_car;
    int horse_force_car;
    Status status;

    std::string vvod;
    size_t pos;
    std::string split;

    while (true) {
        std::cout << "\nВыберите действие:\n1 - Добавить (push)\n2 - Удалить с начала (pop)\n3 - Очистка (clear)\n4 - Выбрать номер автомобиля\n5-Выход";
        std::string vibor_pol;
        std::cout << "\nВведите число для действия (можно ввести только от 1 до 5): ";
        if (!(std::cin >> vibor_pol)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        size_t pos1;
        int vibor_pol1 = std::stoi(vibor_pol, &pos1);
        if (pos1 != vibor_pol.size()) {
            std::cout << "Ошибка: введены не только цифры\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (vibor_pol1) {
        case 1: {
            std::cout << "Введите марку\n";
            std::cin >> split;
            int count_split = 0;
            if (count_split == 0)
            {
                if (split == "") {
                    std::cout << "\nФайл поврежден";
                    return;
                }
                marka_car = split;
                count_split++;
            }
            std::cout << "Введите модель\n";
            std::cin >> split;
            if (count_split == 1)
            {
                if (split == "") {
                    std::cout << "\nФайл поврежден";
                    return;
                }
                model_car = split;
                count_split++;
            }
            while (true) {
                std::cout << "Введите цвет (0 - Red, 1 - Yellow, 2 - Brown, 3 - Black, 4 - White, 5 - Blue)\n";
                std::cin >> split;
                int colorValue = safeStoi(split);
                if (colorValue == -1) {
                    continue;
                }
                if (colorValue < 0 || colorValue > 5) {
                    std::cout << "Ошибка: Введите другое число\n";
                    continue;
                }
                if (count_split == 2)
                {
                    count_split++;
                    if (colorValue == 0)
                    {
                        color = Red;
                        break;
                    }
                    else if (colorValue == 1)
                    {
                        color = Yellow;
                        break;
                    }
                    else if (colorValue == 2)
                    {
                        color = Brown;
                        break;
                    }
                    else if (colorValue == 3)
                    {
                        color = Black;
                        break;
                    }
                    else if (colorValue == 4)
                    {
                        color = White;
                        break;
                    }
                    else if (colorValue == 5)
                    {
                        color = Blue;
                        break;
                    }
                }
            }
            while (true) {
                std::cout << "Введите пробег\n";
                std::cin >> split;
                if (count_split == 3) {
                    int probeg = safeStoi(split);
                    if (probeg == -1) {
                        continue;
                    }

                    if (probeg < 0) {
                        std::cout << "Пробег не может быть отрицательным\n";
                        continue;
                    }
                    probeg_car = probeg;
                    count_split++;
                    break;
                }
            }
            while (true) {
                std::cout << "Введите число владельцев\n";
                std::cin >> split;
                if (count_split == 4) {
                    int countVlad = safeStoi(split);
                    if (countVlad == -1) {
                        continue;
                    }
                    if (countVlad < 0) {
                        std::cout << "Число владельцев не может быть отрицательным\n";
                        continue;
                    }
                    vlad_car = countVlad;
                    count_split++;
                    break;
                }
            }
            while (true) {
                std::cout << "Введите число лс\n";
                std::cin >> split;
                if (count_split == 5) {
                    int horseForce = safeStoi(split);
                    if (horseForce == -1) {
                        continue;
                    }
                    if (horseForce < 0) {
                        std::cout << "Лошадиные силы не могут быть отрицательными\n";
                        continue;
                    }
                    horse_force_car = horseForce;
                    count_split++;
                    break;
                }
            }
            while (true) {
                std::cout << "Введите статус (0 - В ДТП, 1 - В ремонте, 2 - В норме, 3 - Старая)\n";
                std::cin >> split;
                int statusValue = safeStoi(split);
                if (statusValue == -1) {
                    continue;
                }
                if (statusValue < 0 || statusValue > 3) {
                    std::cout << "Ошибка: Введите другое число\n";
                    continue;
                }

                if (count_split == 6) {
                    count_split++;
                    if (statusValue == 0)
                    {
                        status = dtp_car;
                        break;
                    }
                    else if (statusValue == 1)
                    {
                        status = process_car;
                        break;
                    }
                    else if (statusValue == 2)
                    {
                        status = normal_car;
                        break;
                    }
                    else if (statusValue == 3)
                    {
                        status = None;
                        break;
                    }
                    else if (statusValue == 4)
                    {
                        status = old_car;
                        break;
                    }
                }
            }
            Auto* auto1 = new Auto(marka_car, model_car, color, probeg_car, vlad_car, horse_force_car, status);
            AutoQueuePtr.push(auto1);
            break;
        }
        case 2: {
            if (AutoQueuePtr.empty()) {
                std::cout << "Очередь пуста\n";
                break;
            }
            AutoQueuePtr.pop();
            break;
        }
        case 3: {
            if (AutoQueuePtr.empty()) {
                std::cout << "Очередь пуста\n";
                break;
            }
            int size_queue = AutoQueuePtr.size();
            for (int i = 0; i < size_queue; i++) {
                AutoQueuePtr.pop();
            }
            break;
        }
        case 4: {
            if (AutoQueuePtr.empty()) {
                std::cout << "Очередь пуста\n";
                break;
            }

            int nomer = 0;
            while (true) {
                std::string nomerStr;
                pos = 0;
                std::cout << "Введите номер автомобиля (от 1 до " << AutoQueuePtr.size() << ") для перезаписи\n";
                std::cin >> nomerStr;
                nomer = safeStoi(nomerStr);
                if (nomer == -1) {
                    continue;
                }
                else if (nomer < 1 || nomer > AutoQueuePtr.size()) {
                    std::cout << "Ошибка: такого номера нет\n";
                    continue;
                }
                else {
                    break;
                }
            }

            int size_queue = AutoQueuePtr.size();
            Auto* copy = nullptr;

            for (int i = 1; i <= size_queue; i++) {
                Auto* cur = AutoQueuePtr.front();
                AutoQueuePtr.pop();

                if (i == nomer) {
                    copy = cur;
                }

                AutoQueuePtr.push(cur);
            }

            if (copy != nullptr) {
                vibor(copy);
            }
            break;
        }
        case 5: {
            saveQueuePtr(AutoQueuePtr);
            return;
        }
        default: {
            std::cout << "\nНеверные данные!! Сделай все как надо.\n";
            continue;
        }
        }
    }
}

