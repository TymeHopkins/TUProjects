
for k = 0:1:N
    if (N == 1)
        subplot(2, 2, 1);
        a_k = 1/(j*pi);
        x1(t) = a_k * e^(j*pi*t);
        fplot(x1(t), [-2, 6], 'linewidth', 2)
    
    elseif (N == 3)
        subplot(2, 2, 2);
        a_k = 1/(j*3*pi);
        x2(t) = a_k * e^(j*3*pi*t);
        fplot(x2(t), [-2, 6], 'linewidth', 2)
        
    elseif (N == 7)
        subplot(2, 2, 3);
        a_k = 1/(j*7*pi);
        x3(t) = a_k * e^(j*7*pi*t);
        fplot(x3(t), [-2, 6], 'linewidth', 2)

    elseif (N == 11)
        subplot(2, 2, 4)

    else
        k = k + 1;
    end
end


function plotcall(plot)
    if (plot == 'x(t)')
        subplot(2, 2, 1);
        fplot(x(t), [-2, 6], 'LineWidth', 3)
        xlabel('t')
        ylabel('x(t)')
    end
end
