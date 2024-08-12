#include "raylib.h"
#include "initCamera.h"
// Camera initialization with raylib.
Camera initCamera() {
    Camera camera;
    camera.fovy = 90;
    camera.position = (Vector3) {45.0f, 0.0f, 100.0f};
    camera.projection = CAMERA_PERSPECTIVE;
    camera.target = (Vector3) {45.5f, 0.25f, 43.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    return camera;
}