%L(s) system function for K=1 and K=2
L = tf([48, 480, 2928], [1, 12, 44, 48, 0]);  %K=1

%Root locus plot
rlocus(L);    %Root locus plot for when K=1
grid("on")
