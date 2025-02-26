#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const std::string scoreFilePath = "/var/lib/3laba_app/max_score.txt";

int loadMaxScore() {
    std::ifstream file(scoreFilePath);
    int maxScore = 0;
    if (file.is_open()) {
        file >> maxScore;
    }
    return maxScore;
}

void saveMaxScore(int score) {
    std::ofstream file(scoreFilePath);
    if (file.is_open()) {
        file << score;
    }
}

int main() {
    std::vector<std::string> names = {"Илья Смирнов", "Анна Иванова", "Дмитрий Кузнецов",
                                      "Алексей Попов", "Роман Саныч", "Ольга Петрова",
                                      "Мария Соколова", "Виктор Павлов", "Елена Орлова",
                                      "Павел Лебедев"};

    int score = 0;
    int maxScore = loadMaxScore();

    while (true) {
        // Перемешиваем вектор имен
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(names.begin(), names.end(), g);

        std::cout << "\nВыберите номер, под которым указано имя Роман Саныч:\n\n";
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << i + 1 << ". " << names[i] << "\n";
        }

        int choice = 0;
        std::cout << "\nВаш выбор: ";
        std::cin >> choice;

        if (choice > 0 && choice <= names.size() && names[choice - 1] == "Роман Саныч") {
            ++score;
            std::cout << "Правильно! Ваш текущий счет: " << score << "\n";
        } else {
            std::cout << "Неправильно! Игра окончена.\n";
            std::cout << "Ваш текущий счет: " << score << "\n";
            if (score > maxScore) {
                maxScore = score;
                saveMaxScore(maxScore);
                std::cout << "Новый рекорд!\n";
            }
	    std::cout << "Ваш максимальный счет: " << maxScore << "\n";
            break;
        }
    }

    return 0;
}
