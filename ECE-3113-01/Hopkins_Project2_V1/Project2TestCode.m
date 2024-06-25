syms t real
N = 11;
k = 0;
ak1 = -1/(j*1*pi);
ak3 = -1/(j*3*pi);
ak7 = -1/(j*7*pi);
ak11 = -1/(j*11*pi);

%x(t) Plot Code
x(t) = piecewise(-2 <= t < -1, 0,-1 <= t < 0, 1, 0 <= t < 1, 0, 1 <= t < 2, 1, ...
                  2 <= t < 3, 0, 3 <= t < 4, 1, 4 <= t < 5, 0, 5 <= t < 6, 1);

%xN(t) Plot Code
x1(t) = ak1 * exp(j*pi*t);
x3(t) = ak1 * exp(j*pi*t) + ak3 * exp(j*3*pi*t);
x7(t) = ak1 * exp(j*pi*t) + ak3 * exp(j*3*pi*t) + ak7 * exp(j*7*pi*t);
x11(t) = ak1 * exp(j*pi*t) + ak3 * exp(j*3*pi*t) + ak7 * exp(j*7*pi*t) + ak11 * exp(j*11*pi*t);

%xN(t) Plot Code
for k = 0:N
    if (k == 1)

        %x(t) Plot Format
        subplot(2,2,1)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
        
        %x1(t) Plot Format
        fplot(x1(t), [-3 7], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x1(t)')
        xlabel('Time (s)')
        ylabel('xN(t)')

    elseif (k == 3)

        %x(t) Plot Format
        subplot(2,2,2)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
       
        %x3(t) Plot Format
        fplot(x3(t), [-3 7], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x3(t)')
        xlabel('Time (s)')
        ylabel('xN(t)')

    elseif(k == 7)

        %x(t) Plot Format
        subplot(2,2,3)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on

        %x7(t) Plot Format
        fplot(x7(t), [-3 7], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x7(t)')
        xlabel('Time (s)')
        ylabel('xN(t)')

    elseif (k == 11)

        %x(t) Plot Format
        subplot(2,2,4)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
        
        %x11(t) Plot Format
        fplot(x11(t), [-3 7], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x11(t)')
        xlabel('Time (s)')
        ylabel('xN(t)')

    end
end
        




