#include <iostream>
#include <list>

class IShape
{
public:
    virtual void Draw() = 0;
    virtual ~IShape(){};
};

class Circle: public IShape
{
public:
    virtual void Draw()
    {
      // draw circle on GUI
      std::cout << "Draw circle" <<std::endl; 
    }
    virtual ~Circle(){};
};


class Square: public IShape
{
public:
    virtual void Draw()
    {
      // draw square on GUI
      std::cout << "Draw Square" <<std::endl; 
    }
    virtual ~Square(){};
};


class Client
{
public:
    static void DrawAllShapes(const std::list<IShape*>& shapes)
    {
      for(IShape* shape : shapes)
      {
        shape->Draw();
      }
    }
};


int main()
{
    std::list<IShape*> shapes;
        
    shapes.push_back(new Circle());
    shapes.push_back(new Square());
    
        
    Client::DrawAllShapes(shapes);

    
#if 1
    
    for(IShape* shape : shapes)
    {
        delete shape;
    }
    shapes.clear();
    
#endif
 
}
