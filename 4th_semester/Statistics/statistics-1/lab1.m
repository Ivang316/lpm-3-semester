clear
clc



% 1
% Генерация
lambda = 1;
k = 3;
dist = makedist("Weibull", lambda, k);
setSize = 10000;

X = random(dist, setSize, 1);



% 2.1
% Расчет характеристик
min_el = min(X);
max_el = max(X);

sMean = mean(X);
% выборочная дисперсия
sVariance = var(X, 1);
% исправленная выборочная дисперсия
sNormVariance = var(X);

standardDeviation = sqrt(sVariance);



% 2.3
% Анализ зависимости характеристик от объема выборки
figure("Name", "2.3 Анализ зависимости характеристик от объема выборки", 'NumberTitle','off')
tiledlayout("flow")
for setSize = [10, 100, 1000]
    batchCount = 1000;
    sMeans = zeros(batchCount, 1);
    sNormVariances = zeros(batchCount, 1);
    for i = 1:batchCount
        set = random(dist, setSize, 1);
        sMeans(i) = mean(set);
        sNormVariances(i) = var(set);
    end
    nexttile
    plot(1:batchCount, sMeans);
    title("Выборочное среднее при " + setSize + " элементах");
    if (setSize == 10) 
        ylabel("Теоретическое мат. ожидание равно 0.89");
    end

    nexttile
    t = plot(1:batchCount, sNormVariances);
    title("Выборочная дисперсия при " + setSize + " элементах");    
    if (setSize == 10) 
        ylabel("Теоретическая дисперсия равна 0.");
    end
end



% 2.4
% Нахождение среднего от выборочного среднего и выборочной дисперсии на
% большом объёме
iterations = 1000;
sMeans = zeros(iterations, 1);
sNormVariance = zeros(iterations, 1);

for i = 1:iterations
    setSize = 10000;
    set = random(dist, setSize, 1);
    sMeans(i) = mean(set);
    sNormVariance(i) = var(set);
end

averageSMean = mean(sMeans);
averageSNormVariance = mean(sNormVariance);

disp("2.4");
disp("Среднее выборочное среднее равно " + toFixed(averageSMean, 4) + ", теоретическое среднее равно 0.8930");
disp("Средняя выборочная дисперсия равна " + toFixed(averageSNormVariance, 4) + ", теоретическая дисперсия равна 0.1053");



% 3 
% Рачет относительных частот
[numberOfElements, ~] = size(X);
r = floor(log2(setSize)) + 1;
h = (max_el - min_el) / r;
z = zeros(1, r+1);
for i=1:r+1
    z(i) = min_el + (i-1)*h;
end
z1 = z+h/2;
z2 = z1(1:r);
% количество ui выборочных значений, 
% попавших в каждый из интервалов группировки
u = hist(X, z1);
% % гистограмма относительных частот
H = u/(h*setSize);
figure("Name", "3 Гистограмма относительных частот", 'NumberTitle','off')
bar(z1, H, 1);
range = 0:0.01:2;
FWeibull = pdf(dist, range);
hold on
plot(range, FWeibull, 'lineWidth', 2);
hold off



% 4
groupSetMean = sum(u.*z1) / setSize;
groupSetVariance = sum(((z1 - groupSetMean).^2).*u) / (setSize-1);



% Эмпирическая функция распределения для негруппированных данных
figure("Name", "5 Функции распределения", 'NumberTitle','off')
sortedX = sort(X);
T = 1/setSize : 1/setSize : 1;
stairs(sortedX, T, ':r', 'lineWidth', 2, 'Color', 'r');
hold on

% Эмпирическая функция распределения для группированных данных
H1 = 1:r;
H1(1) = 0;
for i = 2:r
    H1(i) = H1(i-1) + u(i) / setSize;
end
H1(r+1) = 1;
stairs(z, H1, 'lineWidth', 2, 'Color', 'b');

% Теоретическая функция распределения
FWeibull = pdf(dist, range);
plot(range, FWeibull, 'lineWidth', 2, 'Color', 'g');
hold off



function n = toFixed(input, digits) 
    n = floor(input * 10^digits) / (10^digits);
end
