# 🎮 HANGMAN Game - Optimized Edition

A feature-rich Hangman game built in C++ with enhanced gameplay mechanics, statistics tracking, and an immersive user experience.

## ✨ Features

- 🎯 **Interactive Gameplay** - Guess letters to uncover hidden words
- 💡 **Hint System** - Get helpful hints when you're stuck
- 📊 **Game Statistics** - Track wins, losses, and total guesses
- 🎨 **ASCII Art Hangman** - Visual representation of your progress
- 🎵 **Sound Effects** - Windows audio feedback for better immersion
- 📚 **Multiple Words** - Various word categories with hints
- ⚡ **Optimized Performance** - Efficient algorithms and data structures

## 🛠️ Technologies Used

- **Language**: C++ (C++17 Standard)
- **Platform**: Windows
- **Compiler**: G++ (MSYS2 UCRT64)
- **Audio**: Windows Multimedia API (winmm)

## 🚀 Building the Project

### Prerequisites
- G++ compiler (MSYS2 UCRT64)
- Windows OS

### Debug Build
```bash
g++ -g -std=c++17 -Wall -o hangman.exe "HANGMAN optimize.cpp" -lwinmm
```

### Release Build (Optimized)
```bash
g++ -O2 -std=c++17 -Wall -o hangman.exe "HANGMAN optimize.cpp" -lwinmm
```

### Using VS Code Tasks
```bash
# Debug build
Ctrl+Shift+B

# Release build
Ctrl+Shift+B (then select release option)
```

## 🎮 How to Play

1. Run the executable: `hangman.exe`
2. Guess letters one at a time
3. Try to reveal the complete word before running out of attempts
4. Use hints when available
5. View your statistics after each game

## 📁 Project Structure

```
HANGMAN optimize/
├── HANGMAN optimize.cpp    # Main game source code
├── README.md              # Project documentation
└── hangman.exe            # Compiled executable
```

## 📊 Game Statistics

The game tracks your performance:
- Total games played
- Wins and losses
- Average guesses per game
- Win/loss ratio

## 💡 Code Highlights

- **Struct-based Design**: Clean separation with `Word` and `GameStats` structures
- **Dynamic Gameplay**: Hangman stages progress as the player guesses incorrectly
- **Type Animation**: Smooth text output using sleep delays
- **Hint Integration**: Context-aware hints for each word
- **Performance Optimized**: Using vectors and algorithms for efficient word management

## 🎯 Future Enhancements

- [ ] Difficulty levels (Easy, Medium, Hard)
- [ ] Custom word lists
- [ ] Networked multiplayer
- [ ] Leaderboard system
- [ ] Configuration file support
- [ ] Cross-platform build support

## 📝 License

This project is open source and available for educational purposes.

## 👨‍💻 Author

Created as a C++ practice project with focus on game logic and optimization.

---

**⭐ If you like this project, consider giving it a star!**
