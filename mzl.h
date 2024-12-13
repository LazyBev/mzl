#ifndef MZL_H
#define MZL_H

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

// Mzl enum for status codes
typedef enum {
    MzlOk = 0,        // Success
    MzlErr = -1,      // General error
    MzlWinErr = -2,   // Window-related error
    MzlGLErr = -3     // OpenGL initialization error
} MzlRet;

// Define the MZL struct to hold OpenGL resources
typedef struct {
    GLFWwindow *window; // GLFW window pointer
} MZL;

// Define a struct to store RGBA color values
typedef struct {
    float rgba[4]; // RGBA components (0.0 to 1.0)
} MzlColor;

// Predefined colors (defined in the implementation file)
extern const MzlColor MzlColors[];

// Function to initialize a GLFW window and OpenGL context
/**
 * Initializes a GLFW window with the specified dimensions and title.
 *
 * @param width The width of the window in pixels (must be > 0).
 * @param height The height of the window in pixels (must be > 0).
 * @param title The title of the window (cannot be NULL).
 * @return A pointer to an initialized MZL structure, or NULL on failure.
 */
MZL* MzlInitWindow(int width, int height, const char *title);

// Function to check if the window should close
/**
 * Checks if the specified MZL window should close.
 *
 * @param MzlWin Pointer to the MZL structure.
 * @return MzlOk if the window should close, or an error code otherwise.
 */
MzlRet MzlWindowShouldClose(MZL* MzlWin);

// Function to set the OpenGL drawing color
/**
 * Sets the OpenGL drawing color using the specified RGBA values.
 *
 * @param color A pointer to an array of 4 floats representing the RGBA color.
 * @return MzlOk on success, or an error code if the input is invalid.
 */
MzlRet setColor(const float color[4]);

// Assertion function to validate a statement
/**
 * Asserts that the specified statement is true.
 *
 * @param statement The statement to validate.
 * @param comment A message to display if the assertion fails.
 * @return MzlOk if the assertion passes, or an error code otherwise.
 */
MzlRet MzlAssert(bool statement, const char *comment);

// Function to clean up and free resources
/**
 * Cleans up and releases resources associated with the specified MZL window.
 *
 * @param mzl Pointer to the MZL structure to clean up.
 * @return MzlOk on success, or an error code otherwise.
 */
MzlRet MzlCleanup(MZL *mzl);

#endif // MZL_H
