#include <stdio.h>
#include <math.h>
#include "Tools.h"
#include "MathFunctions.h"
#include "ArgParse.h"

int main(int argc, char **argv) {
    ParseArgs(argc, argv);
    if(arguments.test_root) {
        double actualRes = root(root_params.f, root_params.g, root_params.a, root_params.b,
                             root_params.eps1, root_params.f_deriv, root_params.g_deriv);
        double absoluteInacr, relativeInacr;
        calcInnacuracy(actualRes, root_params.result, &absoluteInacr, &relativeInacr);
        fprintf(stderr, "Answer: %lf\nAbsolute inaccuracy: %lf\nRelative inaccuracy %lf%%\n", actualRes, absoluteInacr, relativeInacr*100);
        printf("%lf %lf %lf\n", actualRes, absoluteInacr, relativeInacr);
        return 0;
    }
    if(arguments.test_integral) {
        double actualRes = integral(integral_params.f, integral_params.a, integral_params.b,
                                    integral_params.eps2);
        double absoluteInacr, relativeInacr;
        calcInnacuracy(actualRes, integral_params.result, &absoluteInacr, &relativeInacr);
        fprintf(stderr, "Answer: %lf\nAbsolute inaccuracy: %lf\nRelative inaccuracy %lf%%\n", actualRes, absoluteInacr, relativeInacr*100);
        printf("%lf %lf %lf\n", actualRes, absoluteInacr, relativeInacr);
        return 0;
    }

    return 0;
}