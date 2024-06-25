%PART A
clc ;
clear all;
close all ;

% Define the range of frequencies for the plots
omega = linspace (-1000*pi , 1000*pi , 1000);

%Plot 1: |X 1(jw)|
subplot(3, 1, 1);
u = @(x) double(x >= 0);
X_1jw = (0.5) * (u(omega + 20*pi) - u(omega - 20*pi)); 
plot(omega, abs(X_1jw), 'b', 'LineWidth', 1);
title('X_1(jw)'); 
xlabel('W_(rad/sec)');
ylabel('X_1(jw)');
grid on;
ylim([-0.1, 0.6]);
xlim([-1000*pi , 1000*pi]);

% Plot 2: Stem plot for X_2(jw)
subplot (3, 1, 2);
frequencies = [-200*pi , 200*pi ];
amplitudes = [5*pi, 5*pi];
stem(frequencies , amplitudes , 'b', 'MarkerFaceColor', 'b', 'LineWidth', 1);
xlabel ('\omega');
ylabel('X_2(j\omega)'); 
title('X_2(j\omega)'); 
grid on;
xlim([-1000*pi , 1000*pi ]) ;
xticks (-1000* pi :200* pi :1000* pi ) ;
xticklabels ({ '-1000\pi', '-800\pi ' , '-600\pi ' , '-400\pi ' , '-200\pi ' , '0',...
'200\pi ' , '400\pi ' , '600\pi ' , '800\pi ' , '1000\pi'}) ;

% Plot 3: |Y(jw)|
subplot(3, 1, 3);
omega = linspace (-1000*pi , 1000*pi , 10000);
Y_abs = (5/4) * (heaviside(omega-180*pi) + heaviside(omega + 220*pi) - heaviside(omega - 220*pi) - heaviside(omega + 180*pi));
plot(omega, Y_abs, 'b', 'LineWidth', 1);
title('|Y( j \omega)|');
xlabel ('\omega') ;
ylabel('|Y(j\omega)|');
grid on;
xlim([-600*pi , 600*pi ]) ;
xticks([-600*pi, -400*pi, -200*pi, 0, 200*pi, 400*pi, 600*pi]);
xticklabels ({'-600\pi' , '−400\pi ' , '−200\pi ' , '0' , '200\pi ' , '400\pi ' , '600\pi'});

%PART B 
 % Define the time vector
 t = linspace (0 , 0.05 , 1000) ; %Changes range and resolution of time as needed
 
 % Define the parameter u
 u_values = [0.5 , 1];

 % Create a new figure
 figure ;
 
 % Loop over each value of u to create separate subplots
 for i = 1:length(u_values)
     u = u_values(i);
     y = 4 * (1 + u * cos(100 * pi * t)) .* cos(2000 * pi * t);
    % Define the subplot . There will be 2 rows and 1 column of plots .
     subplot(2, 1, i);
     plot(t, y, 'Color', 'b', 'LineWidth', 1);
     xlabel('Time (t)');
     ylabel('y(t)');
     grid on;
end

% Enhance spacing between subplots
ubplot adjustments = struct(’h pad’, 0.5, ’v pad’, 0.5); 
sgtitle('Comparison of y(t) for different values of u'); % Add a super title to the figure

% Define the frequencies for the delta functions
frequencies = [-2100*pi , -2000*pi , -1900*pi , 1900*pi , 2000*pi , 2100*pi ];

% Magnitudes for mu = 1
magnitudes_mu_1 = [2*pi , 4*pi , 2*pi , 2*pi , 4*pi , 2*pi ];

% Corrected magnitudes for mu = 0.5
magnitudes_mu_05 = [pi, 4*pi, pi, pi, 4*pi, pi];

% Create a new figure
figure;

% Subplot for mu = 1
subplot(2, 1, 1);
stem(frequencies , magnitudes_mu_1, 'filled', 'b', 'LineWidth', 1);
title('Y(j\omega) for \mu = 1');
xlabel ('\omega') ;
ylabel ('Magnitude') ;
xlim([-2500 * pi, 2500 * pi]); 
ylim([0, max(magnitudes_mu_1) + pi]);
grid on;

% Subplot for mu = 0.5
subplot(2, 1, 2);
stem(frequencies , magnitudes_mu_05 , 'filled', 'b', 'LineWidth', 1);
title('Y(j\omega) for \mu = 0.5');
xlabel ('\omega') ;
ylabel ('Magnitude') ;
xlim([-2500 * pi, 2500 * pi]); 
ylim([0, max(magnitudes_mu_05) + pi]); 
grid on;