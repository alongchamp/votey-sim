
#include "graphics.h"
#include "shapes.h"
#include "votey.h"

enum screen_state { menu, game_play, pause, game_over };

GLdouble width, height;
int wd;
int mouse_x, mouse_y;
screen_state screen;

Rectangle_Coord r, r2, r3, r4, r5, r6;
Circle_Coord c, c2, c3, c4, c5;
Trainer t;
Student StudentA("What is the answer to 40 + 2?", "Web Design");
Student StudentB("How do you find the shortest path?", "Algorithms");
Student StudentC("How do you find the secret key <d,n> in RSA?", "Cryptography");
Student StudentD("Why does my code have an error?", "Java");
Student StudentE("What do I do to make multiple routines or different types work at different times?", "C++");

int circle_leap = 10;

// if the rectangle is overlapping the point (x,y),
// set the rectangle color to blue.
// otherwise set the rectangle color to green.
void update_rectangle(int x, int y) {
	/*if (r.is_overlapping(x, y)) {
		r.set_color(0, 0, 1);
	}
	else {
		r.set_color(0, 1, 0);
	}*/
}

/* START HELPER DISPLAY FUNCTIONS */

void display_menu() {
	// draw a string message
	string message = "Click anywhere to begin";
	glColor3f(1, 1, 1);
	glRasterPos2i((int)width/2.6, (int)height/2);
	for (int i = 0; i < message.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
	}
}

void display_game() {
	// draw circle and rectangle
	//c.draw();
	r.draw();
	

	if (r.is_overlapping(r2)) {
		r2.set_color(0, 0, 0);
		// draw a string message
		// string message = "You win!    JK";
		glColor3f(1, 1, 0);
		glRasterPos2i(25, ((int)height * 3.5) / 4);
		for (int i = 0; i < StudentA.getQuestion().length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentA.getQuestion()[i]);
		}
		c.draw();
		c2.draw();
		c3.draw();
		c4.draw();
		c5.draw();
	}
	else if (r.is_overlapping(r3)) {
		r3.set_color(0, 0, 0);
		// draw a string message
		//string message = "You win!    JK";
		glColor3f(1, 1, 0);
		glRasterPos2i(25, ((int)height * 3.5) / 4);
		for (int i = 0; i < StudentB.getQuestion().length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentB.getQuestion()[i]);
		}
		c.draw();
		c2.draw();
		c3.draw();
		c4.draw();
		c5.draw();
	}
	else if (r.is_overlapping(r4)) {
		r4.set_color(0, 0, 0);
		// draw a string message
		//string message = "You win!    JK";
		glColor3f(1, 1, 0);
		glRasterPos2i(25, ((int)height * 3.5) / 4);
		for (int i = 0; i < StudentC.getQuestion().length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentC.getQuestion()[i]);
		}
		c.draw();
		c2.draw();
		c3.draw();
		c4.draw();
		c5.draw();
	}
	else if (r.is_overlapping(r5)) {
		r5.set_color(0, 0, 0);
		// draw a string message
		//string message = "You win!    JK";
		glColor3f(1, 1, 0);
		glRasterPos2i(25, ((int)height * 3.5) / 4);
		for (int i = 0; i < StudentD.getQuestion().length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentD.getQuestion()[i]);
		}
		c.draw();
		c2.draw();
		c3.draw();
		c4.draw();
		c5.draw();
	}
	else if (r.is_overlapping(r6)) {
		r6.set_color(0, 0, 0);
		// draw a string message
		//string message = "You win!    JK";
		glColor3f(1, 1, 0);
		glRasterPos2i(25, ((int)height * 3.5) / 4);
		for (int i = 0; i < StudentE.getQuestion().length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentE.getQuestion()[i]);
		}
		c.draw();
		c2.draw();
		c3.draw();
		c4.draw();
		c5.draw();
	}
	
	else {
		r2.set_color(0, 0, 1);
		r3.set_color(0, 0, 1);
		r4.set_color(0, 0, 1);
		r5.set_color(0, 0, 1);
		r6.set_color(0, 0, 1);
	}

	r2.draw();
	r3.draw();
	r4.draw();
	r5.draw();
	r6.draw();

	/*if (c2.is_overlapping(c)) {
		c2.set_radius(c2.get_radius() - 2);
		if (c2.get_radius() == 0) {
			screen = game_over;
		}
	}

	if (c2.is_overlapping(r2)) {
		c2.set_outside_color(1, 1, 1);
	}
	else {
		c2.set_outside_color(0, 0, 0);
	}*/

	//c2.draw();

	// draw outer rectangle as outside boundry
	// bottom
	glLineWidth(5);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex3f(0, ((int)height * 2) / 3, 0);
	glVertex3f((int)width, ((int)height * 2) / 3, 0);
	glEnd();

	// top
	glLineWidth(10);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f((int)width,0, 0);
	glEnd();

	// left
	glLineWidth(10);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, ((int)height * 2) / 3, 0);
	glEnd();

	// right
	glLineWidth(10);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f((int)width, 0, 0);
	glVertex3f((int)width, ((int)height * 2) / 3, 0);
	glEnd();

	// draw inner rectange as inside boundry
	// bottom
	glLineWidth(5);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(((int)width * 1) / 6, ((int)height * 3) / 6, 0);
	glVertex3f(((int)width * 5) / 6, ((int)height * 3) / 6, 0);
	glEnd();

	// top
	glLineWidth(5);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(((int)width * 1) / 6, ((int)height * 1) / 6, 0);
	glVertex3f(((int)width * 5) / 6, ((int)height * 1) / 6, 0);
	glEnd();

	// left
	glLineWidth(5);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(((int)width * 1) / 6, ((int)height * 1) / 6, 0);
	glVertex3f(((int)width * 1) / 6, ((int)height * 3) / 6, 0);
	glEnd();

	// right
	glLineWidth(5);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(((int)width * 5) / 6, ((int)height * 1) / 6, 0);
	glVertex3f(((int)width * 5) / 6, ((int)height * 3) / 6, 0);
	glEnd();

	// question/professor line
	glLineWidth(10);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(((int)width * 4) / 6, ((int)height * 2) / 3, 0);
	glVertex3f(((int)width * 4) / 6, (int)height, 0);
	glEnd();
}

void display_game_over() {
	// draw a string message
	string message = "You win!    JK";
	glColor3f(1, 1, 0);
	glRasterPos2i(100, 250);
	for (int i = 0; i < StudentA.getQuestion().length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, StudentA.getQuestion()[i]);
	}

}

void display_key() {
	string message = "Jackie";
	glColor3f(0, 1, 1);
	glRasterPos2i((((int)width * 4) / 6) + 50, (((int)height * 2) / 3) + 30);
	for (int i = 0; i < message.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
	}
	string message1 = "Lisa";
	glColor3f(0, 1, 1);
	glRasterPos2i((((int)width * 4) / 6) + 50, (((int)height * 2) / 3) + 70);
	for (int i = 0; i < message1.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message1[i]);
	}
	string message2 = "Bob";
	glColor3f(0, 1, 1);
	glRasterPos2i((((int)width * 4) / 6) + 50, (((int)height * 2) / 3) + 110);
	for (int i = 0; i < message2.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
	}
	string message3 = "Byung";
	glColor3f(0, 1, 1);
	glRasterPos2i((((int)width * 4) / 6) + 50, (((int)height * 2) / 3) + 150);
	for (int i = 0; i < message3.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message3[i]);
	}
	string message4 = "Ling";
	glColor3f(0, 1, 1);
	glRasterPos2i((((int)width * 4) / 6) + 50, (((int)height * 2) / 3) + 190);
	for (int i = 0; i < message4.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message4[i]);
	}
}

/* END HELPER DISPLAY FUNCTIONS */

void init() {
	width = glutGet(GLUT_SCREEN_WIDTH) / 1.5;
	height = glutGet(GLUT_SCREEN_HEIGHT) / 1.5;

	screen = menu;

	mouse_x = mouse_y = 0;

	// initialize rectangle fields
	r.set_width(50);
	r.set_length(40);
	// set color to green
	r.set_color(0.0f, 1.0f, 0.0f);

	r2.set_width(50);
	r2.set_length(40);
	r2.set_top_left(100, 50);
	// set color to blue
	r2.set_color(0.0f, 0.0f, 1.0f);

	r3.set_width(50);
	r3.set_length(40);
	r3.set_top_left(900, 400);
	// set color to blue
	r3.set_color(0.0f, 0.0f, 1.0f);

	r4.set_width(50);
	r4.set_length(40);
	r4.set_top_left(50, 300);
	// set color to blue
	r4.set_color(0.0f, 0.0f, 1.0f);

	r5.set_width(50);
	r5.set_length(40);
	r5.set_top_left(600, 50);
	// set color to blue
	r5.set_color(0.0f, 0.0f, 1.0f);

	r6.set_width(50);
	r6.set_length(40);
	r6.set_top_left(1200, 150);
	// set color to blue
	r6.set_color(0.0f, 0.0f, 1.0f);

	// initalize circle fields
	// outside color will be seafoam green
	c.set_outside_color((112.0 / 255), (217.0 / 255), (169.0 / 255));
	// fill color will be coral
	c.set_color((248.0 / 255), (131.0 / 255), (121.0 / 255));
	c.set_center((((int)width * 4) / 6) + 25, (((int)height * 2) / 3) + 63);
	c.set_radius(10);

	// outside color will be black
	c2.set_outside_color(0, 191, 255);
	// fill color will be coral
	c2.set_color(0, 191, 255);
	c2.set_center((((int)width * 4) / 6) + 25, (((int)height * 2) / 3) + 23);
	c2.set_radius(10);

	// outside color will be black
	c3.set_outside_color(255, 140, 0);
	// fill color will be coral
	c3.set_color(255, 140, 0);
	c3.set_center((((int)width * 4) / 6) + 25, (((int)height * 2) / 3) + 103);
	c3.set_radius(10);

	// outside color will be black
	c4.set_outside_color(230, 230, 250);
	// fill color will be coral
	c4.set_color(230, 230, 250);
	c4.set_center((((int)width * 4) / 6) + 25, (((int)height * 2) / 3) + 143);
	c4.set_radius(10);

	// outside color will be black
	c5.set_outside_color(255, 0, 255);
	// fill color will be coral
	c5.set_color(255, 0, 255);
	c5.set_center((((int)width * 4) / 6) + 25, (((int)height * 2) / 3) + 183);
	c5.set_radius(10);
}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glColor3f(0.0f, 0.0f, 1.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	// tell OpenGL to use the whole window for drawing
	glViewport(0, 0, width, height);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.f, 1.f);



	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// TIME TO DRAW

	switch (screen) {
	case menu:
		display_menu();
		break;
	case game_play:
		display_game();
		display_key();
		break;
	case game_over:
		display_game_over();
		break;
	}



	glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
	// escape
	if (key == 27) {
		glutDestroyWindow(wd);
		string name;
		cout << "Please enter your name: ";
		cin >> name;
		Instance i;
		i.Save(t.getScore(), name);
		cout << endl;
		i.lookUp();
		cout << endl;
		exit(0);
	}
}

void kbdS(int key, int x, int y) {
	if (screen == game_play) {
		switch (key) {
		case GLUT_KEY_DOWN:
			if (r.get_bottom_left_y() < ((int)height * 4) / 6) {
				r.move(0, circle_leap);
			}
			break;
		case GLUT_KEY_LEFT:
			if (r.get_bottom_left_x() > 0) {
				r.move(-circle_leap, 0);
			}
			break;
		case GLUT_KEY_RIGHT:
			if (r.get_top_right_x() < (int)width) {
				r.move(circle_leap, 0);
			}
			break;
		case GLUT_KEY_UP:
			if (r.get_top_right_y() > 0) {
				r.move(0, -circle_leap);
			}
			break;
		}
	}
	glutPostRedisplay();

	return;
}


void cursor(int x, int y) {
	//r.set_top_left(x, y);
	mouse_x = x;
	mouse_y = y;

	if (screen == game_play) {
		//update_rectangle(x, y);


		// change color maggies square when you hover over it
		if (r.is_overlapping(x, y)) {
			r.set_color(1, 0, 1);
		}
		else {
			r.set_color(0, 1, 0);
		}
	}

	glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		// Professor Lisa Dion
		if (((c.get_center_x() - 10) < x) && (x < (c.get_center_x() + 10)) && ((c.get_center_y() - 10) < y) && (y < (c.get_center_y() + 10))) {
			if (r.is_overlapping(r2) && StudentA.getAnswered()) {
				cout << t.Talk(0, StudentA) << endl;
			}
			if (r.is_overlapping(r3) && StudentB.getAnswered()) {
				cout << t.Talk(0, StudentB) << endl;
			}

			if (r.is_overlapping(r4) && StudentC.getAnswered()) {
				cout << t.Talk(0, StudentC) << endl;
			}
			if (r.is_overlapping(r5) && StudentD.getAnswered()) {
				cout << t.Talk(0, StudentD) << endl;
			}
			if (r.is_overlapping(r6) && !StudentE.getAnswered()) {
				cout << t.Talk(0, StudentE) << endl;
				StudentE.setAnswered();
			}
		}
		// Professsor Jackie Horton
		if (((c2.get_center_x() - 10) < x) && (x < (c2.get_center_x() + 10)) && ((c2.get_center_y() - 10) < y) && (y < (c2.get_center_y() + 10))) {
			if (r.is_overlapping(r2) && StudentA.getAnswered()) {
				cout << t.Talk(1, StudentA) << endl;
			}
			if (r.is_overlapping(r3) && StudentB.getAnswered()) {
				cout << t.Talk(1, StudentB) << endl;
			}

			if (r.is_overlapping(r4) && StudentC.getAnswered()) {
				cout << t.Talk(1, StudentC) << endl;
			}
			if (r.is_overlapping(r5) && !StudentD.getAnswered()) {
				cout << t.Talk(1, StudentD) << endl;
				StudentD.setAnswered();
			}
			if (r.is_overlapping(r6) && !StudentE.getAnswered()) {
				cout << t.Talk(1, StudentE) << endl;
			}
		}
		// Professor Bob Erickson
		if (((c3.get_center_x() - 10) < x) && (x < (c3.get_center_x() + 10)) && ((c3.get_center_y() - 10) < y) && (y < (c3.get_center_y() + 10))) {
			if (r.is_overlapping(r2) && !StudentA.getAnswered()) {
				cout << t.Talk(2, StudentA) << endl;
				StudentA.setAnswered();
			}
			if (r.is_overlapping(r3) && StudentB.getAnswered()) {
				cout << t.Talk(2, StudentB) << endl;
			}

			if (r.is_overlapping(r4) && StudentC.getAnswered()) {
				cout << t.Talk(2, StudentC) << endl;
			}
			if (r.is_overlapping(r5) && StudentD.getAnswered()) {
				cout << t.Talk(2, StudentD) << endl;
			}
			if (r.is_overlapping(r6) && !StudentE.getAnswered()) {
				cout << t.Talk(2, StudentE) << endl;
			}
		}
		// Professor Byung Lee
		if (((c4.get_center_x() - 10) < x) && (x < (c4.get_center_x() + 10)) && ((c4.get_center_y() - 10) < y) && (y < (c4.get_center_y() + 10))) {
			if (r.is_overlapping(r2) && StudentA.getAnswered()) {
				cout << t.Talk(3, StudentA) << endl;
			}
			if (r.is_overlapping(r3) && !StudentB.getAnswered()) {
				cout << t.Talk(3, StudentB) << endl;
				StudentB.setAnswered();
			}

			if (r.is_overlapping(r4) && StudentC.getAnswered()) {
				cout << t.Talk(3, StudentC) << endl;
			}
			if (r.is_overlapping(r5) && StudentD.getAnswered()) {
				cout << t.Talk(3, StudentD) << endl;
			}
			if (r.is_overlapping(r6) && !StudentE.getAnswered()) {
				cout << t.Talk(3, StudentE) << endl;
			}
		}
		// Professor Alan Ling
		if (((c5.get_center_x() - 10) < x) && (x < (c5.get_center_x() + 10)) && ((c5.get_center_y() - 10) < y) && (y < (c5.get_center_y() + 10))) {
			if (r.is_overlapping(r2) && StudentA.getAnswered()) {
				cout << t.Talk(4, StudentA) << endl;
			}
			if (r.is_overlapping(r3) && StudentB.getAnswered()) {
				cout << t.Talk(4, StudentB) << endl;
			}

			if (r.is_overlapping(r4) && !StudentC.getAnswered()) {
				cout << t.Talk(4, StudentC) << endl;
				StudentC.setAnswered();
			}
			if (r.is_overlapping(r5) && StudentD.getAnswered()) {
				cout << t.Talk(4, StudentD) << endl;
			}
			if (r.is_overlapping(r6) && !StudentE.getAnswered()) {
				cout << t.Talk(4, StudentE) << endl;
			}
		}
		cout << "Score: " << t.getScore() << endl;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&screen == menu) {
		screen = game_play;
	}

	glutPostRedisplay();
}

void timer(int extra) {
	if (screen == game_play && r.get_top_left_x() + r.get_width() < width) {
		//r.move(5, 0);
		update_rectangle(mouse_x, mouse_y);
	}

	glutTimerFunc(30, timer, 0);
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

	init();

	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize((int)width, (int)height);
	glutInitWindowPosition((int)width / 4, (int)height / 4); // Position the window's initial top-left corner
															 /* create the window and store the handle to it */
	wd = glutCreateWindow("Graphics!" /* title */);

	// Register callback handler for window re-paint event
	glutDisplayFunc(display);

	// Our own OpenGL initialization
	initGL();

	// register keyboard press event processing function
	// works for numbers, letters, spacebar, etc.
	glutKeyboardFunc(kbd);

	// register special event: function keys, arrows, etc.
	glutSpecialFunc(kbdS);

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