clear;
clc

N = 10000;
nu = 4;
X = random('T', nu, N, 1);

% 1. Критерий хи-квадрат Пирсона
X_max = max(X);
X_min = min(X);
r = floor(log2(N)) + 1;
h = (X_max - X_min) / r;
for i=0:r
    z(i + 1) = X_min + i * h;
end
clear('i');
for i=1:r
    z1(i) = z(i + 1) - h / 2;
end
clear('i');
u = hist(X, z1);

p = 1:r;
for i=1:r
    % Рассчитываем вероятность попадания в i-ый интервал разбиения
    p(i) = cdf('T', z(i + 1), nu) - cdf('T', z(i), nu);
end

G = 0;
for i=1:r
    G = G + power((u(i) - N * p(i)), 2) / (N * p(i));
end

% Число степеней свободы (13)
k = r - 1;
% Уровни значимости
alpha1 = 0.1;
alpha2 = 0.05;
alpha3 = 0.01;
% Критические значения с помощью обратной функции распределения хи-квадрат Пирсона
G_cr1 = chi2inv(1 - alpha1, k); % 19.8119
G_cr2 = chi2inv(1 - alpha2, k); % 22.3620
G_cr3 = chi2inv(1 - alpha3, k); % 27.6882

% 2. Критерий Колмогорова
x = 1:1:r;
f_0 = cdf('T', x, nu);

% Эмпирическая функция распределения
emp = 1:length(x);
for i=1:length(x)
  emp(i) = 0;
  for j=1:N
      if (X(j) < x(i))
          emp(i) = emp(i) + 1;
      end
  end
  emp(i) = emp(i) / N;
end

% Ищем max |f_0 - emp|
D_max = 0;
for i=1:length(x)
    if(abs(f_0(i) - emp(i)) > D_max)
        D_max = abs(f_0(i) - emp(i));
    end
end

% Статистика D
D = sqrt(N) * D_max;
% По таблице распределения Колмогорова
D_cr1 = 1.2238;
D_cr2 = 1.3581;
D_cr3 = 1.6276;
















