%-----PROPORTIONAL-DERIVATIVE (PD) CONTROLLER CODE-----
disp('PROPORTIONAL-DERIVATIVE (PD) CONTROLLER RESULTS')
% Plant transfer function
numG = 1;
denG = [1 5 6];
G = tf(numG, denG);

% Beta values
K_temp = 10;
BetaValues = [0.2, 0.5, 1, 5];

% Calculations of specifications for step response
Overshoot = zeros(1, length(BetaValues));
SettlingTime = zeros(1, length(BetaValues));
SteadyStateError = zeros(1, length(BetaValues));
RiseTime = zeros(1, length(BetaValues));

% Loop through each beta value
for i = 1: length(BetaValues)
    b = BetaValues(i);

% Proportional-integral controller transfer function
s = tf('s');
D = tf((K_temp * (1 + b * s)), (1));

closedLoopTransfer = feedback(series(D, G), 1);

[y, t] = step(closedLoopTransfer, 12);

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

figure (3);
plot (t, y,'DisplayName', ['Beta = ' num2str(b)]);
hold on;
end

% Plot the step response for the various beta values
title('Proportional-Derivative Controller Step Response Over Beta Value Range');
xlabel('Time (seconds)');
ylabel('Output');
legend;
grid on;
hold off;
BetaValues;
Overshoot;
SettlingTime;
SteadyStateError;
RiseTime;