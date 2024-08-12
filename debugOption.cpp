#include "raylib.h"

void drawOutlines() {
    DrawLine3D({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 49.0f}, RED);
    DrawCubeWiresV({0.0f, 0.0f, 0.0f + 15.0f}, {16.0f, 16.0f, 30.0f}, BLACK);
    DrawCubeWiresV({0.0f, 0.0f, 0.0f + 33.5f}, {5.0f, 5.0f, 7.0f}, BLACK);
    DrawCubeWiresV({0.0f, 0.0f, 0.0f + 43.0f}, {12.0f, 12.0f, 12.0f}, BLACK);
    DrawCubeWiresV({44.0f, -8.5f, 43.0f}, {100.0f, 5.0f, 5.0f}, BLACK);
    DrawCubeWiresV({28.0f, -8.5f, 43.0f}, {40.0f, 7.5f, 7.5f}, BLACK);
    DrawCubeWiresV({64.5f, -8.5f, 43.0f}, {10.0f, 8.0f, 8.0f}, BLACK);
    DrawCubeWiresV({60.5f, -12.8f, 43.0f}, {2.0f, 2.0f, 8.0f}, BLACK);
    DrawCubeWiresV({68.5f, -12.8f, 43.0f}, {2.0f, 2.0f, 8.0f}, BLACK);
    DrawCubeWiresV({10.0f, -12.55f, 43.0f}, {2.0f, 2.0f, 7.5f}, BLACK);
    DrawCubeWiresV({30.0f, -13.75f, 43.0f}, {3.0f, 3.0f, 3.0f}, BLACK);
    DrawCubeWiresV({30.0f, -17.75, 43.0f}, {2.0f, 5.0f, 2.0f}, BLACK);
    DrawCubeWiresV({30.0f, -25.25, 43.0f}, {8.0f, 10.0f, 8.0f}, BLACK);
    DrawCubeWiresV({53.0f, 0.25f, 43.0f}, {3.0f, 10.0f, 10.0f}, BLACK);
    DrawCubeWiresV({56.0f, -17.25f, 43.0f}, {3.0f, 10.0f, 10.0f}, BLACK);
    DrawCubeWiresV({52.0f, 0.25f, 32.0f}, {5.0f, 10.0f, 12.0f}, BLACK);
    DrawCubeWiresV({57.0f, -17.25f, 35.0f}, {5.0f, 10.0f, 6.0f}, BLACK);
    DrawCubeWiresV({47.25f, 0.25f, 23.5f}, {14.5f, 10.0f, 5.0f}, RED);
    DrawCubeWiresV({61.75f, -17.25f, 29.5f}, {14.5f, 10.0f, 5.0f}, BLUE);
    DrawCubeWiresV({54.5f, -8.5f, 15.5f}, {10.7f, 10.7f, 5.0f}, BLACK);
    DrawCubeWiresV({54.5f, -8.5f, 10.5f}, {3.5f, 3.5f, 5.0f}, BLACK);
    DrawCubeWiresV({54.5f, -8.5f, 0.5f}, {10.0f, 10.0f, 15.0f}, BLACK);
    DrawCubeWiresV({43.5f, -8.5f, 15.5f}, {7.0f, 80.0f, 11.0f}, BLACK);
    DrawCubeWiresV({65.5f, -8.5f, 15.5f}, {7.0f, 80.0f, 11.0f}, BLACK);
    DrawLine3D({0.0f, -17.0f, 0.0f}, {0.0f, -17.0f, 49.0f}, RED);
    DrawCubeWiresV({0.0f, -17.0f, 15.0f}, {16.0f, 16.0f, 30.0f}, BLACK);
    DrawCubeWiresV({0.0f, -17.0f, 33.5f}, {5.0f, 5.0f, 7.0f}, BLACK);
    DrawCubeWiresV({0.0f, -17.0f, 43.0f}, {12.0f, 12.0f, 12.0f}, BLACK);
    DrawLine3D({84.5f, 0.0f, 0.0f}, {84.5f, 0.0f, 49.0f}, RED);
    DrawCubeWiresV({84.5f, 0.0f, 15.0f}, {16.0f, 16.0f, 30.0f}, BLACK);
    DrawCubeWiresV({84.5f, 0.0f, 33.5f}, {5.0f, 5.0f, 7.0f}, BLACK);
    DrawCubeWiresV({84.5f, 0.0f, 43.0f}, {12.0f, 12.0f, 12.0f}, BLACK);
    DrawLine3D({84.5f, -19.0f, 0.0f}, {84.5f, -19.0f, 49.0f}, RED);
    DrawCubeWiresV({84.5f, -19.0f, 15.0f}, {16.0f, 16.0f, 30.0f}, BLACK);
    DrawCubeWiresV({84.5f, -19.0f, 33.5f}, {5.0f, 5.0f, 7.0f}, BLACK);
    DrawCubeWiresV({84.5f, -19.0f, 43.0f}, {12.0f, 12.0f, 12.0f}, BLACK);


    Vector3 positions[] = {
        {0.0f, 0.0f, 15.0f},
        {0.0f, 0.0f, 33.5f},
        {0.0f, 0.0f, 43.0f},
        {44.0f, -8.5f, 43.0f},
        {28.0f, -8.5f, 43.0f},
        {64.5f, -8.5f, 43.0f},
        {60.5f, -13.5f, 43.0f},
        {68.5f, -13.5f, 43.0f},
        {10.0f, -13.25f, 43.0f},
        {30.0f, -13.75f, 43.0f},
        {30.0f, -17.75f, 43.0f},
        {30.0f, -25.25f, 43.0f},
        {53.0f, 0.25f, 43.0f},
        {56.0f, -17.25f, 43.0f},
        {52.0f, 0.25f, 32.0f},
        {57.0f, -17.25f, 38.0f},
        {47.25f, 0.25f, 23.5f},
        {61.75f, -17.25f, 29.5f},
        {54.5f, -8.5f, 15.5f},
        {54.5f, -8.5f, 10.5f},
        {54.5f, -8.5f, 0.5f},
        {43.5f, -8.5f, 15.5f},
        {65.5f, -8.5f, 15.5f},
        {0.0f, -17.0f, 15.0f},
        {0.0f, -17.0f, 33.5f},
        {0.0f, -17.0f, 43.0f},
        {84.5f, 0.0f, 15.0f},
        {84.5f, 0.0f, 33.5f},
        {84.5f, 0.0f, 43.0f},
        {84.5f, -19.0f, 15.0f},
        {84.5f, -19.0f, 33.5f},
        {84.5f, -19.0f, 43.0f}
    };

    for (int i = 0; i < sizeof(positions) / sizeof(positions[0]); i++) {
        DrawSphere(positions[i], 0.2f, BLACK);
    }

}