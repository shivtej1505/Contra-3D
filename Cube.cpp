// Class build cube
#include "custom_struct.h"
#include "create_draw.h"

class Cube {
  private:
  VAO* cube;
  GLfloat length;
  GLfloat height;
  GLfloat breadth;

  public:
  void initialize(GLfloat l = 1.0f, GLfloat h = 1.0f, GLfloat b = 1.0f) {
    length = l;
    height = h;
    breadth = b;
    createCube();
  }

  private:
  // Cube face will be identified using their face center
  void createCube() {
    const GLfloat cube_color_buffer[] = {
          // X = l/2, Y = h/2, Z = 0
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,

          //
          1.0f,  0.0f,  0.0f,
          1.0f,  0.0f,  0.0f,
          1.0f,  0.0f,  0.0f,
          1.0f,  0.0f,  0.0f,
          1.0f,  0.0f,  0.0f,
          1.0f,  0.0f,  0.0f,

          1.0f,  0.0f,  1.0f,
          1.0f,  0.0f,  1.0f,
          1.0f,  0.0f,  1.0f,

          1.0f,  0.0f,  1.0f,
          1.0f,  0.0f,  1.0f,
          1.0f,  0.0f,  1.0f,

          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,

          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,

          0.0f,  1.0f,  1.0f,
          0.0f,  1.0f,  1.0f,
          0.0f,  1.0f,  1.0f,

          0.0f,  1.0f,  1.0f,
          0.0f,  1.0f,  1.0f,
          0.0f,  1.0f,  1.0f,

          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,

          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f
      };
    const GLfloat cube_vertex_buffer[] = {
      // X = l/2, Y = h/2, Z = 0
      0, 0, 0,
      length, 0, 0,
      length, height, 0,
      0, 0, 0,
      0, height, 0,
      length, height, 0,

      // X = l/2, Y = h/2, Z = b
      0, 0, breadth,
      length, 0, breadth,
      length, height, breadth,
      0, 0, breadth,
      0, height, breadth,
      length, height, breadth,


      0, 0, 0,
      0, 0, breadth,
      0, height, breadth,
      0, 0, 0,
      0, height, 0,
      0, height, breadth,

      length, 0, 0,
      length, 0, breadth,
      length, height, breadth,

      length, 0, 0,
      length, height, 0,
      length, height, breadth,

      0, height, 0,
      length, height, 0,
      length, height, breadth,

      0, height, 0,
      0, height, breadth,
      length, height, breadth,

      0, 0, 0,
      length, 0, 0,
      length, 0, breadth,

      0, 0, 0,
      0, 0, breadth,
      length, 0, breadth,
    };
    cube = create3DObject(GL_TRIANGLES, 36, cube_vertex_buffer, cube_color_buffer, GL_FILL);
  }

  public:
  void drawCube(glm::mat4 VP, GLfloat x = 0.0f, GLfloat y = 0.0f, GLfloat z = 0.0f) {
    glm::mat4 MVP;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translateCube = glm::translate(glm::vec3(x, y, z));
    Matrices.model *= (translateCube);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(cube);
  }
};
