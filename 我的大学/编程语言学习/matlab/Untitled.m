A = [0 -1 4; 9 -14 25; -34 49 64;];
B = zeros(3, 3);
for i = 1:numel(A)
    B(i) = A(i);
end
disp(B);
for i = 1:numel(A)
    if (B(i) < 0)
        B(i) = -B(i);
    end
end
disp(B);
