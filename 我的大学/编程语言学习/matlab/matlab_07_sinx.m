x = 0:pi/10:pi;
y = sin(x);
fid = fopen('matlab_08_sinx.txt', 'w');
for i = 1:11
    fprintf(fid, '%5.3f %8.4f\n', x(i), y(i));
end
fclose(fid);
type matlab_08_sinx.txt;
