%-----PROPORTIONAL-INTEGRAL (PI) CONTROLLER CODE-----
disp('PROPORTIONAL-INTEGRAL (PI) CONTROLLER RESULTS')
% Plant transfer function
numG = 1;
denG = [1 5 6];
G = tf(numG, denG);

% Alpha values
K_temp = 10;
AlphaValues = [0.5, 1, 3, 5];

% Calculations of specifications for step response
Overshoot = zeros(1, length(AlphaValues));
SettlingTime = zeros(1, length(AlphaValues));
SteadyStateError = zeros(1, length(AlphaValues));
RiseTime = zeros(1, length(AlphaValues));

% Loop through each alpha value
temp = 0;
for i = 1: length(AlphaValues)
a = AlphaValues(i);

% Proportional-integral controller transfer function
s = tf('s');
D = tf(((K_temp * (1 + (a / s)))), (1));

closedLoopTransfer = feedback(series(D, G), 1);

[y, t] = step(closedLoopTransfer, 25);

yfinal = y(end);

[Y, k] = max(y);
PeakTime = t(k);
Overshoot = 100 * (Y - yfinal) / yfinal;

n = find(y >= 0.1 * yfinal, 1, 'first');
m = find(y >= 0.9 * yfinal, 1, 'first');
RiseTime = (t(m) - t(n));

SteadyStateError = abs(1 - yfinal);

SettlingIndices = find(abs(y - yfinal) <= 0.02 * yfinal);

if ~ isempty(SettlingIndices)
    last_consecutive = SettlingIndices(find(diff(SettlingIndices) > 1, 1, 'last') + 1);
    if isempty(last_consecutive)
    last_consecutive = SettlingIndices(1);
    end
SettlingTime = t(last_consecutive);
else
    SettlingTime = NaN;
end

Overshoot(i) = Overshoot;
SettlingTime(i) = SettlingTime;

SteadyStateError(i) = SteadyStateError;
RiseTime(i) = RiseTime;

figure (2);
plot(t, y, 'DisplayName', ['a = ' num2str(a)]);
hold on ;
end

% Plot the step response for the various alpha values 
title('Proportional-Integral Controller Step Response Over Alpha Value Range');
xlabel('Time (seconds)');
ylabel('Output');
legend;
grid on;
hold off;
AlphaValues;
Overshoot;
SettlingTime;
SteadyStateError;
RiseTime;