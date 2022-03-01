clear
clc
% �������� �������� �������������� �������

% � 1
sigma = 2;
muX = 1;        muY = 3;
n1 = 100;       n2 = 150;
X = normrnd(muX, sigma, 1, n1);
Y = normrnd(muY, sigma, 1, n2);
S2_x = var(X);
S2_y = var(Y);

% F - ����������� �������� ��������
if (S2_x > S2_y)
    k1 = n1 - 1;
    k2 = n2 - 1;
    F = S2_x / S2_y;
else
    k1 = n2 - 1;
    k2 = n1 - 1;
    F = S2_y / S2_x;
end
alpha = 0.05;

% ������� 1:
% ����������� ����� �������� ������� 1
F_CrFisher1 = finv(1 - alpha, k1, k2);
if (F < F_CrFisher1)
    disp('1.1 ��������� H0: D(X) = D(Y)');
elseif (F > F_CrFisher1)
    disp('1.1 ��������� H0: D(X) > D(Y)');
end

% ������� 2:
% ����������� ����� �������� ������� 2
F_CrFisher2 = finv(1 - alpha / 2, k1, k2);
if (F < F_CrFisher2)
    disp('1.2 ��������� H0: D(X) = D(Y)');
elseif (F > F_CrFisher2)
    disp('1.2 ��������� H0: D(X) != D(Y)');
end


