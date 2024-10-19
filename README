## Building

### Prerequisites

- SFML
- MSVC 2019 Build Tools\*

\* Note: this is just what I used, you can use your own alternative, though the build commands will be different.

### MSVC 2019 Build Tools

This command will compile x64 version for Windows.

```sh
cl /EHsc /favor:INTEL64 /I".\include" /I"D:\code\lib\SFML-2.6.1\include" .\src\Raytracing.cpp .\src\Obstacle.cpp /link /LIBPATH:"D:\code\lib\SFML-2.6.1\lib" sfml-audio.lib sfml-graphics.lib sfml-main.lib sfml-network.lib sfml-system.lib sfml-window.lib
```

After compiling, ensure the DLLs for SFML are in included in your `PATH` when you run the compiled executable.
