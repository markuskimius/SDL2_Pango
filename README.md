# SDL2_Pango

SDL2_Pango is a library for graphically rendering internationalized and tagged
text in SDL2 using TrueType fonts.

SDL2_Pango is a port of [SDL_Pango] to SDL2.  SDL_Pango was originally written
by NAKAMURA Ken'ichi.  It has been ported to SDL2 by Pere Pujal i Carabantes.
Additional contributions have been made by many authors (see [AUTHORS]).


## Example

<img src='https://github.com/markuskimius/SDL2_Pango/blob/master/test/screenshot.png' />

* [Source text]
* [Source code]


## Build & Installation

### Prerequisites

SDL2_Pango requires [Pango], [FreeType2], and [SDL2].

### Unix, Linux

On most Unix-based platforms including Linux, build and install using the
following command:

```bash
$ ./configure && make && sudo make install
```

### Windows

On Windows, SDL2_Pango can be built and installed in [MinGW]/[MSYS2] as though
it were a Unix platform.  Visual C++ 2003 and WiX files are also provided, but
they are legacy files from SDL_Pango and have not been updated for SDL2. 

### macOS

On macOS, SDL2_Pango can be built and installed using [MacPorts] as though it
were a Unix platform.  Be sure to install them into the same directory as the
rest of MacPorts files (typically `/opt/local`):

```bash
$ ./configure --prefix=/opt/local && make && sudo make install
```

SDL2_Pango should also build fine using [Homebrew] and [Fink] but they have not
been tested.

### Android

On Android, build using [Android.mk].


## Usage

See the [documentation] from SDL_Pango which has the same API as SDL2_Pango.


## License

Licensed under LGPL 2.1.  See [COPYING] for more information.


[SDL_Pango]: http://sdlpango.sourceforge.net/
[Source text]: https://github.com/markuskimius/SDL2_Pango/blob/master/test/markup.txt
[Source code]: https://github.com/markuskimius/SDL2_Pango/blob/master/test/testbench.c
[Pango]: https://pango.gnome.org/
[SDL2]: https://www.libsdl.org/
[FreeType2]: https://freetype.org/
[Android.mk]: https://github.com/markuskimius/SDL2_Pango/blob/master/Android.mk
[MinGW]: https://www.mingw-w64.org/
[MSYS2]: https://www.msys2.org/
[MacPorts]: https://www.macports.org/
[Homebrew]: https://brew.sh/
[Fink]: https://www.finkproject.org/
[documentation]: https://htmlpreview.github.io/?https://github.com/markuskimius/SDL2_Pango/blob/master/docs/html/index.html
[AUTHORS]: https://github.com/markuskimius/SDL2_Pango/blob/master/AUTHORS
[COPYING]: https://github.com/markuskimius/SDL2_Pango/blob/master/COPYING
