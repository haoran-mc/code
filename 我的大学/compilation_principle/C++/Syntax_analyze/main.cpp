#include "./include/RecursiveDescentAnalysis.h"
#include "./include/ForecastAnalysis.h"

int main() {
    RecursiveDescentAnalysis recursiveDescentAnalysis;
    recursiveDescentAnalysis.run();

    ForecastAnalysis forecastAnalysis;
    forecastAnalysis.run();
    return 0;
}
