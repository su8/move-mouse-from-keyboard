/*
   08/13/2018
 
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
 
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int err_handler(Display *, XErrorEvent *);
int err_handler(Display *dpy, XErrorEvent *evt) {
  (void)dpy;
  (void)evt;
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  int x = 0, y = 0, step = 0;
  unsigned int mask = 0;
  XWindowAttributes xw;
  Window root_window; 
  Display *dpy = NULL;

  if (3 > argc) {
    printf("%s\n", "Not enought arguments");
    return EXIT_FAILURE;
  }

  if (NULL == (dpy = XOpenDisplay(NULL))) {
    return EXIT_FAILURE;
  }

  XSetErrorHandler(err_handler);
  root_window = DefaultRootWindow(dpy);

  XGetWindowAttributes(dpy, root_window, &xw);
  XQueryPointer(dpy, root_window, &root_window, &root_window, &x, &y, &x, &y, &mask);
  /* XSelectInput(dpy, root_window, KeyReleaseMask); */

  step = (int)strtol(argv[2], (char **)NULL, 10);
  if ('x' == argv[1][0]) {
    XWarpPointer(dpy, None, root_window, 0, 0, 0, 0,
      ((x + step) % xw.width) - 1, y);
    printf("%d\n", ((x+step)%xw.width)-1);
  } else {
    XWarpPointer(dpy, None, root_window, x, y, (unsigned int)xw.width,
      (unsigned int)xw.height, x, ((y + step) % xw.height) - 1);
    printf("%d\n", y+step%xw.height-1);
  }

  XFlush(dpy);
  XCloseDisplay(dpy);

  return EXIT_SUCCESS;
}
