#include <stdio.h>
#include "mzl.h"

int main() {
    MZL* window = MzlInitWindow(1000, 800, "Hi");
    while (!MzlWindowShouldClose(window)) {
    }
}