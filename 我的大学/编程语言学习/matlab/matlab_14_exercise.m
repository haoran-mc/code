t = linspace(1, 2);
f = t.^2;
g = sin(2 * pi * t);
plot(t, f, t, g, 'or');
legend({'t^2', '2*\pi*t'}, "Location", "northwest");
title("Mini Assignment #1");
xlabel("Time(ms)");
ylabel("t(t)");
