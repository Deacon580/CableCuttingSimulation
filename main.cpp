#include "raylib.h"
#include "initCamera.h"
#include "staticParts.h"
#include "movingParts.h"
#include "operationControl.h"

Color boxColors[6] = {RED}; // The boxes represent which stage is done.

void drawSchematic();
void drawControlBoxes();

int main()
{
    InitWindow(800, 600, "SIMULATION");
    DisableCursor();
    SetTargetFPS(240);
    Camera cam = initCamera();

    while(!WindowShouldClose()) {
        UpdateCamera(&cam, CAMERA_FREE);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(cam);
                if(!mainStages[0]) {
                    calibration();
                    if(calibrationStages[4]) {
                        mainStages[0] = true;
                        cable14.draw = false;
                        cable15.draw = false;
                        cable16.draw = false;
                        cable17.draw = false;
                        cable18.draw = false;
                    }
                } else if(!mainStages[1]) {
                    rightOuterInsulationCut();
                    if(rightOuterInsulationCutStages[3]) {
                        mainStages[1] = true;
                    }
                }else if(!mainStages[2]) {
                    rightInnerInsulationCut();
                    if(rightInnerInsulationCutStages[3]) {
                        mainStages[2] = true;
                    }
                } else if(!mainStages[3]) {
                    advanceMiddlePart();
                    if(advanceMiddlePartStage) {
                        mainStages[3] = true;
                    }
                } else if(!mainStages[4]) {
                    leftOuterInsulationCut();
                    if(leftOuterInsulationCutStages[8]) {
                        mainStages[4] = true;
                    }
                } else if(!mainStages[5]) {
                    leftInnerInsulationCut();
                    if(leftInnerInsulationCutStages[6]) {
                        mainStages[5] = true;
                    }
                } else if(!mainStages[6]) {
                    resetEveryThing();
                }
                drawSchematic();
            EndMode3D();
        drawControlBoxes();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void drawSchematic() { //Drawing everything.
    drawMotorBodyAndShaft();
    drawMotorCogOutline();
    drawCable();
    drawGuidingPipe();
    drawGuidingThingyAfterBlades();
    drawGuidingPipePistonHeadAndShaft();
    drawGuidingPipePistonBody();
    drawTopBlade();
    drawBottomBlade();
    drawMetalBladeHoldOn();
    drawGear();
    drawStepMotor();
    drawRails();
    drawCollectionBox();
    //Board.
    DrawCubeV({45.0f, -10.0f, 33.5f}, {120.0f, 60.0f, 2.0f}, {152, 155, 157, 255});
}

void drawControlBoxes() {
    for(int i=0; i<6; i++) {
        if(mainStages[i]) {
            boxColors[i] = GREEN;
        } else {
            boxColors[i] = RED;
        }
        DrawRectangle(5+35*i, 565, 30, 30, boxColors[i]);
    }
}