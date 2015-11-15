#ifndef __First__FAEngine__
#define __First__FAEngine__

#include <stdio.h>
#include <string>
#include <windows.h>
#include "FAScene.h"
#include "FireArrow.h"

class FAEngine {

private:

//    static FAEngine instance;

    FAScene* activeScene;
    LPCTSTR WndClassName = "FAWindow";
    HWND hwnd = NULL;

    bool shouldQuit = false;
    // GLFWwindow* window;


    float lastBufferedTime;


    void initLibraries();
    float tpf();
    void setupWindow();

public:

    HINSTANCE hInstance;

    FAEngine();
    FAEngine(HINSTANCE hInstance);

    void update();
    void render();
    void run();

    void setWindowsSize(int width, int height);
    void setWindowTitle(std::string title);
    void setSamples(int sample);
    // void setWindowColor(glm::vec3 color);
    void setDecorated(bool decoration);
    void setScene(FAScene* scene);
    void setCursorState(int state);
    // void setPosition(float x, float y);

    int getCursorState();

    void initEngine();

    void swapScene(FAScene* scene);

    // static void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);
    // void forwardKeyInput(int key, int action);
    // static void mouse_key_callback(GLFWwindow* win, int button, int action, int mods);
    // void forwardMouseKeyInput(int button, int action);
    // static void cursorPosition_callback(GLFWwindow* win, double x, double y);
    // void forwardcursorPosition(double x, double y);

    virtual void setWindowAttributes(){}

    virtual ~FAEngine();

protected:

    int windowWidth;
    int windowHeight;
    int samples;
    std::string windowTitle;
    // glm::vec3 windowColor;
    bool isDecorated;
    int cursorState;
    // glm::vec2 position;

    virtual FAScene* setInitialScene();
    virtual void init(){}
};

#endif /* defined(__FireArrow__FAEngine__) */
