#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const std::string scoreFilePath = "/var/lib/lib/3laba_app/max_score.txt";
const std::string historyFilePath = "/var/lib/lib/3laba_app/score_history.txt";

enum class Language { RUSSIAN, ENGLISH };

Language chooseLanguage() {
    int choice;
    std::cout << "Choose language (1 - Russian, 2 - English): ";
    std::cin >> choice;
    return (choice == 2) ? Language::ENGLISH : Language::RUSSIAN;
}

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

void saveScoreHistory(int score) {
    std::ofstream file(historyFilePath, std::ios::app);
    if (file.is_open()) {
        file << "Score: " << score << "\n";
    }
}

void resetScores() {
    std::ofstream maxScoreFile(scoreFilePath);
    std::ofstream historyFile(historyFilePath);
    if (maxScoreFile.is_open() && historyFile.is_open()) {
        maxScoreFile << 0;
        historyFile << "";  // Clear history
    }
}

int main() {
    // Выбор языка
    Language lang = chooseLanguage();

    std::vector<std::string> names = lang == Language::RUSSIAN
        ? std::vector<std::string>{"Илья Смирнов", "Анна Иванова", "Дмитрий Кузнецов",
                                   "Алексей Попов", "Роман Саныч", "Ольга Петрова",
                                   "Мария Соколова", "Виктор Павлов", "Елена Орлова",
                                   "Павел Лебедев"}
        : std::vector<std::string>{"Ilya Smirnov", "Anna Ivanova", "Dmitry Kuznetsov",
                                   "Alexey Popov", "Roman Sanych", "Olga Petrova",
                                   "Mariya Sokolova", "Victor Pavlov", "Elena Orlova",
                                   "Pavel Lebedev"};

    int score = 0;
    int maxScore = loadMaxScore();

    while (true) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(names.begin(), names.end(), g);

        std::cout << "\nChoose the number under which Roman Sanych is listed:\n\n";
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << i + 1 << ". " << names[i] << "\n";
        }

        int choice = 0;
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice > 0 && choice <= names.size() && names[choice - 1] == (lang == Language::RUSSIAN ? "Роман Саныч" : "Roman Sanych")) {
            ++score;
            std::cout << "Correct! Your current score: " << score << "\n";
        } else {
            std::cout << "Wrong! Game over.\n";
            std::cout << "Your current score: " << score << "\n";
            if (score > maxScore) {
                maxScore = score;
                saveMaxScore(maxScore);
                std::cout << "New record!\n";
            }
            saveScoreHistory(score);
            std::cout << "Your max score: " << maxScore << "\n";
            break;
        }
    }

    return 0;
}
