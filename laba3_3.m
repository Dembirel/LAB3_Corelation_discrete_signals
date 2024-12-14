a = [0.3 0.2 -0.1 4.2 -2 1.5 0];
b = [0.3 4 -2.2 1.6 0.1 0.1 0.2];

% Визуализация исходных данных
figure;
subplot(2, 1, 1);
plot(a, 'o-');
title('Массив a');
xlabel('Индекс');
ylabel('Значение');

subplot(2, 1, 2);
plot(b, 'o-');
title('Массив b');
xlabel('Индекс');
ylabel('Значение');

max_corr = -inf; % начальное значение максимальной корреляции
best_shift = 0; % начальное значение сдвига

% Нормализованный расчет корреляции
for shift = 0:length(b)-1
    shifted_b = circshift(b, shift); % циклический сдвиг b
    
    % Нормализация массивов
    a_mean = mean(a);
    b_mean = mean(shifted_b);
    
    a_norm = a - a_mean;
    b_norm = shifted_b - b_mean;
    
    % Вычисление нормализованной корреляции
    correlation = sum(a_norm .* b_norm) / (sqrt(sum(a_norm.^2)) * sqrt(sum(b_norm.^2)));
    
    % Обновление максимальной корреляции
    if correlation > max_corr
        max_corr = correlation;
        best_shift = shift;
    end
end

disp(['Максимальная нормализованная корреляция: ', num2str(max_corr)]);
disp(['Лучший сдвиг: ', num2str(best_shift)]);

% Применение лучшего сдвига
best_shifted_b = circshift(b, best_shift);

% Визуализация результатов
figure;
plot(a, 'o-', 'DisplayName', 'Массив a');
hold on;
plot(best_shifted_b, 'x-', 'DisplayName', ['Сдвинутый b (сдвиг = ', num2str(best_shift), ')']);
title('Сравнение a и сдвинутого b');
xlabel('Индекс');
ylabel('Значение');
legend show;
hold off;
