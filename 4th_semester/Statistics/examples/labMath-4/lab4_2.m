clear
clc

% � 2
mu = 1;
sigmaX = 2;     sigmaY = 4;
n = 100;        m = 150;
X = normrnd(mu, sigmaX, 1, n);
Y = normrnd(mu, sigmaY, 1, m);
meanX = mean(X);
meanY = mean(Y);

% Z - ����������� �������� ��������
Z = (meanX - meanY) / sqrt(sigmaX.^2 / n + sigmaY.^2 / m);

% ������� 1:
alpha = 0.05;
% ����������� ����� �������� ������� 1
F_CrLablas1 = (1 - alpha) / 2; % 0.475
% ������ �� ������� �������
Z_1 = 1.96;
if (abs(Z) < Z_1)
    disp('2.1 ��������� H0: M(X) = M(Y)');
elseif (abs(Z) > Z_1)
    disp('2.1 ��������� H0: M(X) != M(Y)');
end

% ������� 2
% ����������� ����� �� ������� 2
F_CrLaplas2 = (1 - 2 * alpha) / 2; % 0.45
% ������ �� ������� �������
Z_2 = 1.65;
if (Z < Z_2)
    disp('2.2 ��������� H0: M(X) = M(Y)');
elseif (Z > Z_2)
    disp('2.2 ��������� H0: M(X) > M(Y)');
end

% ������� 3
if (Z > -Z_2)
    disp('2.3 ��������� H0: M(X) = M(Y)');
elseif (Z < -Z_2)
    disp('2.3 ��������� H0: M(X) < M(Y)');
end


