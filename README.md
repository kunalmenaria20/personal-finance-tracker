# Personal Finance Tracker

📊 A simple command-line based personal finance tracker built in C++ using CMake.  
Track your expenses, income, and manage your finances easily from your terminal.

> 🚧 **This project is currently in development.** More features and improvements will be added soon!

---

## 📁 Project Structure (Work In Progress)
include/ # Header files (Transaction.h, TransactionManager.h)
src/ # Source files (main.cpp, Transaction.cpp,TransactionManager.cpp) 
CMakeLists.txt # CMake build configuration

---

## ✅ Planned Features

- [x] Track income and expenses
- [ ] Filter by category/date
- [ ] View summaries (daily/monthly)
- [ ] Import/export CSV data
- [ ] Add basic CLI UI enhancements
- [ ] (Future) Add GUI using Qt or similar

---

## 🛠️ Build Instructions

bash
git clone https://github.com/kunalmenaria20/personal-finance-tracker.git
cd personal-finance-tracker
mkdir build && cd build
cmake ..
mingw32-make
./finance-tracker.exe
