
# 📝 To-Do List Application

A **To-Do List** application built using **C++17**, **Qt QML**, and **Berkeley DB**. This project provides a modern graphical user interface for managing tasks and stores task data using **Berkeley DB** for persistence.

---

## 🎯 Features
- **Add, delete tasks** with a clean GUI.
- **Mark tasks as complete** or pending.
- **Persistent storage** using **Berkeley DB**.
- Built with **Qt QML** for a dynamic and interactive GUI.

---

## 📚 Dependencies
The project relies on the following dependencies:

| Dependency       | Version        | Description                    |
|------------------|----------------|--------------------------------|
| **CMake**        | 3.14+          | Build system                   |
| **Qt QML**       | 5.15+          | GUI framework                  |
| **Berkeley DB**  | 18.1.40        | Embedded database for storage  |
| **GCC/Clang**    | 9+ (GCC)       | C++17 or higher support        |

---

## 🛠️ Build Instructions

The project uses **CMake** for building. Follow these steps to build the project from the command line.

### 🔧 Steps to Build

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MahmoudAbou-Hawis/to-do-list.git
   cd to-do-list
   ```

2. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Download Berkeley DB** (if not already in the `resources` folder):
   The Berkeley DB library is bundled in the **resources** folder for easy access. If it's missing, download it manually or extract it from the provided resources:
   - Go to the `resources` directory.
   - Download **Berkeley DB 18.1.40**.
   - Extract it into the project folder or use the included copy.

4. **Run CMake to configure the project:**
   ```bash
   cmake ..
   ```

5. **Build the project using `make`:**
   ```bash
   make
   ```

6. **Run the application:**
   ```bash
   ./to-do-list
   ```

---

## 🧩 Installing Dependencies on Linux (Ubuntu Example)

If you choose to install dependencies from the package manager instead of using the included **Berkeley DB** version, follow these instructions:

### 📦 Install Required Packages:
1. **CMake:**
   ```bash
   sudo apt update
   sudo apt install cmake
   ```

2. **Qt QML:**
   ```bash
   sudo apt install qtdeclarative5-dev
   ```

3. **GCC (if not installed):**
   ```bash
   sudo apt install build-essential
   ```

4. **Berkeley DB:**
   To install **Berkeley DB** from source, follow these steps:

   1. **Download the Berkeley DB source code:**
      ```bash
      wget https://download.oracle.com/berkeley-db/db-18.1.40.tar.gz
      ```

   2. **Extract the tarball:**
      ```bash
      tar -xzvf db-18.1.40.tar.gz
      ```

   3. **Navigate to the build directory:**
      ```bash
      cd db-18.1.40/build_unix
      ```

   4. **Configure the build:**
      ```bash
      ./dist/configure --prefix=/usr/local
      ```

   5. **Build Berkeley DB:**
      ```bash
      make
      ```

   6. **Install Berkeley DB:**
      ```bash
      sudo make install
      ```

---

## 🖥️ Running the Application
After building the project, navigate to the `build` directory and run the executable:

```bash
cd build
./to-do-list
```

---

## 📂 Project Structure
```
to-do-list/
├── CMakeLists.txt     # CMake configuration file
├── main.cpp           # Main entry point
├── headers/           # Header files
├── src/               # Source files
├── resources/         # GUI assets & Berkeley DB
├── build/             # Build directory (generated)
```

---


## 📜 License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

---

## 📧 Contact
For any inquiries or feedback, feel free to contact:

**Mahmoud Abou-Hawis**  
- GitHub: [MahmoudAbou-Hawis](https://github.com/MahmoudAbou-Hawis)  
- LinkedIn: [Mahmoud Abou-Hawis](https://www.linkedin.com/in/abou-hawis/)  
