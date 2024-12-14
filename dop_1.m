% Задание размерности последовательности
N = 30;
M = 31;
rng shuffle

% Генерация случайных последовательностей с нормальным распределением
x = randn(1, N);  % Генерация 30 случайных чисел
y = randn(1, N);
z = randn(1, N); 

% Массивы для хранения значений автокорреляции
autoCorrx = zeros(1, M);
autoCorry = zeros(1, M);
autoCorrz = zeros(1, M);

% Вычисление автокорреляции для каждого сдвига от 1 до 60
for lag = 1:M
    % Сдвиг последовательности на lag позиций
    shifted_x = circshift(x, lag);
    shifted_y = circshift(y, lag);
    shifted_z = circshift(z, lag);
    
    % Вычисление автокорреляции для сдвига
    autoCorrx(lag) = sum(x .* shifted_x) / N;
    autoCorry(lag) = sum(y .* shifted_y) / N;
    autoCorrz(lag) = sum(z .* shifted_z) / N;
end

% Нормализация автокорреляции
autoCorrx = autoCorrx / max(autoCorrx);  % Нормализация на максимальное значение по модулю
autoCorry = autoCorry / max(autoCorry);
autoCorrz = autoCorrz / max(autoCorrz);

% Построение графика автокорреляции
figure;
plot(1:M, autoCorrx, '-o', 'DisplayName', 'Последовательность x');
hold on;
plot(1:M, autoCorry, '-x', 'DisplayName', 'Последовательность y');
plot(1:M, autoCorrz, '-s', 'DisplayName', 'Последовательность z');
title('Нормализованная автокорреляция для разных сдвигов');
xlabel('Сдвиг');
ylabel('Нормализованная автокорреляция');
legend show;
grid on;
hold off;
