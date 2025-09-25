from typing import overload

from . import keyboard

class SmortRuntimeError(Exception):
    """Colliqual exception raised for runtime errors in Smort."""
    pass

class SmortImageError(SmortRuntimeError):
    """Exception raised for errors in the Smort image handling."""
    pass

class Vector2:
    x: int
    y: int

class Image:
    width: int
    height: int
    size: Vector2

    def __init__(self, path: str) -> None: ...

    # The blit methods receive an Image instance as the first argument and blit it onto their own.
    # The x and y parameters specify the position to blit the source image onto the destination image.
    # The width and height parameters specify the dimensions to scale the source image to before blitting.
    # If width and height are not provided, the source image is blitted at its original size.
    @overload
    def blit(self, src: Image, x: int = 0, y: int = 0) -> None: ...
    @overload
    def blit(self, src: Image, x: int = 0, y: int = 0, width: int = 0, height: int = 0) -> None: ...

class Window:
    width: int
    height: int
    size: Vector2

    def __init__(self, title: str = "My Nice Little Window", width: int = 600, height: int = 800, handles_updates: bool = True) -> None:
        """Initialize a new window with the given title, dimensions, and update handling flag."""
        ...

    def clear(self) -> None:
        """Clear the window with the current background color"""
        ...
    def tick(self) -> None:
        """Update the window, process events, and display the current frame"""
        ...

    def is_open(self) -> bool: 
        """Check if the window is still open"""
        ...

    @overload
    def fill(self, r: float, g: float, b: float) -> None: ...
    @overload
    def fill(self, r: int, g: int, b: int) -> None: ...

    @overload
    def blit(self, path: str, x: int, y: int) -> None: ...
    @overload
    def blit(self, path: str, x: int, y: int, width: int, height: int) -> None: ...

    @overload
    def blit(self, image: Image, x: int, y: int) -> None: ...
    @overload
    def blit(self, image: Image, x: int, y: int, width: int, height: int) -> None: ...

    def close(self) -> None: ...

def get_size(image: str) -> None: ...
def get_width(image: str) -> None: ...
def get_height(image: str) -> None: ...
