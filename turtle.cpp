#include "turtle.h"
#include "CTurtle-master/turtle.h"

using namespace std;
ZObject nil;
ZObject init()
{
    nil.type = 'n';
    Module* d = vm_allocModule();
    d->name = "turtle";
    d->members.emplace(("setWindowSize"), ZObjFromFunction("turtle.setWindowSize", &setWindowSize));
    d->members.emplace(("closeWindow"), ZObjFromFunction("turtle.closeWindow", &closeWindow));
    d->members.emplace(("penUp"), ZObjFromFunction("turtle.penUp", &penUp));
    d->members.emplace(("penDown"), ZObjFromFunction("turtle.penDown", &penDOWN));
    d->members.emplace(("setPenSize"), ZObjFromFunction("turtle.setPenSize", &setPenSize));
    d->members.emplace(("goto"), ZObjFromFunction("turtle.goto", &GOTO));
    d->members.emplace(("moveto"), ZObjFromFunction("turtle.moveto", &moveto));
    d->members.emplace(("left"), ZObjFromFunction("turtle.left", &left));
    d->members.emplace(("right"), ZObjFromFunction("turtle.right", &right));
    d->members.emplace(("forward"), ZObjFromFunction("turtle.forward", &forward));
    d->members.emplace(("backward"), ZObjFromFunction("turtle.backward", &backward));
    d->members.emplace(("setAngle"), ZObjFromFunction("turtle.setAngle", &setAngle));
    d->members.emplace(("circle"), ZObjFromFunction("turtle.circle", &circle));
    d->members.emplace(("filled_circle"), ZObjFromFunction("turtle.filled_circle", &filled_circle));
    d->members.emplace(("setBgColor"), ZObjFromFunction("turtle.setBgColor", &setBgColor));
    d->members.emplace(("setSpeed"), ZObjFromFunction("turtle.setSpeed", &setSpeed));
    d->members.emplace(("hide"), ZObjFromFunction("turtle.hide", &hide));
    d->members.emplace(("show"), ZObjFromFunction("turtle.show", &show));
    d->members.emplace(("fill"), ZObjFromFunction("turtle.fill", &fill));
    d->members.emplace(("saveBMP"), ZObjFromFunction("turtle.saveBMP", &saveBMP));
    d->members.emplace(("setColor"), ZObjFromFunction("turtle.setColor", &setColor));
    d->members.emplace(("done"), ZObjFromFunction("turtle.done", &idle));

    return ZObjFromModule(d);
}
ZObject setWindowSize(ZObject* args,int n)
{
    if(n!=2)
    {
        return Z_Err(ArgumentError,"2 arguments needed!");
        
    }
    if(args[0].type!='i' || args[1].type!='i')
    {
        return Z_Err(TypeError,"2 integer arguments needed!");
        
    }
    if(args[0].i < 0 || args[1].i <0)
    {
        return Z_Err(ValueError,"Integer argument are negative! ");
        
    }
    if (t_init(args[0].i,args[1].i,window)!=0)
    {
       return Z_Err(Error,"Error initializing window.");
       
    }
    return nil;
}
ZObject setBgColor(ZObject* args,int n)
{
    if(n!=3)
    {
        return Z_Err(ArgumentError,"3 arguments needed!");
        
    }
    if(args[0].type!='i' || args[1].type!='i' || args[2].type!='i')
    {
        return Z_Err(TypeError,"3 integer arguments needed!");
        
    }
    if(args[0].i < 0 || args[1].i <0 || args[2].i < 0  || args[0].i > 255 || args[1].i >255 || args[2].i > 255 )
    {
        return Z_Err(ValueError,"Invalid Arguments!");
        
    }
    t_bkgColor(args[0].i,args[1].i,args[2].i);
    return nil;
}
ZObject setColor(ZObject* args,int n)
{
    if(n!=3)
    {
        return Z_Err(ArgumentError,"3 arguments needed!");
        
    }
    if(args[0].type!='i' || args[1].type!='i' || args[2].type!='i')
    {
        return Z_Err(TypeError,"3 integer arguments needed!");
        
    }
    if(args[0].i < 0 || args[1].i <0 || args[2].i < 0  || args[0].i > 255 || args[1].i >255 || args[2].i > 255 )
    {
        return Z_Err(ValueError,"Invalid Arguments!");
        
    }
    t_turColor(args[0].i,args[1].i,args[2].i);
    return nil;
}
ZObject closeWindow(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_close();
    return nil;
}
ZObject fill(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_fill();
    return nil;
}
ZObject show(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_showTurtle();
    return nil;
}
ZObject idle(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_idle();
    return nil;
}
ZObject hide(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_hideTurtle();
    return nil;
}
ZObject penUp(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_penUp();
    return nil;
}
ZObject penDOWN(ZObject* args,int n)
{
    if(n!=0)
    {
        return Z_Err(ArgumentError,"0 arguments needed!");
        
    }
    t_penDown();
    return nil;
}
ZObject setPenSize(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");   
    }
    if(args[0].type=='i')
    {
        t_penSize((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_penSize((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject left(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_turnLeft((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_turnLeft((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject right(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_turnRight((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_turnRight((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject forward(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_forward((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_forward((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject backward(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_backward((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_backward((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject setAngle(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_setAngle((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_setAngle((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject saveBMP(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='s')
    {
        t_saveBMP((char*)((string*)args[0].ptr)->c_str());
    }
    else
    {
        return Z_Err(TypeError,"String argument needed!");
        
    }
    return nil;
}
ZObject setSpeed(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_speed((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_speed((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject circle(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_circle((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_circle((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
EXPORT ZObject filled_circle(ZObject* args,int n)
{
    if(n!=1)
    {
        return Z_Err(ArgumentError,"1 argument needed!");
        
    }
    if(args[0].type=='i')
    {
        t_circle_filled((double)args[0].i);
    }
    else if(args[0].type=='f')
    {
        t_circle_filled((double)args[0].f);
    }
    else
    {
        return Z_Err(TypeError,"Integer or float argument needed!");
        
    }
    return nil;
}
ZObject GOTO(ZObject* args,int n)
{
    if(n!=2)
    {
        return Z_Err(ArgumentError,"2 arguments needed!");
        
    }
    if(args[0].type!='i' || args[1].type!='i')
    {
        return Z_Err(TypeError,"2 integer arguments needed!");
        
    }
    if(args[0].i < 0 || args[1].i <0)
    {
        return Z_Err(ValueError,"Integer arguments are negative!");
        
    }
    t_goTo((double)args[0].i,(double)args[1].i);
    return nil;
}
ZObject moveto(ZObject* args,int n)
{
    if(n!=2)
    {
        return Z_Err(ArgumentError,"2 arguments needed!");
        
    }
    if(args[0].type!='i' || args[1].type!='i')
    {
        return Z_Err(TypeError,"2 integer arguments needed!");
        
    }
    if(args[0].i < 0 || args[1].i <0)
    {
        return Z_Err(ValueError,"Integer arguments are negative!");
        
    }
    t_moveTo((double)args[0].i,(double)args[1].i);
    return nil;
}
