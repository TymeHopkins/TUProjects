syms t real
N = 11;
k = 0;
a_k = -1/(j*k*pi);

%x(t) Plot Code
x(t) = piecewise(-2 <= t < -1, 0,-1 <= t < 0, 1, 0 <= t < 1, 0, 1 <= t < 2, 1, ...
                  2 <= t < 3, 0, 3 <= t < 4, 1, 4 <= t < 5, 0, 5 <= t < 6, 1);

fplot(x(t), [-3 7], 'LineWidth', 1)
%x1(t) Plot Code
x1(t) = (2/pi)*sin(pi*t-pi)+0.5;
%x1(t) = a_k * exp(j*pi*t);

%x3(t) Plot Code
x3(t) = (2/pi)*sin(pi*t-pi) + 0.5 + (2/(3*pi))*sin(3*pi*t-pi);


%x7(t) Plot Code
x7(t) =  ((2/pi)*sin(pi*t-pi)+0.5) + (2/(3*pi))*sin(3*pi*t-pi) +(2/(5*pi))*sin(5*pi*t-pi)+ (2/(7*pi))*sin(7*pi*t-pi);

%x11(t) Plot Code
x11(t) = ((2/pi)*sin(pi*t-pi)+0.5) + (2/(3*pi))*sin(3*pi*t-pi) + (2/(5*pi))*sin(5*pi*t-pi) + (2/(7*pi))*sin(7*pi*t-pi) + (2/(9*pi))*sin(9*pi*t-pi) + (2/(11*pi))*sin(11*pi*t-pi);

%xN(t) Plot Code
for k = 0:N
    if (k == 1)
        
        %x(t) Plot Format
        subplot(2,2,1)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
        
        %x1(t) Plot Format
        fplot(x1(t), [-2 6], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x1(t)')
        xlabel('Time (s)')
        ylabel('x1(t)')

    elseif (k == 3)
        %x(t) Plot Format
        subplot(2,2,2)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
       
        %x3(t) Plot Format
        fplot(x3(t), [-2 6], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x3(t)')
        xlabel('Time (s)')
        ylabel('x3(t)')

    elseif(k == 7)
        %x(t) Plot Format
        subplot(2,2,3)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on

        %x7(t) Plot Format
        fplot(x7(t), [-2 6], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x7(t)')
        xlabel('Time (s)')
        ylabel('x7(t)')

    elseif (k == 11)
        %x(t) Plot Format
        subplot(2,2,4)
        fplot(x(t), [-3 7], 'LineWidth', 1)
        hold on
        
        %x11(t) Plot Format
        fplot(x11(t), [-2 6], 'LineWidth', 1)
        hold off
        title('CTFS Representation of x(t) and x11(t)')
        xlabel('Time (s)')
        ylabel('x11(t)')
    end
end
        




