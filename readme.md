# vkDemos

This repository contains various samples I have developed in order to learn the Vulkan API. Most of them are based on [Vulkan Tutorial](https://vulkan-tutorial.com/), but that may change as I develop my own way of doing things.

## Current structure (work in progress)

`/vkd` contains a growing collection of abstractions that help make the examples less verbose.

`/include` and `/third-party` contain other libraries. `/third-party` uses submodules, so remember to clone recursively!

All other directories likely contain a demo.

## Cloning
```
git clone --recursive https://github.com/calokat/vk-demos.git
```

If you already cloned, you can bring in the submodules with:

```
git submodule init
git submodule update
```

## Building

- Make sure you have the Volkan SDK for your platform.
- GLFW is included as a submodule in this package. However, for Linux systems it is recommended to install `glfw-devel` or equivalent since that will also install all of the X11 headers that GLFW needs.

```
    mkdir build
    cd build
    cmake ..
```

Development mostly takes place on Fedora. If building doesn't work on a platform you are running on, please consider creating an issue!