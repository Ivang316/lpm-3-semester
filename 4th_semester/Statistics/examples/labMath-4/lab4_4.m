clear
clc

% № 4
N = 1000;
nu = 4;

% Распределение Стьюдента
X = trnd(nu, 1, N);
Y = trnd(nu, 1, N);

% Оценка коэффициента корреляции
meanX = mean(X);
meanY = mean(Y);

Sx = sqrt(var(X));
Sy = sqrt(var(Y));

roSum = sum((X - meanX).* (Y - meanY));
ro = ((1 / (N - 1)) * roSum) / (Sx * Sy);

% Значение статистики T
T = ro * sqrt(N - 2) / sqrt(1 - ro^2);

alpha1 = 0.1;
alpha2 = 0.05;
alpha3 = 0.01;

% Находим критические точки
T_Cr1 = tinv(1 - alpha1, N - 2); % 1.2824
T_Cr2 = tinv(1 - alpha2, N - 2); % 1.6464
T_Cr3 = tinv(1 - alpha3, N - 2); % 2.3301


