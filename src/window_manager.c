#include "../include/window_manager.h"

Window createWindow(int width, int height, const char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    Window win;
    win.window = glfwCreateWindow(width, height, title, NULL, NULL);

    if(win.window == NULL){
        glfwTerminate();
    }
    glfwMakeContextCurrent(win.window);


    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        glfwTerminate();
    }

    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    
    return win;
}

int isClosedWindow(Window* win){
    return glfwWindowShouldClose(win->window);
}

void clearDisplay(){
    glClearColor(0.2f, 0.2f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void updateWindow(Window* win){
    glfwSwapBuffers(win->window);
    glfwPollEvents();
}

void _frameBufferSizeCallback(GLFWwindow* win, int w, int h){
    glViewport(0, 0, w, h);
}

void processInput(Window* win){
    if(glfwGetKey(win->window, GLFW_KEY_A) == GLFW_PRESS){win->input.a = 1;}else{win->input.a = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_B) == GLFW_PRESS){win->input.b = 1;}else{win->input.b = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_C) == GLFW_PRESS){win->input.c = 1;}else{win->input.c = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_D) == GLFW_PRESS){win->input.d = 1;}else{win->input.d = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_E) == GLFW_PRESS){win->input.e = 1;}else{win->input.e = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_F) == GLFW_PRESS){win->input.f = 1;}else{win->input.f = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_G) == GLFW_PRESS){win->input.g = 1;}else{win->input.g = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_H) == GLFW_PRESS){win->input.h = 1;}else{win->input.h = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_I) == GLFW_PRESS){win->input.i = 1;}else{win->input.i = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_J) == GLFW_PRESS){win->input.j = 1;}else{win->input.j = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_K) == GLFW_PRESS){win->input.k = 1;}else{win->input.k = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_L) == GLFW_PRESS){win->input.l = 1;}else{win->input.l = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_M) == GLFW_PRESS){win->input.m = 1;}else{win->input.m = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_N) == GLFW_PRESS){win->input.n = 1;}else{win->input.n = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_O) == GLFW_PRESS){win->input.o = 1;}else{win->input.o = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_P) == GLFW_PRESS){win->input.p = 1;}else{win->input.p = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_Q) == GLFW_PRESS){win->input.q = 1;}else{win->input.q = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_R) == GLFW_PRESS){win->input.r = 1;}else{win->input.r = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_S) == GLFW_PRESS){win->input.s = 1;}else{win->input.s = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_T) == GLFW_PRESS){win->input.t = 1;}else{win->input.t = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_U) == GLFW_PRESS){win->input.u = 1;}else{win->input.u = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_V) == GLFW_PRESS){win->input.v = 1;}else{win->input.v = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_W) == GLFW_PRESS){win->input.w = 1;}else{win->input.w = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_X) == GLFW_PRESS){win->input.x = 1;}else{win->input.x = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_Y) == GLFW_PRESS){win->input.y = 1;}else{win->input.y = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_Z) == GLFW_PRESS){win->input.z = 1;}else{win->input.z = 0;}

    if(glfwGetKey(win->window, GLFW_KEY_ESCAPE) == GLFW_PRESS){win->input.esc = 1;}else{win->input.esc = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_SPACE) == GLFW_PRESS){win->input.space = 1;}else{win->input.space = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_ENTER) == GLFW_PRESS){win->input.enter = 1;}else{win->input.enter = 0;}

    if(glfwGetKey(win->window, GLFW_KEY_0) == GLFW_PRESS){win->input.n0 = 1;}else{win->input.n0 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_1) == GLFW_PRESS){win->input.n1 = 1;}else{win->input.n1 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_2) == GLFW_PRESS){win->input.n2 = 1;}else{win->input.n2 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_3) == GLFW_PRESS){win->input.n3 = 1;}else{win->input.n3 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_4) == GLFW_PRESS){win->input.n4 = 1;}else{win->input.n4 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_5) == GLFW_PRESS){win->input.n5 = 1;}else{win->input.n5 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_6) == GLFW_PRESS){win->input.n6 = 1;}else{win->input.n6 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_7) == GLFW_PRESS){win->input.n7 = 1;}else{win->input.n7 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_8) == GLFW_PRESS){win->input.n8 = 1;}else{win->input.n8 = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_9) == GLFW_PRESS){win->input.n9 = 1;}else{win->input.n9 = 0;}

    if(glfwGetKey(win->window, GLFW_KEY_RIGHT) == GLFW_PRESS){win->input.arrow_right = 1;}else{win->input.arrow_right = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_DOWN) == GLFW_PRESS){win->input.arrow_down = 1;}else{win->input.arrow_down = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_LEFT) == GLFW_PRESS){win->input.arrow_left = 1;}else{win->input.arrow_left = 0;}
    if(glfwGetKey(win->window, GLFW_KEY_UP) == GLFW_PRESS){win->input.arrow_up = 1;}else{win->input.arrow_up = 0;}

    if(glfwGetMouseButton(win->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){win->input.fire1 = 1;}else{win->input.fire1 = 0;}
    if(glfwGetMouseButton(win->window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS){win->input.fire2 = 1;}else{win->input.fire2 = 0;}
    glfwGetCursorPos(win->window, &(win->input.mouseX), &(win->input.mouseY));
}

void fprocessWindow(){
    gltTerminate();
    glfwTerminate();
}

