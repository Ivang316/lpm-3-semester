clear
clc

% Выборка распределения Стьюдента
N = 10000;
nu = 4;
X = random('T', nu, N, 1);

% Количество интервалов
r = floor(log2(N)) + 1;
% min и max значения выборки
X_max = max(X);
X_min = min(X);
% Ширина каждого интервала группировки
h = (X_max - X_min) / r;
% Массив границ z интервалов группировки
for i=0:r
    z(i + 1) = X_min + i * h;
end
clear 'i';
% Середина каждого столбца столбчатой диаграммы
for i=1:r
    z1(i) = z(i + 1) - h / 2;
end
clear 'i';
% Построение гистограммы
U = hist(X, z1);
H = U / (h * N);

% Найдём оценку nu по методу моментов
variance = var(X);
equation = @(x) x / (x - 2) - variance;
NU_MM = fzero(equation, nu);

% Найдём оценку nu по медоду максимального правдоподобия
likeX = (1:0.01:5);
for i=1:length(likeX)
    likeY(i) = mmp(likeX(i), X);
end
[likeMax, likeIndex] = max(likeY);
NU_MMP = likeX(likeIndex);

% Плотность вероятности
x = (-20:0.001:20);
pdf_student = pdf('T', x, nu);
pdf_student2 = pdf('T', x, NU_MMP);

% Эмпирическая функция распределения для негруппированных данных
X_sort = sort(X);
T = 1/N:1/N:1;
% Теоретическая функция распределения
y = (-20:0.001:20);
cdf_student = cdf('T', y, nu);
cdf_student2 = cdf('T', y, NU_MMP);

% Вывод
figure;
subplot(2, 2, 1);
bar(z1, H, 1);
hold on;
plot(x, pdf_student, '-r');
hold on;
plot(x, pdf_student2, '-g');
hold off;

subplot(2, 2, 2);
plot(likeX, likeY);

subplot(2, 2, 3);
fplot(equation, [2 5]);

subplot(2, 2, 4);
stairs(X_sort, T);
hold on;
plot(y, cdf_student, '-r');
hold on;
plot(y, cdf_student2, '-g');
hold off;


bias = 0; % Смещение оценки
scatering = 0; % Рассеяние оценки
for i=1:100
    X = random('T', nu, N, 1);
    likeX = (1:0.01:5);
    for j=1:length(likeX)
        likeY(j) = mmp(likeX(j), X);
    end
    [likeMax, likeIndex] = max(likeY);
    NU_MMP = likeX(likeIndex);
    
    bias = bias + NU_MMP - nu;
    scatering = scatering + (NU_MMP - nu)^2;
end
bias = bias / 100; % Оценка по ММП, несмещенная
scatering = scatering / 100;
dispers = scatering - bias^2; % Дисперсия оценки



