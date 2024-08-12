#include "staticParts.h"
#include <raylib.h>

// These are the non-moving parts.

void drawMotorBodyAndShaft() {
    /*FIRST TOP MOTOR*/
    DrawCylinderEx({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 30.0f}, 8.0f, 8.0f, 40, {60, 60, 60, 255});
    DrawCylinderEx({0.0f, 0.0f, 0.0f + 30.0f}, {0.0f, 0.0f, 0.0f + 37.0f}, 2.5f, 2.5f, 40, {100, 100, 100, 255});
    DrawCylinderEx({0.0f, 0.0f, 0.0f + 37.0f}, {0.0f, 0.0f, 0.0f + 49.0f}, 6.0f, 6.0f, 40, {150, 100, 0, 255});
    /*FIRST BOTTOM MOTOR*/
    DrawCylinderEx({0.0f, -17.0f, 0.0f}, {0.0f, -17.0f, 30.0f}, 8.0f, 8.0f, 40, {60, 60, 60, 255});
    DrawCylinderEx({0.0f, -17.0f, 0.0f + 30.0f}, {0.0f, -17.0f, 0.0f + 37.0f}, 2.5f, 2.5f, 40, {100, 100, 100, 255});
    DrawCylinderEx({0.0f, -17.0f, 0.0f + 37.0f}, {0.0f, -17.0f, 0.0f + 49.0f}, 6.0f, 6.0f, 40, {150, 100, 0, 255});
    /*SECOND TOP MOTOR*/
    DrawCylinderEx({84.5f, 0.0f, 0.0f}, {84.5f, 0.0f, 30.0f}, 8.0f, 8.0f, 40, {60, 60, 60, 255});
    DrawCylinderEx({84.5f, 0.0f, 30.0f}, {84.5f, 0.0f, 37.0f}, 2.5f, 2.5f, 40, {100, 100, 100, 255});
    DrawCylinderEx({84.5f, 0.0f, 37.0f}, {84.5f, 0.0f, 49.0f}, 6.0f, 6.0f, 40, {150, 100, 0, 255});
    /*SECOND BOTTOM MOTOR*/
    DrawCylinderEx({84.5f, -17.0f, 0.0f}, {84.5f, -17.0f, 30.0f}, 8.0f, 8.0f, 40, {60, 60, 60, 255});
    DrawCylinderEx({84.5f, -17.0f, 30.0f}, {84.5f, -17.0f, 37.0f}, 2.5f, 2.5f, 40, {100, 100, 100, 255});
    DrawCylinderEx({84.5f, -17.0f, 37.0f}, {84.5f, -17.0f, 49.0f}, 6.0f, 6.0f, 40, {150, 100, 0, 255});
}

void drawGuidingThingyAfterBlades() {
    /*GUIDING THINGY AFTER BLADES*/
    DrawCylinderEx({59.5f, -8.5f, 43.0f}, {69.5f, -8.5f, 43.0f}, 4.0f, 4.0f, 40, {200, 200, 200, 255});
    DrawCylinderEx({60.5f, -12.8f, 39.0f}, {60.5f, -12.8f, 47.0f}, 1.0f, 1.0f, 40, {200, 200, 200, 255});
    DrawCylinderEx({68.5f, -12.8f, 39.0f}, {68.5f, -12.8f, 47.0f}, 1.0f, 1.0f, 40, {200, 200, 200, 255});
    //Guiding pipe's bolt. Will stay here chilling
    DrawCylinderEx({10.0f, -12.55f, 39.25f}, {10.0f, -12.55f, 46.75f}, 1.0f, 1.0f, 40, {200, 200, 200, 255});
}

void drawGuidingPipePistonBody() {
    /*GUIDING PIPE'S PISTON BODY*/
    DrawCylinderEx({30.0f, -20.25, 43.0f}, {30.0f, -30.25, 43.0f}, 4.0f, 4.0f, 40, {50, 50, 200, 255});
}

void drawCollectionBox() {
    DrawCubeV({120.0f, -23.0f, 45.0f}, {55.0f, 20.0f, 15.0f}, BROWN);
}