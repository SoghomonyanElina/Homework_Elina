#include <iostream>
class Vector_3 {
    private:
      double x,y,z;
    public:
      Vector_3(double x, double y, double z) : x(x), y(y), z(z) {}
      friend Vector_3 operator+(const Vector_3& V1, const Vector_3& V2);
      friend std::ostream& operator<<(std::ostream& cout, const Vector_3& V3 );
};

Vector_3 operator+(const Vector_3& V1, const Vector_3& V2) {
  return Vector_3(V1.x + V2.x,V1.y + V2.y,V1.z + V2.z);
}
std::ostream& operator<<(std::ostream& cout, const Vector_3& V3) {
  cout << '(' << V3.x << ',' << V3.y << ',' << V3.z << ')';
  return cout;
}

int main() {
  Vector_3 V1(0, 4, 4);
  Vector_3 V2(2, 3, 5);
  Vector_3 V3 = V1 + V2;
  std::cout << V3 << std::endl;
}

//inside of class
/*#include <iostream>
class Vector_3 {
  private:
    double x, y, z;
  public:
    Vector_3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector_3 operator+(const Vector_3& V) const {
      return Vector_3(x + V.x, y + V.y, z + V.z);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector_3& V) {
      os << '(' << V.x << ',' << V.y << ',' << V.z << ')';
      return os;
    }
};

int main() {
  Vector_3 V1(3, 4, 4);
  Vector_3 V2(2, 3, 5);
  Vector_3 V = V1 + V2;
  std::cout << V << std::endl;
}*/




