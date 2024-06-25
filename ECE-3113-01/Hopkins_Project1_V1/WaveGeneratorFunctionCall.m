t = 0.01:0.01:3;
y = WaveGenerator (30);
figure;
plot (t,y, ' Linewidth ', 2);
set (0, 'DefaultAxesFontSize', 15);
title ( '30% duty cycle square wave');
xlabel ('Time (s)');
ylabel ('Amplitude');
