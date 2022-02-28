function y = mmp(nu, X)
    gam = gamma((nu + 1) / 2) / (gamma(nu / 2) * sqrt(nu * pi));
    first = length(X) * log(gam);
    second = ((nu + 1) / 2) * sum(log((X.^2)./ nu + 1));
    y = first - second;
end
