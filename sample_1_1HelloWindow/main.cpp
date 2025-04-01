#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;

void init(GLFWwindow* window) {};
void display(GLFWwindow* window, double currentTime) {
	//openGL调用glClearColor
	glClearColor(1.0, 0.7, 0.9,1.0);//指定清除背景时用的颜色值,(1,0,0,1)代表RGB值中的红色（末尾的1表示不透明度）
	glClear(GL_COLOR_BUFFER_BIT);//openGL调用，将颜色填充到缓冲区中
}

int main(void) {
	if (!glfwInit()) { exit(EXIT_FAILURE); }//GLFW库初始化
	/*WindowHints指定了机器必须与 OpenGL版本4.3兼容（“主版本号”=4，“次版本号”=3）*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	GLFWwindow* window = glfwCreateWindow(800, 600, "testColorShow", NULL, NULL);
	/*
	if (window == NULL) {
		cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	*/
	
	glfwMakeContextCurrent(window);//创建GLFW窗口并不会自动将它与当前 OpenGL上下文关联起来——因此我们需要调用 glfwMakeContextCurrent()

	if (glewInit() != GLEW_OK) { //初始化GLEW库
		cerr << "Failed to initialize GLEW" << endl;
		exit(EXIT_FAILURE); 
	}
	glfwSwapInterval(1);//glfwSwapInterval()和glfwSwapBuffers()用来开启垂直同步（Vsync）,GLFW窗口默认是双缓冲的

	init(window);
	//循环渲染，调用display（）方法
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());//用glfwGetTime()，它会返回 GLFW初始化之后经过的时间.将当前时间传入了display()调用，这样方便保证动画在不同计算机上以相同速度播放
		glfwSwapBuffers(window);//绘制屏幕
		glfwPollEvents();//处理窗口相关事件（如按键事件）当GLFW探测 到应该关闭窗口的事件（如用户单击了右上角的×）时，循环就会终止
	}
	glfwDestroyWindow(window);//GLFW销毁窗口
	glfwTerminate();//终止运行
	exit(EXIT_SUCCESS);
}