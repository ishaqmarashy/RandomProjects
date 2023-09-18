#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 90.0f
#define SENSITIVITY 0.0f
#define ZOOM 45.0f

enum class Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
public:
    // Camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    GLFWwindow* window;

    // Euler Angles
    float Yaw;
    float Pitch;

    // Camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // Constructor with default values
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        float yaw = -90.0f, float pitch = 0.0f);
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
    // Processes keyboard input
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

    // Processes mouse movement
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    // Processes mouse scroll input
    void ProcessMouseScroll(float yoffset);
private:
    // Calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
    void processInput(float deltaTime);
    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    inline glm::mat4 GetViewMatrix() const { 
        return glm::lookAt(Position, Position + Front, Up);}
};
