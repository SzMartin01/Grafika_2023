#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->padlo), "assets/models/padlo.obj");
    load_model(&(scene->fal2), "assets/models/fal2.obj");
    load_model(&(scene->fal3), "assets/models/fal3.obj");
    load_model(&(scene->fal4), "assets/models/fal4.obj");
    load_model(&(scene->kisfal1), "assets/models/kisfal1.obj");
    load_model(&(scene->kisfal2), "assets/models/kisfal2.obj");
    load_model(&(scene->cica), "assets/models/cica.obj");
    load_model(&(scene->farok), "assets/models/farok.obj");
    load_model(&(scene->lampa), "assets/models/lampa.obj");
    scene->texture_id = load_texture("assets/textures/plafon.jpg");
    scene->texture_cica = load_texture("assets/textures/cica.jpg");
    scene->texture_padlo = load_texture("assets/textures/padlo.jpg");
    scene->texture_kisfal = load_texture("assets/textures/kisfal.jpg");
    scene->texture_nagyfal = load_texture("assets/textures/nagyfal.jpg");



    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.0;

    scene->diffuse_light[0] = 0.5f;
    scene->diffuse_light[1] = 0.5f;
    scene->diffuse_light[2] = 0.5f;
    scene->diffuse_light[3] = 0.0f;

    scene->ambient_light[0] = 0.5f;
    scene->ambient_light[1] = 0.5f;
    scene->ambient_light[2] = 0.5f;
    scene->ambient_light[3] = 0.0f;

    scene->specular_light[0] = 0.5f;
    scene->specular_light[1] = 0.5f;
    scene->specular_light[2] = 0.5f;
    scene->specular_light[3] = 0.0f;

    scene->position[0] = 1.0f;
    scene->position[1] = 1.0f;
    scene->position[2] = 1.0f;
    scene->position[3] = 1.0f;
}

void set_lighting(Scene *scene)
{

    glLightfv(GL_LIGHT0, GL_AMBIENT, scene->ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, scene->diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, scene->specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, scene->position);
}
void increase_light(Scene *scene)
{
    if (scene->ambient_light[0] < 1.0f)
    {
        scene->ambient_light[0] = scene->ambient_light[1] = scene->ambient_light[2] += 0.1f;
    }
}
void decrease_light(Scene *scene)
{
    if (scene->ambient_light[0] > -0.5f)
    {
        scene->ambient_light[0] = scene->ambient_light[1] = scene->ambient_light[2] -= 0.1f;
    }
}
void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{

    float rotationAngle = sin(SDL_GetTicks() / 150.0f) * 1.0f;
    scene->farok.position.z = rotationAngle;
}

void render_scene(const Scene* scene)
{
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    set_material(&(scene->material));
    set_lighting(scene);
    draw_origin();
    glTranslatef(0.0f,0.0f,1.0f);
    draw_model(&(scene->fal4));
    draw_model(&(scene->lampa));
    glBindTexture(GL_TEXTURE_2D, scene->texture_nagyfal);
    draw_model(&(scene->fal3));
    draw_model(&(scene->fal2));
    glBindTexture(GL_TEXTURE_2D, scene->texture_kisfal);
    draw_model(&(scene->kisfal1));
    draw_model(&(scene->kisfal2));
    glBindTexture(GL_TEXTURE_2D, scene->texture_cica);
    draw_model(&(scene->cica));
    glBindTexture(GL_TEXTURE_2D, scene->texture_padlo);
    draw_model(&(scene->padlo));
    //Farok
    glPushMatrix();
    glRotatef(scene->farok.position.x, 1.5f, 0.1f, 1.0f);
    glRotatef(scene->farok.position.y, 0.0f, 1.0f, 0.0f);
    glRotatef(scene->farok.position.z, 0.1f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, scene->texture_cica);
    draw_model(&(scene->farok));

    glPopMatrix();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
