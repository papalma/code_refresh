// from Book Competitive Programming 3 by Steven and Felix Halim

#include <iostream>
#include <cmath>
#include <iomanip>

double f(double d, double m, double v, double t)
{
    double res = v;
    for (int i = 0; i < m; ++i)
    {
        res = res * (1 + t) - d;
    }
    return res;
}

void bisec(double a, double b)
{
    auto helper = [](double v) { return f(v, 2, 1000, 0.1); };

    if (helper(a) * helper(b) >= 0.0)
    {
        std::cout << "f(a)*f(b) debe ser < 0\n";
        return;
    }

    double res = helper(b);
    std::cout << std::setprecision(10);

    while (std::abs(b-a) > 1.0e-9)
    {
        double v = (a + b) / 2;
        res = helper(v);
        std::cout << "a=" << a << " f(a)="<<helper(a) <<
                    " b=" << b << " f(b)="<<helper(b) <<
                    " c=" << v << " f(c)="<<res<<"\n";
        
        // std::cout << "res=" << res << "\n";
        if (helper(b) * res < 0.0)
            a = v;
        else 
            b = v;
        // else
        // {
        //     std::cout << "error\n";
        //     return;
        // }
    }
}

int main()
{
    bisec(0.01, 1100.0);
}