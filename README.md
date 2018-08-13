Move the mouse pointer only by using the keyboard

# Usage

```bash
# To the right
mouse x 100
mouse y 100

# To the left
mouse x -100
mouse y -100
```

# Installation

```c
$ make
# make install
```

# Problems

The program doesn't work with some tiling window managers such as:

* xmonad
* dwm
* openbox
* i3wm

It have been tested and works on:

- [x] KDE
- [x] XFCE
- [x] GNOME2/3

If you discover that it works/doesn't work in your tiling/window manager, please submit a PR to update the list.
