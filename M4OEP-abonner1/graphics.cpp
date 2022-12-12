#include "graphics.h"
#include "Button.h"
#include "Slime.h"
#include "EverythingSlime.h"
#include "FavoriteSlime.h"
#include "UniqueDietSlime.h"
#include "Food.h"


#include <memory>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
int points = 0;
int plorts = 0;
//Ints to hold the position of the selected slime and food within slimeVec and foodVec respectively
int slimePos;
int foodPos;
//The vectors of buttons made from slimeVec and foodVec respectively
vector<Button> slimes;
vector<Button> foods;
//The vectors of slimes and foods
vector<unique_ptr<Slime>> slimeVec;
vector<Food> foodVec;
//The string to hold the label of the pressed slime and food button respectively
string toFeed = "";
string meal = "";
enum screens{start, game, finish};
screens status = start;
//Toggle to decide whether or not the score will be displayed on screen
bool showScore = false;
int change = 0;


void init() {
    width = 500;
    height = 1000;
    srand(time(0));

    //Add slimes to slimeVec
    slimeVec.push_back(make_unique<EverythingSlime>("Pink Slime"));
    slimeVec.push_back(make_unique<UniqueDietSlime>("Puddle Slime", "water"));
    slimeVec.push_back(make_unique<UniqueDietSlime>("Fire Slime", "ash"));

    //Add foods to foodVec
    Food nothing("Nothing", "Nothing");
    foodVec.push_back(nothing);
    Food everything("Everything", "Everything");
    foodVec.push_back(everything);
    Food water("Unique", "Water");
    foodVec.push_back(water);
    Food ash("Unique", "Ash");
    foodVec.push_back(ash);
    Food seaHen("Meat", "Sea Hen");
    foodVec.push_back(seaHen);
    Food Hen("Meat", "Hen Hen");
    foodVec.push_back(Hen);
    Food parsnip("Veggie", "Silver Parsnip");
    foodVec.push_back(parsnip);
    Food carrot("Veggie", "Carrot");
    foodVec.push_back(carrot);
    Food cuberry("Fruit", "Cuberry");
    foodVec.push_back(cuberry);
    Food pogofruit("Fruit", "Pogofruit");
    foodVec.push_back(pogofruit);

    //Add FavoriteSlimes to slimeVec
    slimeVec.push_back(make_unique<FavoriteSlime>("Angler Slime", seaHen));
    slimeVec.push_back(make_unique<FavoriteSlime>("Mosaic Slime", parsnip));
    slimeVec.push_back(make_unique<FavoriteSlime>("Phosphor Slime", cuberry));

    //Populate slimes
    for(int i = 0; i < slimeVec.size(); i++)
    {
        slimes.push_back(Button({106/255.0, 206/255.0, 224/255.0}, {150, 50 + 100 * i}, 150, 50, slimeVec[i]->getName()));
    }

    //Populate foods
    for(int i = 0; i < foodVec.size(); i++)
    {
        foods.push_back(Button({106/255.0, 206/255.0, 224/255.0}, {350, 50 + 100 * i}, 150, 50,foodVec[i].getName()));
    }

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(198/255.0, 79/255.0, 85/255.0, 1.0f);
}


/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing

    if (status == start) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        string instr1 = "Match the slime to its favorite food!";
        glRasterPos2i(105, 194);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < instr1.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, instr1[i]);
        }
        string instr2 = "First, pick a slime from the left column!";
        glRasterPos2i(95, 206);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < instr2.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, instr2[i]);
        }
        string instr3 = "Then, pick its favorite food from the right column!";
        glRasterPos2i(45, 218);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < instr3.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, instr3[i]);
        }
        string begin = "Press 'enter' to start";
        glRasterPos2i(145, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < begin.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, begin[i]);
        }
        glFlush();
    }

    if (status == game) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //Draw the buttons in slimes and foods
        for(int i = 0; i < slimes.size(); i++)
        {
            slimes[i].draw();
        }
        for(int i = 0; i < foods.size(); i++)
        {
            foods[i].draw();
        }

        //When a button from slimes and foods have been pressed, determine how many points and plorts to award the guess
        if(toFeed != "" && meal != "") {
            //Find the slime and food chose from their respective vectors
            for (int i = 0; i < slimes.size(); i++) {
                if (toFeed == slimeVec[i]->getName()) {
                    slimePos = i;
                }
            }
            for (int i = 0; i < foods.size(); i++) {
                if (meal == foodVec[i].getName()) {
                    foodPos = i;
                }
            }

            //Feed the food to the slime and determine how many points and plorts are produced
            int plortsOut = slimeVec[slimePos]->feed(foodVec[foodPos]);
            plorts += plortsOut;
            //If 2 plorts are produced, the match was good, award 1 point
            if (plortsOut == 2) {
                points++;
            }
            //If no plorts are produced and the food guessed was nothing, determine if the slime guessed has a favorite food
            if (plortsOut == 0 && meal == "Nothing") {
                int testPlorts = 0;
                bool favorite = false;
                //Loop through foods and feed every food to the slime to see if it has a favorite food
                for (int i = 0; i < foods.size(); i++) {
                    testPlorts = 0;
                    testPlorts += slimeVec[slimePos]->feed(foodVec[i]);
                    if (testPlorts == 2) {
                        favorite = true;
                    }

                }
                //If the slime has no favorite food, award 1 point
                if (!favorite) {
                    points++;
                }
            }

            //Remove the guessed slime and food (unless the food is nothing or everything) from their respective vectors
            slimes.erase(slimes.begin() + slimePos);
            slimeVec.erase(slimeVec.begin() + slimePos);
            if (meal != "Nothing" && meal != "Everything") {
                foods.erase(foods.begin() + foodPos);
                foodVec.erase(foodVec.begin() + foodPos);
            }
            //Reset the strings to hold the guesses to empty
            toFeed = "";
            meal = "";
        }

        //Show the score if the toggle is true
        if(showScore)
        {
            string direction = "Points: " + to_string(points);
            glRasterPos2i(10, 990);
            glColor3f(1.0f, 1.0f, 1.0f);
            for (const char &letter: direction) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
        }

        //When every slime has been guessed, the game is over
        if(slimes.size() == 0)
        {
            status = finish;
        }
        glFlush();
    }

    if (status == finish) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height/2, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //Display the final points earned, and then the final amount of plorts produced
        string finalPoints = "You earned " + to_string(points) + " points!";
        glRasterPos2i(150, 225);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (const char &letter: finalPoints) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
        string finalPlorts = "You earned " + to_string(plorts) + " plorts!";
        glRasterPos2i(150, 235);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (const char &letter: finalPlorts) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
        glFlush();
    }
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27 || key == 8) {
        glutDestroyWindow(wd);
        exit(0);
    }
    // start the game
    if (status == start && key == 13) {
        status = game;
    }
    // change the toggle showScore when s is pressed while in the game
    int state;
    if(status == game && (key == 83 || key == 115)) {
        showScore = !showScore;
    }
    
    glutPostRedisplay();
}


/*void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            spawn.move(0, 1);
            break;
        case GLUT_KEY_LEFT:
            spawn.move(-1, 0);
            break;
        case GLUT_KEY_RIGHT:
            spawn.move(1, 0);
            break;
        case GLUT_KEY_UP:
            spawn.move(0, -1);
            break;
    }

    glutPostRedisplay();
}*/

void cursor(int x, int y) {
    /*
     * If the x, y passed in overlap with a button in either slimes or food, that button should be hovered over
     */
    for(int i = 0; i < slimes.size(); i++)
    {
        if (slimes[i].isOverlapping(x, y)) {
            slimes[i].hover();
        }
        else {
            slimes[i].release();
        }
    }
    for(int i = 0; i < foods.size(); i++)
    {
        if (foods[i].isOverlapping(x, y)) {
            foods[i].hover();
        }
        else {
            foods[i].release();
        }
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    /*
     * if the left button is down and the x, y overlap with a button in slimes or food, the label of that button should be stored in either toFeed or meal respectively
     */
    for(int i = 0; i < slimes.size(); i++)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slimes[i].isOverlapping(x, y)) {
            slimes[i].pressDown();
            toFeed = slimes[i].getLabel();
        }
    }
    for(int i = 0; i < foods.size(); i++)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && foods[i].isOverlapping(x, y)) {
            foods[i].pressDown();
            meal = foods[i].getLabel();
        }
    }
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(1000, 50); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Slime Matcher!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    //glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
