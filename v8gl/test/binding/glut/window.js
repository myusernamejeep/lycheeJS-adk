
glut.init();


var id;
var windows = [];

glut.initDisplayMode(glut.RGB | glut.DEPTH);
glut.initWindowPosition(100, 100);
glut.initWindowSize(400, 400);

id = glut.createWindow("Toplevel window");

windows.push(id);


glut.setWindow(windows[0]);
glut.setWindowTitle("Toplevel Window (changed title)");

id = glut.createSubWindow(windows[0], 50, 50, 300, 300);

windows.push(id);

glut.setWindow(windows[1]);
glut.setWindowTitle("SubWindow");

id = glut.getWindow();

console.log('id:' + id);

console.debug(windows);

glut.mainLoop();

glut.destroyWindow(windows[0]);



