#include <FA/FAEngine.h>

    //message callback?
    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

FAEngine::FAEngine() {

}

FAEngine::FAEngine(HINSTANCE hInstance) {
    this->hInstance = hInstance;
}

void FAEngine::initLibraries() {
    // ilInit();
    //
    // ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    // ilEnable(IL_ORIGIN_SET);
    //
    // if (! glfwInit()) {
    //     std::cout << "GLFW Failed To Initialize" << std::endl;
    //     glfwTerminate();
    // }
}

float FAEngine::tpf() {
    // float currentTime = glfwGetTime();
    // float delta = currentTime - lastBufferedTime;
    // lastBufferedTime = currentTime;
    return 0.1;
}

void FAEngine::initEngine() {
    //Set some defaults to make sure everything works "Out of the box"

    this->windowWidth = 1024;
    this->windowHeight = 720;
    this->samples = 0;
    this->windowTitle = "FAGame";
    //this->windowColor = glm::vec3(0.5,0.5,0.5);
    // this->lastBufferedTime = glfwGetTime();
    // this->cursorState = GLFW_CURSOR_NORMAL;
    // this->position = glm::vec2(0,300);

    //Initialize the nesessary libraries for the FireArrowEngine

    initLibraries();

    setupWindow();

    setScene(setInitialScene());

    init();
}

void FAEngine::update() {
    activeScene->onUpdate(tpf());
}

void FAEngine::render() {
    // glClearColor(this->windowColor.r, this->windowColor.g, this->windowColor.b, 1.0);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // activeScene->onRender();
    // glfwPollEvents();
    // glfwSwapInterval(1);
    // glfwSwapBuffers(window);
}

void FAEngine::setWindowsSize(int width, int height) {
    this->windowWidth = width;
    this->windowHeight = height;
}

void FAEngine::setWindowTitle(std::string title) {
    this->windowTitle = title;
}

void FAEngine::setSamples(int sample) {
    this->samples = sample;
}

// void FAEngine::setWindowColor(glm::vec3 color) {
//     this->windowColor = color;
// }

void FAEngine::setDecorated(bool decoration) {
    this->isDecorated = decoration;
}

void FAEngine::setScene(FAScene* newScene) {
    // delete activeScene;
    activeScene = newScene;
    activeScene->setCallback(this);
    // activeScene->setShaderNode(shaders);
    activeScene->setWindowSize(windowWidth, windowHeight);
    activeScene->onInit();
}

void FAEngine::setCursorState(int state) {
    cursorState = state;
    // glfwSetInputMode(window, GLFW_CURSOR, state);
}

// void FAEngine::setPosition(float x, float y) {
//     this->position = glm::vec2(x, y);
// }

int FAEngine::getCursorState() {
    return this->cursorState;
}

void FAEngine::swapScene(FAScene* scene) {
    activeScene = scene;
}

// void FAEngine::key_callback(GLFWwindow* win, int key, int scancode, int action, int mods) {
//      FAEngine *engine =
//      static_cast<FAEngine*>(glfwGetWindowUserPointer(win));
//      if (key == GLFW_KEY_Q) {
//          if (action == GLFW_PRESS) {
//              glfwSetWindowShouldClose(win, 1);
//              return;
//          }
//      }
//
//      engine->forwardKeyInput(key, action);
// }
//
// void FAEngine::forwardKeyInput(int key, int action) {
//     activeScene->getKeyInput(key, action);
// }
//
// void FAEngine::mouse_key_callback(GLFWwindow* win, int button, int action, int mods) {
//     FAEngine *engine =
//     static_cast<FAEngine*>(glfwGetWindowUserPointer(win));
//     engine->forwardMouseKeyInput(button, action);
// }
//
// void FAEngine::forwardMouseKeyInput(int button, int action) {
//     activeScene->getMouseKeyInput(button, action);
// }
//
// void FAEngine::cursorPosition_callback(GLFWwindow* win, double x, double y) {
//     FAEngine *engine =
//     static_cast<FAEngine*>(glfwGetWindowUserPointer(win));
//     engine->forwardcursorPosition(x, y);
// }
//
// void FAEngine::forwardcursorPosition(double x, double y) {
//     activeScene->getCursorPosition(x, y);
// }
//
bool FAEngine::shouldTerminate() {
    // return !glfwWindowShouldClose(window);
    return false;
}

void FAEngine::setupWindow() {

  WNDCLASSEX wc;    //Create a new extended windows class

  	wc.cbSize = sizeof(WNDCLASSEX);    //Size of our windows class
  	wc.style = CS_HREDRAW | CS_VREDRAW;    //class styles
  	wc.lpfnWndProc = WndProc;    //Default windows procedure function
  	wc.cbClsExtra = NULL;    //Extra bytes after our wc structure
  	wc.cbWndExtra = NULL;    //Extra bytes after our windows instance
  	wc.hInstance = hInstance;    //Instance to current application
  	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);    //Title bar Icon
  	wc.hCursor = LoadCursor(NULL, IDC_ARROW);    //Default mouse Icon
  	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);    //Window bg color
  	wc.lpszMenuName = NULL;    //Name of the menu attached to our window
  	wc.lpszClassName = WndClassName;    //Name of our windows class
  	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); //Icon in your taskbar

  	if (!RegisterClassEx(&wc))    //Register our windows class
  	{
  		//if registration failed, display error
  		MessageBox(NULL, "Error registering class",
  			"Error", MB_OK | MB_ICONERROR);
  		return;
  	}

    hwnd = CreateWindowEx(    //Create our Extended Window
		NULL,    //Extended style
		WndClassName,    //Name of our windows class
		"Window Title",    //Name in the title bar of our window
		WS_OVERLAPPEDWINDOW,    //style of our window
		CW_USEDEFAULT, CW_USEDEFAULT,    //Top left corner of window
		this->windowWidth,    //Width of our window
		this->windowHeight,    //Height of our window
		NULL,    //Handle to parent window
		NULL,    //Handle to a Menu
		hInstance,    //Specifies instance of current program
		NULL    //used for an MDI client window
		);

	if (!hwnd)    //Make sure our window has been created
	{
		//If not, display error
		MessageBox(NULL, "Error creating window",
			"Error", MB_OK | MB_ICONERROR);
		return;
	}

	ShowWindow(hwnd, 1);    //Shows our window
	UpdateWindow(hwnd);    //Its good to update our window


//     setWindowAttributes();
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //something with forward compatible
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // no idea yet! TODO research
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //set opengl target 3.x
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2); //set opengl target x.2
//     glfwWindowHint(GLFW_SAMPLES, this->samples);
//     glfwWindowHint(GLFW_DECORATED, isDecorated);
// //    glfwWindowHint(GLFW_REFRESH_RATE, 100);
// //    int count;
// //    GLFWmonitor** monitors = glfwGetMonitors(&count);
// //    if (count > 1) {
// //        window = glfwCreateWindow(this->windowWidth, this->windowHeigth, this->windowTitle.c_str(), monitors[1], NULL);
// //    } else {
//         window = glfwCreateWindow(this->windowWidth, this->windowHeigth, this->windowTitle.c_str(), NULL, NULL);
// //    }
//
//     // Windows OS:
//     //GLFWwindow *window = glfwCreateWindow(1024, 720, "FireArrow Demo", glfwGetPrimaryMonitor(), NULL);
//     if (window == NULL) {
//         std::cout << "Window failed to create!" << std::endl;
//         glfwTerminate();
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetWindowUserPointer(window, this);
//     glfwSetKeyCallback(window, key_callback);
//     glfwSetMouseButtonCallback(window, mouse_key_callback);
//     glfwSetCursorPosCallback(window, cursorPosition_callback);
//     glfwSetInputMode(window, GLFW_CURSOR, cursorState);
//     glfwSetWindowPos(window, position.x, position.y);
//
// //    glEnable(GL_DEPTH_TEST);
//     glEnable(GL_TEXTURE_2D);
//     glDisable(GL_CULL_FACE);
//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//     glEnable(GL_DEPTH_TEST);
//     glDepthFunc(GL_LEQUAL);

}

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,	WPARAM wParam, LPARAM lParam) {
	switch (msg) {

	case WM_KEYDOWN:    //For a key down
						//if escape key was pressed, display popup box
		if (wParam == VK_ESCAPE) {
			if (MessageBox(0, "Are you sure you want to exit?",
				"Really?", MB_YESNO | MB_ICONQUESTION) == IDYES)

				//Release the windows allocated memory
				DestroyWindow(hwnd);
		}
		return 0;

	case WM_DESTROY:    //if x button in top right was pressed
		PostQuitMessage(0);
		return 0;
	}
	//return the message for windows to handle it
	return DefWindowProc(hwnd,
		msg,
		wParam,
		lParam);
}

FAScene* FAEngine::setInitialScene() {
    return new FAScene();
}

FAEngine::~FAEngine() {
    //Terminate Libraries
    // glfwTerminate();

    //dealloc objects
//    delete camera;
//    camera = nullptr;
//    delete activeScene;
//    activeScene = nullptr;
}
