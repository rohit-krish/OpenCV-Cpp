# OpenCV C++
Using opencv in C++

```
sudo apt install g++ cmake make git libgtk2.0-dev pkg-config
```

## Method 01

```
git clone https://github.com/opencv/opencv.git
mkdir -p build && cd build
cmake -D CMAKE_BUILD_TYPE=Release -D OPENCV_GENERATE_PKGCONFIG=YES -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j4
sudo make install
```

### test
```
pkg-config --cflags --libs opencv4
pkg-config --modversion opencv4
```
to run, type the below code on terminal
```
g++ -Wall <file_name.cpp> -o <output_name> `pkg-config --cflags --libs opencv4`
```

for vscode users if you want linting then you have to add the below code to your .vscode/c_cpp_properties.json
```
{
    "configurations": [
        {
            "name": "OpenCV C++",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include/opencv4/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```


## Method 02

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
* you can run it just like you run any other c++ program, or you can use <b>CMake: Run Without Debugging</b> option that you will get in the command pallete after installing the extensions (the executable will be stored on the build folder).
