#ifndef CAMERA_H
#define CAMERA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float position[3];  // Using C-style array for vectors
    float front[3];
    float up[3];
    float yaw;
    float pitch;
    float speed;
    float sensitivity;
} Camera;

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} Camera_Movement;

void camera_init(Camera* camera, float position[3]);
void camera_get_view_matrix(Camera* camera, float view[16]);
void camera_process_keyboard(Camera* camera, int key, float deltaTime);
void camera_process_mouse_movement(Camera* camera, float xOffset, float yOffset);
void camera_update_direction(Camera* camera);

#ifdef __cplusplus
}
#endif

#endif




