# AssaultCube Trainer (C++ / WinAPI)

🎯 A lightweight external memory trainer for the open-source game **AssaultCube**.  
Built with **pure C++** and **Windows API**, this project demonstrates practical memory manipulation techniques through real-time modification of in-game values.

---

## 📌 Features

- 📦 Writes directly to memory of external process (`ac_client.exe`)
- 🔫 Sets ammo value to `1337` in singleplayer mode
- 🧱 Uses only native Windows API — no dependencies
- 🧠 Demonstrates core reverse engineering and game hacking concepts

---

## 🚀 How to Run

1. 📥 Download and install [AssaultCube (v1.2.0.2)](https://github.com/assaultcube/AC/releases)
2. 🎮 Launch the game and enter **singleplayer**
3. 🛠️ Open the trainer source in **Visual Studio** (2022 or newer recommended)
4. 🔨 Build the project (Win64 / Release configuration)
5. ▶️ Run the compiled `.exe` — your ammo will now be set to 1337

---

## 🛠️ Tech Stack

- Language: **C++**
- Platform: **Windows(10,11)**
- APIs used: `OpenProcess`, `WriteProcessMemory`, `CreateToolhelp32Snapshot`, `Module32First`, `Module32Next`

---

## 💻 Code Snippet (Core Logic)

```cpp
uintptr_t ammoAddress = 0x0077A250;  // Static memory address
int ammoValue = 1337;

HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
WriteProcessMemory(hProcess, (LPVOID)ammoAddress, &ammoValue, sizeof(ammoValue), nullptr);
