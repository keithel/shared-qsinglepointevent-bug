# Simple Qt bug reproducer app - QSinglePointEvent shared data
This is a simple Qt bug reproducer app that tries to show that when constructing
more than one QSinglePointEvent (or derived type) objects on the stack, the
first event created has its position overwritten with the coordinates of the
second event.

Bug exists in Qt 6.n

## Running
cmake -B build -G Ninja . -DCMAKE_PREFIX_PATH=<Qt dir>/lib/cmake
cmake --build build
build/shared-qsinglepointevent-bug
