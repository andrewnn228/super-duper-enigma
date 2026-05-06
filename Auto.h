#pragma once
#include "Zavisimpsti.h"
class Auto
{
private:
    std::string marka;
    std::string model;
    Color color;
    int probeg;
    int count_vlad;
    int horse_force;
    Status status_auto;
public:
    Auto() {
        this->marka = "";
        this->model = "";
        this->color = none;
        this->probeg = 0;
        this->count_vlad = 0;
        this->horse_force = 0;
        this->status_auto = None;
    }
    Auto(std::string marka, std::string model, Color color, int probeg, int count_vlad, int horse_force, Status status_auto) {
        this->marka = marka;
        this->model = model;
        this->color = color;
        this->probeg = probeg;
        this->count_vlad = count_vlad;
        this->horse_force = horse_force;
        this->status_auto = status_auto;
    }
    void Drive(int km) {
        if (this->probeg > 10000000)
        {
            this->status_auto = old_car;
            std::cout << "Машина сломана окончательно (ее не починить)" << std::endl;
            return;
        }
        if (this->status_auto != dtp_car && this->status_auto != process_car) {
            this->probeg += km;
            std::cout << "\nПробег: " << this->probeg << std::endl;
        }
        else if (this->status_auto == dtp_car) {
            std::cout << "\nМашина в ДТП, почини сначала машину\n";
        }
        else if (this->status_auto == process_car) {
            std::cout << "\nМашина в ремонте, забери машину из ремонта\n";
        }
    }
    void Sell() {
        if (this->probeg > 10000000)
        {
            this->status_auto = old_car;
            std::cout << "Машина сломана окончательно (ее не починить)" << std::endl;
            return;
        }
        if (this->status_auto != dtp_car && this->status_auto != process_car) {
            this->count_vlad++;
            std::cout << "\nМашина была продана. Число владельцев автомобиля: " << this->count_vlad << std::endl;
            Drive(100);
        }
        else if (this->status_auto == dtp_car) {
            std::cout << "\nМашина в ДТП, почини сначала машину\n";
        }
        else if (this->status_auto == process_car) {
            std::cout << "\nМашина в ремонте, забери машину из ремонта\n";
        }
    }
    void DTP() {
        if (this->probeg > 10000000)
        {
            this->status_auto = old_car;
            std::cout << "Машина сломана окончательно (ее не починить)" << std::endl;
            return;
        }
        if (this->status_auto != dtp_car && this->status_auto != process_car) {
            std::cout << "\nМашина попала в ДТП\n";
            Drive(100);
            this->status_auto = Status::dtp_car;
        }
        else if (this->status_auto == dtp_car) {
            std::cout << "\nМашина в ДТП, почини сначала машину\n";
        }
        else if (this->status_auto == process_car) {
            std::cout << "\nМашина в ремонте, забери машину из ремонта\n";
        }
    }
    void Repair() {
        if (this->probeg > 10000000)
        {
            this->status_auto = old_car;
            std::cout << "Машина сломана окончательно (ее не починить)" << std::endl;
            return;
        }
        if (this->status_auto != process_car) {
            std::cout << "\nМашина в ремонте" << std::endl;
            this->status_auto = Status::process_car;
        }
        else
        {
            std::cout << "Машина уже в ремонте" << std::endl;
        }
    }
    void UnRepair() {
        if (this->probeg > 10000000)
        {
            this->status_auto = old_car;
            std::cout << "Машина сломана окончательно (ее не починить)" << std::endl;
            return;
        }
        if (this->status_auto == process_car) {
            std::cout << "\nМашину забрали из ремонта" << std::endl;
            this->status_auto = Status::normal_car;
            Drive(100);
        }
        if (this->status_auto == normal_car) {
            std::cout << "Машина в нормальном состоянии" << std::endl;
        }
        if (this->status_auto == dtp_car) {
            std::cout << "Машина в ДТП, отдай в ремонт" << std::endl;
        }
    }
    std::string get_mark() const {
        return this->marka;
    }
    std::string get_model() const {
        return this->model;
    }
    Color get_color() const {
        return this->color;
    }
    int get_probeg() const {
        return this->probeg;
    }
    int get_count_vlad() const {
        return this->count_vlad;
    }
    int get_horse_force() const {
        return this->horse_force;
    }
    Status get_status() const {
        return this->status_auto;
    }
};

