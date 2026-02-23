#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

void type(string a)
{
    for (int i = 0; a[i] != '\0'; i++) {
        cout << a[i];
        Sleep(42);
    }
}

struct Word {
    string word;
    string hint;
};
struct GameStats {
    int totalGames = 0;
    int wins = 0;
    int losses = 0;
    int totalGuesses = 0;
};

void displayHangman(int wrong) {
    const vector<string> hangman = {
        "   _______     \n"
        "  |/      |    \n"
        "  |            \n"
        "  |            \n"
        "  |            \n"
        "  |            \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |            \n"
        "  |            \n"
        "  |            \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |       |    \n"
        "  |       |    \n"
        "  |            \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |      /|    \n"
        "  |       |    \n"
        "  |            \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |      /|\\   \n"
        "  |       |    \n"
        "  |            \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |      /|\\   \n"
        "  |       |    \n"
        "  |      /     \n"
        "__|__          \n",
        "   _______     \n"
        "  |/      |    \n"
        "  |      \xF0\x9F\x98\x9F   \n"
        "  |      /|\\   \n"
        "  |       |    \n"
        "  |      / \\   \n"
        "__|__         \n"
    };

    cout << hangman[wrong] << endl;
}

void printGameStats(const GameStats& stats) {
    cout << "\n\033[1;32m===== Game Stats =====\033[0m\n"; 
    cout << "Total games: " << stats.totalGames << "\n";
    cout << "Wins: " << stats.wins << "\n";
    cout << "Losses: " << stats.losses << "\n";
    cout << "Total guesses: " << stats.totalGuesses << "\n";
    double average = 0.0;
    if (stats.totalGames > 0) {
        average = static_cast<double>(stats.totalGuesses) / stats.totalGames;  };
    cout << "Average guesses per game: " << average << "\n";
	cout << "======================\n\n";
}

void playMusic(const char* filename) {
    PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
}


void playGame(vector<Word>& levelWords, const string& levelname, GameStats& stats) {
    srand(time(0));
    stats.totalGames++;
    Word chosen = levelWords[rand() % levelWords.size()];
    string word = chosen.word;
    string display(word.size(), '_');
    vector<char> guessed;
    int wrong = 0;
    int guessesThisGame = 0;

    cout << "\nHint: " << chosen.hint << endl;

    while (wrong < 6 && display != word) {
        system("cls");
        system("Color 0A"); 
        cout << "\033[1m";
        cout << R"(
 _   _    _    _   _   ____   __  __      _      _   _ 
| | | |  / \  | \ | | / ___| |  \/  |    / \    | \ | |
| |_| | / _ \ |  \| | | |  _ | |\/| |   / _ \   |  \| |
|  _  |/ ___ \| |\  | | |_| || |  | |  / ___ \  | |\  |
|_| |_/_/   \_\_| \_| \____/ |_|  |_| /_/   \_\ |_| \_|
        )" << endl;
        cout << "\033[0m" << endl;

        cout << "Level: " << levelname << endl;
        cout << "Hint: " << chosen.hint << endl;
        cout << "Word: " << display << endl;
        displayHangman(wrong);
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);
        guessesThisGame++;

        if (find(guessed.begin(), guessed.end(), guess) != guessed.end()) {
            continue;
        }

        guessed.push_back(guess);
        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                display[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            wrong++;
        }
    }

    stats.totalGuesses += guessesThisGame;

    system("cls");
    system("Color 0A");
    cout << "\033[1m";
    cout << R"(
 _   _    _    _   _   ____   __  __      _      _   _ 
| | | |  / \  | \ | | / ___| |  \/  |    / \    | \ | |
| |_| | / _ \ |  \| | | |  _ | |\/| |   / _ \   |  \| |
|  _  |/ ___ \| |\  | | |_| || |  | |  / ___ \  | |\  |
|_| |_/_/   \_\_| \_| \____/ |_|  |_| /_/   \_\ |_| \_|
        )" << endl;
    cout << "\033[0m" << endl;
    Sleep(42);

    cout << "Level: " << levelname << endl;
    cout << "Hint: " << chosen.hint << endl;
    cout << "Word: " << display << endl;
    displayHangman(wrong);

    if (display == word) {
        stats.wins++;
        playMusic("wining.wav");
        cout << "\n\xF0\x9F\x8E\x89\xF0\x9F\x8E\x89 Congratulations! \xF0\x9F\x8E\x89\xF0\x9F\x8E\x89\n";
        cout << "\xE2\x9C\x85 You guessed the word correctly: " << word << "\n";
        cout << "\xF0\x9F\x8F\x86 You're a Hangman Champion! \xF0\x9F\x98\x84\n";
    }
    else {
        stats.losses++;
        playMusic("lose.wav");
        cout << "\n\xF0\x9F\x92\x80 Game Over! \xF0\x9F\x98\xA2\n";
        cout << "The correct word was: " << word << "\n";
        cout << "\xF0\x9F\x99\x88 Better luck next time! \xF0\x9F\x92\xAA\n";
    }

    cout << "\nWord guessed: " << display << "  Correct word: " << word << "\n";

    printGameStats(stats);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    GameStats stats;
    char again;
    do {
        system("Color 0A");
        cout << "\033[1m" << endl;
        cout << R"(
 _   _    _    _   _   ____   __  __      _      _   _ 
| | | |  / \  | \ | | / ___| |  \/  |    / \    | \ | |
| |_| | / _ \ |  \| | | |  _ | |\/| |   / _ \   |  \| |
|  _  |/ ___ \| |\  | | |_| || |  | |  / ___ \  | |\  |
|_| |_/_/   \_\_| \_| \____/ |_|  |_| /_/   \_\ |_| \_|
        )" << endl;
        cout << "\033[0m" << endl;

        vector<Word> School = {
            {"apple", "A common fruit in lunchboxes."},
            {"book", "You read this in class."},
            {"pencil", "Used for writing."},
            {"eraser", "Used to remove mistakes."},
            {"teacher", "Leads the classroom."},
            {"chalk", "Used on a blackboard."},
            {"notebook", "You write your notes here."},
            {"ruler", "You used it to draw statright line."},
            {"bag", "You carry this to school."},
            {"uniform", "What all students wear in school."}
        };

        vector<Word> College = {
            {"lecture", "You attend this (or sleep through it)."},
            {"assignment", "You submit this late."},
            {"exam", "You fear this."},
            {"professor", "Teaches at college."},
            {"project", "You work on this with a group."},
            {"semester", "Half of an academic year."},
            {"library", "You study here quietly."},
            {"hostel", "Where students live on campus."},
            {"cafeteria", "Place to grab snacks or coffee."},
            {"presentation", "You stand in front and explain your topic."}
        };

        vector<Word> University = {
            {"thesis", "Your final academic boss fight."},
            {"research", "You do this for knowledge."},
            {"internship", "Work experience for students."},
            {"dissertation", "A long report written for a degree."},
            {"scholarship", "Financial aid for good students."},
            {"laboratory", "A place for experiments."},
            {"graduation", "The big day with caps and gowns."},
            {"professor", "An academic expert or teacher."},
            {"publication", "When your research is printed officially."},
            {"innovation", "Creating something new and useful."}
        };

        type("Welcome to Hangman Game!");
        cout << "\n";
        type("Choose Level : ");
        cout << "\n";
        type("1.School");
        cout << "\n";
        type("2.College");
        cout << "\n";
        type("3.University");
        cout << "\n";

        char choice;
        cin >> choice;

        switch (choice) {
        case '1': playGame(School, "School", stats); break;
        case '2': playGame(College, "College", stats); break;
        case '3': playGame(University, "University", stats); break;
        default: cout << "Invalid choice!" << endl;
        }
        if ((choice >= 'A' && choice <= 'Z') || (choice >= 'a' && choice <= 'z')) {
            cout << "Invalid input! Alphabets are not allowed.\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') {
            cout << "Thank you for playing! Goodbye!" << endl;
        }
        else {
            system("cls");
        }
    } while (again == 'y' || again == 'Y');

    return 0;
}

