
#ifdef _WIN32
  #include "zapi.h"
  #define EXPORT __declspec(dllexport)
#else
  #include "zapi.h"
  #define EXPORT
#endif
extern "C"
{

    EXPORT ZObject init();
    //Functions
    EXPORT ZObject setWindowSize(ZObject*,int);
    EXPORT ZObject closeWindow(ZObject*,int);
    EXPORT ZObject penUp(ZObject*,int);
    EXPORT ZObject penDOWN(ZObject*,int);
    EXPORT ZObject setPenSize(ZObject*,int);
    EXPORT ZObject left(ZObject*,int);
    EXPORT ZObject right(ZObject*,int);
    EXPORT ZObject setAngle(ZObject*,int);
    EXPORT ZObject forward(ZObject*,int);
    EXPORT ZObject backward(ZObject*,int);
    EXPORT ZObject GOTO(ZObject*,int);
    EXPORT ZObject moveto(ZObject*,int);
    EXPORT ZObject circle(ZObject*,int);
    EXPORT ZObject filled_circle(ZObject*,int);
    EXPORT ZObject fill(ZObject*,int);
    EXPORT ZObject setSpeed(ZObject*,int);
    EXPORT ZObject setBgColor(ZObject*,int);
    EXPORT ZObject hide(ZObject*,int);
    EXPORT ZObject show(ZObject*,int);
    EXPORT ZObject saveBMP(ZObject*,int);
    EXPORT ZObject setColor(ZObject*,int);
    EXPORT ZObject idle(ZObject*,int);
}
