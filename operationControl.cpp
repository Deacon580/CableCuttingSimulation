#include "operationControl.h"
#include <raylib.h>
//Commonly used functions in the code.
void motorControl(int motorNo, float rotAngle, float motorSpeed, float direction) {
    if(!motorStages[motorNo]) {
        if(motorRotation[motorNo] < rotAngle && direction == 1) {
            motorRotation[motorNo] += motorSpeed * GetFrameTime();
        } else if(motorRotation[motorNo] > rotAngle  && direction == -1) {
            motorRotation[motorNo] -= motorSpeed * GetFrameTime();
        } else {
            motorStages[motorNo] = true;
        }
    }
}

void closeBlades(float a) {
    if(!bladeStages[0]) {
        if(bladeOffset < a) {
            bladeOffset += 24.0f * GetFrameTime();
            gearAngle += 180.0f * GetFrameTime();
        } else {
            bladeStages[0] = true;
        }
    }
}
void openBlades() {
    if(!bladeStages[0]) {
        if(bladeOffset > 0.0f) {
            bladeOffset -= 24.0f * GetFrameTime();
            gearAngle-= 180.0f * GetFrameTime();
        } else {
            bladeStages[0] = true;
        }
    }
}

void riseGuidingPipe() {
    if(!guidingPipeStages[0]) {
        if(guidingPipeAngle < 10) {
            guidingPipeAngle += 30.0f * GetFrameTime();
            pistonHeadOffset += 12.0f * GetFrameTime();
        } else {
            guidingPipeStages[0] = true;
        }
    }
}

void lowerGuidingPipe() {
    if(!guidingPipeStages[0]) {
        if(guidingPipeAngle > 0) {
            guidingPipeAngle -= 30.0f * GetFrameTime();
            pistonHeadOffset -= 12.0f * GetFrameTime();
        } else {
            guidingPipeStages[0] = true;
        }
    }
}
//Function for each step in the main steps.
void calibration() {
    if(!calibrationStages[0]) {
        motorControl(0, 200, 300.0f, 1.0f);
        cable14.moveCable(300.0f, 1);
        cable15.moveCable(300.0f, 1);
        cable16.moveCable(300.0f, 1);
        cable17.moveCable(300.0f, 1);
        cable18.moveCable(300.0f, 1);
        if(motorStages[0]) {
            motorStages[0] = false;
            calibrationStages[0] = true;
        }
    } else if(!calibrationStages[1]) {
        closeBlades(5.0f);
        if(bladeStages[0]) {
            calibrationStages[1] = true;
            bladeStages[0] = false;
        }
    } else if(!calibrationStages[2]) {
        openBlades();
        if(bladeStages[0]) {
            calibrationStages[2] = true;
            bladeStages[0] = false;
        }
    } else if(!calibrationStages[3]) {
        motorControl(1, 440, 300.0f, 1);
        cable14.moveCable(300.0f, 1.0f);
        cable15.moveCable(300.0f, 1.0f);
        cable16.moveCable(300.0f, 1.0f);
        cable17.moveCable(300.0f, 1.0f);
        cable18.moveCable(300.0f, 1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            calibrationStages[3] = true;
        }
    } else if(!calibrationStages[4]) {
        cable14.dropCable();
        cable15.dropCable();
        cable16.dropCable();
        cable17.dropCable();
        cable18.dropCable();
        if(cable14.endPos.y <= -22.0f) {
            calibrationStages[4] = true;
        }
    }
}

void rightOuterInsulationCut() {
    if(!rightOuterInsulationCutStages[0]) {
        motorControl(0, 66.9f, 100.0f, 1);
        cable3.moveCable(100.0f, 1.0f);
        cable4.moveCable(100.0f, 1.0f);
        cable5.moveCable(100.0f, 1.0f);
        cable6.moveCable(100.0f, 1.0f);
        cable7.moveCable(100.0f, 1.0f);
        cable8.moveCable(100.0f, 1.0f);
        cable9.moveCable(100.0f, 1.0f);
        cable10.moveCable(100.0f, 1.0f);
        cable11.moveCable(100.0f, 1.0f);
        cable12.moveCable(100.0f, 1.0f);
        cable13.moveCable(100.0f, 1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            rightOuterInsulationCutStages[0] = true;
        }
    } else if(!rightOuterInsulationCutStages[1]) {
        closeBlades(3.2f);
        if(bladeStages[0]) {
            rightOuterInsulationCutStages[1] = true;
            bladeStages[0] = false;
        }
    } else if(!rightOuterInsulationCutStages[2]) {
        motorControl(0, 0.0f, 100.0f, -1);
        cable2.draw = false;
        cable3.moveCable(100.0f, -1.0f);
        cable4.moveCable(100.0f, -1.0f);
        cable6.moveCable(100.0f, -1.0f);
        cable7.moveCable(100.0f, -1.0f);
        cable8.moveCable(100.0f, -1.0f);
        cable9.moveCable(100.0f, -1.0f);
        cable10.moveCable(100.0f, -1.0f);
        cable11.moveCable(100.0f, -1.0f);
        cable12.moveCable(100.0f, -1.0f);
        cable13.moveCable(100.0f, -1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            rightOuterInsulationCutStages[2] = true;
            cable5.draw = false;
        }
    } else if(!rightOuterInsulationCutStages[3]) {
        openBlades();
        if(bladeStages[0]) {
            rightOuterInsulationCutStages[3] = true;
            bladeStages[0] = false;
        }
    }
}

void rightInnerInsulationCut() {
    if(!rightInnerInsulationCutStages[0]) {
        motorControl(0, 38.2f, 100.0f, 1);
        cable3.moveCable(100.0f, 1.0f);
        cable4.moveCable(100.0f, 1.0f);
        cable6.moveCable(100.0f, 1.0f);
        cable7.moveCable(100.0f, 1.0f);
        cable8.moveCable(100.0f, 1.0f);
        cable9.moveCable(100.0f, 1.0f);
        cable10.moveCable(100.0f, 1.0f);
        cable11.moveCable(100.0f, 1.0f);
        cable12.moveCable(100.0f, 1.0f);
        cable13.moveCable(100.0f, 1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            rightInnerInsulationCutStages[0] = true;
        }
    } else if(!rightInnerInsulationCutStages[1]) {
        closeBlades(3.6f);
        if(bladeStages[0]) {
            rightInnerInsulationCutStages[1] = true;
            bladeStages[0] = false;
        }
    } else if(!rightInnerInsulationCutStages[2]) {
        motorControl(0, 0.0f, 100.0f, -1);
        cable3.moveCable(100.0f, -1.0f);
        cable4.moveCable(100.0f, -1.0f);
        cable6.moveCable(100.0f, -1.0f);
        cable7.moveCable(100.0f, -1.0f);
        cable8.moveCable(100.0f, -1.0f);
        cable9.moveCable(100.0f, -1.0f);
        cable12.moveCable(100.0f, -1.0f);
        cable13.moveCable(100.0f, -1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            rightInnerInsulationCutStages[2] = true;
            cable10.draw = false;
            cable11.draw = false;
        }
    } else if(!rightInnerInsulationCutStages[3]) {
        openBlades();
        if(bladeStages[0]) {
            rightInnerInsulationCutStages[3] = true;
            bladeStages[0] = false;
        }
    }
}

void advanceMiddlePart() {
    if(!advanceMiddlePartStage) {
        if(motorRotation[0] >= 300) {
            cable2.draw = true;
        }
        motorControl(0, 444.0f, 300.0f, 1);
        cable3.moveCable(300.0f, 1.0f);
        cable4.moveCable(300.0f, 1.0f);
        cable6.moveCable(300.0f, 1.0f);
        cable7.moveCable(300.0f, 1.0f);
        cable8.moveCable(300.0f, 1.0f);
        cable9.moveCable(300.0f, 1.0f);
        cable12.moveCable(300.0f, 1.0f);
        cable13.moveCable(300.0f, 1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            advanceMiddlePartStage = true;
        }
    }
}

void leftOuterInsulationCut() {
    if(!leftOuterInsulationCutStages[0]) {
        closeBlades(5.0f);
        if(bladeStages[0]) {
            leftOuterInsulationCutStages[0] = true;
            bladeStages[0] = false;
            motorRotation[0] = 0.0f; motorRotation[1] = 0.0f;
        }
    } else if(!leftOuterInsulationCutStages[1]) {
        motorControl(0, -20.0f, 90.0f, -1);
        cable2.endPos.x -= 12.0f *GetFrameTime();
        if(motorStages[0]) {
            motorStages[0] = false;
            leftOuterInsulationCutStages[1] = true;
        }
    } else if(!leftOuterInsulationCutStages[2]) {
        riseGuidingPipe();
        if(guidingPipeStages[0]) {
            leftOuterInsulationCutStages[2] = true;
            guidingPipeStages[0] = false;
            motorRotation[0] = 0.0f;
        }
    } else if(!leftOuterInsulationCutStages[3]) {
        motorControl(0, 66.9f, 100.0f, -1);
        cable3.moveCable(100.0f, -1.0f);
        cable4.moveCable(100.0f, -1.0f);
        cable6.moveCable(100.0f, -1.0f);
        cable7.moveCable(100.0f, -1.0f);
        cable8.moveCable(100.0f, -1.0f);
        cable9.moveCable(100.0f, -1.0f);
        cable10.moveCable(100.0f, -1.0f);
        cable11.moveCable(100.0f, -1.0f);
        cable12.moveCable(100.0f, -1.0f);
        cable13.moveCable(100.0f, -1.0f);
        if(motorStages[0]) {
            motorStages[0] = false;
            leftOuterInsulationCutStages[3] = true;
            cable5.draw = false;
            motorRotation[1] = 0.0f;
        }
    } else if(!leftOuterInsulationCutStages[4]) {
        openBlades();
        if(bladeStages[0]) {
            leftOuterInsulationCutStages[4] = true;
            bladeStages[0] = false;
            motorRotation[1] = 0.0f;
        }
    } else if(!leftOuterInsulationCutStages[5]) {
        motorControl(1, -66.9f, 100.0f, -1);
        cable3.moveCable(100.0f, -1.0f);
        cable4.moveCable(100.0f, -1.0f);
        cable6.moveCable(100.0f, -1.0f);
        cable7.moveCable(100.0f, -1.0f);
        cable8.moveCable(100.0f, -1.0f);
        cable9.moveCable(100.0f, -1.0f);
        cable10.moveCable(100.0f, -1.0f);
        cable11.moveCable(100.0f, -1.0f);
        cable12.moveCable(100.0f, -1.0f);
        cable13.moveCable(100.0f, -1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            leftOuterInsulationCutStages[5] = true;
        }
    } else if(!leftOuterInsulationCutStages[6]) {
        closeBlades(3.2f);
        if(bladeStages[0]) {
            leftOuterInsulationCutStages[6] = true;
            bladeStages[0] = false;
            motorRotation[0] = 0.0f; motorRotation[1] = 0.0f;
        }
    } else if(!leftOuterInsulationCutStages[7]) {
        motorControl(1, 66.9f, 100.0f, 1);
        cable3.moveCable(100.0f, 1.0f);
        cable6.moveCable(100.0f, 1.0f);
        cable7.moveCable(100.0f, 1.0f);
        cable8.moveCable(100.0f, 1.0f);
        cable9.moveCable(100.0f, 1.0f);
        cable10.moveCable(100.0f, 1.0f);
        cable11.moveCable(100.0f, 1.0f);
        cable12.moveCable(100.0f, 1.0f);
        cable13.moveCable(100.0f, 1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            leftOuterInsulationCutStages[7] = true;
            cable4.draw = false;
        }
    } else if(!leftOuterInsulationCutStages[8]) {
        openBlades();
        if(bladeStages[0]) {
            leftOuterInsulationCutStages[8] = true;
            bladeStages[0] = false;
            motorRotation[1] = 0.0f;
        }
    }
}

void leftInnerInsulationCut() {
    if(!leftInnerInsulationCutStages[0]) {
        motorControl(1, -38.2f, 100.0f, -1);
        cable3.moveCable(100.0f, -1.0f);
        cable6.moveCable(100.0f, -1.0f);
        cable7.moveCable(100.0f, -1.0f);
        cable8.moveCable(100.0f, -1.0f);
        cable9.moveCable(100.0f, -1.0f);
        cable10.moveCable(100.0f, -1.0f);
        cable11.moveCable(100.0f, -1.0f);
        cable12.moveCable(100.0f, -1.0f);
        cable13.moveCable(100.0f, -1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            leftInnerInsulationCutStages[0] = true;
        }
    } else if(!leftInnerInsulationCutStages[1]) {
        closeBlades(3.6f);
        if(bladeStages[0]) {
            leftInnerInsulationCutStages[1] = true;
            bladeStages[0] = false;
            motorRotation[0] = 0.0f; motorRotation[1] = 0.0f;
        }
    } else if(!leftInnerInsulationCutStages[2]) {
        motorControl(1, 38.2f, 100.0f, 1);
        cable3.moveCable(100.0f, 1.0f);
        cable6.moveCable(100.0f, 1.0f);
        cable7.moveCable(100.0f, 1.0f);
        cable10.moveCable(100.0f, 1.0f);
        cable11.moveCable(100.0f, 1.0f);
        cable12.moveCable(100.0f, 1.0f);
        cable13.moveCable(100.0f, 1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            leftInnerInsulationCutStages[2] = true;
            cable8.draw = false; cable9.draw = false;
        }
    } else if(!leftInnerInsulationCutStages[3]) {
        openBlades();
        if(bladeStages[0]) {
            leftInnerInsulationCutStages[3] = true;
            bladeStages[0] = false;
        }
    } else if(!leftInnerInsulationCutStages[4]) {
        motorControl(1, 420.0f, 150.0f, 1);
        cable3.moveCable(150.0f, 1.0f);
        cable6.moveCable(150.0f, 1.0f);
        cable7.moveCable(150.0f, 1.0f);
        cable10.moveCable(150.0f, 1.0f);
        cable11.moveCable(150.0f, 1.0f);
        cable12.moveCable(150.0f, 1.0f);
        cable13.moveCable(150.0f, 1.0f);
        if(motorStages[1]) {
            motorStages[1] = false;
            leftInnerInsulationCutStages[4] = true;
        }
    } else if(!leftInnerInsulationCutStages[5]) {
        lowerGuidingPipe();
        if(guidingPipeStages[0]) {
            leftInnerInsulationCutStages[5] = true;
            guidingPipeStages[0] = false;
        }
    } else if(!leftInnerInsulationCutStages[6]) {
        motorControl(0, 20.0f, 90.0f, 1);
        cable2.endPos.x += 12.0f *GetFrameTime();
        if(motorStages[0]) {
            motorStages[0] = false;
            leftInnerInsulationCutStages[6] = true;
        }
    }
}
//Resetting every variable and stage for the process to start again.
void resetEveryThing() {
    if(!resetStages) {
        cable3.dropCable();
        cable6.dropCable();
        cable7.dropCable();
        cable10.dropCable();
        cable11.dropCable();
        cable12.dropCable();
        cable13.dropCable();
        if(cable3.startPos.y <= -22.0f) {
            resetStages = true;
            cable1 = {true, {-60.0f, -8.5f, 43.0f}, {10.0f, -8.5f, 43.0f}};
            cable2 = {true, {0.0f, 0.0f, 0.0f}, {46.5f, 0.0f, 0.0f}};

            cable3 = {true, {15.0f, -8.5f, 43.0f}, {47.5f, -8.5f, 43.0f}};
            cable4 = {true, {8.0f, -8.5f, 43.0f}, {15.0f, -8.5f, 43.0f}};
            cable5 = {true, {47.5f, -8.5f, 43.0f}, {54.5f, -8.5f, 43.0f}};
            cable6 = {true, {12.0f, -8.5f, 42.5f}, {50.5f, -8.5f, 42.5f}};
            cable7 = {true, {12.0f, -8.5f, 43.5f}, {50.5f, -8.5f, 43.5f}};
            cable8 = {true, {7.99f, -8.5f, 42.5f}, {12.0f, -8.5f, 42.5f}};
            cable9 = {true, {7.99f, -8.5f, 43.5f}, {12.0f, -8.5f, 43.5f}};
            cable10 = {true, {50.5f, -8.5f, 42.5f}, {54.51f, -8.5f, 42.5f}};
            cable11 = {true, {50.5f, -8.5f, 43.5f}, {54.51f, -8.5f, 43.5f}};
            cable12 = {true, {7.98f, -8.5f, 42.5f}, {54.52f, -8.5f, 42.5f}};
            cable13 = {true, {7.98f, -8.5f, 43.5f}, {54.52f, -8.5f, 43.5f}};
            for(int i=1; i<7; i++) {
                mainStages[i] = false;
            }
            motorRotation[0] = { 0.0f }; motorRotation[1] = { 0.0f };
            motorStages[0] = { false }; motorStages[0] = { false };

            bladeOffset = 0.0f;
            bladeStages[0] = { false };

            guidingPipeAngle = 0.0f;
            guidingPipeStages[0] = { false };

            for(int i=0; i<4; i++) {
                rightOuterInsulationCutStages[i] = { false };
                rightInnerInsulationCutStages[i] = { false };
            }
            advanceMiddlePartStage = false;
            for(int i=0; i<9; i++) {
                leftOuterInsulationCutStages[i] = { false };
            }
            for(int i=0; i<7; i++) {
                leftInnerInsulationCutStages[i] = { false };
            }
            resetStages = false;
        }
    }
}
