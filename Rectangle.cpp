#include <stdio.h>
typedef struct point 
{
   int X ;
   int Y ;
}POINT;

typedef struct Rectangle
{
	POINT TopLeft;
	POINT BottomRight;
}RECT;

bool CheckPointRectangle(RECT rect , POINT pt) 
{
	if( (rect.TopLeft.X <=pt.X ) && (rect.TopLeft.Y <=pt.Y) 
		&& (rect.BottomRight.X >=pt.X )&& (rect.BottomRight.Y) >=pt.Y )
		return true;

	return false;
}
bool CheckIntersectRectangle (RECT rect1 , RECT rect2)
{	
	//Top Left of rect2
	if( CheckPointRectangle( rect1 ,rect2.TopLeft))
		return true;
	//BottomRight of rect2
	if( CheckPointRectangle( rect1 ,rect2.BottomRight))
		return true;
	//Top Right of rect2
	POINT TopRight ={  rect2.BottomRight.X ,rect2.TopLeft.Y  };
	if( CheckPointRectangle( rect1 ,TopRight))
		return true;
	//Bottom Left of rect2
	POINT BottomLeft ={ rect2.TopLeft.X,rect2.BottomRight.Y};	
	if( CheckPointRectangle( rect1 ,BottomLeft))
		return true;
	return false;
}

int main_rectInter ()
{
	RECT rect1 ={{5,10 },{15,20}},rect2 ={{15,2},{30,10}};

	printf("%d ",CheckIntersectRectangle(rect1,rect2));
 return 0;
}