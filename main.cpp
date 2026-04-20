#include <GLFW/glfw3.h>

int main() {
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(window)) {
    int width = 0;
    int height = 0;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.10f, 0.16f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    const float aspect = (height > 0) ? static_cast<float>(width) / static_cast<float>(height) : 1.0f;
    if (aspect >= 1.0f) {
      glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    } else {
      glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glColor3f(0.95f, 0.58f, 0.20f);
    glVertex2f(0.0f, 0.65f);
    glVertex2f(-0.65f, -0.60f);
    glVertex2f(0.65f, -0.60f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
