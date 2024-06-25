%-----PROPORTIONAL CONTROLLER CODE-----
disp('PROPORTIONAL CONTROLLER RESULTS')
% Plant transfer function
numG = 1;
denG = [1 5 6];
G = tf(numG , denG);

% K values
K = [5 , 10 , 20 , 50];

% Calculations of specifications for step response
Overshoot = zeros(1, length(K));
SettlingTime = zeros(1, length(K));
SteadyStateError = zeros(1, length(K));
RiseTime = zeros(1, length(K));

% Loop through each K value
for i = 1: length(K)
    K_temp = K(i);

% Proportional controller transfer function
D = tf(K_temp, 1);

closedLoopTransfer = feedback(series(D, G), 1);

[y, t] = step(closedLoopTransfer, 5);

yfinal = y(end);

[Y, k] = max(y);
PeakTime = t(k);
Overshoot = 100 * (Y - yfinal) / yfinal;

n = find (y >= 0.1 * yfinal, 1, 'first');
m = find (y >= 0.9 * yfinal , 1, 'first');
RiseTime = t(m) - t(n);

SteadyStateError = abs(1 - yfinal);

SettlingIndices = find(abs(y - yfinal) <= 0.02 * yfinal);

if ~ isempty(SettlingIndices)
    last_consecutive = SettlingIndices(find(diff(SettlingIndices) > 1 , 1 , 'last') + 1);
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
figure (1);
plot(t, y, 'DisplayName', ['K = ' num2str(K_temp)]);
hold on;
end

% Plot the step response for the various K values
title('Proportional Controller Step Response Over K Value Range') ;
xlabel('Time (seconds)');
ylabel('Output');
legend;
grid on;
hold off;
K;
Overshoot;
SettlingTime;
SteadyStateError;
RiseTime;

