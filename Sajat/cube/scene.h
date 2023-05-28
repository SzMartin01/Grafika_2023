#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Cicamodel
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_triangles;
    Vertex* vertices;
    TextureVertex* texture_vertices;
    Vertex* normals;
    Triangle* triangles;
    vec3 position;
} Cicamodel;

typedef struct Scene
{
    Model padlo;
    Model fal2;
    Model fal3;
    Model fal4;
    Model kisfal1;
    Model kisfal2;
    Model lampa;
    Cicamodel cica;
    Cicamodel farok;
    Material material;
    GLuint texture_id;
    GLuint texture_cica;
    GLuint texture_padlo;
    GLuint texture_kisfal;
    GLuint texture_nagyfal;
    float ambient_light[4];
    float diffuse_light[4];
    float specular_light[4];
    float position[4];
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene* scene);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void increase_light(Scene *scene);
void decrease_light(Scene *scene);

#endif /* SCENE_H */

