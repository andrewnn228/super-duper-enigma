#pragma once
#include "Auto.h"

int safeStoi(const std::string& input);

Auto readFile(const std::string& line);
void writeFile(std::ofstream& file, const Auto& car);
void loadVector(std::vector<Auto>& cars);
void loadList(std::list<Auto>& cars);
void loadQueue(std::queue<Auto>& cars);
void loadVectorPtr(std::vector<Auto*>& cars);
void loadListPtr(std::list<Auto*>& cars);
void loadQueuePtr(std::queue<Auto*>& cars);
void saveVector(const std::vector<Auto>& cars);
void saveList(const std::list<Auto>& cars);
void saveQueue(std::queue<Auto> cars);
void saveVectorPtr(const std::vector<Auto*>& cars);
void saveListPtr(const std::list<Auto*>& cars);
void saveQueuePtr(std::queue<Auto*> cars);