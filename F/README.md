# F. EPAM Systems

Time limit 2000/4000/4000/4000 ms. Memory limit 65000/65000/65000/65000 Kb.

## Задание 1. Проверить корректность расстановки скобок в выражении.

Дана строка, содержащая в себе символы латинского алфавита, символы математических операций, пробелы и скобки: "(" и ")". Необходимо написать программу, проверяющую, корректно ли расставлены скобки в строке.

**Входные данные:** строка, которую необходимо проверить.

Программа должна выводить значение "1", если скобки расставлены корректно и "0" - если некорректно.

**Пример:**

- `(a + b)` - корректная строка
- `(x + y) * a + b)` - некорректная строка
- `foo() + bar()` - корректная строка
