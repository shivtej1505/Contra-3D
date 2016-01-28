all: contra3D

game3D: Contra-3D.cpp glad.c
	g++ -o contra3D Contra-3D.cpp glad.c -lGL -lglfw -ldl

clean:
	rm contra3D
