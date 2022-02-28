clear
clc
N = 10000;
X = random("Exponential", 2, N, 1);
X_min = min(X);
X_max = max(X);
r = floor(log2(N)) + 1;
h = (X_max - X_min) / r;
for i=1:r+1
	z(i) = X_min + (i-1)*h;
end
z1 = z+h/2;
z2 = z1(1:r);
U = hist(X, z2);
U2 = histogram(X, z2);
tmp = U2.Values;
sum(U);
bar(z2, U/(h*N), 1);
x = 0:0.001:12;
f = pdf("Exponential", x, 2);
hold on
plot(x, f)
