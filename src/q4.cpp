#include <matplot/matplot.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using namespace matplot;

// Plotting Transfer orbit because why the fuck not

double p_calc(int r1, int r2, double aMin, double f1, double f2, double delf)
{
    if (delf == 0)
    {
        delf == abs(f2 - f1);
    }
    double k = r1 * r2 * (1 - cos(delf));
    double m = r1 * r2 * (1 + cos(delf));
    double l = r1 + r2;
    double p = (k * m - 2 * aMin * k * l) / (4 * aMin * m - 2 * aMin * pow(l, 2));

    return p;
};

void transfer_orbit()
{

    // Given Parameters:
    double mu_earth = 398600;

    // Arrival Location Details:
    double a = 27000;
    double e = 0.6;
    double f = deg2rad(30); // ITS FUCKING MATLAB BAYBEEEEEE
    double r = (a * (1.0 - e * e)) / (1.0 + e * cos(f));

    // Departure Location:
    double d_a = 8000;
    double d_e = 0.01;
    double d_f = deg2rad(30.f); // ITS FUCKING MATLAB BAYBEEEEEE
    double d_r = (d_a * (1.0 - d_e * d_e)) / (1.0 + d_e * cos(d_f));

    // Transfer Orbit:
    double delf = abs(d_f - f);
    double aMin = 0.25 * (d_r + r + sqrt(pow(d_r, 2) + pow(r, 2) - 2.0 * r * d_r * cos(delf)));
    double p = p_calc(d_r, r, aMin, 0, 0, delf);
    double time = p / 3600;

    // T orbit time calc
    double delT = sqrt((pow(aMin, 3)) / mu_earth) * pi;

    double t_e = sqrt(1 - (p / aMin));

    vector<double> d_delf = iota(0, 0.0635, 2 * pi);
    vector<double> a_delf = iota(0, 0.0635, 2 * pi);
    vector<double> t_delf = iota(0, 0.0317, pi);

    vector<double> d_orbit = transform(d_delf, [d_a, d_e](auto x)
                                       { return (d_a*(1-pow(d_e,2)))/(1+d_e*cos(x));; });
    vector<double> a_orbit = transform(d_delf, [a, e](auto x)
                                       { return (a*(1-pow(e,2)))/(1+e*cos(x));; });
    vector<double> t_orbit = transform(d_delf, [aMin, t_e](auto x)
                                       { return (aMin*(1-pow(t_e,2)))/(1+t_e*cos(x));; });
//sdg
    polarplot(d_delf, d_orbit, "c");
    hold(on);
    polarplot(a_delf, a_orbit, "m");
    polarplot(t_delf, t_orbit, "g");
    hold(off);
    matplot::legend({"Departure", "Arrival", "Transfer"});

    show();
}