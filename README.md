# SDL2_Pango

This is a port of SDL_Pango to SDL2, based on the [initial port] for
[Tux Paint] by Pere Pujal i Carabantes. It's been updated to newer
versions of autoconf, automake, and libtools, and the generated
files have been included in the repo so the package is ready to
be built.

## Installation

For most Unix-based operationg systems, it is:

```bash
$ ./configure && make && sudo make install
```

For Android, use [Android.mk].

For other operating systems, see [INSTALL] from the original distribution.


[initial port]: https://sourceforge.net/projects/tuxpaint-sdl2/files/SDL2_Pango/SDL2_Pango-0.1.2.tar.gz
[Android.mk]: https://github.com/markuskimius/SDL2_Pango/blob/master/Android.mk
[INSTALL]: https://github.com/markuskimius/SDL2_Pango/blob/master/INSTALL
[Tux Paint]: http://tuxpaint.org/
