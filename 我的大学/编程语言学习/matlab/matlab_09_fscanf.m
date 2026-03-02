fid = fopen("matlab_10_data.txt", "r");
i = 1;
while ~feof(fid)
    name(i, :) = fscanf(fid, "%5c", 1);
    year(i)    = fscanf(fid, "%d", 1);
    no1(i)    = fscanf(fid, "%d", 1);
    no2(i)    = fscanf(fid, "%d", 1);
    no3(i)    = fscanf(fid, "%f", 1);
    no4(i)    = fscanf(fid, "%f\n");
    i = i + 1;
end
fclose(fid);
