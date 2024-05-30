# AbstractFactory

Легенда: Реализована некоторая система, которая способна генерировать код на языке С++, причем, программы только определенного вида

Требуется реализовать подобную генерацию программ на С# и Java, путем расширения возможностей предложенной реализации используя фабричные подходы. При реализации требуется добавить модификаторы классов и методов, которых нет в C++, но есть в C# и Java.

Для решения задачи используем паттерн "Абстрактная фабрика"

Класс Unit - абстрактный класс, представляющий некую языковую конструкцию

Классы ClassUnit, MethodUnit и PrintOperatorUnit представляют собой абстрактные продукты

Классы cpp_class_unit, java_class_unit и sharp_class_unit являются конкретными продуктами абстрактного продукта ClassUnit

Класс cpp_method_unit, java_method_unit и sharp_method_unit являются конкретными продуктами абстрактного продукта MethodUnit

Класс cpp_print_operator_unit, java_print_operator_unit и sharp_print_operator_unit являются конкретными продуктами абстрактного продукта PrintOperatorUnit

Класс Factory - представляет собой абстрактную фабрику, в которой объявленны методы, создающие каждый тип продукта

Класс cpp_factory - конкретная фабрика, создающая семейство продуктов cpp

Класс java_factory - конкретная фабрика, создающая семейство продуктов java

Класс sharp_factory - конкретная фабрика, создающая семейство продуктов sharp

Класс ProgramFactory - класс, в котором есть единственный атрибут - указатель на объект типа Factory а также присутствуют некоторые методы, представляющие собой различные тесты.
