%L(s) system function for K=1 and K=2
LK1 = tf(1*[1, 2], [1, 1, 0, -2]);  %K=1
LK2 = tf(2*[1, 2], [1, 1, 0, -2]);  %K=2

%Bode plot of system function L(s)
x = bode(LK1);      %Bode plot for when K=1
grid("on")
margin(LK1);        %GM and PM of Bode plot system function L(s)
grid("on")

y = bode(LK2);      %Bode plot for when K=2
grid("on")
margin(LK2);        %GM and PM of Bode plot system function L(s)
grid("on")

%Root locus plot
rlocus(LK1);        %Root locus plot for when K=1
grid("on")

rlocus(LK2);        %Root locus plot for when K=2
grid("on")

%Nquist plot of system function L(s)
nyquist(LK1);       %Nquist plot for when K=1
grid("on")

nyquist(LK2);       %Nquist plot for when K=2
grid("on")
