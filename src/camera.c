#include <camera/camera.h>
#include <cglm/cglm.h>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

void camera_init(Camera* camera, vec3 startPosition) {
    glm_vec3_copy(startPosition, camera->position);
    glm_vec3_copy((vec3){0.0f, 0.0f, -1.0f}, camera->front);
    glm_vec3_copy((vec3){0.0f, 1.0f, 0.0f}, camera->up);
    camera->yaw = -90.0f;
    camera->pitch = 0.0f;
    camera->speed = 2.5f;
    camera->sensitivity = 0.1f;
}

void camera_get_view_matrix(Camera* camera, mat4 view) {
    vec3 target;
    glm_vec3_add(camera->position, camera->front, target);
    glm_lookat(camera->position, target, camera->up, view);
}

void camera_process_keyboard(Camera* camera, Camera_Movement direction, float deltaTime) {
    float velocity = camera->speed * deltaTime;
    vec3 right;
    glm_vec3_cross(camera->front, camera->up, right);
    glm_vec3_normalize(right);
    if (direction == FORWARD)
        glm_vec3_muladds(camera->front, velocity, camera->position);
    if (direction == BACKWARD)
        glm_vec3_muladds(camera->front, -velocity, camera->position);
    if (direction == LEFT)
        glm_vec3_muladds(right, -velocity, camera->position);
    if (direction == RIGHT)
        glm_vec3_muladds(right, velocity, camera->position);
}


void camera_process_mouse_movement(Camera* camera, float xOffset, float yOffset) {
    xOffset *= camera->sensitivity;
    yOffset *= camera->sensitivity;

    camera->yaw += xOffset;
    camera->pitch -= yOffset;

    if (camera->pitch > 89.0f) camera->pitch = 89.0f;
    if (camera->pitch < -89.0f) camera->pitch = -89.0f;

    vec3 newFront = {
        cosf(glm_rad(camera->yaw)) * cosf(glm_rad(camera->pitch)),
        sinf(glm_rad(camera->pitch)),
        sinf(glm_rad(camera->yaw)) * cosf(glm_rad(camera->pitch))
    };

    glm_vec3_normalize(newFront);
    glm_vec3_copy(newFront, camera->front);
}

void camera_update_direction(Camera* camera)
{
    float front[3];

    front[0] = cosf(glm_rad(camera->yaw)) * cosf(glm_rad(camera->pitch));
    front[1] = sinf(glm_rad(camera->pitch));
    front[2] = sinf(glm_rad(camera->yaw)) * cosf(glm_rad(camera->pitch));

    glm_vec3_normalize_to(front, camera->front);

    float worldUp[3] = { 0.0f, 1.0f, 0.0f };
    float right[3];
    glm_vec3_cross(camera->front, worldUp, right);
    glm_vec3_normalize(right);

    glm_vec3_cross(right, camera->front, camera->up);
    glm_vec3_normalize(camera->up);
}



