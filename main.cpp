#include "main.h"
int main()
{
    std::string marka_car;
    std::string model_car;
    std::string color_car;
    std::string probeg_car;
    Color color;
    std::string vlad_car;
    std::string horse_force_car;
    std::string status_car;
    Status status;
    std::string vibor_pol1;
    std::string vibor_pol2;
    int flag_vibor_pol1;
    bool flag2_vibor_pol2;
    setlocale(0, "");
    while (true) {
        std::cout << "\nВыберите действие. Какой контейнер вы хотите создать:\n1 - Создать vector\n2 - Создать list\n3 - Создать queue\n";
        std::cout << "\nВведите число для действия (можно ввести только от 1 до 3): ";
        std::cin >> vibor_pol1;
    
        int menu1 = safeStoi(vibor_pol1);
        if (menu1 == -1) {
            continue;
        }

        switch (menu1) {
        case 1:
            flag_vibor_pol1 = 1;
            break;
        case 2:
            flag_vibor_pol1 = 2;
            break;
        case 3:
            flag_vibor_pol1 = 3;
            break;
        default:
            std::cout << "\nНеверные данные!! Сделай все как надо.\n";
            continue;
        }
        break;
    }
    while (true) { 
        std::cout << "\nВыберите действие. Какой вид объекта хранить:\n1 - Указатели на объекты\n2 - Сами объекты\n";
        std::cout << "\nВведите число для действия (можно ввести только от 1 до 2): ";
        std::cin >> vibor_pol2;

        int menu2 = safeStoi(vibor_pol2);
        if (menu2 == -1) {
            continue;
        }
        switch (menu2) {
        case 1:
            flag2_vibor_pol2 = true;
            break;
        case 2:
            flag2_vibor_pol2 = false;
            break;
        default:
            std::cout << "\nНеверные данные!! Сделай все как надо.\n";
            continue;
        }
        break;
    }
    int** arr = new int* [6];
    int a = 0;
    if (flag_vibor_pol1 == 1 and flag2_vibor_pol2 == true) {
        std::vector<Auto*> AutoVecPtr;
        loadVectorPtr(AutoVecPtr);
        vibor1(AutoVecPtr);
    }
    else if (flag_vibor_pol1 == 1 and flag2_vibor_pol2 == false) {
        std::vector<Auto> AutoVec;
        loadVector(AutoVec);
        vibor2(AutoVec);
    }
    else if (flag_vibor_pol1 == 2 and flag2_vibor_pol2 == true) {
        std::list<Auto*> AutoListPtr;
        loadListPtr(AutoListPtr);
        vibor4(AutoListPtr);
    }
    else if (flag_vibor_pol1 == 2 and flag2_vibor_pol2 == false) {
        std::list<Auto> AutoList;
        loadList(AutoList);
        vibor3(AutoList);
    }
    else if (flag_vibor_pol1 == 3 and flag2_vibor_pol2 == true) {
        std::queue<Auto*> AutoQueuePtr;
        loadQueuePtr(AutoQueuePtr);
        vibor6(AutoQueuePtr);
    }
    else if (flag_vibor_pol1 == 3 and flag2_vibor_pol2 == false) {
        std::queue<Auto> AutoQueue;
        loadQueue(AutoQueue);
        vibor5(AutoQueue);
    }
    system("pause");
    return 0;
}