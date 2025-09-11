# Smort - the braincell-efficient library!
### My Python multimedia library written in C++

**Smort** is a simple, easy, and fast multimedia library written in C++ and designed to be an easy introduction to graphical interfaces in Python.

## Features

- Simple API for creating windows and handling graphics
- Keyboard and mouse utilities
- Error handling for robust applications
- Python bindings via pybind11

## Installation

You can install Smort from source:

```bash
git clone https://github.com/amosbarsinai/smort.git
cd smort
./build.py
```

## Usage Example

```python
import smort

window = smort.Window(width=800, height=600, title="Hello Smort!")
while window.is_open():
    window.clear()
    window.blit("some_image.jpg", 0, 0)
    window.display()
```

## Contributing

Contributions are welcome! Please open issues or pull requests on GitHub.

## NOTE:
Smort is still under heavy development. It is not yet recommended for personal use. Any contributions to the project will be greatly appreciated. Pull requests can be opened on [GitHub](https://github.com/AmosBarSinai/smort/pulls).


### Licensing:
The license can be viewed [here](LICENSE.md).
