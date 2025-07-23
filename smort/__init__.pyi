from typing import overload

from . import keyboard

class Window:
    width: int
    height: int
    
    @overload
    def __init__(self, title: str, width: int, height: int) -> None: ...
    @overload
    def __init__(self, title: str, width: int, height: int, handles_updates: bool) -> None: ...

    def clear(self) -> None: ...    # Clear the window with the current background color
    def tick(self) -> None: ...     # Update the window, process events, and display the current frame
    def is_open(self) -> bool: ...  # Check if the window is still open

    @overload
    def fill(self, r: float, g: float, b: float) -> None: ...
    @overload
    def fill(self, r: int, g: int, b: int) -> None: ...

    @overload
    def blit(self, path: str, x: int, y: int) -> None: ...
    @overload
    def blit(self, path: str, x: int, y: int, width: int, height: int) -> None: ...

    def close() -> None: ...

    def smort() -> None: ...       # smort

def get_size(image: str) -> None: ...
def get_width(image: str) -> None: ...
def get_height(image: str) -> None: ...