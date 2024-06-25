
% 50% Duty Cycle
subplot(2,1,1)
amplitudeDutyCycle = 1 * [ones(1, 100), zeros(1, 100)];
dt = 1 / numel(amplitudeDutyCycle);
seconds = 3;
y = repmat(amplitudeDutyCycle, [1, seconds]);
t = dt * (0 : (numel(y) - 1));
plot(t, y, 'LineWidth', 2);
xlabel('Time (s)');
ylabel('Amplitude');
title('50% Duty Cycle');


% 70% Duty Cycle
subplot(2,1,2)
amplitudeDutyCycle = 1 * [ones(1, 700), zeros(1, 300)];
dt = 1 / numel(amplitudeDutyCycle);
seconds = 3;
y = repmat(amplitudeDutyCycle, [1, seconds]);
t = dt * (0 : (numel(y) - 1));
plot(t, y, 'LineWidth', 2);
xlabel('Time (s)');
ylabel('Amplitude');
title('70% Duty Cycle');

