# OpenCV-Cpp
Using opencv in C++

## I'm using Visual Studio Code as my IDE
go through the [article](https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/) to download and setup opencv

### There are two ways we can work with opencv c++ in vscode
__first and simple method__

```
sudo apt install libopencv-dev
```

```
pkg-config --modversion opencv4
```
now if you get a version correctly then all set

now you can add the below code to your .vscode/c_cpp_properties.json
```
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include/opencv4/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c17",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```
to run, type the below code on terminal
```
g++ -Wall <file_name.cpp> -o <output_name> `pkg-config --cflags --libs opencv4`
```
__second method__
install the below extensions
```
twxs.cmake
```
```
ms-vscode.cmake-tools
```
* **make sure you have the CMakeLists.txt file**

<img src="https://raw.githubusercontent.com/rohit-krish/OpenCV-Cpp/main/command%20palette%20screen%20shot.png" alt="screenshot of my vscode command pallette">

* and to build go for the option <b>CMake: Build</b><br>
* and the executable will be stored on the build folder, you can run it just like you run any other c++ program, or you can use <b>CMake: Run Without Debugging<b> option that you will get in the command pallete after installing the extensions.
