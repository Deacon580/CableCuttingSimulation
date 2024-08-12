#include "movingParts.h"
#include <raylib.h>
#include <rlgl.h>
#include "operationControl.h"

//These are the moving parts of the simulation, this is where the animation is.

void drawMotorCogOutline() {
    /*FIRST TOP MOTOR*/
    rlPushMatrix();
    rlTranslatef(0.0f, 0.0f, 0.0f + 37.0f);
    rlRotatef(motorRotation[0], 0.0f, 0.0f, 1.0f);
    DrawCylinderWiresEx({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f + 12.0f}, 6.0f, 6.0f, 40, {0, 0, 0, 255});
    rlPopMatrix();
    /*FIRST BOTTOM MOTOR*/
    rlPushMatrix();
    rlTranslatef(0.0f, -17.0f, 0.0f + 37.0f);
    rlRotatef(-motorRotation[0], 0.0f, 0.0f, 1.0f);
    DrawCylinderWiresEx({0.0f, 0.0f, 0.0f + 0.0f}, {0.0f, 0.0f, 0.0f + 12.0f}, 6.0f, 6.0f, 40, {0, 0, 0, 255});
    rlPopMatrix();
    /*SECOND TOP MOTOR*/
    rlPushMatrix();
    rlTranslatef(84.5f, 0.0f, 37.0f);
    rlRotatef(motorRotation[1], 0.0f, 0.0f, 1.0f);
    DrawCylinderWiresEx({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 12.0f}, 6.0f, 6.0f, 40, {0, 0, 0, 255});
    rlPopMatrix();
    /*SECOND BOTTOM MOTOR*/
    rlPushMatrix();
    rlTranslatef(84.5f, -17.0f, 37.0f);
    rlRotatef(-motorRotation[1], 0.0f, 0.0f, 1.0f);
    DrawCylinderWiresEx({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 12.0f}, 6.0f, 6.0f, 40, {0, 0, 0, 255});
    rlPopMatrix();
}

void drawCable() {
    /*CABLE*/
    //This part is static, never moves.
    if(cable1.draw)
        DrawCylinderEx(cable1.startPos, cable1.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});

    rlPushMatrix();
    rlTranslatef(8.0f, -8.5f, 43.0f);
    rlRotatef(guidingPipeAngle, 0.0f, 0.0f, 1.0f);
    if(cable2.draw)
        DrawCylinderEx(cable2.startPos, cable2.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});
    rlPopMatrix();

    //Product cable.
    //Outer Insulations
        //middle
    if(cable3.draw)
        DrawCylinderEx(cable3.startPos, cable3.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});
        //left
    if(cable4.draw)
        DrawCylinderEx(cable4.startPos, cable4.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});
        //right
    if(cable5.draw)
        DrawCylinderEx(cable5.startPos, cable5.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});

    //Inner Insulations
        //middle
    if(cable6.draw)
        DrawCylinderEx(cable6.startPos, cable6.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
    if(cable7.draw)
        DrawCylinderEx(cable7.startPos, cable7.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
        //left
    if(cable8.draw)
        DrawCylinderEx(cable8.startPos, cable8.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
    if(cable9.draw)
        DrawCylinderEx(cable9.startPos, cable9.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
        //right
    if(cable10.draw)
        DrawCylinderEx(cable10.startPos, cable10.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
    if(cable11.draw)
        DrawCylinderEx(cable11.startPos, cable11.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});

    //The inner copper cable
    if(cable12.draw)
        DrawCylinderEx(cable12.startPos, cable12.endPos, 0.2f, 0.2f, 40, {184, 115, 51, 255});
    if(cable13.draw)
        DrawCylinderEx(cable13.startPos, cable13.endPos, 0.2f, 0.2f, 40, {184, 115, 51, 255});

    //The calibration cable.
    if(cable14.draw)
        DrawCylinderEx(cable14.startPos, cable14.endPos, 2.5f, 2.5f, 40, {255, 0, 0, 255});
    if(cable15.draw)
        DrawCylinderEx(cable15.startPos, cable15.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
    if(cable16.draw)
        DrawCylinderEx(cable16.startPos, cable16.endPos, 0.2f, 0.2f, 40, {184, 115, 51, 255});
    if(cable17.draw)
        DrawCylinderEx(cable17.startPos, cable17.endPos, 0.6f, 0.6f, 40, {0, 0, 255, 255});
    if(cable18.draw)
        DrawCylinderEx(cable18.startPos, cable18.endPos, 0.2f, 0.2f, 40, {184, 115, 51, 255});
}

void drawGuidingPipe() {
    /*GUIDING PIPE*/
    rlPushMatrix();
    rlTranslatef(8.0f, -8.5f, 43.0f);
    rlRotatef(guidingPipeAngle, 0.0f, 0.0f, 1.0f);
    DrawCylinderEx({0.0f, 0.0f, 0.0f}, {40.0f, 0.0f, 0.0f}, 3.75f, 3.75f, 40, {200, 200, 200, 255});
    rlPopMatrix();
}

void drawGuidingPipePistonHeadAndShaft() {
    /*GUIDIN PIPE'S PISTON HEAD AND SHAFT*/
    DrawCylinderEx({30.0f, -13.0f+ pistonHeadOffset, 43.0f}, {30.0f, -15.25f+ pistonHeadOffset, 43.0f}, 1.5f, 1.5f, 40, {255, 165, 0, 255});
    DrawSphereEx({30.0f, -13.75f + pistonHeadOffset, 43.0f}, 1.5f, 20, 20, {255, 165, 0, 255});
    DrawCylinderEx({30.0f, -15.25f+ pistonHeadOffset , 43.0f}, {30.0f, -20.25f, 43.0f}, 1.0f, 1.0f, 40, {100, 100, 100, 255});
}

void drawTopBlade() {
    /*TOP BLADE*/
    DrawCubeV({53.0f, 2.75f - bladeOffset, 43.0f}, {3.0f, 5.0f, 10.0f}, GRAY);
    DrawTriangle3D({54.5f, 0.25f - bladeOffset, 48.0f}, {54.5f, -4.75f - bladeOffset, 48.0f}, {54.5f, 0.25f - bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({54.5f, -4.75f - bladeOffset, 48.0f}, {54.5f, -4.75f - bladeOffset, 38.0f}, {54.5f, 0.25f - bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({54.5f, 0.25f - bladeOffset, 48.0f}, {51.5f, 0.25f - bladeOffset, 48.0f}, {54.5f, -4.75f - bladeOffset, 48.0f}, GRAY);
    DrawTriangle3D({54.5f, 0.25f - bladeOffset, 38.0f}, {54.5f, -4.75f - bladeOffset, 38.0f}, {51.5f, 0.25f - bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({51.5f, 0.25f - bladeOffset, 48.0f}, {51.5f, 0.25f - bladeOffset, 38.0f},{54.5f, -4.75f - bladeOffset, 48.0f}, GRAY);
    DrawTriangle3D({54.5f, -4.75f - bladeOffset, 48.0f}, {51.5f, 0.25f - bladeOffset, 38.0f},{54.5f, -4.75f - bladeOffset, 38.0f}, GRAY);
}

void drawBottomBlade() {
    /*BOTTOM BLADE*/
    DrawCubeV({56.0f, -19.75f + bladeOffset, 43.0f}, {3.0f, 5.0f, 10.0f}, GRAY);
    DrawTriangle3D({54.5f, -17.25f + bladeOffset, 48.0f}, {54.5f, -12.25f + bladeOffset, 38.0f}, {54.5f, -17.25f + bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({54.5f, -17.25f + bladeOffset, 48.0f}, {54.5f, -12.25f + bladeOffset, 48.0f}, {54.5f, -12.25f + bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({57.5f, -17.25f + bladeOffset, 48.0f},{57.5f, -17.25f + bladeOffset, 38.0f},{54.5f, -12.25f + bladeOffset, 38.0f}, GRAY);
    DrawTriangle3D({57.5f, -17.25f + bladeOffset, 48.0f},{54.5f, -12.25f + bladeOffset, 38.0f},{54.5f, -12.25f + bladeOffset, 48.0f}, GRAY);
    DrawTriangle3D({54.5f, -17.25f + bladeOffset, 48.0f}, {57.5f, -17.25f + bladeOffset, 48.0f}, {54.5f, -12.25f + bladeOffset, 48.0f}, GRAY);
    DrawTriangle3D({54.5f, -17.25f + bladeOffset, 38.0f}, {54.5f, -12.25f + bladeOffset, 38.0f}, {57.5f, -17.25f + bladeOffset, 38.0f}, GRAY);
}

void drawMetalBladeHoldOn() {
    /*METALS BLADES HOLD ONTO*/
    DrawCubeV({52.0f, 0.25f - bladeOffset, 32.0f}, {5.0f, 10.0f, 12.0f}, {80, 80, 80, 255});
    DrawCubeV({57.0f, -17.25f + bladeOffset, 35.0f}, {5.0f, 10.0f, 6.0f}, {80, 80, 80, 255});
    DrawCubeV({47.25f, 0.25f - bladeOffset, 23.5f}, {14.5f, 10.0f, 5.0f}, {80, 80, 80, 255});
    DrawCubeV({61.75f, -17.25f + bladeOffset, 29.5f}, {14.5f, 10.0f, 5.0f}, {80, 80, 80, 255});
    DrawCubeV({66.5f, -17.25f + bladeOffset, 24.0f}, {5.0f, 10.0f, 7.0f}, {80, 80, 80, 255});
}

void drawGear() {
    /*GEAR*/
    rlPushMatrix();
    rlTranslatef(54.5f, -8.5f, 15.5f);
    rlRotatef(0.0f + gearAngle, 0.0f, 0.0f, 1.0f);
    DrawCubeV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, {100, 100, 0, 255});
    rlPopMatrix();

    rlPushMatrix();
    rlTranslatef(54.5f, -8.5f, 15.5f);
    rlRotatef(22.5f + gearAngle, 0.0f, 0.0f, 1.0f);
    //DrawCubeWiresV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, BLACK);
    DrawCubeV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, {100, 100, 0, 255});
    rlPopMatrix();

    rlPushMatrix();
    rlTranslatef(54.5f, -8.5f, 15.5f);
    rlRotatef(45.0f + gearAngle, 0.0f, 0.0f, 1.0f);
    //DrawCubeWiresV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, BLACK);
    DrawCubeV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, {100, 100, 0, 255});
    rlPopMatrix();

    rlPushMatrix();
    rlTranslatef(54.5f, -8.5f, 15.5f);
    rlRotatef(67.5f + gearAngle, 0.0f, 0.0f, 1.0f);
    //DrawCubeWiresV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, BLACK);
    DrawCubeV({0.0f, 0.0f, 0.0f}, {10.7f, 10.7f, 5.0f}, {100, 100, 0, 255});
    rlPopMatrix();
}

void drawStepMotor() {
    /*STEP MOTOR*/
    DrawCylinderEx({54.5f, -8.5f, 8.0f}, {54.5f, -8.5f, 13.0f}, 1.75f, 1.75f, 20, {80, 80, 80, 255});
    DrawCylinderEx({54.5f, -8.5f, -7.0f}, {54.5f, -8.5f, 8.0f}, 5.0f, 5.0f, 40, {80, 80, 80, 255});
}

void drawRails() {
    /*METALS CONNECT THE BLADES TO GEAR*/
    DrawCubeV({43.5f, -8.5f - bladeOffset, 15.5f}, {7.0f, 80.0f, 11.0f}, {80, 80, 80, 255});
    DrawCubeV({65.5f, -8.5f + bladeOffset, 15.5f}, {7.0f, 80.0f, 11.0f}, {80, 80, 80, 255});
}