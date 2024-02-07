#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class primitive {
public:
	virtual void resize(float) = 0;
	virtual void draw() = 0;
	virtual bool cmp(primitive*) = 0;
	virtual void move(float, float) = 0;
	virtual void set_colour(int colour) = 0;

	virtual ~primitive() = default;
};

class figure : public primitive{
protected:
	int type;
	float x;
	float y;
	int colour;

public:
	bool cmp(primitive*) override;
	void move(float, float) override;
	void set_colour(int colour) override;
};

class circle : public figure {
private:
	float radius;

public:
	circle(float, float, float);

	void resize(float) override;
	void draw() override;
};

#endif /* FIGURE_H */