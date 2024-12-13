#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "mzl.h"

// Assertion function for runtime checks
MzlRet MzlAssert(bool statement, const char *comment) {
    if (statement) return MzlOk;
    printf("Assertion failed: %s\n", comment);
    return MzlErr;
}

// Predefined colors
const MzlColor MzlColors[] = {
    {{1.0f, 0.0f, 0.0f, 1.0f}}, // Red
    {{0.0f, 1.0f, 0.0f, 1.0f}}, // Green
    {{0.0f, 0.0f, 1.0f, 1.0f}}, // Blue
    {{1.0f, 1.0f, 0.0f, 1.0f}}, // Yellow
    {{0.0f, 1.0f, 1.0f, 1.0f}}, // Cyan
    {{1.0f, 0.0f, 1.0f, 1.0f}}, // Magenta
    {{0.0f, 0.0f, 0.0f, 1.0f}}, // Black
    {{1.0f, 1.0f, 1.0f, 1.0f}}  // White
};

// Initialize a GLFW window and OpenGL context
MZL* MzlInitWindow(int width, int height, const char* title) {
    MzlAssert(width > 0 && height > 0, "Mzl ERROR: Invalid window dimensions");
    MzlAssert(title != NULL, "Mzl ERROR: Title cannot be NULL");

    if (!glfwInit()) {
        printf("Mzl ERROR: Can't initialize GLFW\n");
        return NULL;
    }

    MZL* MzlWin = malloc(sizeof(MZL));
    if (!MzlWin) {
        printf("Mzl ERROR: Memory allocation failed\n");
        glfwTerminate();
        return NULL;
    }

    MzlWin->window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!MzlWin->window) {
        printf("Mzl ERROR: Failed to create GLFW window\n");
        free(MzlWin);
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(MzlWin->window);

    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK) {
        printf("Mzl ERROR: Failed to initialize GLEW: %s\n", glewGetErrorString(glewStatus));
        glfwDestroyWindow(MzlWin->window);
        free(MzlWin);
        glfwTerminate();
        return NULL;
    }

    return MzlWin;
}

// Check if the window should close
MzlRet MzlWindowShouldClose(MZL* Mzl) {
    if (!Mzl || !Mzl->window) {
        printf("Mzl ERROR: Invalid Mzl or window pointer\n");
        return MzlErr;
    }

    glfwWindowShouldClose(Mzl->window);

    return MzlOk;
}

// Set the OpenGL drawing color
MzlRet setColor(const float color[4]) {
    if (!color) {
        printf("Mzl ERROR: Color pointer cannot be NULL\n");
        return MzlErr;
    }

    for (int i = 0; i < 4; i++) {
        if (color[i] < 0.0f || color[i] > 1.0f) {
            printf("Mzl ERROR: Color component %d out of range [0.0, 1.0]\n", i);
            return MzlErr;
        }
    }

    glColor4fv(color);
    return MzlOk;
}

// Cleanup and free resources
MzlRet MzlCleanup(MZL *mzl) {
    if (!mzl || !mzl->window) {
        printf("Mzl ERROR: Invalid Mzl or window pointer\n");
        return MzlErr;
    }

    glfwDestroyWindow(mzl->window);
    glfwTerminate();
    free(mzl);

    return MzlOk;
}
