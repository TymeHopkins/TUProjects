syms t real
N = 11;
k = 0;
a_k = -1/(j*k*pi);

%x(t) Plot Code
x(t) = piecewise(-2 <= t < -1, 0,-1 <= t < 0, 1, 0 <= t < 1, 0, 1 <= t < 2, 1, ...
                  2 <= t < 3, 0, 3 <= t < 4, 1, 4 <= t < 5, 0, 5 <= t < 6, 1);

fplot(x(t), [-3 7], 'LineWidth', 2)

title('CTFS Representation of x(t)')
xlabel('Time (s)')
ylabel('x(t)')
