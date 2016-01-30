class Tile {
  private:
  Cube cube;
  GLfloat tile_length;
  GLfloat tile_height;
  GLfloat tile_breadth;
  GLfloat xpos;
  GLfloat ypos;
  GLfloat zpos;

  public:
  void initialize(GLfloat l, GLfloat h, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    tile_length = l;
    tile_height = h;
    tile_breadth = b;
    xpos = x;
    ypos = y;
    zpos = z;
    cube.initialize(tile_length, tile_height, tile_breadth);
  }

  void drawTile(glm::mat4 VP) {
    cube.drawCube(VP, xpos, ypos, zpos);
  }
};
