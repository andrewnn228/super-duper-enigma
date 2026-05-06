#include "vibor.h"
void vibor(Auto* a) {
    while (true) {
        std::cout << "\nВыберите действие:\n1 - Ездить\n2 - Продать\n3 - ДТП\n4 - Ремонт\n5 - Забрать из ремонта\n6 - Характеристики АВТО\n7 - Выйти из программы\n";
        std::string vibor_pol;
        std::cout << "\nВведите число для действия (можно ввести только от 1 до 7): ";
        if (!(std::cin >> vibor_pol)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        size_t pos1;
        int vibor_pol1 = std::stoi(vibor_pol, &pos1);
        if (pos1 != vibor_pol.size()) {
            std::cout << "Ошибка: введены не только цифры\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string vvod;
        size_t pos;

        switch (vibor_pol1) {
        case 1:
            std::cout << "\nВведите кол-во километров для езды (округляйте, чтобы не было дробных): " << std::endl;
            std::getline(std::cin, vvod);

            if (vvod.empty()) {
                std::cout << "\nВы ничего не ввели!\n";
                continue;
            }

            try
            {
                int km = std::stoi(vvod, &pos);
                if (pos != vvod.size()) {
                    std::cout << "Ошибка: введены не только цифры\n";
                    break;
                }
                if (km < 0) {
                    std::cout << "Ошибка: число не может быть отрицательным\n";
                    break;
                }
                if (km < 0) throw std::out_of_range("neg");
                a->Drive(km);
            }
            catch (const std::invalid_argument&)
            {
                std::cout << "\nВы ввели строку, а не число!\n";
                continue;
            }
            catch (const std::out_of_range&)
            {
                std::cout << "\nЧисло слишком большое\n";
                continue;
            }
            break;
        case 2:
            a->Sell();
            break;
        case 3:
            a->DTP();
            break;
        case 4:
            a->Repair();
            break;
        case 5:
            a->UnRepair();
            break;
        case 6:
            std::cout << "Марка: " << a->get_mark() << std::endl;
            std::cout << "Модель: " << a->get_model() << std::endl;
            if (a->get_color() == 0)
            {
                std::cout << "Цвет: Red" << std::endl;
            }
            else if (a->get_color() == 1)
            {
                std::cout << "Цвет: Yellow" << std::endl;
            }
            else if (a->get_color() == 2)
            {
                std::cout << "Цвет: Brown" << std::endl;
            }
            else if (a->get_color() == 3)
            {
                std::cout << "Цвет: Black" << std::endl;
            }
            else if (a->get_color() == 4)
            {
                std::cout << "Цвет: White" << std::endl;
            }
            else if (a->get_color() == 5)
            {
                std::cout << "Цвет: Blue" << std::endl;
            }
            else if (a->get_color() == 6)
            {
                std::cout << "Цвет: None" << std::endl;
            }
            std::cout << "Пробег: " << a->get_probeg() << std::endl;
            std::cout << "Кол-во владельцев: " << a->get_count_vlad() << std::endl;
            std::cout << "Лошадиные силы: " << a->get_horse_force() << std::endl;
            if (a->get_status() == 0)
            {
                std::cout << "Состояние: ДТП" << std::endl;
            }
            else if (a->get_status() == 1)
            {
                std::cout << "Состояние: В ремонте" << std::endl;
            }
            else if (a->get_status() == 2)
            {
                std::cout << "Состояние: Нормальное" << std::endl;
            }
            else if (a->get_status() == 3)
            {
                std::cout << "Состояние: None" << std::endl;
            }
            else if (a->get_status() == 4)
            {
                std::cout << "Состояние: Старое" << std::endl;
            }
            break;
        case 7:
            return;
        default:
            std::cout << "\nНеверные данные!! Сделай все как надо.\n";
            continue;
        }
    }
    return;
}