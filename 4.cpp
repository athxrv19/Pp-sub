        this->height = height;
    }

    double calculateVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        this->sideLength = sideLength;
    }

    double calculateVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double calculateVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.calculateVolume() << endl;
    cout << "Volume of cube: " << cube.calculateVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.calculateVolume() << endl;

    return 0;
}

//using friend function

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    friend double calculateVolume(const Shape& shape);
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) : sideLength(sideLength) {}
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) : length(length), width(width), height(height) {}
};

double calculateVolume(const Shape& shape) {
    if (dynamic_cast<const Cylinder*>(&shape)) {
        const Cylinder& cylinder = dynamic_cast<const Cylinder&>(shape);
        return 3.14159 * cylinder.radius * cylinder.radius * cylinder.height;
    } else if (dynamic_cast<const Cube*>(&shape)) {
        const Cube& cube = dynamic_cast<const Cube&>(shape);
        return cube.sideLength * cube.sideLength * cube.sideLength;
    } else if (dynamic_cast<const Cuboid*>(&shape)) {
        const Cuboid& cuboid = dynamic_cast<const Cuboid&>(shape);
        return cuboid.length * cuboid.width * cuboid.height;
    } else {
        return 0.0;
    }
}

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << calculateVolume(cylinder) << endl;
    cout << "Volume of cube: " << calculateVolume(cube) << endl;
    cout << "Volume of cuboid: " << calculateVolume(cuboid) << endl;

    return 0;
}
