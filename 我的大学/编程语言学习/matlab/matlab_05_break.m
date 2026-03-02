x = 2; k = 0; error = inf;
error_threshold = 1e-32;
while error > error_threshold
    if k > 100
    	break
    end
    x = x - sin(x)/cos(x);
    error = abs(x - pi);
    k = k + 1;
end
