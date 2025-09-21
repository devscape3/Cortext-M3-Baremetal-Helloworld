# Cortex-M3 Bare Metal "Hello World" in Renode

This project demonstrates how to build and run a minimal **bare-metal Cortex-M3 program** that prints `"Hello, World!"` over UART using [Renode](https://renode.io/).

---

## Prerequisites

1. **ARM GCC Toolchain**

   Download and install the ARM GNU toolchain (Windows):

   👉 [ARM GNU Toolchain 14.3 (Windows, 32-bit host, arm-none-eabi target)](https://developer.arm.com/-/media/Files/downloads/gnu/14.3.rel1/binrel/arm-gnu-toolchain-14.3.rel1-mingw-w64-i686-arm-none-eabi.exe)

   During installation, **select "Add to PATH"**.

   - Default install location:  
     ```
     C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\14.3 rel1
     ```
   - The compiler will be available in the `bin` folder:  
     ```
     C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\14.3 rel1\bin\arm-none-eabi-gcc.exe
     ```

   ⚠️ If you forgot to select "Add to PATH", add the following manually to your system PATH:
   ```
   C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\14.3 rel1\bin
   ```
   
2. **Renode Simulator**

Download and install [Renode](https://renode.io/).

---

## Building the Project

Open **Command Prompt** in the project folder and run:

```bat
build.bat
```
This will compile your source code and produce an ELF binary (hello.elf).

## Running in Renode

1. Launch Renode.

2. In the Renode monitor window, run the following commands (adjust the paths as needed):

```
mach create
machine LoadPlatformDescription @cortex-m3.repl
sysbus LoadELF @hello.elf
showAnalyzer sysbus.uart0
start
```

- cortex-m3.repl is the Renode platform description file.

- hello.elf is your compiled program.

