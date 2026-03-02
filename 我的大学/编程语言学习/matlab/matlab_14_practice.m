x = linspace(1, 2);
y1 = x.^2;
y2 = sin(2*pi*x);
plot(x, y1,  x, y2, "or");
title("Mini Assignment #1");
legend("t^2", "sin(2*\pi*t)");
xlabel("Time(ms)");
ylabel("f(t)");
