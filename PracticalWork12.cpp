#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


// Структура для вопросов
struct Question {
    string text;
    string options[4];
    int correctAnswer;
};


int getRandomNumber(int min, int max);
void showGreeting();
void showMenu();
void showRules();
void changePlayerName(string& playerName);
void changeNumberOfQuestions(int& numQuestions);
void changeInterfaceColor();
void showSettings();
void showQuestion(const Question& question);
bool checkAnswer(const Question& question, char answer);
void playGame();


int main() {
    setlocale(LC_ALL, "RU");

    srand(time(0)); // Инициализация генератора случайных чисел

    showGreeting();

    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            playGame();
            break;
        case 2:
            showSettings();
            break;
        case 3:
            showRules();
            break;
        case 4:
            cout << "\n\t\tДо свидания!\n";
            return 0;
        default:
            cout << "\t\tНекорректный ввод.\n";
        }
    }

    return 0;
}


// Функция для генерации случайного числа
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}


// Функция для вывода приветствия
void showGreeting() {
    cout << "\n\t\tДобро пожаловать в викторину!\n\n";
}


// Функция для вывода меню
void showMenu() {
    cout << "\n\t\tМеню:\n\n";
    cout << "\t\t1. Начать игру\n";
    cout << "\t\t2. Настройки\n";
    cout << "\t\t3. Правила\n";
    cout << "\t\t4. Выйти\n\n";
    cout << "\t\tВыберите пункт: ";
}


// Функция для вывода правил
void showRules() {
    cout << "\n\t\tПравила игры:\n\n";
    cout << "\t\t- Вы получаете очки за правильный ответ на вопрос.\n";
    cout << "\t\t- Вы проходите дальше за правильный ответ.\n";
    cout << "\t\t- Вы теряете жизнь при неправильном ответе.\n\n";
    cout << "\t\tНажмите Enter, чтобы вернуться в главное меню...";
    cin.ignore();
    cin.get();
}


// Функция для изменения имени игрока
void changePlayerName(string& playerName) {
    cout << "\n\t\tВведите новое имя игрока: ";
    getline(cin, playerName);
    cout << "\n\t\tИмя игрока изменено на: " << playerName << endl;
}


// Функция для изменения количества вопросов
void changeNumberOfQuestions(int& numQuestions) {
    cout << "\n\t\tВведите количество вопросов (8, 10 или 12): ";
    cin >> numQuestions;
    while (numQuestions != 8 && numQuestions != 10 && numQuestions != 12) {
        cout << "\t\tНекорректный ввод. Введите 8, 10 или 12: ";
        cin >> numQuestions;
    }
    cout << "\n\t\tКоличество вопросов изменено на: " << numQuestions << endl;
}


// Функция для изменения цвета интерфейса (не реализовано)
void changeInterfaceColor() {
    cout << "\n\t\tИзменение цвета интерфейса - в разработке...\n";
}


// Функция для вывода настроек
void showSettings() {
    string playerName = "Игрок";
    int numQuestions = 10;
    cout << "\n\t\tНастройки:\n\n";
    cout << "\t\t1. Имя игрока: " << playerName << endl;
    cout << "\t\t2. Количество вопросов: " << numQuestions << endl;
    cout << "\t\t3. Цвет интерфейса\n\n";
    cout << "\t\tВыберите пункт (или 0, чтобы вернуться в главное меню): ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        changePlayerName(playerName);
        break;
    case 2:
        changeNumberOfQuestions(numQuestions);
        break;
    case 3:
        changeInterfaceColor();
        break;
    case 0:
        break;
    default:
        cout << "\t\tНекорректный ввод.\n";
    }
}


// Функция для вывода вопроса
void showQuestion(const Question& question) {
    cout << "\n\t\t" << question.text << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "\t\t" << char('A' + i) << ". " << question.options[i] << endl;
    }
}


// Функция для проверки ответа
bool checkAnswer(const Question& question, char answer) {
    return answer == char('A' + question.correctAnswer);
}


// Функция для игры
void playGame() {
    string playerName = "Игрок";
    int numQuestions = 10;
    int lives = 3;
    int score = 0;

    // Вопросы
    vector<Question> questions = {
        {
            "Системный язык программирования?",
            {"Python", "C#", "Ruby", "C++"},
            3
        },
        {
            "Язык программирования, используемый для веб-разработки?",
            {"C++", "Java", "JavaScript", "Python"},
            2
        },
        {
            "Язык программирования, используемый для разработки мобильных приложений?",
            {"C#", "Swift", "Kotlin", "Python"},
            1
        },
        {
            "Какой язык программирования не является объектно-ориентированным?",
            {"C++", "Java", "Python", "C"},
            3
        },
        {
            "Какой язык программирования используется для разработки игр?",
            {"JavaScript", "Python", "C++", "Java"},
            2
        },
        {
            "Какой язык программирования используется для разработки баз данных?",
            {"C#", "SQL", "Python", "Java"},
            1
        },
        {
            "Какой язык программирования используется для разработки искусственного интеллекта?",
            {"Python", "C++", "Java", "C#"},
            0
        },
        {
            "Какой язык программирования используется для разработки веб-серверов?",
            {"PHP", "Python", "Java", "C#"},
            0
        },
        {
            "Какой язык программирования используется для разработки мобильных приложений для Android?",
            {"Kotlin", "Swift", "Java", "C#"},
            2
        },
        {
            "Какой язык программирования используется для разработки приложений для iOS?",
            {"Swift", "Kotlin", "Java", "C#"},
            0
        }
    };


    // Генерация случайного порядка вопросов
    for (int i = questions.size() - 1; i > 0; --i) {
        int j = getRandomNumber(0, i);
        swap(questions[i], questions[j]);
    }


    // Запуск игры
    cout << "\n\t\tИгра началась!\n\n";
    for (int i = 0; i < numQuestions; ++i) {
        cout << "\t\t[+] Игрок: " << playerName << " | Жизни: " << lives << " | Очки: " << score << endl;
        showQuestion(questions[i]);
        cout << "\t\t[+] Выбрать ответ: ";
        char answer;
        cin >> answer;
        if (checkAnswer(questions[i], answer)) {
            cout << "\t\tПравильно! +1 очко.\n";
            score++;
        }
        else {
            cout << "\t\tНеправильно! -1 жизнь.\n";
            lives--;
        }
        if (lives == 0) {
            cout << "\n\t\tВы проиграли! 😔\n";
            break;
        }
    }
    if (lives > 0) {
        cout << "\n\t\tВы победили! 🥳\n";
        cout << "\t\tОставшиеся жизни: " << lives << endl;
        cout << "\t\tНабранные очки: " << score << endl;
    }
}