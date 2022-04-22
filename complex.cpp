#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

class Complex {
public:
    double x;
    double y;
    double r;
    double alpha;
    int t;
    Complex() {

    }

    Complex(double x1, double y1) {
        x = x1;
        y = y1;
        t = 0;
    }

    Complex(double r1, double alpha1, int t1) {
        r = r1;
        alpha = alpha1;
        t = t1;
    }
};

ostream& operator<< (ostream& out, Complex cm) {
    if (cm.t == 0) {
        if (cm.y == 0) {
            out << cm.x;
        }
        else if (cm.y < 0) {
            out << cm.x << " - " << -cm.y << "i";
        }
        else {
            out << cm.x << " + " << cm.y << "i";
        }
    }
    else {
        out << cm.r << "(cos(" << cm.alpha << ")" << " + sin(" << cm.alpha << "))";
    }
    return out;
}

Complex operator+ (Complex cmf, Complex cms) { Complex temp(cmf.x + cms.x, cmf.y + cms.y); return temp; } /*сложение двух комплексных чисел*/
Complex operator-(Complex cmf, Complex cms) { Complex temp(cmf.x - cms.x, cmf.y - cms.y); return temp; } /*вычитание двух комплексных чисел*/
Complex operator== (Complex cmf, double a) { Complex temp(a, 0); return temp; } /*приравнивание числа к комплексному*/
double operator~(Complex cm) { return sqrt(cm.x * cm.x + cm.y * cm.y); } /*нахождение модуля*/
double operator!(Complex cm) {
    double a = cm.x;
    double b = cm.y;
    double tg = b / a;
    double arctg_rad = 0;
    double arctg_grad = 0;
    if (tg >= -1 && tg <= 1) {
        for (int i = 1; i < 287000; i++) {
            arctg_rad += (pow(-1, i - 1)*pow(tg, 2*i-1))/(2*i-1);
        }
        arctg_grad = arctg_rad * ((180) / M_PI);
        return arctg_grad;
    }                                          /*нахождение угла между прямой и вектором*/
    else {
        tg = 1 / tg;
        for (int i = 1; i < 287000; i++) {
            arctg_rad += (pow(-1, i - 1) * pow(tg, 2 * i - 1)) / (2 * i - 1);
        }
        arctg_rad = M_PI / 2 - arctg_rad;
        arctg_grad = arctg_rad * ((180) / M_PI);
        return arctg_grad;
    }
    
    return arctg_grad;
}

Complex operator*(Complex cmf, Complex cms) {
    Complex temp;
    if (cmf.t == 0 & cms.t == 0) {
        double r = ~cms * ~cmf;
        double alpha = !cms + !cmf;
        temp = Complex(r, alpha, 1);
    }
    return temp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Complex cm1(3, 4);
    Complex cm2(3, 4);
    Complex cm3 = cm1 * cm2;
    cout << cm3;
}
