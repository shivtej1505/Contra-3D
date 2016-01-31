// Class build cube
#include "custom_struct.h"
#include "create_draw.h"
#include "color.h"

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
    const int tmp[] = {11, 12, 13, 1, 3, 14};
    GLfloat my_color[108];
    int start = 0;
    for (int i=0; i<6; i++) {
      if (tmp[i] == 1) {
        start = copy_color(start, BLACK_COLOR, my_color);
      } else if (tmp[i] == 2) {
        start = copy_color(start, RED_COLOR, my_color);
      } else if (tmp[i] == 3) {
        start = copy_color(start, GREEN_COLOR, my_color);
      } else if (tmp[i] == 4) {
        start = copy_color(start, YELLOW_COLOR, my_color);
      } else if (tmp[i] == 5) {
        start = copy_color(start, BLUE_COLOR, my_color);
      } else if (tmp[i] == 6) {
        start = copy_color(start, MAGENTA_COLOR, my_color);
      } else if (tmp[i] == 7) {
        start = copy_color(start, CYAN_COLOR, my_color);
      } else if (tmp[i] == 8) {
        start = copy_color(start, DARK_GRAY_COLOR, my_color);
      } else if (tmp[i] == 9) {
        start = copy_color(start, LIGHT_GRAY_COLOR, my_color);
      } else if (tmp[i] == 10) {
        start = copy_color(start, BROWN_COLOR, my_color);
      } else if (tmp[i] == 11) {
        start = copy_color(start, ORANGE_COLOR, my_color);
      } else if (tmp[i] == 12) {
        start = copy_color(start, PINK_COLOR, my_color);
      } else if (tmp[i] == 13) {
        start = copy_color(start, PURPLE_COLOR, my_color);
      } else if (tmp[i] == 14) {
        start = copy_color(start, WHITE_COLOR, my_color);
      }
    }
    for (int i=1; i<= 108; i++) {
      printf("%f ", my_color[i-1]);
      if (!(i%3))
        printf("\n" );
    }
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
    cube = create3DObject(GL_TRIANGLES, 36, cube_vertex_buffer, my_color, GL_FILL);
  }

  int copy_color(int start, const GLfloat *array, GLfloat color_array[]) {
    for (int i=0; i<18; i++) {
      color_array[start++] = array[i%3];
    }
    return start;
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
