clc;
clear all;
close all;

syms t k;

%Plot parameters
T1 = 0.002; %Pulsewidthof2ms
T = 0.01; % Period of 10 ms
wo = 200 * pi; %Fundamental angul
wc = 2; % Upper limit of the summation
ao = 0.4; %DC offset

%Create time vector
t_values = linspace(-0.04, 0.04, 1000);

% Define the signals
u(t) = heaviside(t);
x1(t) = (u(t+T1)-u(t-T1));
x_t = symsum(x1(t-k*T), k, -5, 5);
y_sym(t) = ao + symsum((2*sin(k*wo*T1)/(k*pi)) * cos(k*wo*t), k, 1, wc);

% Convert symbolic expressions to numeric for plotting
x_values = double(subs(x_t, t, t_values));
y_values = double(subs(y_sym, t, t_values));

%Plot x(t)
subplot(3, 1, 1); % Divide figure into 3 rows, 1 column, select 1st cell
plot(t_values , x_values , 'r'); 
xlabel('Time (s)');
ylabel ('Amplitude'); 
title('x(t)');
grid on; 
ylim([-0.1 1.1]);

%Plot y(t)
subplot(3, 1, 2); % Select 2nd cell 
plot(t_values , y_values , 'g'); 
xlabel('Time (s)');
ylabel ('Amplitude') ;
title('y(t)');
grid on;
ylim([-0.2 1.3]);

%Plot x(t) and y(t)
subplot(3, 1, 3); % Select 3rd cell
plot(t_values , x_values , 'r', 'LineWidth' , 2);
hold on;
plot(t_values , y_values , 'g', 'LineWidth', 2); 
x_label('Time (s)');
y_label ('Amplitude');
title('Input/Output');
legend('x(t)', 'y(t)'); 
grid on;
ylim([-0.1 1.3]);
hold off ;






