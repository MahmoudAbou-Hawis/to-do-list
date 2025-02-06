# 📝 To-Do List Application

A **To-Do List** application built using **C++17**, **Qt QML**, and **Berkeley DB**. This project provides a modern graphical user interface for managing tasks and stores task data using **Berkeley DB** for persistence. Additionally, it supports **Google login**, **Google Calendar integration**, and **task assignment with Google Calendar notifications**.

---

## 🎯 Features

- **Add, delete, and manage tasks** with a clean GUI.
- **Mark tasks as complete** or pending.
- **Persistent storage** using **Berkeley DB**.
- **Google Login** for authentication.
- **Schedule tasks in Google Calendar** automatically.
- **Assign tasks to users**, with notifications sent via Google Calendar.
- Built with **Qt QML** for a dynamic and interactive GUI.

---

## 📚 Dependencies

The project relies on the following dependencies:

| Dependency      | Version  | Description                            |
| --------------- | -------- | -------------------------------------- |
| **CMake**       | 3.14+    | Build system                           |
| **Qt QML**      | 5.15+    | GUI framework                          |
| **Berkeley DB** | 18.1.40  | Embedded database for storage          |
| **GCC/Clang**   | 9+ (GCC) | C++17 or higher support                |
| **Google API**  | Latest   | Google authentication and Calendar API |

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

   - Go to the `resources` directory.
   - Download **Berkeley DB 18.1.40**.
   - Extract it into the project folder or use the included copy.

4. **Set up Google API credentials:**

   - Create a **Google Cloud Project** and enable **Google Calendar API**.
   - Download the **OAuth 2.0 client ID JSON** file.
   - Place it inside the project directory.
   - Set up the authentication process as per Google API documentation.

5. **Run CMake to configure the project:**

   ```bash
   cmake ..
   ```

6. **Build the project using ********************************`make`********************************:**

   ```bash
   make
   ```

7. **Run the application:**

   ```bash
   ./to-do-list
   ```

---

## 🧩 Google API Setup

To enable Google login and Calendar integration:

1. **Create a Google Cloud Project**.
2. **Enable the Google Calendar API and OAuth 2.0 authentication**.
3. **Download the OAuth client JSON** and configure it within the application.

---

## 🗃️ Google Calendar Notifications

To send notifications for assigned tasks:

1. **When a task is assigned using email, an event is created in Google Calendar**.
2. **Google Calendar sends notifications automatically** to the assigned user.

---

## 🖥️ Running the Application

After building the project, navigate to the `build` directory and run the executable:

```bash
cd build
./to-do-list.
```

---

## 📚 Project Structure

```
to-do-list/
├── CMakeLists.txt     # CMake configuration file
├── main               # Main entry point
├── GUI/               # GUI source files
├── tasks/             # Tasks source files
├── utils/             # Utility functions
├── google_api/        # Google authentication and Calendar API
├── build/             # Build directory (generated)
```

---

## 📝 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

---

## 💎 Contact

For any inquiries or feedback, feel free to contact:

**Mahmoud Abou-Hawis**

- GitHub: [MahmoudAbou-Hawis](https://github.com/MahmoudAbou-Hawis)
- LinkedIn: [Mahmoud Abou-Hawis](https://www.linkedin.com/in/abou-hawis/)

