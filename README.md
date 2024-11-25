# **Task Manager Simulation**

---

#### **Overview**
This program simulates a simple task manager by reading and managing process information from the system's task list. The program allows users to view, add, and sort processes based on various attributes, such as process ID, memory usage, and session details. The program outputs data in a well-formatted table.

---

#### **Features**
1. Automatically fetches the current processes on the system (`tasklist`) and stores them in a CSV file (`processes.csv`).
2. Parses the CSV file to extract and manage process details:
   - **Image Name**
   - **Process ID**
   - **Session Name**
   - **Session Number**
   - **Memory Usage**
3. Allows users to:
   - Add custom processes manually.
   - Display the list of processes in tabular format.
   - Sort the processes by:
     - Image Name
     - Process ID
     - Session Name
     - Session Number
     - Memory Usage
4. Uses a vector-based structure for storing and managing process information.

---

#### **How It Works**
1. **Initialization**:
   - The program executes the command `tasklist /FO CSV /NH` to get the current system processes and saves the output to `processes.csv`.
   - The processes are then read, parsed, and stored in a vector of `process` objects.

2. **Process List Class**:
   - The `ProcessList` class is responsible for managing the vector of processes.
   - Includes methods for sorting, adding, and displaying processes.

3. **Main Menu**:
   - Provides an interactive interface for users to manage the task list.

---

#### **How to Use**

1. **Compile the Code**:
   Use a C++ compiler (e.g., `g++`) to compile the program:
   ```bash
   g++ task_manager.cpp -o task_manager
   ```

2. **Run the Program**:
   Execute the compiled file:
   ```bash
   ./task_manager
   ```

3. **Menu Options**:
   - **1. Add Process**: Allows users to add a custom process by entering its details.
   - **2. Display Manager**: Displays all processes in a formatted table.
   - **3. Sort by Image Name**: Displays the process list sorted by the image name.
   - **4. Sort by ID**: Displays the process list sorted by process ID.
   - **5. Sort by Session Name**: Displays the process list sorted by session name.
   - **6. Sort by Session Number**: Displays the process list sorted by session number.
   - **7. Sort by Memory Usage**: Displays the process list sorted by memory usage.
   - **0. Exit**: Exits the program.

---

#### **Dependencies**
- The program relies on the `tasklist` command, available on Windows systems.
- A C++ compiler supporting C++11 or later is required.

---

#### **Key Classes and Functions**

1. **`process` Class**:
   - Stores attributes for a single process.
   - Includes a `displayProcess` method to print the process in a formatted manner.

2. **`ProcessList` Class**:
   - Manages the list of processes using a `vector`.
   - Includes methods to:
     - Parse the `processes.csv` file.
     - Add a process to the list.
     - Sort processes by various attributes.
     - Display the process list.

3. **`toInt` Function**:
   - Converts strings containing numbers (e.g., `41,184`) to integers by ignoring non-digit characters.

4. **`readWords` Function**:
   - Parses a single line of CSV input into a vector of process attributes.

---

#### **Sample Output**
**Menu Example**:
```
Task manager
1. add process to task manager
2. display manager
3. display manager sorted by image name
4. display manager sorted by id
5. display manager sorted by session name
6. display manager sorted by session number
7. display manager sorted by memory usage
0. Exit
Enter your choice:
```

**Formatted Process List**:
```
image name                     ID       session name      session#    Memory usage
-----------------------------------------------------------------------------------
chrome.exe                  17540            Console            13           41184 K
notepad.exe                  2468            Console             1            2048 K
```

---

#### **Notes**
- The program truncates image names longer than 24 characters for formatting purposes.
- Memory usage is displayed in kilobytes (`K`).

---

#### **Future Improvements**
- Add error handling for invalid input formats.
- Support more complex CSV parsing for different locales.
- Implement search functionality to find processes by name or ID.

---

#### **License**
This program is open-source and free to use for educational purposes. Contributions are welcome!
