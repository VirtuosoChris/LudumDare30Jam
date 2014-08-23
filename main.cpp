#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "TileSet.h"
#include "SimpleImage.h"
#include "TileMap.h"
#include "TileShaders.h"
#include "TileRenderer.h"
#include "GLShader.h"
#include "Quad.h"
#include "GPUMesh.h"
#include "GameMap.h"
#include "playSound.h"

std::shared_ptr<GameMap> pMap;


void keyboard(unsigned char, int, int)
{

    
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    pMap->draw();
    
    glutSwapBuffers();

}

void reshape(int width, int height)
{
    
    glViewport(0, 0, width, height);

}

void idle()
{
    
    glutPostRedisplay();

}


void init()
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    
    TileSet tiles;
    
    SimpleImage img = loadImageFromFile("atlasexample.atlas.png");
    
    GL::ImageFormat imgFormat;
    imgFormat.width = img.width;
    imgFormat.height = img.height;
    imgFormat.channels = img.channels;
    
    std::cout<<"ATLAS IMAGE:"<<std::endl;
    std::cout<<"W:  "<<imgFormat.width<<std::endl;
    std::cout<<"H:  "<<imgFormat.height<<std::endl;
    std::cout<<"CH: "<<imgFormat.channels<<std::endl;
    
    std::cout<<imgFormat.width<<std::endl;
    
    GL::GLTexture atlasTex(imgFormat, img.data.get());
    
    tiles.pushAtlasForMaterial("default", atlasTex );
    
    const unsigned int tileWidth = 32;
    const unsigned int tileHeight =32;
    
    tiles.setTileSize(tileWidth, tileHeight);
    
    SimpleImage mapImg = loadImageFromFile("map.png");
    
    GL::ImageFormat mapFormat;
    mapFormat.width = mapImg.width;
    mapFormat.height = mapImg.height;
    mapFormat.channels = mapImg.channels;
    
    std::cout<<"\nMAP FILE : "<<std::endl;
    std::cout<<"W: "<<mapFormat.width<<std::endl;
    std::cout<<"H: "<<mapFormat.height<<std::endl;
    std::cout<<"CH "<<mapFormat.channels<<std::endl;
    
    
    GL::GLTexture mapTexture(mapFormat, mapImg.data.get());

    TileMap map(mapTexture);
    
    pMap.reset(new GameMap(tiles, map));
    
}


int main(int argc,  char * argv[])
{

    // insert code here...
    
    const unsigned int windowWidth = 1024;
    const unsigned int windowHeight = 768;
    
    glutInit(&argc, argv);
    
    alutInit(&argc, argv);
    
    glutInitWindowSize(windowWidth, windowHeight);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    glutCreateWindow("Tile Renderer Test");
    
    init();
    
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    
    glutKeyboardFunc(keyboard);
    
    glutIdleFunc(idle);
    
    glutMainLoop();
    
    
    return 0;
}

