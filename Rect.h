#ifndef __RECT_H__
#define __RECT_H__

class Rect {

public:
	Rect(int left, int top, int width, int height):m_left(left),m_top(top),m_width(width),m_height(height){}
	~Rect(){}
	int get_left(void) { return m_left; }
	void set_left(int left) { m_left = left; }

	int get_top(void) { return m_top; }
	void set_top(int top) { m_top = top; }

	int get_width(void) { return m_width; }
	void set_width(int width) { m_width = width; }

	int get_height(void) { return m_height; }
	void set_height(int height) { m_height = height; }

	void increase_left(int left) { m_left += left; }

	template<typename T>
	void convertToSDLRect(T &rect) const{
		rect.x = m_left;
        rect.y = m_top;
        rect.w = m_width;
        rect.h = m_height;
	}
protected:
private:

//---------------------------------------------------

public:
private:
    int m_left;

	int m_top;

    int m_width;

    int m_height;
protected:

};


#endif //__RECT_H__
