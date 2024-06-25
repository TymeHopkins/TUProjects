syms t
g(t) = piecewise(t < -5, 0, (-5 <= t) & (t < -2), (-2*t)-10, (-2 <= t) & (t < 2), sin(pi*t)/2-6, t >= 2, -6*exp(-(t-2)/2));

%Creates a 2 by 2 grpah tile layout
tiledlayout(2,2)

%First function: g(t)
nexttile
fplot(g(t), [-10, 10])
xlabel('t')
ylabel('g(t)')

%Second function: g(2*t)
nexttile
fplot(g(2*t), [-10, 10])
xlabel('t')
ylabel('g(2*t)')

%Third fucntion: 2*g(3-t)
nexttile
fplot(2*g(3-t), [-10, 10])
xlabel('t')
ylabel('2*g(3-t)')

%Fourth function: -2*g((t + 1)/2)
nexttile
fplot(-2*g((t + 1)/2), [-10, 10])
xlabel('t')
ylabel('-2*g((t + 1)/2)')


subplot(4, 1, 1);
x(t) = piecewise(-2 <= t < -1, 0,-1 <= t < 0, 1, 0 <= t < 1, 0, 1 <= t < 2, 1, ...
                  2 <= t < 3, 0, 3 <= t < 4, 1, 4 <= t < 5, 0, 5 <= t < 6, 1);
fplot(x(t), [-2, 6], 'linewidth', 2);

