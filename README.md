# C-Polymorphism: VTable & VPTR Implementation

A deep-dive into the low-level mechanics of Object-Oriented Programming. This project implements polymorphism, inheritance, and dynamic dispatch in pure C11, mimicking the exact memory layout and behavior used by C++ compilers (like GCC and Clang).

## 🧠 Technical Architecture

In high-level languages, the "magic" of virtual functions is hidden. This project implements that magic manually:

### 1. Memory Alignment (Inheritance)
By nesting the `Shape` base struct as the first member of derived structs (`Circle`, `Square`), we guarantee that the memory address of a `Circle*` is identical to its `Shape*` component. This allows for safe upcasting.

### 2. The Virtual Table (VTable)
Each "Class" has exactly one static `VTable` containing function pointers. This avoids the overhead of storing function pointers inside every single object instance.

### 3. Dynamic Dispatch (VPTR)

Every object instance carries a `vptr` (virtual pointer). When `call_draw()` is invoked, the program performs a **"Late Binding"** lookup:

1. **Access**: Retrieve the object's `vptr` from the start of the memory block.
2. **Jump**: Navigate to the corresponding `VTable` address.
3. **Execute**: Call the function pointer for the specific implementation (e.g., `circle_draw`).
	
## 🛠 Project Structure
```
.
├── CMakeLists.txt          # Modern CMake build configuration
├── include/                # Public Interfaces
│   ├── shape.h             # Base Class & VTable contract
│   ├── circle.h            # Circle "Class"
│   └── square.h            # Square "Class"
├── src/                    # Implementations
│   ├── main.c              # Polymorphic demo
│   ├── shape.c             # Dispatcher logic & Base methods
│   ├── circle.c            |
│   └── square.c            |
└── README.md
```

## 🚀 Building the Project

This project uses **CMake** for a cross-platform, compiler-independent build process. We follow the *out-of-source* build pattern to keep the repository source tree clean.

### Prerequisites
* **CMake** (3.10 or higher)
* **C Compiler** (GCC, Clang, or MSVC)

### Quick Start Commands
Run these commands from the root of the project directory:

#### 1. Configure
This creates the `build` directory and generates the build system (Makefiles, Ninja, or MSVC solutions).
```bash
cmake -S . -B build
```

#### 2. Build
This compiles the source code into the final executable.
```bash
cmake --build build
```

#### 3. Run
```bash
# Linux / macOS
./build/vptr_demo

# Windows (MSVC)
./build/Debug/vptr_demo.exe
```


