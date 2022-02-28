clear
clc

lambda = 1;
k = 3;
dist = makedist("Weibull", lambda, k);
size = 400;

% 1
X = random(dist, size, 1);

% 2
min = min(X);
max = max(X);

mean = mean(X);

variance = var(X, 1);
% исправленная выборочная дисперсия
varianceNormalized = var(X);

standardDeviation = sqrt(var(X));

XSorted = sort(X);


