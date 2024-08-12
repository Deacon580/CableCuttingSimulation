#ifndef OPERATIONCONTROL_H
#define OPERATIONCONTROL_H
#include <raylib.h>


//These are stages for the operations. They work by executing the task step by step.
inline bool mainStages[7] = { false };

inline float motorRotation[2] = { 0.0f };
inline bool motorStages[2] = { false };
inline bool bladeStages[1] = { false };
inline bool guidingPipeStages[1] = { false };\

inline bool calibrationStages[5] = { true, false, false, false, false };

inline bool rightOuterInsulationCutStages[4] = { false };
inline bool rightInnerInsulationCutStages[4] = { false };
inline bool advanceMiddlePartStage = false;
inline bool leftOuterInsulationCutStages[9] = { false };
inline bool leftInnerInsulationCutStages[7] = { false };
inline bool resetStages = false;
// These are the changing variables for the animation to take in place.
inline float gearAngle = 0.0f;
inline float bladeOffset = 0.0f;
inline float pistonHeadOffset = 0.0f;
inline float guidingPipeAngle = 0.0f;

class Cables {
public:
    bool draw;
    Vector3 startPos;
    Vector3 endPos;
    void moveCable(float speed, float direction) {
        startPos.x += 2 * PI * 6.0f * speed / 360 * direction * GetFrameTime();
        endPos.x += 2 * PI * 6.0f * speed / 360 * direction * GetFrameTime();
    }
    void dropCable() {
        if(startPos.y >= -22.0f && calibrationStages[3]) {
            startPos.y -= 30.0f * GetFrameTime();
            endPos.y -= 30.0f * GetFrameTime();
        }
    }
};

//Cables are grouped together for easier debugging.

inline Cables cable1 = {true, {-60.0f, -8.5f, 43.0f}, {10.0f, -8.5f, 43.0f}};
inline Cables cable2 = {true, {0.0f, 0.0f, 0.0f}, {46.5f, 0.0f, 0.0f}};

inline Cables cable3 = {true, {15.0f, -8.5f, 43.0f}, {47.5f, -8.5f, 43.0f}};
inline Cables cable4 = {true, {8.0f, -8.5f, 43.0f}, {15.0f, -8.5f, 43.0f}};
inline Cables cable5 = {true, {47.5f, -8.5f, 43.0f}, {54.5f, -8.5f, 43.0f}};
inline Cables cable6 = {true, {12.0f, -8.5f, 42.5f}, {50.5f, -8.5f, 42.5f}};
inline Cables cable7 = {true, {12.0f, -8.5f, 43.5f}, {50.5f, -8.5f, 43.5f}};
inline Cables cable8 = {true, {7.99f, -8.5f, 42.5f}, {12.0f, -8.5f, 42.5f}};
inline Cables cable9 = {true, {7.99f, -8.5f, 43.5f}, {12.0f, -8.5f, 43.5f}};
inline Cables cable10 = {true, {50.5f, -8.5f, 42.5f}, {54.51f, -8.5f, 42.5f}};
inline Cables cable11 = {true, {50.5f, -8.5f, 43.5f}, {54.51f, -8.5f, 43.5f}};
inline Cables cable12 = {true, {7.98f, -8.5f, 42.5f}, {54.52f, -8.5f, 42.5f}};
inline Cables cable13 = {true, {7.98f, -8.5f, 43.5f}, {54.52f, -8.5f, 43.5f}};

inline Cables cable14 = {true, {54.5f, -8.5f, 43.0f}, {94.0f, -8.5f, 43.0f}};
inline Cables cable15 = {true, {54.4f, -8.5f, 42.5f}, {94.1f, -8.5f, 42.5f}};
inline Cables cable16 = {true, {54.3f, -8.5f, 42.5f}, {94.2f, -8.5f, 42.5f}};
inline Cables cable17 = {true, {54.4f, -8.5f, 43.5f}, {94.1f, -8.5f, 43.5f}};
inline Cables cable18 = {true, {54.3f, -8.5f, 43.5f}, {94.2f, -8.5f, 43.5f}};

void calibration();
void motorControl(int motorNo, float rotAngle, float motorSpeed, float direction);
void checkCablesToMove(float motorSpeed, float direction);
void closeBlades(float a);
void openBlades();
void rightOuterInsulationCut();
void rightInnerInsulationCut();
void advanceMiddlePart();
void leftOuterInsulationCut();
void leftInnerInsulationCut();
void resetEveryThing();

#endif //OPERATIONCONTROL_H
