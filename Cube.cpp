// Class build cube
#include "custom_struct.h"
#include "create_draw.h"

class Cube {
  private:
  VAO* cube;

  public:
  void createCube() {
    static const GLfloat g_color_buffer_data[] = {
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,

          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,

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

    static const GLfloat myVertex_buffer[] = {
      0,0,0,
      1,0,0,
      1,1,0,

      0,0,0,
      0,1,0,
      1,1,0,

      0,0,1,
      1,0,1,
      1,1,1,

      0,0,1,
      0,1,1,
      1,1,1,

      0,0,0,
      0,0,1,
      0,1,1,

      0,0,0,
      0,1,0,
      0,1,1,

      1,0,0,
      1,1,0,
      1,1,1,

      1,0,0,
      1,0,1,
      1,1,1,

      0,1,0,
      0,1,1,
      1,1,0,

      0,1,1,
      1,1,0,
      1,1,1,

      0,0,0,
      0,0,1,
      1,0,0,

      0,0,1,
      1,0,0,
      1,0,1

    };
    cube = create3DObject(GL_TRIANGLES, 36, myVertex_buffer, g_color_buffer_data, GL_FILL);
  }

  void drawCube(glm::mat4 VP) {
    printf("called\n" );
    glm::mat4 MVP;
    Matrices.model = glm::mat4(1.0f);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(cube);
  }
};
