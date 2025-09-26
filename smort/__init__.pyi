from typing import overload

from . import keyboard

class SmortRuntimeError(Exception):
    """Colliqual exception raised for runtime errors in Smort."""
    pass

class SmortImageError(SmortRuntimeError):
    """Exception raised for errors in the Smort image handling."""
    pass

class Vector2:
    """A simple two-dimensional vector class."""

    x: int
    y: int

class Image:
    """The basic image class.
    Images can be loaded from files and manipulated in memory."""

    width: int
    height: int
    size: Vector2

    def __init__(self, path: str) -> None:
        """Load an image from the specified file path."""
        ...

    # The blit methods receive an Image instance as the first argument and blit it onto their own.
    # The x and y parameters specify the position to blit the source image onto the destination image.
    # The width and height parameters specify the dimensions to scale the source image to before blitting.
    # If width and height are not provided, the source image is blitted at its original size.
    @overload
    def blit(self, src: Image, x: int = 0, y: int = 0) -> None:
        """Blit the source image onto this image at position (x, y) while keeping the source image's original size."""
        ...
    @overload
    def blit(self, src: Image, x: int = 0, y: int = 0, width: int = 0, height: int = 0) -> None:
        """Blit the source image onto this image at position (x, y) while scaling the source image to (width, height)."""
        ...

class Window:
    """The main window class.
    A Window instance represents a window on the screen where graphics can be drawn and events can be processed."""
    width: int
    height: int
    size: Vector2

    def __init__(self, title: str = "My Nice Little Window", width: int = 600, height: int = 800, handles_updates: bool = True) -> None:
        """Initialize a new window with the given title, dimensions, and update handling flag."""
        ...

    def clear(self) -> None:
        """Clear the window with the current background color."""
        ...
    def tick(self) -> None:
        """Update the window, process events, and display the current frame."""
        ...

    def is_open(self) -> bool: 
        """Check if the window is still open."""
        ...

    @overload
    def fill(self, r: float, g: float, b: float) -> None:
        """Fill the window with the specified RGB color values (0.0 to 1.0)."""
        ...
    @overload
    def fill(self, r: int, g: int, b: int) -> None:
        """Fill the window with the specified RGB color values (0 to 255)."""
        ...

    @overload
    def blit(self, path: str, x: int, y: int) -> None:
        """Blit an image from the specified file path onto the window at position (x, y)."""
        ...
    @overload
    def blit(self, path: str, x: int, y: int, width: int, height: int) -> None:
        """Blit an image from the specified file path onto the window at position (x, y) while scaling it to (width, height)."""
        ...

    @overload
    def blit(self, image: Image, x: int, y: int) -> None:
        """Blit the specified image onto the window at position (x, y)."""
    @overload
    def blit(self, image: Image, x: int, y: int, width: int, height: int) -> None:
        """Blit the specified image onto the window at position (x, y) while scaling it to (width, height)."""
        ...

    def close(self) -> None:
        """Destroy the window and free associated resources."""
        ...
